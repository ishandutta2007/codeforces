#include <cmath>
#include <cstdio>
#include <cstring>

const int MAXN = 5e5 + 5, MAXM = 5e4 + 5, MAXL = 1e5 + 5, MAXS = MAXL * 100;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar();int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + s - '0', s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) { putchar( '-' ), x = -x; }
	if( 9 < x ) { write( x / 10 ); }
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

struct edge
{
	int to, nxt;
}Graph[MAXL << 1];

struct pii
{
	int mx, indx;
	pii() { mx = 0, indx = 1e6; }
	pii( const int M, const int I ) { mx = M, indx = I; }
	bool operator > ( const pii &b ) const { return mx == b.mx ? indx < b.indx : mx > b.mx; }
};

pii bst[MAXS]; 
int lch[MAXS], rch[MAXS];
int ed[MAXN], mxl[MAXN];
int ch[MAXL][26], fa[MAXL][18], mx[MAXL], rot[MAXL], head[MAXL];
int N, M, Q, lg2, rt, lst, tot, cnt, siz;
char S[MAXN], T[MAXL];

void upt( const int x ) { bst[x] = MAX( bst[lch[x]], bst[rch[x]] ); }
void copy( int a, int b ) { fa[a][0] = fa[b][0], mx[a] = mx[b], memcpy( ch[a], ch[b], sizeof ch[b] ); }

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void expand( const char c )
{
	int x = c - 'a';
	if( ch[lst][x] && mx[ch[lst][x]] == mx[lst] + 1 ) { lst = ch[lst][x]; return ; }
	int p = lst, cur = ++ tot;
	mx[cur] = mx[lst] + 1, lst = cur;
	while( p && ! ch[p][x] ) ch[p][x] = cur, p = fa[p][0];
	if( ! p ) { fa[cur][0] = rt; return ; }
	int q = ch[p][x];
	if( mx[q] == mx[p] + 1 ) { fa[cur][0] = q; return ; }
	int nq = ++ tot; copy( nq, q );
	mx[nq] = mx[p] + 1, fa[q][0] = fa[cur][0] = nq;
	if( mx[p] + 1 == mx[cur] ) lst = nq;
	while( p && ch[p][x] == q ) ch[p][x] = nq, p = fa[p][0];
}

void update( int &u, const int l, const int r, const int pos )
{
	if( ! u ) u = ++ siz; int mid = l + r >> 1;
	if( l == r ) { bst[u].mx ++, bst[u].indx = l; return ; }
	if( pos <= mid ) update( lch[u], l, mid, pos );
	else update( rch[u], mid + 1, r, pos );
	upt( u );
}

pii query( const int u, const int l, const int r, const int segL, const int segR )
{
	if( ! u ) return pii();
	if( segL <= l && r <= segR ) return bst[u];
	if( l == r ) return pii();
	int mid = l + r >> 1; pii ret = pii();
	if( segL <= mid ) ret = MAX( ret, query( lch[u], l, mid, segL, segR ) );
	if( mid < segR ) ret = MAX( ret, query( rch[u], mid + 1, r, segL, segR ) );
	return ret;
}

int merg( int lrt, int rrt, int l, int r )
{
	if( ! lrt || ! rrt ) return lrt | rrt;
	int cur = ++ siz, mid = l + r >> 1;
	if( l == r )
	{
		bst[cur] = bst[lrt], bst[cur].mx += bst[rrt].mx;
		return cur;
	}
	lch[cur] = merg( lch[lrt], lch[rrt], l, mid ); 
	rch[cur] = merg( rch[lrt], rch[rrt], mid + 1, r );
	upt( cur );
	return cur;
}

void DFS( const int u )
{
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
	{
		DFS( v = Graph[i].to );
		rot[u] = merg( rot[u], rot[v], 1, M );
	}
}

int main()
{
	rt = ++ tot;
	scanf( "%s", S + 1 ), N = strlen( S + 1 );
	read( M );
	for( int i = 1 ; i <= M ; i ++ )
	{
		lst = rt, scanf( "%s", T + 1 );
		for( int j = 1 ; T[j] ; j ++ ) 
			expand( T[j] ), update( rot[lst], 1, M, i );	
	}
	for( int i = 2 ; i <= tot ; i ++ ) addEdge( fa[i][0], i );
	DFS( rt );
	lg2 = log2( tot );
	for( int j = 1 ; j <= lg2 ; j ++ )
		for( int i = 1 ; i <= tot ; i ++ )
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	int p = rt, len;
	for( int i = 1, x ; i <= N ; i ++ )
	{
		x = S[i] - 'a';
		while( p && ! ch[p][x] ) p = fa[p][0], len = mx[p];
		if( ! p ) p = rt, len = 0;
		else len ++, p = ch[p][x];
		ed[i] = p, mxl[i] = len;
	}
	read( Q );
	int lef, rig, L, R;
	while( Q -- )
	{
		read( lef ), read( rig ), read( L ), read( R );
		if( mxl[R] < R - L + 1 ) { printf( "%d 0\n", lef ); continue; }
		p = ed[R];
		for( int j = lg2 ; ~ j ; j -- )
			if( fa[p][j] && mx[fa[p][j]] >= R - L + 1 )
				p = fa[p][j];
		pii ans = query( rot[p], 1, M, lef, rig );
		if( ans.mx == 0 ) ans.indx = lef;
		write( ans.indx ), putchar( ' ' ), write( ans.mx ), putchar( '\n' );
	}
	return 0;
}