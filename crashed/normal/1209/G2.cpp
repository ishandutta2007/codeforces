#include <set>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
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

template<typename _T>
_T MAX( const _T a, const _T b ) {
    return a > b ? a : b;
}

struct Element {
    int mn, mx;
    int lMx, rMx, su;

    Element(): mn( INF ), lMx( - INF ), rMx( - INF ), su( 0 ) {}
    Element( int V, int K ): mn( V ), mx( K ), lMx( K ), rMx( - INF ), su( 0 ) {}
    Element( int V, int X, int L, int R, int S ): mn( V ), mx( X ), lMx( L ), rMx( R ), su( S ) {}

    Element operator + ( const Element &q ) const {
        Element ret;
        if( mn < q.mn ) {
            ret = *this;
            ret.rMx = MAX( ret.rMx, q.mx );
        } else if( mn > q.mn ) {
            ret = q;
            ret.lMx = MAX( ret.lMx, mx );
        } else {
            ret.mn = mn;
            ret.lMx = lMx, ret.rMx = q.rMx;
            ret.su = su + q.su + MAX( rMx, q.lMx );
        }
        ret.mx = MAX( mx, q.mx );
        return ret;
    }
};

std :: set<int> app[MAXN];

Element tre[MAXN << 2];
int tag[MAXN << 2];

int A[MAXN];
int N, Q;

inline void Upt( const int x ) { tre[x] = tre[x << 1] + tre[x << 1 | 1]; }
inline void Add( const int x, const int delt ) { tre[x].mn += delt, tag[x] += delt; }
inline void Normalize( const int x ) { if( tag[x] ) Add( x << 1, tag[x] ), Add( x << 1 | 1, tag[x] ), tag[x] = 0; }

void Update( const int x, const int l, const int r, const int segL, const int segR, const int delt ) {
    if( segL > segR ) return ;
    if( segL <= l && r <= segR ) { Add( x, delt ); return ; }
    int mid = ( l + r ) >> 1; Normalize( x );
    if( segL <= mid ) Update( x << 1, l, mid, segL, segR, delt );
    if( mid  < segR ) Update( x << 1 | 1, mid + 1, r, segL, segR, delt );
    Upt( x );
}

void Modify( const int x, const int l, const int r, const int p, const int nVal ) {
    if( l == r ) {
        tre[x].mx = tre[x].lMx = nVal;
        return ;
    }
    int mid = ( l + r ) >> 1; Normalize( x );
    if( p <= mid ) Modify( x << 1, l, mid, p, nVal );
    else Modify( x << 1 | 1, mid + 1, r, p, nVal );
    Upt( x );
}

void Query() {
    // Note that b_n always = 0
    write( N - ( tre[1].su + tre[1].lMx ) ), putchar( '\n' );
}

void Remove( const int c ) {
    if( app[c].empty() ) return ;
    int l = * app[c].begin(),
        r = * app[c].rbegin();
    Modify( 1, 1, N, l, 0 );
    Update( 1, 1, N, l, r - 1, -1 );
}

void Apply( const int c ) {
    if( app[c].empty() ) return ;
    int l = * app[c].begin(),
        r = * app[c].rbegin();
    Modify( 1, 1, N, l, app[c].size() );
    Update( 1, 1, N, l, r - 1, 1 );
}

int main() {
    read( N ), read( Q );
    rep( i, 1, N ) {
        read( A[i] );
        app[A[i]].insert( i );
    }
    rep( i, 1, 2e5 ) Apply( i );
    Query();
    while( Q -- ) {
        int p, x, c;
        read( p ), read( x );
        Remove( c = A[p] );
        app[c].erase( p );
        Apply( c );
        Remove( c = A[p] = x );
        app[c].insert( p );
        Apply( c );
        Query();
    }
    return 0;
}