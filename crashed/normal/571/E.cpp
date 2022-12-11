#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int mod = 1e9 + 7;
const int MAXN = 105, MAXD = 6e3 + 5;

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
inline _T Max( const _T &a, const _T &b ) {
	return a > b ? a : b;
}

LL sol[MAXN];

int val[MAXD], tot;
int a0[MAXD][MAXN], b0[MAXD][MAXN];

int A[MAXN], B[MAXN];

int N;

inline int Qkpow( int, LL );
inline int Inv( const int &a ) { return Qkpow( a, mod - 2 ); }
inline int Mul( int x, const int &v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int &v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int &v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int& MulEq( int &x, const int &v ) { return x = 1ll * x * v % mod; }
inline int& SubEq( int &x, const int &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
inline int& AddEq( int &x, const int &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

inline LL Mul( const LL &a, const LL &b, const LL &mod ) {
	return ( a * b - ( LL ) ( ( long double ) a / mod * b ) * mod + mod ) % mod;
}

inline int Qkpow( int base, LL indx ) {
	int ret = 1;
	while( indx ) {
		if( indx & 1 ) MulEq( ret, base );
		MulEq( base, base ), indx >>= 1;
	}
	return ret;
}

LL Exgcd( const LL &a, const LL &b, LL &x, LL &y ) {
	if( ! b ) return x = 1, y = 0, a;
	int d = Exgcd( b, a % b, y, x );
	y -= x * ( a / b ); return d;
}

inline void Factorize( int x ) {
	for( int i = 2 ; 1ll * i * i <= x ; i ++ )
		if( ! ( x % i ) ) {
			val[++ tot] = i;
			while( ! ( x % i ) ) x /= i;
		}
	if( x > 1 ) val[++ tot] = x;
}

inline void CheckSolution( const int &ind, const LL &x ) {
	rep( i, 1, N ) sol[i] = -1;
	sol[ind] = x;
	rep( i, 1, tot ) rep( j, 1, N ) {
		if( j == ind ) continue;
		if( ! b0[i][j] ) {
			if( a0[i][ind] + b0[i][ind] * x != a0[i][j] )
				puts( "-1" ), exit( 0 );
		} else {
			if( ~ sol[j] ) {
				if( a0[i][ind] + b0[i][ind] * x != 
					a0[i][j] + b0[i][j] * sol[j] )
					puts( "-1" ), exit( 0 );
			} else {
				if( ( b0[i][ind] * x + a0[i][ind] - a0[i][j] ) % b0[i][j] )
					puts( "-1" ), exit( 0 );
				sol[j] = ( b0[i][ind] * x + a0[i][ind] - a0[i][j] ) / b0[i][j];
			}
		}
	}
	write( Mul( A[ind], Qkpow( B[ind], x ) ) ), putchar( '\n' );
	exit( 0 );
}

int main() {
	read( N );
	rep( i, 1, N ) {
		read( A[i] ), read( B[i] );
		Factorize( A[i] );
		Factorize( B[i] );
	}
	std :: sort( val + 1, val + 1 + tot );
	tot = std :: unique( val + 1, val + 1 + tot ) - val - 1;
	rep( i, 1, tot ) {
		int prm = val[i];
		rep( j, 1, N ) {
			a0[i][j] = b0[i][j] = 0;
			for( int x = A[j] ; ! ( x % prm ) ; x /= prm, a0[i][j] ++ );
			for( int x = B[j] ; ! ( x % prm ) ; x /= prm, b0[i][j] ++ );
		}
	}
	int idx = -1;
	rep( i, 1, tot ) {
		int zero = -1;
		bool all = true;
		rep( j, 1, N ) 
			if( b0[i][j] == 0 )
				zero = a0[i][j];
			else all = false;
		if( ~ zero ) {
			rep( j, 1, N )
				if( b0[i][j] == 0 )
					if( zero != a0[i][j] )
						return puts( "-1" ), 0;
			if( all ) continue;
			rep( j, 1, N )
				if( b0[i][j] != 0 ) {
					if( zero < a0[i][j] || ( zero - a0[i][j] ) % b0[i][j] )
						return puts( "-1" ), 0;
					CheckSolution( j, ( zero - a0[i][j] ) / b0[i][j] );
				}
		} 
		idx = i;
	}
	if( idx == -1 ) {
		write( A[1] ), putchar( '\n' );
		return 0;
	}
	if( idx ^ 1 ) {
		std :: swap( a0[1], a0[idx] );
		std :: swap( b0[1], b0[idx] );
	}
	rep( i, 1, tot ) {
		bool all = true;
		rep( j, 1, N ) all &= b0[i][j] == 0;
		if( all ) continue;
		rep( j, 2, N )
			if( b0[1][1] * b0[i][j] != b0[1][j] * b0[i][1] ) {
				int p = ( a0[i][j] - a0[i][1] ) * b0[1][j] -
						( a0[1][j] - a0[1][1] ) * b0[i][j],
					q = b0[i][1] * b0[1][j] - b0[1][1] * b0[i][j];
				if( p % q ) return puts( "-1" ), 0;
				CheckSolution( 1, p / q );
			} else {
				if( a0[1][1] * b0[i][1] != b0[1][1] * a0[i][1] ) return puts( "-1" ), 0;
				if( a0[i][j] * b0[1][j] != b0[i][j] * a0[1][j] ) return puts( "-1" ), 0;
			}
	}
	LL r = a0[1][1] % b0[1][1], M = b0[1][1];
	rep( j, 2, N ) {
		int a = a0[1][j] % b0[1][j], b = b0[1][j];
		LL x, y, d = Exgcd( M, b, x, y );
		int scl = ( ( a - r ) % b + b ) % b;
		if( scl % d ) return puts( "-1" ), 0;
		int stp = b / d; x = x % stp * ( scl / d ) % stp;
		LL nwM = M / d * b; r = ( Mul( M, x, nwM ) + r ) % nwM, M = nwM;
	}
	int mx = 0;
	rep( j, 1, N ) mx = Max( mx, a0[1][j] );
	if( mx > r ) r += ( mx - r + M - 1 ) / M * M;
	write( Mul( A[1], Qkpow( B[1], ( r - a0[1][1] ) / b0[1][1] ) ) ), putchar( '\n' );
	return 0;
}