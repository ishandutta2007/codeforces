#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef pair<int, int> Block;

const int MAXN = 1e5 + 5;

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

struct Tower
{
    int h, idx;
    Tower() { h = idx = 0; }  
    Tower( int H, int I ) { h = H, idx = I; }
    bool operator < ( const Tower &b ) const { return ! ( h < b.h || h == b.h && idx < b.idx ); }
};

priority_queue<Tower> q;

Block b[MAXN];

int id[MAXN];
int N, M, X;

int main()
{
    int T;
    read( T );
    while( T -- )
    {
        read( N ), read( M ), read( X );
        puts( "YES" );
        rep( i, 1, N ) read( b[i].first ), b[i].second = i;
        std :: sort( b + 1, b + 1 + N );
        while( ! q.empty() ) q.pop();
        rep( i, 1, M ) q.push( Tower( 0, i ) );
        rep( i, 1, N )
        {
            Tower t = q.top(); q.pop();
            id[b[i].second] = t.idx;
            q.push( Tower( t.h + b[i].first, t.idx ) );
        }
        rep( i, 1, N ) write( id[i] ), putchar( i == N ? '\n' : ' ' );
    }
    return 0;
}