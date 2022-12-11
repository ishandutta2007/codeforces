// LUOGU_RID: 94132981
#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = ( 1 << 20 ) + 5;

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

int su[MAXN];
int f[MAXN], tmp[MAXN];

int N, U, K;

inline void Conv( const int &b, int *coe ) {
	int n = 1 << b;
	for( int i = 0 ; i < b ; i ++ )
		for( int j = 0 ; j < n ; j ++ )
			if( j >> i & 1 ) coe[j] ^= coe[j ^ ( 1 << i )];
}

void Divide( const int &B, const int &L, const int &R, const int &len, int *val ) {
	if( ! len || B < 0 ) return ;
	int mid = ( L + R ) >> 1;
	if( len == R - L + 1 ) {
		rep( i, 0, len - 1 ) tmp[i] = val[i];
		Conv( B, tmp );
		rep( i, 0, len - 1 ) su[i + L] = tmp[i];
	} else if( len <= mid - L + 1 ) 
		Divide( B - 1, L, mid, len, val );
	else {
		std :: vector<int> old( val, val + len );
		int rsd = len - ( R - mid ), hlf = 1 << ( B - 1 );
		rep( i, 0, rsd - 1 ) val[i + hlf] ^= val[i];
		Divide( B - 1, mid + 1, R, rsd, val + hlf );
		rep( i, 0, hlf - 1 ) 
			tmp[i] = i < rsd ? su[i + mid + 1] : 0;
		Conv( B - 1, tmp );
		rep( i, 0, hlf - 1 ) tmp[i] ^= old[i + rsd];
		rep( i, 0, hlf - 1 ) val[i] = tmp[i];
		Divide( B - 1, L, mid, hlf, val );
	}
}

int main() {
	Read( N );
	for( U = 1, K = 0 ; U < N ; U <<= 1, K ++ );
	rep( i, 0, N - 1 ) {
		int b; Read( b );
		su[( U - 1 ) ^ i] = b;
	}
	rep( i, 0, U - 1 ) f[i] = i <= U - 1 - N ? 0 : su[i];
	Conv( K, f );
	// su  a su 
	if( U == N ) {
		rep( i, 1, N )
			Write( f[N - i] ), putchar( " \n"[i == N] );
		return 0;
	}
	Divide( K, 0, U - 1, U - N, f + N );
	Conv( K, su );
	rep( i, 1, N ) Write( su[N - i] ), putchar( " \n"[i == N] );
	return 0;
}