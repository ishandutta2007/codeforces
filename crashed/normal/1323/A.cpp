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
int N;

int main()
{
	int bac[2];
	int T;
	read( T );
	while( T -- )
	{
		bac[0] = bac[1] = 0;
		read( N );
		for( int i = 1 ; i <= N ; i ++ ) read( a[i] ), bac[a[i] % 2] ++;
		if( bac[1] == 1 && ! bac[0] ) write( -1 );
		else if( bac[1] > 1 )
		{
			int tot = 2;
			write( 2 ), putchar( '\n' );
			for( int i = 1 ; i <= N && tot ; i ++ )
				if( a[i] % 2 )
					write( i ), putchar( ' ' ), tot --;
		}	
		else
		{
			write( 1 ), putchar( '\n' );
			for( int i = 1 ; i <= N ; i ++ )
				if( ! ( a[i] % 2 ) )
				{ write( i ), putchar( ' ' ); break; }
		}
		puts( "" );
	}
	return 0;
}