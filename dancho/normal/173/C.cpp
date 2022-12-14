#include <cstdio>
#include <cstring>


inline void swap( int &a, int &b )
{
	int t = a; a = b; b = t;
}

int n, m;
int a[512][512];
long long ps[512][512];
long long val[2][512][512];

inline long long getpr( int i, int j, int k )
{
	return ps[i+k-1][j+k-1] - ps[i-1][j+k-1] - ps[i+k-1][j-1] + ps[i-1][j-1];
}

int main()
{
	int i, j, k;
	
	int cr, pr;
	
	long long mx = -(1LL<<62);
	
	scanf( "%d %d", &n, &m );
	memset( ps, 0, sizeof( ps ) );
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
		{
			scanf( "%d", &a[i][j] );
			ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + a[i][j];
		}
	}
	
	cr = 1;
	pr = 0;
	
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
		{
			val[cr][i][j] = a[i][j];
		}
	}
	
	swap( pr, cr );
	for ( k = 3; k <= m && k <= n; k=k+2 )
	{
		for ( i = 1; i+k-1 <= n; i++ )
		{
			for ( j = 1; j+k-1 <= m; j++ )
			{
				val[cr][i][j] = getpr( i, j, k ) - val[pr][i+1][j+1] - a[i+1][j];
				if ( val[cr][i][j] > mx ) mx = val[cr][i][j];
			}
		}
		swap( pr, cr );
	}
	
	printf( "%I64d\n", mx );
	return 0;
}