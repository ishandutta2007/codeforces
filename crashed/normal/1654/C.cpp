#include <set>
#include <queue>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 2e5 + 5;

template<typename _T>
void read( _T &x ) {
    x = 0; char s = getchar(); bool f = false;
    while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    if( f ) x = -x;
}

template<typename _T>
void write( _T x ) {
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) write( x / 10 );
    putchar( x % 10 + '0' );
}

std :: multiset<LL> s;
std :: priority_queue<LL> q;

int N;

int main() {
    int T; read( T );
    while( T -- ) {
        read( N ); LL su = 0;
        s.clear();
        while( ! q.empty() ) q.pop();
        rep( i, 1, N ) {
            LL a; read( a );
            s.insert( a ), su += a;
        }
        q.push( su );
        int stp = 0;
        bool flg = true;
        while( ! q.empty() ) {
            LL x = q.top(); q.pop();
            if( s.find( x ) != s.end() ) {
                std :: multiset<LL> :: iterator it = s.find( x );
                s.erase( it ); 
            } else {
                if( stp == N - 1 ) {
                    flg = false; break;
                }
                stp ++;
                q.push( x >> 1 );
                q.push( ( x + 1 ) >> 1 );
            }
        }
        puts( flg ? "YES" : "NO" );
    }
    return 0;
}