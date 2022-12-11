#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int mod = 1e9 + 7;
const int MAXN = 5e6 + 5, MAXM = 2e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

LL ans[MAXN];
LL A[MAXN], T[MAXN];
int N, M;

namespace Generate
{
	int seed = 0, base = 0;
	
	int Rnd()
	{
		int ret = seed;
		seed = ( 1ll * seed * base + 233 ) % mod;
		return ret;
	}
}

void Input()
{
	read( N ), read( M );
	for( int i = 1, lst = 0 ; i <= M ; i ++ )
	{
		int p, k, b, w;
		read( p ), read( k ), read( b ), read( w );
		Generate :: seed = b, Generate :: base = w;
		rep( j, lst + 1, p ) 
			T[j] = ( Generate :: Rnd() & 1 ),
			A[j] = ( Generate :: Rnd() % k ) + 1;
		lst = p;
	}
}

int main()
{
	Input();
	LL su[2] = {};
	rep( i, 1, N ) su[T[i]] += A[i];
	int los = su[0] == su[1] ? T[1] : su[0] > su[1];
	int beg = 1;
	if( los ^ T[1] )
	{
		ans[1] ++, A[1] --;
		for( ; beg <= N && T[beg] ^ los ; beg ++ );
	}
	LL cnt = 0;
	for( int i = 1, stp = N << 1 ; stp ; i = i % N + 1, stp -- )
	{
		if( T[i] == los ) cnt += A[i], ans[i] += A[i], A[i] = 0;
		else
		{
			LL delt = MIN( cnt, A[i] );
			A[i] -= delt, ans[i] += delt, cnt -= delt;
		}
	}
	int prt = 1;
	rep( i, 1, N )
		prt = 1ll * prt * ( ( ans[i] ^ ( 1ll * i * i ) ) % mod + 1 ) % mod;
	write( prt ), putchar( '\n' );
	return 0;
}