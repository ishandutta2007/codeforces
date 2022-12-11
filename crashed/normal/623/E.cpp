#include <cstdio>
#include <vector>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int mod = 1e9 + 7;
const int MAXK = 3e4 + 5;

template<typename _T>
void read( _T &x ) {
	x = 0; char s = getchar(); int f = 1;
	while( ! ( '0' <= s && s <= '9' ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
inline _T Max( const _T &a, const _T &b ) {
	return a > b ? a : b;
}

typedef std :: vector<int> Poly;

Poly ans, pw, tmp;

int fac[MAXK], ifac[MAXK];

LL N; int K;

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

inline int C( int n, int m ) { return n < m ? 0 : Mul( fac[n], Mul( ifac[m], ifac[n - m] ) ); }

inline void Init( const int &n ) {
	fac[0] = 1; rep( i, 1, n ) fac[i] = Mul( fac[i - 1], i );
	ifac[n] = Inv( fac[n] ); per( i, n - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

inline Poly operator + ( const Poly &P, const Poly &Q ) {
	int n = P.size(), m = Q.size();
	Poly ret; ret.reserve( Max( n, m ) );
	for( int i = 0 ; i < n || i < m ; i ++ ) {
		int t = 0;
		if( i < n ) AddEq( t, P[i] );
		if( i < m ) AddEq( t, Q[i] );
		ret.push_back( t );
	}
	return ret;
}

inline Poly operator - ( const Poly &P, const Poly &Q ) {
	int n = P.size(), m = Q.size();
	Poly ret; ret.reserve( Max( n, m ) );
	for( int i = 0 ; i < n || i < m ; i ++ ) {
		int t = 0;
		if( i < n ) AddEq( t, P[i] );
		if( i < m ) SubEq( t, Q[i] );
		ret.push_back( t );
	}
	return ret;
}

Poly operator * ( Poly &P, Poly &Q ) {
	if( P.empty() || Q.empty() ) return Poly();
	int n = P.size(), m = Q.size();
	Poly ret( n + m - 1, 0 );
	if( n <= 100 || m <= 100 ) {
		for( int i = 0 ; i < n ; i ++ )
			for( int j = 0 ; j < m ; j ++ )
				AddEq( ret[i + j], Mul( P[i], Q[j] ) );
		return ret;
	} else {
		int h = n >> 1;
		Poly A( P.begin(), P.begin() + h ),
			 B( P.begin() + h, P.end() ),
			 C( Q.begin(), Q.begin() + h ),
			 D( Q.begin() + h, Q.end() ),
			 U( A + B ), V( C + D );
		Poly R( A * C ), S( B * D ), T( U * V - R - S );
		for( int i = 0 ; i < ( int ) R.size() ; i ++ )
			AddEq( ret[i], R[i] );
		for( int i = 0 ; i < ( int ) S.size() ; i ++ )
			AddEq( ret[i + h * 2], S[i] );
		for( int i = 0 ; i < ( int ) T.size() ; i ++ )
			AddEq( ret[i + h], T[i] );
	}
	return ret;
}

int main() {
	read( N ), read( K ), Init( K );
	if( N > K ) return puts( "0" ), 0;
	pw.push_back( 0 );
	ans.push_back( 1 );
	rep( i, 1, K ) pw.push_back( ifac[i] );
	for( int i = 0, uni, dif ; ( 1 << i ) <= N ; i ++ ) {
		if( N >> i & 1 ) {
			tmp = pw, uni = Qkpow( 2, N & ( ( 1 << i ) - 1 ) ), dif = 1;
			for( int j = 0 ; j <= K ; j ++, MulEq( dif, uni ) )
				MulEq( tmp[j], dif );
			tmp = ans * tmp;
			ans = Poly( tmp.begin(), tmp.begin() + K + 1 );
		}
		tmp = pw, uni = Qkpow( 2, 1 << i ), dif = 1;
		for( int j = 0 ; j <= K ; j ++, MulEq( dif, uni ) )
			MulEq( tmp[j], dif );
		tmp = pw * tmp;
		pw = Poly( tmp.begin(), tmp.begin() + K + 1 );
	}
	int res = 0;
	for( int i = 0 ; i <= K ; i ++ )
		AddEq( res, Mul( ans[i], ifac[K - i] ) );
	write( Mul( res, fac[K] ) ), putchar( '\n' );
	return 0;
}