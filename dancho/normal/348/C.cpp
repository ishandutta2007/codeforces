#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m, q;
long long a[1<<18];

vector<int> bs[1<<18]; // koi golemi darzhat a[i].

int comnd[1<<17][128]; // kolko obshti st-ti ima s[i] sas j-toto golqmo

int nn[1<<18], ln = 0, on[1<<18];   // nn za golemite
vector<int> s[1<<18];

long long sub[1<<18]; // kolko sam uvelichil big zaradi small upd
long long bub[1<<18]; // kolko sam uvelichil big zaradi big upd

int main()
{
	int i, j, k;
	scanf( "%d %d %d", &n, &m, &q );
	
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &k );
		a[i] = k;
	}
	
	memset( nn, 0, sizeof( nn ) );
	memset( on, -1, sizeof( on ) );
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d", &k );
		if ( k >= 1000 )
		{
			ln++;
			nn[i] = ln;
			on[ln] = i;
		}
		for ( int l = 0; l < k; ++l )
		{
			scanf( "%d", &j );
			s[i].push_back( j );
			if ( nn[i] )
			{
				bs[j].push_back( i );
			}
		}
	}
	
	memset( comnd, 0, sizeof( comnd ) );
	memset( sub, 0, sizeof( sub ) );
	memset( bub, 0, sizeof( bub ) );
	for ( i = 1; i <= m; ++i )
	{
		for ( j = 0; j < (int) s[i].size(); ++j )
		{
			for ( k = 0; k < (int) bs[ s[i][j] ].size(); ++k )
			{
				++comnd[i][ nn[ bs[ s[i][j] ][k] ] ];
			}
			if ( nn[i] )
			{
				sub[i] += a[ s[i][j] ];
			}
		}
	}
	
	for ( i = 1; i <= ln; ++i )
		if ( comnd[on[i]][ i ] != (int) s[ on[i] ].size() )
		{
			while ( 1 );
		}
	
	char op[8];
	
	for ( i = 1; i <= q; i++ )
	{
		scanf( "%s", op );
		if ( op[0] == '?' )
		{
			scanf( "%d", &k );
			if ( nn[k] )
			{
				long long ans = sub[k];
				for ( j = 1; j <= ln; j++ )
				{
					ans += bub[ on[j] ] * comnd[k][j];
				}
				printf( "%I64d\n", ans );
			}
			else
			{
				long long ans = 0;
				for ( j = 0; j < (int) s[k].size(); ++j )
				{
					ans += a[ s[k][j] ];
				}
				for ( j = 1; j <= ln; j++ )
				{
					ans += bub[ on[j] ] * comnd[k][j];
				}
				printf( "%I64d\n", ans );
			}
		}
		else if ( op[0] == '+' )
		{
			int x;
			scanf( "%d %d", &k, &x );
			
			if ( nn[k] )
			{
				bub[k] = bub[k] + x;
			}
			else
			{
				for ( j = 0; j < (int) s[k].size(); ++j )
				{
					a[ s[k][j] ] = a[ s[k][j] ] + x;
				}
				for ( j = 1; j <= ln; ++j )
				{
					sub[ on[j] ] += (long long) x * comnd[k][j];
				}
			}
		}
	}
	return 0;
}