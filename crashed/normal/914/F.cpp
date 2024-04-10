#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e5 + 5, MAXB = 355, MAXV = 705;

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
_T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

template<typename _T>
_T Max( const _T &a, const _T &b ) {
	return a > b ? a : b;
}

char buf[MAXN], str[MAXN];

struct SAM {
	int ch[MAXV][26], fa[MAXV], mx[MAXV], ed[MAXV];
	int rt, ntot, lst;

	SAM(): ch{{}}, fa{}, mx{}, ed{}, rt( 0 ), ntot( 0 ), lst( 0 ) {}
	
	inline int NewNode() {
		int r = ++ ntot;
		fa[r] = mx[r] = ed[r] = 0;
		memset( ch[r], 0, sizeof ch[r] );
		return r;
	}

	inline void Copy( const int &a, const int &b ) {
		fa[a] = fa[b], mx[a] = mx[b];
		memcpy( ch[a], ch[b], sizeof ch[b] );
	}

	inline void Expand( const char &c ) {
		int x = c - 'a', cur = NewNode(), p = lst;
		mx[cur] = mx[lst] + 1, ed[lst = cur] ++;
		while( p && ! ch[p][x] ) ch[p][x] = cur, p = fa[p];
		if( ! p ) { fa[cur] = rt; return ; }
		int q = ch[p][x];
		if( mx[q] == mx[p] + 1 ) { fa[cur] = q; return ; }
		int nq = NewNode(); Copy( nq, q );
		mx[nq] = mx[p] + 1, fa[cur] = fa[q] = nq;
		while( p && ch[p][x] == q ) ch[p][x] = nq, p = fa[p];
	}

	void Build( const int &l, const int &r ) {
		static int seq[MAXV] = {}, buc[MAXV] = {};

		ntot = 0, rt = lst = NewNode();
		for( int i = l ; i < r ; i ++ ) Expand( str[i] );
		rep( i, 0, ntot ) buc[i] = 0;
		rep( i, 1, ntot ) buc[mx[i]] ++;
		rep( i, 1, ntot ) buc[i] += buc[i - 1];
		per( i, ntot, 1 ) seq[buc[mx[i]] --] = i;
		per( i, ntot, 2 ) ed[fa[seq[i]]] += ed[seq[i]];
	}

	int Query( const int &l, const int &r ) {
		int p = rt, x;
		for( int i = l ; i < r ; i ++ ) {
			x = buf[i] - 'a';
			if( ! ch[p][x] ) return 0;
			p = ch[p][x];
		}
		return ed[p];
	}
};

int nxt[MAXN];

SAM each[MAXB], fre;
bool tag[MAXB];

int lef[MAXB], rig[MAXB];
int bel[MAXN];
int tot, LEN, THRE;

int N, M, Q;

void Build() {
	// LEN = THRE = sqrt( N );
	LEN = THRE = 350;
	for( int i = 1 ; i <= N ; i += THRE ) {
		tot ++, lef[tot] = i, rig[tot] = Min( N, i + THRE - 1 );
		for( int j = lef[tot] ; j <= rig[tot] ; j ++ ) bel[j] = tot;
		tag[tot] = true;
	}
}

int Match( const int &l, const int &r ) {
	int ret = 0, p = 0;
	for( int i = l ; i < r ; i ++ ) {
		while( p && buf[p + 1] ^ str[i] ) p = nxt[p];
		if( buf[p + 1] == str[i] ) p ++;
		if( p == M ) ret ++;
	}
	return ret;
}

int main() {
	scanf( "%s", str + 1 );
	N = strlen( str + 1 ); 
	Build(), read( Q );
	for( int cas = 1 ; cas <= Q ; cas ++ ) {
		int opt; read( opt );
		if( opt == 1 ) {
			int x; 
			read( x ), scanf( "%s", buf ); 
			str[x] = buf[0], tag[bel[x]] = true;
		}
		if( opt == 2 ) {
			int l, r; 
			read( l ), read( r );
			scanf( "%s", buf + 1 );
			M = strlen( buf + 1 );
			
			nxt[1] = 0;
			for( int i = 2, j = 0 ; i <= M ; i ++ ) {
				while( j && buf[j + 1] != buf[i] ) j = nxt[j];
				if( buf[j + 1] == buf[i] ) j ++;
				nxt[i] = j;
			}

			if( M > LEN )
				write( Match( l, r + 1 ) ), putchar( '\n' );
			else {
				int ans = 0, bL = bel[l], bR = bel[r];
				if( bL == bR )
					ans = Match( l, r + 1 );
				else {
					ans += Match( l, rig[bL] + 1 );
					ans += Match( lef[bR], r + 1 );
					rep( i, bL, bR - 1 ) ans += Match( Max( l, rig[i] - M + 2 ), Min( r, lef[i + 1] + M - 2 ) + 1 );
					rep( i, bL + 1, bR - 1 ) {
						if( tag[i] )
							each[i].Build( lef[i], rig[i] + 1 ), tag[i] = false;
						ans += each[i].Query( 1, M + 1 );
					}
				}
				write( ans ), putchar( '\n' );
			}
		}
	}
	return 0;
}