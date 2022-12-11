#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e5 + 5, MAXV = 35;

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

int fa[MAXV];

char A[MAXN], B[MAXN];
int N;

void MakeSet( const int n ) { rep( i, 1, n ) fa[i] = i; }
int  FindSet( const int u ) { return fa[u] = ( fa[u] == u ? u : FindSet( fa[u] ) ); }
void UnionSet( const int u, const int v ) { fa[FindSet( u )] = FindSet( v ); }

int main() {
    int T; read( T );
    while( T -- ) {
        read( N );
        scanf( "%s", A + 1 );
        scanf( "%s", B + 1 );
        if( ( int ) strlen( A + 1 ) != N ||
            ( int ) strlen( B + 1 ) != N ) {
            puts( "-1" );
            continue;
        }
        MakeSet( 26 );
        bool flg = true;
        rep( i, 1, N ) {
            if( A[i] == B[i] ) continue;
            if( A[i] > B[i] ) { flg = false; break; }
            UnionSet( A[i] - 'a' + 1, B[i] - 'a' + 1 );
        }
        if( ! flg ) {
            puts( "-1" );
            continue;
        }
        int tot = 0;
        rep( i, 1, 26 ) tot += fa[i] == i;
        write( 26 - tot ), putchar( '\n' );
    }
    return 0;
}