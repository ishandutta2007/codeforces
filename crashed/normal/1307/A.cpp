#include <cstdio>

const int MAXN = 105;

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

int a[MAXN];
int N, D;

int main()
{
	int T, ans;
	read( T );
	while( T -- )
	{
		read( N ), read( D );
		for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
		ans = a[1];
		for( int i = 2 ; i <= N && D ; i ++ )
		{
			if( a[i] * ( i - 1 ) <= D ) D -= a[i] * ( i - 1 ), ans += a[i];
			else ans += D / ( i - 1 ), D = 0; 
		}
		write( ans ), putchar( '\n' );
	}
	return 0;
}