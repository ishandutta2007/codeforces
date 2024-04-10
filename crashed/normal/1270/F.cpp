#include <cmath>
#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN = 2e5 + 5, MAXT = 505;

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
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int buc[MAXN * MAXT];
int s[MAXN], nxt[MAXN];
int N, T;
char S[MAXN];

int main()
{
	LL ans = 0;
	scanf( "%s", S + 1 ), N = strlen( S + 1 ), T = ceil( sqrt( N ) );
	for( int i = 1 ; i <= N ; i ++ ) s[i] = s[i - 1] + S[i] - '0';
	if( s[N] == 0 ) { puts( "0" ); return 0; }
	for( int i = N ; ~ i ; i -- )
	{
		if( s[i] ^ s[i + 1] ) nxt[i] = i + 1;
		else nxt[i] = nxt[i + 1];
	}
	for( int k = 1, t ; k <= T ; k ++ )
	{
		for( int i = 0 ; i <= N ; i ++ ) buc[s[i] * k - i + N] ++;
		for( int i = 0 ; i <= N ; i ++ ) t = buc[s[i] * k - i + N], ans += 1ll * t * ( t - 1 ) / 2, buc[s[i] * k - i + N] = 0;
	}
	int l, r, tl, tr;
	for( int i = 0 ; i < N ; i ++ )
	{
		l = i, r = nxt[i];
		for( int k = 1 ; k <= N / T && s[i] + k <= s[N] ; k ++ )
		{
			l = nxt[l], r = nxt[r];
			tr = r - i - 1, tl = l - i;
			tl = MAX( tl, k * T + 1 );
			if( tl <= tr ) ans += tr / k - ( tl - 1 ) / k;
		}
	}
	write( ans ), putchar( '\n' );
	return 0;
}