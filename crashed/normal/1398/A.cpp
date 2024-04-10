#include <cstdio>

const int MAXN = 1e5 + 5;

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
	int T;
	read( T );
	while ( T -- )
	{
		bool flg = false;
		read( N );
		for( int i = 1 ; i <= N ; i ++ )
		{
			read( a[i] );
			if( i > 2 && ! flg )
			{
				if( a[1] + a[2] <= a[i] )
				{ printf( "%d %d %d\n", 1, 2, i ); flg = true; }
			}
		}
		if( ! flg ) puts( "-1" );
	}
	return 0;
}