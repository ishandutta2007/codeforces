#include <cstdio>
#include <cstring>

typedef unsigned long long ull;

const int base = 29;
const int MAXN = 1.5e5 + 5, MAXSIZ = 10;

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

ull h[MAXN], p[MAXN];
int seq[MAXN];
char S[MAXN];
int N;

ull getHash( const int l, const int r ) { return h[r] - h[l - 1] * p[r - l + 1]; }
int id( const char c ) { return c - 'a'; }

int main()
{
	ull val;
	int T, las, res;
	p[0] = 1;
	for( int i = 1 ; i <= 1.5e5 ; i ++ ) p[i] = p[i - 1] * base;
	const ull one = id( 'o' ) * p[2] + id( 'n' ) * p[1] + id( 'e' ),
			  two = id( 't' ) * p[2] + id( 'w' ) * p[1] + id( 'o' );
	read( T );
	while( T -- )
	{
		scanf( "%s", S + 1 );
		res = las = 0, N = strlen( S + 1 );
		for( int i = 1 ; i <= N ; i ++ )
		{
			h[las + 1] = h[las] * base + id( S[i] ), las ++;
			val = getHash( las - 2, las );
			if( val == one ) seq[++ res] = i - 1, h[las - 1] = h[las - 2] * base + id( S[i] ), las --;
			else if( val == two )
			{
				if( S[i + 1] == 'n' && S[i + 2] == 'e' ) seq[++ res] = i, las --;
				else seq[++ res] = i - 1, h[las - 1] = h[las - 2] * base + id( S[i] ), las --;
			}
		}
		write( res ), putchar( '\n' );
		for( int i = 1 ; i <= res ; i ++ ) write( seq[i] ), putchar( i == res ? '\n' : ' ' );
	}
	return 0;
}
/*
1
twoo
*/