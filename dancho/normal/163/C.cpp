#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct el
{
	double sp;
	int cn;
	bool operator<( const el& x ) const
	{
		return sp < x.sp;
	}
};

const double eps = 1e-7;

int n, l, v1, v2;

int a[100020];
double le[100020];

el e[200020];

int main()
{
	int i, k;
	
	double sx, ta, x, y;
	double sa;
	
	scanf( "%d %d %d %d", &n, &l, &v1, &v2 );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
	}
	k = a[1];

	ta = (double)l/(double)(v1+v2);
	sx = ta*v1;
	sa = l-sx;
	while ( sa < 0 ) sa = sa + l+l;
	while ( sa > 2*l ) sa = sa-l-l;
	for ( i = 1; i <= n; i++ )
	{
		a[i] = a[i] - k;
		le[i] = 0;
		e[i].sp = a[i]; e[i].cn = -1;
		e[i+n].sp = a[i] - sa; e[i+n].cn = +1;
		while ( e[i+n].sp < 0 )e[i+n].sp = e[i+n].sp + 2.0*l;
	}
	
	sort ( e + 1, e + 2*n + 1 );
	
//	for ( i = 1; i <= 2*n; i++ )
//		printf( "%d %lf %d\n", i, e[i].sp, e[i].cn );
//	printf( "%lf\n", sa );
	
	k = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i]+eps < sa ) k++;
	}
	
	x = 0;
	for ( i = 1; i <= 2*n; i++ )
	{
		y = e[i].sp;
		le[k] = le[k] + y-x;
		k = k + e[i].cn;
//		if ( k < 0 ) k = 0;
		x = y;
	}
	y = 2*l;
	le[k] = le[k] + y-x;
	
	for ( i = 0; i <= n; i++ )
	{
		printf( "%.20lf\n", le[i]/(double)(2.0*l) );
	}
	return 0;
}