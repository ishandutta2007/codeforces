#include <cstdio>
#include <utility>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2005;

template<typename _T>
inline void Read( _T &x ) {
    x = 0; char s = getchar(); bool f = false;
    while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    if( f ) x = -x;
}

template<typename _T>
inline void Write( _T x ) {
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) Write( x / 10 );
    putchar( x % 10 + '0' );
}

typedef std :: pair<int, int> Edge;

Edge edg[MAXN]; int len;

int mat[MAXN][MAXN];

int mn[MAXN], mx[MAXN];
int seq[MAXN], tot;
int stk[MAXN], top;

int N;

inline void Link( const int &u, const int &v ) {
    edg[++ len] = Edge( u, v );
}

int Merge( const int &l, const int &r ) {
    if( tot == 2 ) 
        Link( std :: max( mn[seq[1]], l ),
              std :: min( mx[seq[2]], r ) );
    else if( tot > 2 ) {
        per( i, tot - 1, 3 )
            Link( mx[seq[i]], mx[seq[i - 2]] );
        Link( std :: max( mn[seq[1]], l ), mx[seq[tot]] );
        Link( std :: max( mn[seq[2]], l ), mx[seq[tot]] );
    }
    mn[seq[tot]] = mn[seq[1]];
    return seq[tot];
}

int main() {
    int T; Read( T );
    while( T -- ) {
        Read( N ), top = len = 0;
        rep( i, 1, N ) rep( j, i, N )
            scanf( "%1d", &mat[i][j] );
        rep( i, 1, N ) mn[i] = mx[i] = i;
        rep( i, 1, N ) {
            stk[++ top] = i;
            per( j, i - 1, 1 )
                if( mat[j][i] ) {
                    //  [j, i] 
                    // 
                    tot = 0;
                    while( top > 0 && j <= stk[top] )
                        seq[++ tot] = stk[top --];
                    std :: reverse( seq + 1, seq + 1 + tot );
                    stk[++ top] = Merge( j, i );
                }
        }
        rep( i, 1, N - 1 )
            Write( edg[i].first ), putchar( ' ' ),
            Write( edg[i].second ), putchar( '\n' );
    }
    return 0;
}