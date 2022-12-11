#include <set>
#include <cstdio>
using namespace std;

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 100 + 5;

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

set<int> s;

int N, X;

int main()
{
    int T;
    read( T );
    while( T -- )
    {
        int su = 0;
        read( N ), read( X ), s.clear();
        rep( i, 1, N ) { int w;
            read( w ), s.insert( w );
            su += w;
        }
        if( su == X ) { puts( "NO" ); continue; }
        puts( "YES" ), su = 0;
        rep( i, 1, N )
        {
            int t = *s.begin();
            if( su + t == X )
                t = *s.rbegin();
            write( t ), putchar( i == N ? '\n' : ' ' );
            s.erase( t ), su += t;
        }
    }
    return 0;
}