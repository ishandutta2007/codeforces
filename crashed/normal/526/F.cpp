#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
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

struct Element {
    LL val; int cnt;

    Element(): val( INF ), cnt( 0 ) {}
    Element( LL V ): val( V ), cnt( 1 ) {}
    Element( LL V, int C ): val( V ), cnt( C ) {}

    inline Element operator + ( const Element &q ) const {
        if( val < q.val ) return *this;
        if( val > q.val ) return q;
        return Element( val, q.cnt + cnt );
    }
};

Element tre[MAXN << 2];
LL tag[MAXN << 2];

int stk1[MAXN], top1;
int stk2[MAXN], top2;

int p[MAXN];
int N;

inline void Upt( const int x ) { tre[x] = tre[x << 1] + tre[x << 1 | 1]; }
inline void Add( const int x, const LL delt ) { tre[x].val += delt, tag[x] += delt; }
inline void Normalize( const int x ) { if( tag[x] ) Add( x << 1, tag[x] ), Add( x << 1 | 1, tag[x] ), tag[x] = 0; }

void Build( const int x, const int l, const int r ) {
    if( l > r ) return ;
    tre[x] = Element( 1 );
    if( l == r ) return ;
    int mid = ( l + r ) >> 1;
    Build( x << 1, l, mid );
    Build( x << 1 | 1, mid + 1, r );
}

void Update( const int x, const int l, const int r, const int segL, const int segR, const LL delt ) {
    if( segL > segR ) return ;
    if( segL <= l && r <= segR ) { Add( x, delt ); return ; }
    int mid = ( l + r ) >> 1; Normalize( x );
    if( segL <= mid ) Update( x << 1, l, mid, segL, segR, delt );
    if( mid  < segR ) Update( x << 1 | 1, mid + 1, r, segL, segR, delt );
    Upt( x );
}

Element Query( const int x, const int l, const int r, const int segL, const int segR ) {
    if( segL > segR ) return Element();
    if( segL <= l && r <= segR ) return tre[x];
    int mid = ( l + r ) >> 1; Normalize( x );
    if( segR <= mid ) return Query( x << 1, l, mid, segL, segR );
    if( mid  < segL ) return Query( x << 1 | 1, mid + 1, r, segL, segR );
    return Query( x << 1, l, mid, segL, segR ) +
           Query( x << 1 | 1, mid + 1, r, segL, segR );
}

int main() {
    read( N );
    rep( i, 1, N ) {
        int x, y;
        read( x ), read( y );
        p[x] = y;
    }
    LL ans = 0;
    Build( 1, 1, N );
    rep( i, 1, N ) {
        while( top1 && p[stk1[top1]] <= p[i] )
            Update( 1, 1, N, stk1[top1 - 1] + 1, stk1[top1], - p[stk1[top1]] ), top1 --;
        Update( 1, 1, N, stk1[top1] + 1, i, p[i] ), stk1[++ top1] = i;
        while( top2 && p[stk2[top2]] >= p[i] )
            Update( 1, 1, N, stk2[top2 - 1] + 1, stk2[top2], p[stk2[top2]] ), top2 --;
        Update( 1, 1, N, stk2[top2] + 1, i, - p[i] ), stk2[++ top2] = i;
        Update( 1, 1, N, 1, i, -1 );
        
        Element tmp = Query( 1, 1, N, 1, i );
        if( tmp.val == 0 ) ans += tmp.cnt;
    }
    write( ans ), putchar( '\n' );
    return 0;
}