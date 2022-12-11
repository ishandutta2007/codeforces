#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 3e5 + 5;

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

struct BIT {
    LL a[MAXN]; int n;

    BIT(): a{}, n( 0 ) {}

    inline void Init( const int N ) { n = N; rep( i, 1, n ) a[i] = 0; }

    inline void Down( int &x ) { x &= x - 1; }
    inline void Up( int &x ) { x += x & ( - x ); }
    inline void Update( int x, LL v ) { for( ; x <= n ; Up( x ) ) a[x] += v; }
    inline   LL Query( int x ) { LL ret = 0; for( ; x ; Down( x ) ) ret += a[x]; return ret; }
    inline   LL Query( int l, int r ) { return Query( r ) - Query( l - 1 ); }
};

BIT cnt, contri;

int fath[MAXN], mat[MAXN], son[MAXN];

int stk[MAXN], siz[MAXN], top;

char str[MAXN];

int N, Q;

#define S( x ) 1ll * (x) * ( (x) + 1 ) / 2

int main() {
    read( N ), read( Q );
    scanf( "%s", str + 1 );
    cnt.Init( N ), contri.Init( N );
    rep( i, 1, N ) {
        if( str[i] == '(' )
            top ++, stk[top] = i, siz[top] = 0;
        else {
            if( ! top ) {
                siz[0] = 0;
                continue;
            }
            mat[i] = stk[top], mat[stk[top]] = i;
            son[mat[i]] = siz[top];
            cnt.Update( mat[i], 1 );
            contri.Update( mat[i], S( siz[top] ) );
            fath[stk[top]] = stk[top - 1], siz[-- top] ++;
        }
    }
    rep( i, 1, N ) if( son[i] ) 
        cnt.Update( mat[i], - son[i] );
    while( Q -- ) {
        int t, l, r;
        read( t ), read( l ), read( r );
        if( t == 1 ) {
            cnt.Update( l, -1 );
            if( mat[fath[l]] ) cnt.Update( mat[fath[l]], 1 );
            if( fath[l] )
                contri.Update( fath[l], - ( son[fath[l]] -- ) );
        } else 
            write( contri.Query( l, r ) + S( cnt.Query( l, r ) ) ), putchar( '\n' );
    }
    return 0;
}