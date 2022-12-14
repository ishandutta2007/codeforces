#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-7;

struct point
{
	int x, y, id;
	
	bool operator<( const point &p ) const
	{
		return x+y < p.x + p.y;
	}

	bool operator>( const point &p ) const
	{
		return x-y < p.x - p.y;
	}
};

int ia( int x )
{
	if ( x < 0 ) return -x;
	return x;
}

int n;

point p[1<<20];

int mxl[1<<20], mxr[1<<20], mil[1<<20], mir[1<<20];

int main()
{
	double le, ri, mi;
	int i, j;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &p[i].x, &p[i].y );
	}
	
	sort( p + 1, p + n + 1 );
	//mxl[0] = mxr[n+1] = mil[0] = mir[n+1] = 0;
	mxl[0] = mxr[n+1] = -(1<<31);
	mil[0] = mir[n+1] = (1<<31)-1;
	for ( i = 1; i <= n; i++ )
	{
		//printf( "OP %d %d %d\n", i, p[i].x + p[i].y, p[i].x - p[i].y );
		mxl[i] = max( mxl[i-1], p[i].x-p[i].y );
		mil[i] = min( mil[i-1], p[i].x-p[i].y );
	}
	
	for ( i = n; i > 0; i-- )
	{
		mxr[i] = max( mxr[i+1], p[i].x-p[i].y );
		mir[i] = min( mir[i+1], p[i].x-p[i].y );
	}
	
	le = 0; ri = 1e9*2;
	
	while ( le + eps < ri )
	{
		mi = (le+ri)/2;
		//printf( "BS %lf %lf %lf\n", le, ri, mi );
		j = 1;
		i = 1;
		while ( p[i].x+p[i].y - p[j].x - p[j].y + eps < mi && i <= n )
		{
			i++;
		}

		//printf( "preCIC %d %d %d :: %d %d\n", j, i, max( mxr[i], mxl[j-1] ) - min( mir[i], mil[j-1] ), max( mxr[i], mxl[j-1] ), min( mir[i], mil[j-1] ) );
		if ( mxr[i] - mir[i] < mi || i > n )
		{
			ri = mi;
			continue;
		}

		j = 1;
		for ( ;j <= n; )
		{
			j++;
			while ( p[i].x + p[i].y - p[j].x - p[j].y + eps < mi && i <= n )
			{
				i++;
			}
			//printf( "CIC %d %d %d :: %d %d\n", j, i, max( mxr[i], mxl[j-1] ) - min( mir[i], mil[j-1] ), max( mxr[i], mxl[j-1] ), min( mir[i], mil[j-1] ) );
			if ( max( mxr[i], mxl[j-1] ) - min( mir[i], mil[j-1] ) < mi )
				break;
		}
		//printf( "OP %d %d\n", j, n );
		if ( max( mxr[i], mxl[j-1] ) - min( mir[i], mil[j-1] ) < mi )
			ri = mi;
		else
			le = mi;
	}
	
	printf( "%.10lf\n", ri/2 );
	return 0;
}