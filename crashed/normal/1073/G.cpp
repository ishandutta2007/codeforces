#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN = 4e5 + 5;

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

LL s[MAXN << 2], delt[MAXN << 2]; int tag[MAXN << 2];
int head[MAXN], siz[MAXN], heavy[MAXN], bel[MAXN], LPos[MAXN], LTail[MAXN], seq[MAXN];
int ch[MAXN][26], mx[MAXN], fa[MAXN], ed[MAXN];
int A[MAXN];
int N, Q, rt, lst, tot, cnt, ID, ccnt;
char S[MAXN];

void upt( const int u ) { s[u] = s[u << 1] + s[u << 1 | 1]; }
void add( const int u, const int t ) { s[u] += delt[u] * t, tag[u] += t; }
void copy( int a, int b ) { mx[a] = mx[b], fa[a] = fa[b], memcpy( ch[a], ch[b], sizeof ch[b] ); }
void normalize( const int u ) { if( tag[u] ) add( u << 1, tag[u] ), add( u << 1 | 1, tag[u] ), tag[u] = 0; }

void addEdge( const int from, const int to ) 
{ 
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void expand( const char c )
{
	int x = c - 'a', p = lst, cur = ++ tot;
	mx[cur] = mx[lst] + 1, lst = cur;
	while( p && ! ch[p][x] ) ch[p][x] = cur, p = fa[p];
	if( ! p ) { fa[cur] = rt; return ; }
	int q = ch[p][x];
	if( mx[q] == mx[p] + 1 ) { fa[cur] = q; return ; }
	int nq = ++ tot; copy( nq, q );
	mx[nq] = mx[p] + 1, fa[q] = fa[cur] = nq;
	while( p && ch[p][x] == q ) ch[p][x] = nq, p = fa[p];
}

void DFS1( const int u )
{
	siz[u] = 1, heavy[u] = -1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
	{
		DFS1( v = Graph[i].to ), siz[u] += siz[v];
		if( heavy[u] == -1 || siz[heavy[u]] < siz[v] ) heavy[u] = v;
	}
}

void DFS2( const int u )
{
	LPos[u] = ++ ID, seq[ID] = u;
	if( ~ heavy[u] ) DFS2( heavy[u] ), bel[u] = bel[heavy[u]];
	else bel[u] = ++ ccnt;
	LTail[bel[u]] = u;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ heavy[u] )
			DFS2( v );
}

void build( const int u, const int l, const int r )
{
	if( l > r ) return ;
	if( l == r ) { delt[u] = mx[seq[l]] - mx[fa[seq[l]]]; return ; }
	int mid = l + r >> 1;
	build( u << 1, l, mid ), build( u << 1 | 1, mid + 1, r );
	delt[u] = delt[u << 1] + delt[u << 1 | 1];
}

void update( const int u, const int l, const int r, const int segL, const int segR, const int tims )
{
	if( segL <= l && r <= segR ) { add( u, tims ); return ; }
	if( l == r ) return ; normalize( u );
	int mid = l + r >> 1;
	if( segL <= mid ) update( u << 1, l, mid, segL, segR, tims );
	if( mid < segR ) update( u << 1 | 1, mid + 1, r, segL, segR, tims );
	upt( u );
}

LL query( const int u, const int l, const int r, const int segL, const int segR )
{
	if( segL <= l && r <= segR ) return s[u];
	if( l == r ) return 0; normalize( u );
	int mid = l + r >> 1; LL ret = 0;
	if( segL <= mid ) ret += query( u << 1, l, mid, segL, segR );
	if( segR > mid ) ret += query( u << 1 | 1, mid + 1, r, segL, segR );
	return ret;
}

void change( int u, const int val )
{
	while( u )
	{
		update( 1, 1, tot, LPos[LTail[bel[u]]], LPos[u], val );
		u = fa[LTail[bel[u]]];
	}
}

LL ask( int u )
{
	LL ret = 0;
	while( u ) 
	{ 
		ret += query( 1, 1, tot, LPos[LTail[bel[u]]], LPos[u] ); 
		u = fa[LTail[bel[u]]];
	}
	return ret;
}

int main()
{
	LL ans;
	int sizA, sizB;
	rt = lst = ++ tot;
	read( N ), read( Q );
	scanf( "%s", S + 1 );
	for( int i = N ; i ; i -- ) expand( S[i] ), ed[i] = lst;
	for( int i = 2 ; i <= tot ; i ++ ) addEdge( fa[i], i );
	DFS1( rt );
	DFS2( rt );
	build( 1, 1, tot );
	while( Q -- )
	{
		ans = 0;
		read( sizA ), read( sizB );
		for( int i = 1 ; i <= sizA ; i ++ ) read( A[i] ), change( ed[A[i]], 1 );
		for( int i = 1, p ; i <= sizB ; i ++ ) read( p ), ans += ask( ed[p] );
		for( int i = 1 ; i <= sizA ; i ++ ) change( ed[A[i]], -1 );
		write( ans ), putchar( '\n' );
	}
	return 0;
}