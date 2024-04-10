#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int max( int a, int b )
{
	if ( a > b ) return a;
	return b;
}

int n, t, m;
int a[128][2], b[128][2], c[128];
int d[128][128];
queue<int> q;
vector<string> sol[128];

string w[128];
char x[128];

int main()
{
	FILE * fin = fopen( "input.txt", "r" );
	FILE * fout = fopen( "output.txt", "w" );
	
	int i, j, k;
	fscanf( fin, "%d %d", &n, &t );
	for ( i = 1; i <= n; i++ )
	{
		fscanf( fin, "%d %d %d %d", &a[i][1], &b[i][1], &a[i][2], &b[i][2] );
	}
	
	fscanf( fin, "%d", &m );
	for ( i = 1; i <= m; i++ )
	{
		fscanf( fin, "%s", x );
		w[i] = x;
		fscanf( fin, "%d", &c[i] );
		q.push( i );
	}
	
	memset( d, 0, sizeof( d ) );
	
	int pl = 1, te = 1;
	int ct;
	while ( q.size() > 0 )
	{
		ct = t;
		//printf( "%d %d %d\n", te, pl, 3-pl );
		while ( ( ct > 0 ) && ( q.size() > 0 ) )
		{
			k = q.front();
			q.pop();
			j = c[k] - ( a[te][pl] + b[te][3-pl] )-d[te][k];
			if ( j < 1 ) j = 1;
//			printf( "%d %d %d -> %d\n", pl, te, k, j );
			if ( j <= ct )
			{
				ct = ct - j;
				sol[te].push_back( w[k] );
			}
			else
			{
				q.push( k );
				d[te][k] = d[te][k] + ct;
				ct = 0;
			}
		}
		te++;
		if ( te > n )
		{
			pl = 3 - pl;
			te = 1;
		}
	}
	
	for ( i = 1; i <= n; i++ )
	{
		k = sol[i].size();
//		printf( "%d %d\n", i, k );
		fprintf( fout, "%d", k );
		for ( j = 0; (unsigned)j < sol[i].size(); j++ )
		{
			strcpy( x, sol[i][j].c_str() );
			fprintf( fout, " %s", x );
		}
		fprintf( fout, "\n" );
	}
	
	fclose( fin );
	fclose( fout );
	return 0;
}