#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

int n, m;
vector<pii> r;
set<int> fcol;
int rm[1<<18];

int nn;
vector<int> g[1<<20];

int indeg[1<<20];
bool us[1<<20];
int p[1<<20], lp;

int covm = 0;

void dfst( int v )
{
	int i, u;
	for ( i = 0; i < (int) g[v].size(); i++ )
	{
		u = g[v][i];
		indeg[u]--;
		if ( indeg[u] == 0 && us[u] == 0 )
		{
			us[u] = 1;
			if ( u <= m ) covm++;
			p[++lp] = u;
			dfst( u );
		}
	}
}

int main()
{
	int i, j, k;
	
	scanf( "%d %d", &n, &m );
	
	nn = m;
	for ( i = 1; i <= m; i++ )
	{
		fcol.insert( i );
		rm[i] = 0;
	}
	
	memset( indeg, 0, sizeof( indeg ) );
	memset( us, 0, sizeof( us ) );
	for ( i = 1; i <= n; i++ )
	{
		r.clear();
		for ( j = 1; j <= m; j++ )
		{
			scanf( "%d", &k );
			r.push_back( make_pair( k, j ) );
		}
		sort( r.begin(), r.end() );
		bool fl = 0;
		for ( j = 0; j < (int) r.size(); )
		{
			k = j;
			nn++;
			while ( ( k < (int) r.size() ) && ( r[k].first == r[j].first ) )
			{
				if ( r[k].first != -1 )
				{
					g[ r[k].second ].push_back( nn );
					indeg[nn]++;
				}
				if ( fl )
				{
					g[nn-1].push_back( r[k].second );
					indeg[r[k].second]++;
				}
				k++;
			}
			if ( r[k].first != -1 )
				fl = 1;
			j = k;
		}
	}
	
	lp = 0;
		for ( i = 1; i <= nn; i++ )
		{
			if ( indeg[i] == 0 && us[i] == 0 )
			{
				p[++lp] = i;
				if ( i <= m )
					covm++;
				us[i] = 1;
				dfst( i );
			}
		}
	if ( covm < m )
	{
		printf( "-1\n" );
	}
	else
	{
		bool fl = 0;
		for ( i = 1; i <= lp; i++ )
		{
			if ( p[i] <= m )
			{
				if ( !fl )
					printf( "%d", p[i] );
				else
					printf( " %d", p[i] );
				fl = 1;
			}
		}
		printf( "\n" );
	}
	return 0;
}