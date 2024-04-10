#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int,int> pii;

int n, m;
int len[200020];
int d[200020];
vector<pii> g[200020];

int f[200020], s[200020];
int sum[200020];
int in[200020];
bool us[200020];

void gogo( int v )
{
	if ( us[v] ) return;
	us[v] = 1;
	
	int i, j, u;
	for ( i = 0; i < (int) g[v].size(); i++ )
	{
		u = g[v][i].first;
		j = g[v][i].second;
		if ( us[u] ) continue;

		in[u] += len[j];
		d[j] = u;
		if ( ( in[u] + in[u] == sum[u] ) && ( u < n ) )
		{
			gogo( u );
		}
	}
}

int main()
{
	int i, j, k;
	
	memset( sum, 0, sizeof( sum ) );
	memset( in, 0, sizeof( in ) );
	memset( us, 0, sizeof( us ) );
	
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d %d", &j, &k, &len[i] );
		f[i] = j;
		s[i] = k;
		
		g[j].push_back( make_pair( k, i ) );
		g[k].push_back( make_pair( j, i ) );
		
		sum[j] += len[i];
		sum[k] += len[i];
	}
	
	gogo( 1 );
	
	for ( i = 1; i <= m; i++ )
	{
		if ( f[i] == d[i] )
			printf( "1\n" );
		else
			printf( "0\n" );
	}
	return 0;
}