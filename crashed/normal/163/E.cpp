#include <cstdio>
#include <iostream>
using namespace std;

#define Tour( c ) for( int c = 0 ; c < 26 ; c ++ )
#define up( x ) ( x += ( x & ( -x ) ) )
#define down( x ) ( x -= ( x & ( -x ) ) )

typedef long long LL;

const int MAXN = 1e5 + 5, MAXL = 1e6 + 5;

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

struct edge
{
	int to, nxt;
}Graph[MAXL << 1];

LL BIT[MAXL];
int head[MAXL], pos[MAXL], siz[MAXL];
int ch[MAXL][26], fail[MAXL], q[MAXL];
int ed[MAXN];
int N, K, tot, cnt, ID;
char S[MAXL];
bool inside[MAXN];

void update( int x, const int v ) { for( ; x <= ID ; up( x ) ) BIT[x] += v; }
LL getSum( int x ) { LL ret = 0; for( ; x ; down( x ) ) ret += BIT[x]; return ret; }
void update( const int x ) { if( ! inside[x] ) inside[x] = true, update( pos[ed[x]], 1 ), update( pos[ed[x]] + siz[ed[x]], -1 ); }
void remove( const int x ) { if( inside[x] ) inside[x] = false, update( pos[ed[x]], -1 ), update( pos[ed[x]] + siz[ed[x]], 1 ); }

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void insert( const int rnk )
{
	int p = 0, id;
	for( int i = 1 ; S[i] ; i ++ )
	{
		id = S[i] - 'a';
		if( ! ch[p][id] ) ch[p][id] = ++ tot;
		p = ch[p][id];
	}
	ed[rnk] = p;
}

void init()
{
	int h = 1, t = 0, u, v;
	Tour( i ) if( ch[0][i] ) q[++ t] = ch[0][i];
	while( h <= t )
	{
		u = q[h ++];
		Tour( i )
		{
			if( v = ch[u][i] ) fail[v] = ch[fail[u]][i], q[++ t] = v;
			else ch[u][i] = ch[fail[u]][i];
		}
		addEdge( fail[u], u );
	}
}

void DFS( const int u )
{
	siz[u] = 1, pos[u] = ++ ID;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		DFS( v = Graph[i].to ), siz[u] += siz[v];
}

int main()
{
	LL ans; int id, p;
	read( N ), read( K );
	for( int i = 1 ; i <= K ; i ++ ) scanf( "%s", S + 1 ), insert( i );
	init(); 
	DFS( 0 );
	for( int i = 1 ; i <= K ; i ++ ) update( i );
	while( N -- )
	{
		scanf( "%s", S );
		if( S[0] == '?' )
		{
			ans = p = 0;
			for( int i = 1 ; S[i] ; i ++ )
				p = ch[p][S[i] - 'a'],
				ans += getSum( pos[p] );
			write( ans ), putchar( '\n' );
		}
		else if( S[0] == '+' ) sscanf( S + 1, "%d", &id ), update( id );
		else sscanf( S + 1, "%d", &id ), remove( id );
	}
	return 0;
}