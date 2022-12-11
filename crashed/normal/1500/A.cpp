#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5, MAXA = 2.5e6 + 5;

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

int fir[MAXA << 1], las[MAXA << 1];
int A[MAXN];
int N;

int main()
{
	read( N );
	rep( i, 1, N ) read( A[i] );
	rep( i, 1, N ) rep( j, i + 1, N )
	{
		int su = A[i] + A[j];
		
		if( ! fir[su] )
			fir[su] = i, las[su] = j;
		else if( fir[su] ^ i && fir[su] ^ j && las[su] ^ i && las[su] ^ j )
		{
			printf( "YES\n%d %d %d %d\n", fir[su], las[su], i, j );
			return 0;
		}
	}
	puts( "NO" );
	return 0;
}