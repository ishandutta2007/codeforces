#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 2e5 + 5, MAXM = 10;

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

template<typename _T>
inline _T Min( const _T &a, const _T &b ) {
    return a < b ? a : b;
}

struct Element {
    int f[MAXM];

    Element(): f{} {}
};

int par[MAXN];

Element ele[2];

Element tre[MAXN << 2][2];
bool rev[MAXN << 2];

int A[MAXN];

int N, M, Q;

inline void Down( int &x ) { x &= x - 1; }
inline void Up( int &x ) { x += x & ( -x ); }
inline void Update( int x ) { for( ; x <= N ; Up( x ) ) par[x] ^= 1; }
inline  int Query( int x ) { int ret = 0; for( ; x ; Down( x ) ) ret ^= par[x]; return ret; }

inline Element operator + ( const Element &a, const Element &b ) {
    Element ret;
    rep( d, 0, M ) ret.f[d] = a.f[b.f[d]];
    return ret;
}

inline void Upt( const int &x ) {
    tre[x][0] = tre[x << 1][0] + tre[x << 1 | 1][0];
    tre[x][1] = tre[x << 1][1] + tre[x << 1 | 1][1];
}

inline void Reverse( const int &x ) {
    std :: swap( tre[x][0], tre[x][1] ), rev[x] ^= 1;
}

inline void Normalize( const int &x ) {
    if( ! rev[x] ) return ;
    Reverse( x << 1 );
    Reverse( x << 1 | 1 );
    rev[x] = false;
}

void Reverse( const int &x, const int &l, const int &r, const int &segL, const int &segR ) {
    if( segL <= l && r <= segR ) { Reverse( x ); return ; }
    int mid = ( l + r ) >> 1; Normalize( x );
    if( segL <= mid ) Reverse( x << 1, l, mid, segL, segR );
    if( mid  < segR ) Reverse( x << 1 | 1, mid + 1, r, segL, segR );
    Upt( x );
}

Element Query( const int &x, const int &l, const int &r, const int &segL, const int &segR ) {
    if( segL <= l && r <= segR ) return tre[x][0];
    int mid = ( l + r ) >> 1; Normalize( x );
    if( segR <= mid ) return Query( x << 1, l, mid, segL, segR );
    if( mid  < segL ) return Query( x << 1 | 1, mid + 1, r, segL, segR );
    return Query( x << 1, l, mid, segL, segR ) + Query( x << 1 | 1, mid + 1, r, segL, segR );
}

void Build( const int &x, const int &l, const int &r ) {
    if( l > r ) return ;
    rev[x] = false;
    if( l == r ) {
        tre[x][0] = ele[! A[l]];
        tre[x][1] = ele[A[l]];
        return ;
    }
    int mid = ( l + r ) >> 1;
    Build( x << 1, l, mid );
    Build( x << 1 | 1, mid + 1, r );
    Upt( x );
}

inline void Init() {
    rep( d, 0, M ) {
        ele[0].f[d] = d < M ? d + 1 : 0;
        ele[1].f[d] = Min( d + 1, M );
    }
}

int main() {
    Read( N ), Read( M ), Read( Q );
    rep( i, 1, N ) {
        LL a; Read( a );
        A[i] = a & 1;
    }
    Init(), Build( 1, 1, N );
    while( Q -- ) {
        int opt, l, r;
        Read( opt ), Read( l ), Read( r );
        if( opt == 1 ) {
            LL d; Read( d );
            if( d & 1 ) {
                Reverse( 1, 1, N, l, r );
                Update( l ), Update( r + 1 );
            }
        }
        if( opt == 2 ) {
            Element ans = Query( 1, 1, N, l, r );
            puts( ans.f[M] > 0 ? "1" : "2" );
        }
    }
    return 0;
}