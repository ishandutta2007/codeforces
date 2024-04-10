#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 2e5 + 5, MAXLOG = 19;

template<typename _T>
void read( _T &x ) {
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

struct Edge {
	int to, nxt;
} Graph[MAXN << 1];

std :: vector<int> ed[MAXN];

int tag[MAXN];

int fath[MAXN][MAXLOG];
int DFN[MAXN], dep[MAXN], ID = 0;

int head[MAXN], cnt = 1;
int ch[MAXN][26], mx[MAXN], fa[MAXN];
int rt, lst, ntot, lg2;

char str[MAXN];

int N, K;

inline void AddEdge( const int &from, const int &to ) {
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

inline void Copy( const int &a, const int &b ) {
	mx[a] = mx[b], fa[a] = fa[b];
	memcpy( ch[a], ch[b], sizeof ch[b] );
}

void Expand( const char c ) {
	int x = c - 'a';
	if( ch[lst][x] ) {
		int q = ch[lst][x];
		if( mx[q] == mx[lst] + 1 ) {
			lst = q; return ;
		}
		int nq = ++ ntot, p = lst; Copy( nq, q );
		mx[nq] = mx[lst] + 1, fa[q] = nq;
		while( p && ch[p][x] == q ) ch[p][x] = nq, p = fa[p];
		lst = nq;
	} else {
		int cur = ++ ntot, p = lst;
		mx[cur] = mx[lst] + 1, lst = cur;
		while( p && ! ch[p][x] ) ch[p][x] = cur, p = fa[p];
		if( ! p ) { fa[cur] = rt; return ; }
		int q = ch[p][x];
		if( mx[q] == mx[p] + 1 ) { fa[cur] = q; return ; }
		int nq = ++ ntot; Copy( nq, q );
		mx[nq] = mx[p] + 1, fa[cur] = fa[q] = nq;
		while( p && ch[p][x] == q ) ch[p][x] = nq, p = fa[p];
	}
}

void Init( const int &u, const int &fa ) {
	DFN[u] = ++ ID;
	dep[u] = dep[fath[u][0] = fa] + 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			Init( v, u );
}

void Init() {
	Init( rt, 0 ), lg2 = log2( ntot );
	rep( j, 1, lg2 ) rep( i, 1, ntot )
		fath[i][j] = fath[fath[i][j - 1]][j - 1];
}

void Balance( int &u, const int &stp ) {
	for( int i = 0 ; ( 1 << i ) <= stp ; i ++ )
		if( stp >> i & 1 ) u = fath[u][i];
}

int LCA( int u, int v ) {
	if( dep[u] > dep[v] ) Balance( u, dep[u] - dep[v] );
	if( dep[v] > dep[u] ) Balance( v, dep[v] - dep[u] );
	if( u == v ) return u;
	per( i, lg2, 0 ) if( fath[u][i] ^ fath[v][i] ) u = fath[u][i], v = fath[v][i];
	return fath[u][0];
}

void Recover( const int &u, const int &fa ) {
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			Recover( v, u ), tag[u] += tag[v];
}

int main() {
	rt = ++ ntot;
	read( N ), read( K );
	rep( i, 1, N ) {
		lst = rt; int L;
		scanf( "%s", str + 1 ), L = strlen( str + 1 );
		rep( j, 1, L ) 
			Expand( str[j] ), ed[i].push_back( lst );
	}
	rep( i, 2, ntot ) AddEdge( fa[i], i );
	Init();
	rep( i, 1, N ) {
		int n = ed[i].size();
		std :: sort( ed[i].begin(), ed[i].end(),
			[] ( const int &a, const int &b ) -> bool {
				return DFN[a] < DFN[b];
			} );
		rep( j, 0, n - 1 ) tag[ed[i][j]] ++;
		rep( j, 0, n - 2 ) tag[LCA( ed[i][j], ed[i][j + 1] )] --;
	}
	Recover( rt, 0 );
	rep( i, 1, N ) {
		LL ans = 0;
		int n = ed[i].size();
		rep( j, 0, n - 1 ) {
			int x = ed[i][j];
			if( tag[x] < K ) {
				per( k, lg2, 0 )
					if( fath[x][k] && tag[fath[x][k]] < K )
						x = fath[x][k];
				x = fath[x][0];
			}
			ans += mx[x];
		}
		write( ans ), putchar( " \n"[i == N] );
	}
	return 0;
}