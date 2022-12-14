#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int mod = 1000000007;

int n, q, t;
int a[512];
int pr[512];
int ne[512];

int us[512];

vector<int> b;
long long ps[512];

long long g[2][200020];

bool gogo( int v )
{
	b.push_back( v );
	if ( ne[v] != -1 )
	{
		if ( us[ ne[v] ] != 0 )
			return 0;
		us[ ne[v] ] = 1;
		if ( !gogo( ne[v] ) )
			return 0;
	}
	return 1;
}

int main()
{
	int i, j, k;
	
	memset( ne, -1, sizeof( ne ) );
	memset( pr, -1, sizeof( pr ) );
	
	scanf( "%d %d %d", &n, &q, &t );
	for ( i = 1; i <= n; i++ )
		scanf( "%d", &a[i] );
	for ( i = 1; i <= q; i++ )
	{
		scanf( "%d %d", &j, &k );
		ne[j] = k;
		pr[k] = j;
	}
	
	memset( us, 0, sizeof( us ) );
	for ( i = 1; i <= n; i++ )
	{
		if ( pr[i] == -1 )
		{
			us[i] = 1;
			b.clear();
			if ( !gogo( i ) )
			{
				printf( "0\n" );
				return 0;
			}
			k = (int) b.size();
			long long de = 0;
			for ( j = 0; j < k; j++ )
			{
				if ( j == 0 )
					ps[ b[j] ] = a[ b[j] ];
				else if ( j > 0 )
					ps[ b[j] ] = ps[ b[j-1] ] + a[ b[j] ];
				if ( j+1 < k )
					de += ps[ b[j] ];
			}
			
			if ( (long long) t < de )
			{
				printf( "0\n" );
				return 0;
			}
			t -= de;
			if ( t < 0 )
			{
				printf( "0\n" );
				return 0;
			}
		}
	}
	
	for ( i = 1; i <= n; i++ )
	{
		if ( !us[i] )
		{
			printf( "0\n" );
			return 0;
		}
	}
	
	int pr, cr;
	memset( g, 0, sizeof( g ) );
	g[0][0] = g[1][0] = 1;
	for ( j = 1; j <= n; j++ )
	{
		cr = j%2;
		pr = 1-cr;
		g[cr][0] = 1;
		for ( int s = 1; s <= t; s++ )
		{
			g[cr][s] = 0;
			if ( s - ps[j] >= 0 )
				g[cr][s] += g[cr][ s-ps[j] ];
			if ( j > 1 )
				g[cr][s] += g[pr][ s ];
			if ( g[cr][s] >= mod )
				g[cr][s] %= mod;
		}
	}
	
	printf( "%d\n", (int) g[n%2][t] );
	return 0;
}