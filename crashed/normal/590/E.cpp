#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXV = 5005, MAXE = 5e5 + 5;
const int MAXN = 755, MAXL = 1e7 + 5;

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

template<typename _T>
inline _T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

struct Edge {
	int to, nxt, c;
} Graph[MAXE << 1];

int pnt[MAXN];
bool banned[MAXN];

int pre[MAXN], nxt[MAXN];

int fir[MAXL], ed[MAXL], q[MAXL];
int ch[MAXL][2], fa[MAXL], tot = 0;
bool app[MAXN];

bool str[MAXL], *lef[MAXN], *rig[MAXN], *ptr = str;
char buf[MAXL];

int dep[MAXV], cur[MAXV];
int head[MAXV], cnt = 1, ntot = 0;

int N;

inline void AddEdge( const int &from, const int &to, const int &C ) {
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	Graph[cnt].c = C, head[from] = cnt;
}

inline void AddE( const int &from, const int &to, const int &C ) {
	AddEdge( from, to, C ), AddEdge( to, from, 0 );
}

inline bool BFS( const int &S, const int &T ) {
	static int que[MAXV];

	int h = 1, t = 0;
	rep( i, 1, ntot ) dep[i] = INF;
	dep[que[++ t] = S] = 0;
	while( h <= t ) {
		int u = que[h ++];
		for( int i = head[u], v ; i ; i = Graph[i].nxt )
			if( Graph[i].c && dep[v = Graph[i].to] > dep[u] + 1 )
				dep[que[++ t] = v] = dep[u] + 1;
	} 
	return dep[T] < INF;
}

int DFS( const int &u, const int &lin, const int &T ) {
	if( u == T ) return lin;
	int used = 0, ret, v, c;
	for( int &i = cur[u] ; i ; i = Graph[i].nxt ) {
		v = Graph[i].to, c = Graph[i].c;
		if( c && dep[v] == dep[u] + 1 && ( ret = DFS( v, Min( lin - used, c ), T ) ) ) {
			used += ret, Graph[i].c -= ret, Graph[i ^ 1].c += ret;
			if( used == lin ) break;
		}
	}
	if( used < lin ) dep[u] = INF;
	return used;
}

inline int Dinic( const int &S, const int &T ) {
	int flow = 0;
	while( BFS( S, T ) ) {
		rep( i, 1, ntot ) cur[i] = head[i];
		flow += DFS( S, INF, T );
	}
	return flow;
}

inline void Insert( const char *s, const int &id ) {
	int l = strlen( s ), p = 0, x;
	for( int i = 0 ; i < l ; i ++ ) {
		x = s[i] - 'a';
		if( ! ch[p][x] ) ch[p][x] = ++ tot;
		p = ch[p][x];
	}
	ed[p] = id;
}

inline void Build() {
	int h = 1, t = 0, u;
	if( ch[0][0] ) fa[q[++ t] = ch[0][0]] = 0;
	if( ch[0][1] ) fa[q[++ t] = ch[0][1]] = 0;
	while( h <= t ) {
		u = q[h ++];
		if( ch[u][0] ) fa[q[++ t] = ch[u][0]] = ch[fa[u]][0];
		else ch[u][0] = ch[fa[u]][0];
		if( ch[u][1] ) fa[q[++ t] = ch[u][1]] = ch[fa[u]][1];
		else ch[u][1] = ch[fa[u]][1];
	}
	fir[0] = -1;
	rep( i, 1, t ) {
		u = q[i];
		fir[u] = ed[fa[u]] ? fa[u] : fir[fa[u]];
	}
}

int main() {
	read( N );
	rep( i, 1, N ) {
		scanf( "%s", buf );
		int l = strlen( buf );
		lef[i] = ptr, rig[i] = ( ptr += l );
		rep( j, 0, l - 1 ) lef[i][j] = buf[j] - 'a';
		Insert( buf, i );
	}
	Build(), ntot = N + N;
	const int s = ++ ntot, t = ++ ntot;
	rep( i, 1, N ) {
		int p = 0, u;
		AddE( s, i, 1 ), AddE( i + N, t, 1 );
		rep( j, 1, N ) app[j] = false;
		for( bool *j = lef[i] ; j != rig[i] ; j ++ ) {
			p = ch[p][*j];
			u = ed[p] && j + 1 != rig[i] ? p : fir[p];
			for( ; u > 0 && ! app[ed[u]] ; u = fir[u] )
				app[ed[u]] = true, AddE( i, ed[u] + N, 1 );
		}
	}
	write( N - Dinic( s, t ) ), putchar( '\n' );
	for( int u = 1 ; u <= N ; u ++ )
		for( int i = head[u], v ; i ; i = Graph[i].nxt )
			if( ( v = Graph[i].to, N < v && v <= 2 * N ) )
				if( Graph[i ^ 1].c ) pre[v - N] = u, nxt[u] = v - N;
	int len = 0;
	rep( i, 1, N ) if( ! nxt[i] ) {
		pnt[++ len] = i;
		for( int j = head[i], v ; j ; j = Graph[j].nxt )
			if( ( v = Graph[j].to, N < v && v <= 2 * N ) )
				banned[v - N] = true;
	}
	while( true ) {
		bool flg = false;
		for( int i = 1 ; i <= len ; i ++ ) {
			int &u = pnt[i];
			if( ! banned[u] ) continue;
			for( flg = true ; banned[u] ; ) {
				u = pre[u];
				for( int j = head[u], v ; j ; j = Graph[j].nxt )
					if( ( v = Graph[j].to, N < v && v <= 2 * N ) )
						banned[v - N] = true;
			}
		}
		if( ! flg ) break;
	}
	rep( i, 1, len ) write( pnt[i] ), putchar( " \n"[i == len] );
	return 0;
}