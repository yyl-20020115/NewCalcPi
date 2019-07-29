#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N   1000000

//ff(x) = 4.0 / (1.0 + x^2)

double ff(const double x)
{
	return 4.0 / (1.0 + x * x);
}

int main()
{
	const double d = 0.5;

	const double h = 1.0 / N;

	double sx = 0.0, rx = 0.0;

	/*
	  s = 4.0/N*(1.0/(1.0 + (0.5/N)^2) + 1.0/(1.0+(1.5/N)^2) + 1.0/(1.0 + (2.5/N)^2) + ...)
	*/
	for (int i = 0; i < N; i++) 
	{
		sx += ff(h * (i + d));
	}
	
	rx = h * sx;

	double sy = 0.0,ry = 0.0;

	for (int i = 0; i < N; i++) {
		double u = (i + d) / N;
		sy += (1.0 / (1.0 + u*u));
	}

	ry =4.0 / N * sy;



	printf("\nN = %d, sx = %0.15lf, diff = %le\n", N, rx, rx / 3.141592653589793238 - 1);
	printf("\nN = %d, sy = %0.15lf, diff = %le\n", N, ry, ry / 3.141592653589793238 - 1);
	//getchar();
	return 0;
}
