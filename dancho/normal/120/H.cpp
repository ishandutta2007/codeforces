#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

FILE * fin;
FILE * fout;

int code( char a, char b, char c, char d )
{
	a = a - 'a' + 1; // 0 ... 26
	b = b - 'a' + 1;
	c = c - 'a' + 1;
	d = d - 'a' + 1;
	return a+27*(b+27*(c+27*d));
}

void encode( int v )
{
	while ( v > 0 )
	{
		fprintf( fout, "%c", (v%27-1+'a') );
		v = v / 27;
	}
	fprintf( fout, "\n" );
}

int n;
char x[256][16];
vector<int> ed[256];
int vis[256];
int to[256];
int par[1000020];

bool augment( int v )
{
	if ( vis[v] == 1 ) return 0;
	vis[v] = 1;
	int i, u;
	for ( i = 0; (unsigned)i < ed[v].size(); i++ )
	{
		u = ed[v][i];
		if ( par[u] == -1 )
		{
			par[u] = v;
			to[v] = u;
			return 1;
		}
		else if ( augment( par[u] ) )
		{
			par[u] = v;
			to[v] = u;
			return 1;
		}
	}
	return 0;
}

int match()
{
	int ma = 0;
	int i;
	memset( par, -1, sizeof( par ) );
	memset( to, -1, sizeof( to ) );
	for ( i = 1; i <= n; i++ )
	{
		memset( vis, 0, sizeof( vis ) );
		if ( augment( i ) )
			ma++;
		else
			return 0;
	}
	return ma;
}

int main()
{
	fin = fopen( "input.txt", "r" );
	fout = fopen( "output.txt", "w" );
	
	int i, j, k, l;
	fscanf( fin, "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		fscanf( fin, "%s", x[i] );
		ed[i].clear();
		for ( j = 0; (unsigned)j < strlen( x[i] ); j++ )
		{
			ed[i].push_back( code( x[i][j], 'a'-1, 'a'-1, 'a'-1 ) );
			for ( k = j+1; (unsigned)k < strlen( x[i] ); k++ )
			{
				ed[i].push_back( code( x[i][j], x[i][k], 'a'-1, 'a'-1 ) );
				for ( l = k+1; (unsigned)l < strlen( x[i] ); l++ )
				{
					ed[i].push_back( code( x[i][j], x[i][k], x[i][l], 'a'-1 ) );
					for ( int s = l+1; (unsigned)s < strlen( x[i] ); s++ )
					{
						ed[i].push_back( code( x[i][j], x[i][k], x[i][l], x[i][s] ) );
					}
				}
			}
		}
	}
	
	if ( match() == n )
	{
		for ( i = 1; i <= n; i++ )
		{
			//printf( "%d %d\n", i, to[i] );
			encode( to[i] );
		}
	}
	else
		fprintf( fout, "-1\n" );
	
	fclose( fin );
	fclose( fout );
	return 0;
}