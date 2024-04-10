#include <cstdio>
#include <cstring>
#include <cmath>

int n;
double a, d;

double t, v;
double la;

int main()
{
	la = 0.0;
	int i;
	double vu, tu, tp;
	
	scanf( "%d %lf %lf", &n, &a, &d );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%lf %lf", &t, &v );
		
		tu = v/a; vu = v/2.0;
		if ( tu*vu > d )
		{
			tp = sqrt( 2.0*d/a );
		}
		else
		{
			tp = tu + (d-tu*vu)/v;
		}
		if ( tp + t > la ) la = tp+t;
		printf( "%.12lf\n", la );
	}
	return 0;
}