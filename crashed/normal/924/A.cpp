#include <cstdio>

const int MAXN = 1005, MAXM = 1005;

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

char app[MAXN][MAXM];
int fa[MAXN + MAXM];
int N, M;

void makeSet( int siz ) { for( int i = 1 ; i <= siz ; i ++ ) fa[i] = i; }
int findSet( int u ) { return fa[u] = ( u == fa[u] ? fa[u] : findSet( fa[u] ) ); }
void unionSet( int u, int v ) { fa[findSet( u )] = findSet( v ); }
bool chk( int i, int j ) { return findSet( i ) == findSet( j ); }

int main()
{
	read( N ), read( M );
	makeSet( N + M );
	for( int i = 1 ; i <= N ; i ++ )
	{
		scanf( "%s", app[i] + 1 );
		for( int j = 1 ; j <= M ; j ++ )
			if( app[i][j] == '#' ) unionSet( i, j + N );
	}
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 1 ; j <= M ; j ++ )
			if( app[i][j] == '.' && chk( i, j + N ) )
			{ puts( "No" ); return 0; }
	puts( "Yes" );
	return 0;
}