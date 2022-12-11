#include <cstdio>
#include <vector>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 5005, MAXE = 1e5 + 5;

template <typename _T>
void read( _T &x )/*{{{*/
{
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}/*}}}*/

template <typename _T>
void write( _T x )/*{{{*/
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}/*}}}*/

struct Edge/*{{{*/
{
	int to, nxt;
}Graph[MAXE << 1];/*}}}*/

std :: vector<int> comp[MAXN];

int pre[MAXN][MAXN];

int q[MAXN];

int bla[MAXN], whi[MAXN], tot;

int head[MAXN], col[MAXN];
int N, M, A, B, C, cnt;

void AddEdge( const int from, const int to )/*{{{*/
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}/*}}}*/

bool Color( const int s )/*{{{*/
{
	int h = 1, t = 0;
	col[q[++ t] = s] = 0;
	while( h <= t )
	{
		int u = q[h ++];
		for( int i = head[u], v ; i ; i = Graph[i].nxt )
		{
			if( col[v = Graph[i].to] == -1 ) col[v] = col[u] ^ 1, q[++ t] = v;
			else if( col[v] == col[u] ) return false;
		}
	}
	int b = 0, w = 0;
	rep( i, 1, t ) b += col[q[i]], w += ! col[q[i]];
	tot ++, bla[tot] = b, whi[tot] = w;
	rep( i, 1, t ) comp[tot].push_back( q[i] );
	return true;
}/*}}}*/

void GetColoring( const int i, const int j )/*{{{*/
{
	if( i == 0 ) return ;
	if( pre[i][j] > 0 ) GetColoring( i - 1, pre[i][j] - 1 );
	else
	{
		for( int k = 0 ; k < ( int ) comp[i].size() ; k ++ )
			col[comp[i][k]] ^= 1;
		GetColoring( i - 1, - pre[i][j] - 1 );
	}
}/*}}}*/

int main()
{
	read( N ), read( M );
	read( A ), read( B ), read( C );
	rep( i, 1, M )
	{
		int u, v;
		read( u ), read( v );
		AddEdge( u, v ), AddEdge( v, u );
	}
	rep( i, 1, N ) col[i] = -1;
	bool flg = true;
	rep( i, 1, N ) if( col[i] == -1 )
		if( ! Color( i ) ) { flg = false; break; }
	if( ! flg ) return puts( "NO" ), 0;
	rep( i, 0, tot ) rep( j, 0, N ) pre[i][j] = - 1e9;
	int cnt = 0; pre[0][0] = 0;
	rep( i, 0, tot - 1 )
	{
		rep( j, 0, cnt ) if( pre[i][j] != - 1e9 )
		{
			pre[i + 1][j + bla[i + 1]] = j + 1;
			pre[i + 1][j + whi[i + 1]] = - j - 1;
		}
		cnt += comp[i + 1].size();
	}
	if( pre[tot][B] == - 1e9 ) return puts( "NO" ), 0;
	puts( "YES" );
	GetColoring( tot, B );
	rep( i, 1, N )
	{
		if( col[i] ) putchar( '2' );
		else if( A ) putchar( '1' ), A --;
		else putchar( '3' );
	}
	puts( "" );
	return 0;
}
/*
3 0
3 0 0
*/