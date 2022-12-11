#include <cctype>
#include <cstdio>

#define rep( x, a, b ) for( int ( x ) = a ; x <= b ; x ++ )
#define per( x, a, b ) for( int ( x ) = a ; x >= b ; x -- )

const int MAXN = 3e5 + 5, MAXA = 1.5e7 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( ! isdigit( s ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( isdigit( s ) ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

int prime[MAXA], pn;
int cnt[MAXA];
bool isPrime[MAXA];

int N;

void EulerSieve( const int siz )
{
	rep( i, 2, siz )
	{
		if( ! isPrime[i] ) prime[++ pn] = i;
		for( int j = 1 ; j <= pn && 1ll * i * prime[j] <= siz ; j ++ )
		{
			isPrime[i * prime[j]] = true;
			if( ! ( i % prime[j] ) ) break;
		}
	}
}

int main()
{
	read( N ); int mx;
	rep( i, 1, N ) { int a;
		read( a ), cnt[a] ++;
		mx = MAX( mx, a );
	}
	EulerSieve( mx );
	rep( i, 1, pn )
		per( j, mx / prime[i], 1 )
			cnt[j] += cnt[j * prime[i]];
	int ans = 0x3f3f3f3f;
	rep( i, 1, mx ) if( cnt[i] && cnt[i] < N ) ans = MIN( N - cnt[i], ans );
	write( ans == 0x3f3f3f3f ? -1 : ans ), putchar( '\n' );
	return 0;
}