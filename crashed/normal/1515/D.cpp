#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5;

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

int sock[MAXN];
int N, L, R;

int main()
{
    int T;
    read( T );
    while( T -- )
    {
        read( N ), read( L ), read( R ); 
        rep( i, 1, N ) sock[i] = 0;
        int lef = 0, rig = 0, avai = 0, la = 0, ra = 0;
        rep( i, 1, L ) { int c; read( c ), sock[c] ++; }
        rep( i, 1, R ) { int c; read( c ), sock[c] --; }
        rep( i, 1, N )
        {
            if( sock[i] > 0 ) la += sock[i] / 2, lef += sock[i];
            if( sock[i] < 0 ) ra += ( - sock[i] ) / 2, rig += - sock[i];
        }
        if( rig < lef ) 
            std :: swap( rig, lef ), std :: swap( la, ra );
        if( ra * 2 >= rig - lef )
            write( ( rig - lef ) / 2 + lef ), putchar( '\n' );
        else
            write( rig - ra ), putchar( '\n' );
    }
    return 0;
}