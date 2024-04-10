#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
vector<int> pl[1024], lp[1024];

int lc = 0;
bool us[1024];
int col[1024];
void dfsl( int );

void dfsp( int p )
{
//	printf( "DFSP %d %d %d\n", p, lc, col[p] );
	int u;
	for ( int i = 0; i < (int) pl[p].size(); i++ )
	{
		u = pl[p][i];
		if ( !us[u] )
		{
			us[u] = 1;
			dfsl( u );
		}
	}
}

void dfsl( int l )
{
	int u;
	for ( int i = 0; i < (int) lp[l].size(); i++ )
	{
		u = lp[l][i];
		if ( col[u] == -1 )
		{
			col[u] = lc;
			dfsp( u );
		}
	}
}

int main()
{
	int i, j, k;
	bool fl = 0;
	
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &j );
		while ( j-- )
		{
			scanf( "%d", &k );
			
//			printf( "%d knows %d\n", i, k );
			fl = 1;
			pl[i].push_back( k );
			lp[k].push_back( i );
		}
	}
	
	memset( col, -1, sizeof( col ) );
	memset( us, 0, sizeof( us ) );
	for ( i = 1; i <= n; i++ )
	{
		if ( col[i] == -1 )
		{
			lc++;
			col[i] = lc;
			dfsp( i );
		}
	}
	
	printf( "%d\n", lc-fl );
	return 0;
}