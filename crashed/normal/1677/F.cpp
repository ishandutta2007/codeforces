// LUOGU_RID: 94469787
#include <cstdio>
#include <vector>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
const int MAXN = ( 1 << 18 ) + 5;

template<typename _T>
inline void Read( _T &x ) {
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
inline void Write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) Write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
inline _T Max( const _T &a, const _T &b ) {
	return a > b ? a : b;
}

typedef std :: vector<int> Poly;

int P[MAXN], Q[MAXN];
int fac[MAXN], ifac[MAXN];

int prod[MAXN], pre[MAXN], suf[MAXN];
int A[MAXN], C[MAXN], R[MAXN];
int N, K, p;

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

namespace Basics {
	const int L = 18, g = 3, phi = mod - 1;

	int w[MAXN];

	inline void NTTInit( const int &n = 1 << L ) {
		w[0] = 1, w[1] = Qkpow( g, phi >> L );
		rep( i, 2, n - 1 ) w[i] = Mul( w[i - 1], w[1] );
	}
	
	inline void DIF( int *coe, const int &n ) {
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

	inline void DIT( int *coe, const int &n ) {
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

inline Poly operator + ( const Poly &a, const Poly &b ) {
	if( a.empty() ) return b;
	if( b.empty() ) return a;
	int n = a.size(), m = b.size();
	Poly ret( Max( n, m ), 0 );
	for( int i = 0 ; i < n || i < m ; i ++ ) {
		if( i < n ) AddEq( ret[i], a[i] );
		if( i < m ) AddEq( ret[i], b[i] );
	}
	return ret;
}

inline Poly operator - ( const Poly &a, const Poly &b ) {
	int n = a.size(), m = b.size();
	Poly ret( Max( n, m ), 0 );
	for( int i = 0 ; i < n || i < m ; i ++ ) {
		if( i < n ) AddEq( ret[i], a[i] );
		if( i < m ) SubEq( ret[i], b[i] );
	}
	return ret;
}

inline Poly operator * ( const Poly &a, const Poly &b ) {
	if( a.empty() || b.empty() ) return Poly();
	int n = a.size(), m = b.size(), L;
	for( L = 1 ; L <= n + m - 2 ; L <<= 1 );
	rep( i, 0, L - 1 ) P[i] = Q[i] = 0;
	rep( i, 0, n - 1 ) P[i] = a[i];
	rep( i, 0, m - 1 ) Q[i] = b[i];
	Basics :: DIF( P, L );
	Basics :: DIF( Q, L );
	rep( i, 0, L - 1 ) MulEq( P[i], Q[i] );
	Basics :: DIT( P, L ); 
	return Poly( P, P + n + m - 1 );
}

inline Poly SubMul( const Poly &a, const Poly &b, const int &l ) {
	int n = a.size(), m = b.size(), L;
	for( L = 1 ; L <= n + m - 2 ; L <<= 1 );
	rep( i, 0, L - 1 ) P[i] = Q[i] = 0;
	rep( i, 0, n - 1 ) P[i] = a[i];
	rep( i, 0, m - 1 ) Q[m - 1 - i] = b[i];
	Basics :: DIF( P, L );
	Basics :: DIF( Q, L );
	rep( i, 0, L - 1 ) MulEq( P[i], Q[i] );
	Basics :: DIT( P, L ); Poly ret( l, 0 );
	for( int i = 0 ; i < l && i < n ; i ++ )
		ret[i] = P[i + m - 1];
	return ret;
}

inline Poly Shift( const Poly &f, const int &c ) {
	int n = f.size();
	Poly g( n ), h( n );
	rep( i, 0, n - 1 ) g[i] = Mul( f[i], fac[i] );
	for( int i = 0, pw = 1 ; i < n ; i ++, MulEq( pw, c ) )
		h[i] = Mul( pw, ifac[i] );
	Poly ret( SubMul( g, h, n ) );
	rep( i, 0, n - 1 ) MulEq( ret[i], ifac[i] );
	return ret;
}

namespace PolyInv {
	int U[MAXN], V[MAXN], P[MAXN], Q[MAXN];

	void Newton( const int &n ) {
		if( n == 1 ) {
			U[0] = Inv( P[0] );
			return ;
		}
		int h = ( n + 1 ) >> 1, L; Newton( h );
		for( L = 1 ; L <= n + h - 2 ; L <<= 1 );
		rep( i, 0, L - 1 ) V[i] = Q[i] = 0;
		rep( i, 0, h - 1 ) V[i] = U[i];
		rep( i, 0, n - 1 ) Q[i] = P[i];
		Basics :: DIF( V, L ), Basics :: DIF( Q, L );
		rep( i, 0, L - 1 ) V[i] = Mul( V[i], Sub( 2, Mul( V[i], Q[i] ) ) );
		Basics :: DIT( V, L );
		rep( i, h, n - 1 ) U[i] = V[i];
	}

	inline Poly PolyInv( const Poly &f ) {
		int n = f.size();
		rep( i, 0, n - 1 ) P[i] = f[i];
		Newton( n );
		return Poly( U, U + n );
	}
}

namespace MultiEval {
	int X[MAXN], Y[MAXN];
	Poly prod[MAXN << 2];
	int n, m;

	void Divide1( const int &x, const int &l, const int &r ) {
		Poly().swap( prod[x] );
		if( l == r ) prod[x] = { 1, Mul( mod - 1, X[l] ) };
		else {
			int mid = ( l + r ) >> 1;
			Divide1( x << 1, l, mid );
			Divide1( x << 1 | 1, mid + 1, r );
			prod[x] = prod[x << 1] * prod[x << 1 | 1];
		}
	}

	void Divide2( const int &x, const int &l, const int &r, const Poly &p ) {
		if( l == r ) Y[l] = p[0];
		else {
			int mid = ( l + r ) >> 1;
			Divide2( x << 1, l, mid, SubMul( p, prod[x << 1 | 1], mid - l + 1 ) );
			Divide2( x << 1 | 1, mid + 1, r, SubMul( p, prod[x << 1], r - mid ) );
		}
	}

	inline std :: vector<int> Work( const Poly &f, const std :: vector<int> &x ) {
		n = f.size(), m = x.size();
		rep( i, 0, m - 1 ) X[i] = x[i];
		Divide1( 1, 0, m - 1 );
		Poly val( prod[1] ); val.resize( n, 0 );
		Divide2( 1, 0, m - 1, SubMul( f, PolyInv :: PolyInv( val ), m ) );
		return std :: vector<int> ( Y, Y + m );
	}
}

namespace PseudoMultiPlot {
	typedef std :: pair<Poly, Poly> RetType;

	int S[MAXN], H[MAXN], pw[MAXN], pwInv[MAXN];

	RetType Divide( const int &l, const int &r ) {
		RetType ret;
		if( l == r ) {
			int c = Mul( H[l], Mul( ifac[l - 1], ifac[K + 1 - l] ) );
			if( ( K + 1 - l ) & 1 ) MulEq( c, mod - 1 );
			ret.second = { Mul( mod - 1, l ), 1 };
			ret.first = { c };
		} else {
			int mid = ( l + r ) >> 1;
			RetType lef = Divide( l, mid ), rig = Divide( mid + 1, r );
			ret.first = lef.first * rig.second + lef.second * rig.first;
			ret.second = lef.second * rig.second;
		}
		return ret;
	}

	std :: vector<int> Work() {
		pw[0] = 1, pw[1] = p;
		pwInv[0] = 1, pwInv[1] = Inv( p );
		rep( i, 2, K + 5 ) pw[i] = Mul( pw[i - 1], pw[1] );
		rep( i, 2, K + 5 ) pwInv[i] = Mul( pwInv[i - 1], pwInv[1] );
		rep( i, 1, K + 5 ) S[i] = Add( S[i - 1], Mul( pw[i], Qkpow( i, K ) ) );
		
		Poly g( K + 1, 0 ); g[0] = 1; 
		int inv = Inv( Sub( 1, p ) ), c = Mul( inv, p ), cns = 0;
		rep( i, 1, K ) g[i] = Mul( g[i - 1], c );
		g = Shift( g, mod - 1 );
		rep( i, 0, K ) MulEq( g[i], inv );
		rep( i, 0, K ) AddEq( cns, Mul( g[i], Qkpow( i, K ) ) );
		rep( i, 1, K + 1 ) H[i] = Mul( pwInv[i + 1], Sub( cns, S[i] ) );
		
		Poly fS( Divide( 1, K + 1 ).first );
		std :: vector<int> x( N );
		rep( i, 0, N - 1 ) x[i] = A[i + 1];
		std :: vector<int> res( MultiEval :: Work( fS, x ) );
		rep( i, 0, N - 1 ) res[i] = Sub( cns, Mul( Qkpow( p, A[i + 1] + 1 ), res[i] ) );
		return res;
	}
}

inline void Init( const int &n ) {
	Basics :: NTTInit();
	fac[0] = 1; rep( i, 1, n ) fac[i] = Mul( fac[i - 1], i );
	ifac[n] = Inv( fac[n] ); per( i, n - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

int main() {
	Read( N ), Read( K ), Read( p );
	rep( i, 1, N ) Read( A[i] );
	Init( Max( N, K ) + 5 );

	std :: vector<int> res( PseudoMultiPlot :: Work() );

	prod[0] = pre[0] = 1;
	rep( i, 1, N ) 
		C[i] = Mul( res[i - 1], Inv( A[i] + 1 ) ), 
		R[i] = Mul( A[i], Inv( A[i] + 1 ) );
	rep( i, 1, N ) prod[i] = Mul( prod[i - 1], A[i] + 1 );
	rep( i, 1, N ) pre[i] = Add( pre[i - 1], Inv( prod[i] ) );
	per( i, N, 1 ) suf[i] = Add( suf[i + 1], prod[i] );

	int ans = 0, su = 0;
	rep( i, 1, N ) {
		AddEq( ans, Mul( R[i], Mul( suf[i], su ) ) );
		AddEq( su, Mul( C[i], pre[i - 1] ) );
	}
	su = 0;
	per( i, N, 1 ) {
		AddEq( ans, Mul( R[i], Mul( pre[i - 1], su ) ) );
		AddEq( su, Mul( C[i], suf[i] ) );
	}
	rep( i, 1, N ) AddEq( ans, Mul( C[i], Mul( pre[i - 1], suf[i] ) ) );
	Write( ans ), putchar( '\n' );
	return 0;
}