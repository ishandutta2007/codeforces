#include <cmath>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

template<typename _T>
void read( _T &x )
{
    x = 0; char s = getchar(); int f = 1;
    while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    x *= f;
}

template<typename _T>
void write( _T x )
{
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) write( x / 10 );
    putchar( x % 10 + '0' );
}

bool Chk( const int x )
{
    int v = sqrt( x );
    return v * v == x;
}

int main()
{
    int T;
    read( T );
    while( T -- )
    {
        int N; read( N );
        if( N == 1 ) puts( "NO" );
        else if( Chk( N ) )
        {
            int v = sqrt( N );
            puts( v % 2 == 1 ? "NO" : "YES" );
        }
        else if( N % 2 == 0 && Chk( N / 2 ) ) puts( "YES" );
        else puts( "NO" );
    }
    return 0;
}