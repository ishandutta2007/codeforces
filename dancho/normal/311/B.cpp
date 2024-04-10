#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


struct cat
{
	int h, t;
	long long f;
	
	bool operator<( const cat& c ) const
	{
		return f < c.f;
	}
};

bool us[100020][120];
long long dp[100020][120];

int nex[100020];

int n, m, p;
int d[100020];

long long pf[100020];

int beg[120], end[120];
int sx[100020][120];

cat c[100020];

long long s[100020];

long long eval( int i, int j, int x )
{
	return c[i].f*(i-x) - (pf[i] - pf[x]) + dp[x][j-1];
}

long long value( int i, int j, int x )
{
	return c[i].f*(-x) + pf[x] + dp[x][j-1];
}

double B( int i, int j, int x )
{
	return pf[x] + dp[x][j-1];
}

double A( int i, int j, int x )
{
	return -x;
}

double cross( int x, int j, int y )
{
	return (pf[y] + dp[y][j-1] - (pf[x] + dp[x][j-1]))/(y-x);
	
	int l, r, mi;
	if ( value( m, j, x ) <= value( m, j, y ) )
	{
		return m+1;
	}
	l = y; r = m;
	while ( l+1 < r )
	{
		mi = (l+r)/2;
		if ( value( mi, j, x ) > value( mi, j, y ) )
			r = mi;
		else
			l = mi;
	}
	return r;
}

int main()
{
	int i, j;
	
	scanf( "%d %d %d", &n, &m, &p );
	
	s[1] = 0;
	for ( i = 2; i <= n; i++ )
	{
		scanf( "%d", &d[i] );
		s[i] = s[i-1] + d[i];
	}
	
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d", &c[i].h, &c[i].t );
		c[i].f = c[i].t - s[ c[i].h ];
	}

	sort( c + 1, c + m + 1 );
	
	
	memset( us, 0, sizeof( us ) );
	
	for ( i = m; i > 0; )
	{
		j = i;
		while ( c[j].f == c[i].f && j > 0 )
		{
			nex[j] = i;
			j--;
		}
		i = j;
	}
	
	pf[0] = 0;
	for ( i = 1; i <= m; i++ )
	{
		pf[i] = pf[i-1] + c[i].f;
	}
	
	for ( i = 0; i <= p; i++ )
	{
		beg[i] = end[i] = 1;
		sx[1][i] = 0;
		dp[0][i] = 0;
	}
	for ( i = 1; i <= m; i++ )
	{
		dp[i][0] = (1LL<<62);
		for ( j = p; j > 0; j-- )
		{
			while ( (beg[j-1] < end[j-1] ) && ( eval( i, j, sx[beg[j-1]][j-1] ) >= eval( i, j, sx[beg[j-1]+1][j-1] ) ) )
			{
				//printf( "pop_front %d %d :: %d\n", i, j, sx[beg[j-1]][j-1] );
				beg[j-1]++;
			}
			dp[i][j] = eval( i, j, sx[beg[j-1]][j-1] );
			while ( ( beg[j] < end[j] ) && ( cross( sx[end[j]][j], j+1, i ) <= cross( sx[end[j]-1][j], j+1, sx[end[j]][j] ) ) )
			//while ( ( beg[j] < end[j] ) && ( eval( i+1, j+1, i ) <= eval( i+1, sx[end[j]-1][j], j+1, sx[end[j]][j] ) ) )
			{
			//	printf( "POP_back %d %d\n", i, j );
				end[j]--;
			}
//			if ( cross( sx[end[j]][j], j+1, i ) <=  )
			{
			//	printf( "PUSH %d %d\n", i, j );
				sx[ ++end[j] ][j] = i;
			}
		}
	}
	
	printf( "%I64d\n", dp[m][p] );
	return 0;
}