#include <cstdio>
#include <vector>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod1 = 998244353, mod2 = 1e9 + 9;
const int MAXN = 3e5 + 5, MAXM = 1e6 + 5, MAXLOG = 50;

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

typedef std :: pair<int, int> HashPair;

struct Edge {
	int to, nxt;
} Graph[MAXN << 1];

struct Path {
	int l, r, d;

	Path(): l( 0 ), r( 0 ), d( 0 ) {}
	Path( int L, int R, int D ): l( L ), r( R ), d( D ) {}
};

const HashPair BASE( 37, 53 );

HashPair pref[MAXN][2], pw[MAXN];

int bel[MAXN], LTail[MAXN], LPos[MAXN], seq[MAXN], ID, tot;
int head[MAXN], siz[MAXN], heavy[MAXN], fath[MAXN], dep[MAXN], cnt = 1;

char str[MAXN];

int N, M;

inline HashPair operator + ( const HashPair &a, const HashPair &b ) {
	return HashPair( ( a.first + b.first ) % mod1, ( a.second + b.second ) % mod2 );
}

inline HashPair operator - ( const HashPair &a, const HashPair &b ) {
	return HashPair( ( a.first - b.first + mod1 ) % mod1, ( a.second - b.second + mod2 ) % mod2 );
}

inline HashPair operator * ( const HashPair &a, const HashPair &b ) {
	return HashPair( 1ll * a.first * b.first % mod1, 1ll * a.second * b.second % mod2 );
}

inline void AddEdge( const int &from, const int &to ) {
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void DFS1( const int &u, const int &fa ) {
	siz[u] = 1, heavy[u] = 0;
	dep[u] = dep[fath[u] = fa] + 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa ) {
			DFS1( v, u ), siz[u] += siz[v];
			if( siz[heavy[u]] < siz[v] ) heavy[u] = v;
		}
}

void DFS2( const int &u, const int &fa ) {
	seq[LPos[u] = ++ ID] = u;
	if( ! heavy[u] ) bel[u] = ++ tot;
	else DFS2( heavy[u], u ), bel[u] = bel[heavy[u]];
	LTail[bel[u]] = u;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && v ^ heavy[u] )
			DFS2( v, u );
}

void Init() {
	DFS1( 1, 0 );
	DFS2( 1, 0 );
	pw[0] = HashPair( 1, 1 );
	rep( i, 1, N ) pw[i] = pw[i - 1] * BASE;
	rep( i, 1, N ) pref[i][0] = pref[i - 1][0] * BASE + ( HashPair ) { str[seq[i]] - 'a' + 1, str[seq[i]] - 'a' + 1 };
	per( i, N, 1 ) pref[i][1] = pref[i + 1][1] * BASE + ( HashPair ) { str[seq[i]] - 'a' + 1, str[seq[i]] - 'a' + 1 };
}

// type = 0: normal
// type = 1: reversed;
inline HashPair Get( const int &l, const int &r, const int &typ ) {
	return typ ? pref[l][1] - pref[r + 1][1] * pw[r - l + 1] :
				 pref[r][0] - pref[l - 1][0] * pw[r - l + 1];
}

inline HashPair Get( const Path &p, const int &d ) {
	return p.d ? Get( p.r - d + 1, p.r, 1 ) :
				 Get( p.l, p.l + d - 1, 0 );
}

std :: vector<Path> Divide( int u, int v ) {
	std :: vector<Path> fore, back;
	while( bel[u] ^ bel[v] ) {
		if( dep[LTail[bel[u]]] >= dep[LTail[bel[v]]] )
			fore.push_back( Path( LPos[LTail[bel[u]]], LPos[u], 1 ) ), u = fath[LTail[bel[u]]];
		else
			back.push_back( Path( LPos[LTail[bel[v]]], LPos[v], 0 ) ), v = fath[LTail[bel[v]]];
	}
	if( dep[u] >= dep[v] )
		fore.push_back( Path( LPos[v], LPos[u], 1 ) );
	else
		back.push_back( Path( LPos[u], LPos[v], 0 ) );
	while( ! back.empty() ) fore.push_back( back.back() ), back.pop_back();
	return fore;
}

int main() {
	read( N );
	scanf( "%s", str + 1 );
	rep( i, 1, N - 1 ) {
		int u, v; read( u ), read( v );
		AddEdge( u, v ), AddEdge( v, u );
	}
	Init(); read( M );
	for( int a, b, c, d ; M -- ; ) {
		read( a ), read( b ), read( c ), read( d );
		std :: vector<Path> pA( Divide( a, b ) ),
							pB( Divide( c, d ) );
		std :: reverse( pA.begin(), pA.end() );
		std :: reverse( pB.begin(), pB.end() );
		int ans = 0;
		while( ! pA.empty() && ! pB.empty() ) {
			Path fir = pA.back(); pA.pop_back();
			Path sec = pB.back(); pB.pop_back();
			int lim = Min( fir.r - fir.l + 1, sec.r - sec.l + 1 );
			if( Get( fir, lim ) == Get( sec, lim ) ) {
				ans += lim;
				if( fir.r - fir.l + 1 > lim ) {
					if( fir.d == 0 ) fir.l += lim;
					else fir.r -= lim;
					pA.push_back( fir );
				}
				if( sec.r - sec.l + 1 > lim ) {
					if( sec.d == 0 ) sec.l += lim;
					else sec.r -= lim;
					pB.push_back( sec );
				}
			} else {
				int l = 0, r = lim, mid;
				while( l < r ) {
					mid = ( l + r + 1 ) >> 1;
					if( Get( fir, mid ) == Get( sec, mid ) ) l = mid;
					else r = mid - 1;
				}
				ans += l;
				break;
			}
		}
		write( ans ), putchar( '\n' );
	}
	return 0;
}