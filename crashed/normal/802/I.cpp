#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN = 1e5 + 5;

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
}Graph[MAXN << 1];

int cnt[MAXN], seq[MAXN << 1];
int ep[MAXN << 1], f[MAXN << 1], head[MAXN << 1];
int ch[MAXN << 1][26], fa[MAXN << 1], mx[MAXN << 1];
char S[MAXN];
int N, rt, lst, tot, ecnt;

void copy( const int a, const int b ) { fa[a] = fa[b], mx[a] = mx[b], memcpy( ch[a], ch[b], sizeof ch[b] ); }
void expand( const char c )
{
	int x = c - 'a', p = lst, cur = ++ tot; lst = cur;
	mx[cur] = mx[p] + 1, ep[cur] = 1;
	while( p && ! ch[p][x] ) ch[p][x] = cur, p = fa[p];
	if( ! p ) { fa[cur] = rt; return ; }
	int q = ch[p][x];
	if( mx[q] == mx[p] + 1 ) { fa[cur] = q; return ; }
	int nq = ++ tot; copy( nq, q );
	mx[nq] = mx[p] + 1, fa[cur] = fa[q] = nq;
	while( p && ch[p][x] == q ) ch[p][x] = nq, p = fa[p];
}

void addEdge( const int from, const int to )
{
	ecnt ++;
	Graph[ecnt].to = to, Graph[ecnt].nxt = head[from];
	head[from] = ecnt;
}

void DFS( const int u )
{
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		DFS( v = Graph[i].to ), ep[u] += ep[v];
}

void topo()
{
	for( int i = 1 ; i <= tot ; i ++ ) cnt[mx[i]] ++;
	for( int i = 1 ; i <= N ; i ++ ) cnt[i] += cnt[i - 1];
	for( int i = tot ; i ; i -- ) seq[cnt[mx[i]] --] = i;
}

void clear()
{
	for( int i = 1 ; i <= tot ; i ++ )
	{
		mx[i] = fa[i] = 0; ep[i] = f[i] = head[i] = 0;
		for( int j = 0 ; j < 26 ; j ++ ) ch[i][j] = 0;
		seq[i] = 0;
	}
	for( int i = 1 ; i <= N ; i ++ ) cnt[i] = 0;
	tot = ecnt = 0;
}

int main()
{
	LL res = 0;
	int T;
	read( T );
	while( T -- )
	{
		clear();
		scanf( "%s", S + 1 ); N = strlen( S + 1 );
		rt = lst = ++ tot;
		for( int i = 1 ; i <= N ; i ++ ) expand( S[i] );
		for( int i = 2 ; i <= tot ; i ++ ) addEdge( fa[i], i );
		DFS( 1 );
		topo();
		f[rt] = 1;
		for( int i = 1, u ; i <= tot ; i ++ )
		{
			u = seq[i];
			for( int j = 0 ; j < 26 ; j ++ )
				if( ch[u][j] ) f[ch[u][j]] += f[u];
		}
		res = 0;
		for( int i = 2 ; i <= tot ; i ++ )
			res += 1ll * f[i] * ep[i] * ep[i];
		write( res ), putchar( '\n' );
	}
	return 0;
}