#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int mod = 998244353;
const int MAXN = 1 << 18;

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

typedef std :: vector<int> Poly;

struct Edge {
	int to, nxt;
} Graph[MAXN << 1];

int siz[MAXN], heavy[MAXN];
int head[MAXN], fath[MAXN], cnt = 1;

int N; LL W;

inline int Qkpow( int, int );
inline int Inv( const int &a ) { return Qkpow( a, mod - 2 ); }
inline int Mul( int x, const int &v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int &v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int &v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int& MulEq( int &x, const int &v ) { return x = 1ll * x * v % mod; }
inline int& SubEq( int &x, const int &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
inline int& AddEq( int &x, const int &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

inline int Qkpow( int base, int indx ) {
	int ret = 1;
	while( indx ) {
		if( indx & 1 ) MulEq( ret, base );
		MulEq( base, base ), indx >>= 1;
	}
	return ret;
}

inline void AddEdge( const int &from, const int &to ) {
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

namespace Basics {
	const int L = 18, g = 3, phi = mod - 1;

	int w[MAXN];

	void NTTInit( const int &n = 1 << L ) {
		w[0] = 1, w[1] = Qkpow( g, phi >> L );
		rep( i, 2, n - 1 ) w[i] = Mul( w[i - 1], w[1] );
	}

	void DIF( int *coe, const int &n ) {
		int *wp, p, e, o;
		for( int s = n >> 1 ; s ; s >>= 1 )
			for( int i = 0 ; i < n ; i += s << 1 ) {
				p = ( 1 << L ) / ( s << 1 ), wp = w;
				for( int j = 0 ; j < s ; j ++, wp += p ) {
					e = coe[i + j], o = coe[i + j + s];
					coe[i + j] = Add( e, o );
					coe[i + j + s] = Mul( *wp, Sub( e, o ) );
				}
			}
	}

	void DIT( int *coe, const int &n ) {
		int *wp, p, k;
		for( int s = 1 ; s < n ; s <<= 1 )
			for( int i = 0 ; i < n ; i += s << 1 ) {
				p = ( 1 << L ) / ( s << 1 ), wp = w;
				for( int j = 0 ; j < s ; j ++, wp += p )
					k = Mul( *wp, coe[i + j + s] ),
					coe[i + j + s] = Sub( coe[i + j], k ),
					coe[i + j] = Add( coe[i + j], k );
			}
		std :: reverse( coe + 1, coe + n );
		int inv = Inv( n ); rep( i, 0, n - 1 ) MulEq( coe[i], inv );
	}
}

void DFS( const int u, const int fa ) {
	fath[u] = fa, siz[u] = 1, heavy[u] = 0;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa ) {
			DFS( v, u ), siz[u] += siz[v];
			if( siz[heavy[u]] < siz[v] ) heavy[u] = v;
		}
}

Poly operator * ( const Poly &A, const Poly &B ) {
	static int P[MAXN] = {}, Q[MAXN] = {};
	if( A.empty() || B.empty() ) return Poly();

	int n = A.size(), m = B.size(), L;
	if( n == 1u ) {
		Poly ret( B );
		rep( i, 0, m - 1 )
			MulEq( ret[i], A[0] );
		return ret;
	}
	if( m == 1u ) {
		Poly ret( A );
		rep( i, 0, n - 1 )
			MulEq( ret[i], B[0] );
		return ret;
	}
	for( L = 1 ; L <= n + m - 2 ; L <<= 1 );
	rep( i, 0, L - 1 ) P[i] = Q[i] = 0;
	rep( i, 0, n - 1 ) P[i] = A[i];
	rep( i, 0, m - 1 ) Q[i] = B[i];
	Basics :: DIF( P, L );
	Basics :: DIF( Q, L );
	rep( i, 0, L - 1 ) MulEq( P[i], Q[i] );
	Basics :: DIT( P, L );
	Poly ret; ret.reserve( n + m - 2 );
	rep( i, 0, n + m - 2 ) ret.push_back( P[i] );
	while( ! ret.empty() && ! ret.back() ) ret.pop_back();
	return ret;
}

Poly operator + ( const Poly &A, const Poly &B ) {
	int n = A.size(), m = B.size();
	Poly ret; ret.reserve( std :: max( n, m ) );
	for( int i = 0 ; i < n || i < m ; i ++ ) {
		int val = 0;
		if( i < n ) AddEq( val, A[i] );
		if( i < m ) AddEq( val, B[i] );
		ret.push_back( val );
	}
	return ret;
}

void Shift( Poly &A, int k ) {
	reverse( A.begin(), A.end() );
	while( k -- ) A.push_back( 0 );
	reverse( A.begin(), A.end() );
}

std :: pair<Poly, Poly> Divide( const std :: vector<Poly> &G, const int &l, const int &r ) {
	Poly A, B;
	if( l == r ) {
		A = G[l], A[0] = 1;
		Shift( B = A, 1 );
	} else {
		int mid = ( l + r ) >> 1;
		std :: pair<Poly, Poly>
			&&L = Divide( G, l, mid ),
			&&R = Divide( G, mid + 1, r );
		A = L.first * R.first;
		R.second = R.second * L.first;
		Shift( R.second, mid - l + 1 );
		B = L.second + R.second;
	}
	return std :: make_pair( A, B );
}

Poly Calc( const int &u ) {
	std :: vector<Poly> res;
	for( int v = u, w ; v ; v = heavy[v] ) {
		bool flg = false;
		for( int i = head[v] ; i ; i = Graph[i].nxt )
			if( ( w = Graph[i].to ) ^ fath[v] && w ^ heavy[v] ) {
				res.push_back( Calc( w ) );
				flg = true; break;
			}
		if( ! flg ) res.push_back( { 0 } );
	}
	return Divide( res, 0, ( int ) res.size() - 1 ).second;
}

int main() {
	read( N ), read( W );
	Basics :: NTTInit();
	rep( i, 1, N - 1 ) {
		int u, v; read( u ), read( v );
		AddEdge( u, v ), AddEdge( v, u );
	}
	DFS( 1, 0 );
	Poly &&ans = Calc( 1 );
	int res = 0, binom = 1;
	rep( i, 1, N ) {
		AddEq( res, Mul( binom, ans[i] ) );
		MulEq( binom, Mul( ( W + i ) % mod, Inv( i ) ) );
	}
	write( res ), putchar( '\n' );
	return 0;
}