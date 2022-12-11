#include <cstdio>
#include <vector>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int MAXN = 1e5 + 5, MAXQ = 3e5 + 5;

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

std :: vector<int> vec[MAXN << 2], qry[MAXN];
int mn[MAXN << 2], bst;

int ans[MAXQ], qL[MAXQ];
int A[MAXN];

int N, Q;

void Build( const int &x, const int &l, const int &r ) {
    if( l > r ) return ;
    mn[x] = INF;
    rep( i, l, r ) vec[x].push_back( A[i] );
    std :: sort( vec[x].begin(), vec[x].end() );
    vec[x].erase( std :: unique( vec[x].begin(), vec[x].end() ), vec[x].end() );
    if( l == r ) return ;
    int mid = ( l + r ) >> 1;
    Build( x << 1, l, mid );
    Build( x << 1 | 1, mid + 1, r );
}

void Update( const int &x, const int &l, const int &r, const int &segL, const int &segR, const int &nVal ) {
    if( segL <= l && r <= segR ) {
        int tmp = INF, t = std :: upper_bound( vec[x].begin(), vec[x].end(), nVal ) - vec[x].begin();
        if( t < ( int ) vec[x].size() ) tmp = Min( tmp, vec[x][t] - nVal );
        if( t > 0 ) tmp = Min( tmp, nVal - vec[x][t - 1] );
        if( tmp >= bst ) return ;
        mn[x] = Min( mn[x], tmp );
    }
    if( l == r ) return ;
    int mid = ( l + r ) >> 1;
    if( mid  < segR ) Update( x << 1 | 1, mid + 1, r, segL, segR, nVal );
    if( segL <= mid ) Update( x << 1, l, mid, segL, segR, nVal );
    if( segL <= l && r <= segR ) bst = Min( bst, mn[x] );
    mn[x] = Min( mn[x << 1], mn[x << 1 | 1] );
}

int Query( const int &x, const int &l, const int &r, const int &segL, const int &segR ) {
    if( segL <= l && r <= segR ) return mn[x];
    int mid = ( l + r ) >> 1, ret = INF;
    if( segL <= mid ) ret = Min( ret, Query( x << 1, l, mid, segL, segR ) );
    if( mid  < segR ) ret = Min( ret, Query( x << 1 | 1, mid + 1, r, segL, segR ) );
    return ret;
}

int main() {
    Read( N );
    rep( i, 1, N ) Read( A[i] );
    Read( Q );
    rep( i, 1, Q ) {
        int r; Read( qL[i] ), Read( r );
        qry[r].push_back( i );
    }
    Build( 1, 1, N );
    rep( i, 2, N ) {
        bst = INF;
        Update( 1, 1, N, 1, i - 1, A[i] );
        for( const int &x : qry[i] )
            ans[x] = Query( 1, 1, N, qL[x], i );
    }
    rep( i, 1, Q ) Write( ans[i] ), putchar( '\n' );
    return 0;
}