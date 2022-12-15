#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std ;

const double eps = 1e-7 ;
const int MAX_N = 60000 + 10 , INF = 0x3f3f3f3f ;

int n , x[MAX_N] , v[MAX_N] , minx , maxx ;

bool check(double t)
{
	double lx = x[0] - v[0] * t , rx = x[0] + v[0] * t ;

	for (int i = 1 ; i < n ; ++i)
	{
		double nl = x[i] - v[i] * t , nr = x[i] + v[i] * t ;

		lx = max(lx , nl) ; rx = min(rx , nr) ;

		if (lx > rx) return 0 ;
	}

	return 1 ;
}

int main()
{
	scanf("%d" , &n) ;
	minx = INF ; maxx = -INF ;
	
	///

	for (int i = 0 ; i < n ; ++i)
		scanf("%d" , &x[i]) , minx = min(minx , x[i]) , maxx = max(maxx , x[i]) ;
	for (int i = 0 ; i < n ; ++i)
		scanf("%d" , &v[i]) ;

	///
	
	double L = 0 , R = maxx - minx ;


	while (fabs(L - R) > eps)
	{
		double mid = (L + R) / 2 ;

		if (check(mid)) R = mid ;
		else L = mid ;
	}

	printf("%0.6lf\n" , R) ;

	return 0 ;
}