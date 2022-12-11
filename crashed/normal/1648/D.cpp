#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
const int MAXN = 5e5 + 5, MAXLOG = 21;

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
    LL mxRes, mxL, mxR;
    
    Element(): mxRes( - INF ), mxL( - INF ), mxR( - INF ) {}
    Element( LL Res, LL L, LL R ): mxRes( Res ), mxL( L ), mxR( R ) {}
};

std :: vector<int> rig[MAXN];
int lef[MAXN], dec[MAXN];

Element tre[MAXN << 2], stb[MAXN << 2];

LL beg[MAXN][MAXLOG], sig[MAXN][MAXLOG];
int lg2[MAXN];

LL pref[3][MAXN];

int N, Q;

Element operator + ( const Element &a, const Element &b ) {
    Element ret;
    ret.mxL = MAX( a.mxL, b.mxL );
    ret.mxR = MAX( a.mxR, b.mxR );
    ret.mxRes = MAX( MAX( a.mxRes, b.mxRes ), a.mxL + b.mxR );
    return ret;
}

inline void Upt( const int x ) {
    tre[x] = tre[x << 1] + tre[x << 1 | 1];
}

void Build( const int x, const int l, const int r ) {
    if( l > r ) return ;
    if( l == r ) {
        tre[x].mxRes = tre[x].mxL = - INF;
        tre[x].mxR = pref[1][l] + pref[2][N] - pref[2][l - 1];
        
        stb[x].mxL = pref[0][l] - pref[1][l - 1];
        stb[x].mxR = pref[1][l] + pref[2][N] - pref[2][l - 1];
        stb[x].mxRes = pref[0][l] + pref[1][l] - pref[1][l - 1] + pref[2][N] - pref[2][l - 1];
        
        return ;
    }
    int mid = ( l + r ) >> 1;
    Build( x << 1, l, mid );
    Build( x << 1 | 1, mid + 1, r );
    Upt( x );
    stb[x] = stb[x << 1] + stb[x << 1 | 1];
}

void Update( const int x, const int l, const int r, const int p, const LL nVal ) {
    if( l == r ) {
        tre[x].mxL = MAX( tre[x].mxL, nVal );
        return ;
    }
    int mid = ( l + r ) >> 1;
    if( p <= mid ) Update( x << 1, l, mid, p, nVal );
    else Update( x << 1 | 1, mid + 1, r, p, nVal );
    Upt( x );
}

Element Query( const int x, const int l, const int r, const int segL, const int segR ) {
    if( l > r || segL > segR ) return Element();
    if( segL <= l && r <= segR ) return tre[x];
    int mid = ( l + r ) >> 1;
    if( segR <= mid ) return Query( x << 1, l, mid, segL, segR );
    if( mid  < segL ) return Query( x << 1 | 1, mid + 1, r, segL, segR );
    return Query( x << 1, l, mid, segL, segR ) + Query( x << 1 | 1, mid + 1, r, segL, segR );
}

Element QueryStb( const int x, const int l, const int r, const int segL, const int segR ) {
    if( l > r || segL > segR ) return Element();
    if( segL <= l && r <= segR ) return stb[x];
    int mid = ( l + r ) >> 1;
    if( segR <= mid ) return QueryStb( x << 1, l, mid, segL, segR );
    if( mid  < segL ) return QueryStb( x << 1 | 1, mid + 1, r, segL, segR );
    return QueryStb( x << 1, l, mid, segL, segR ) + QueryStb( x << 1 | 1, mid + 1, r, segL, segR );
}

void Init() {
    Build( 1, 1, N );
    lg2[0] = -1; rep( i, 1, N ) lg2[i] = lg2[i >> 1] + 1;
    rep( i, 1, N ) 
        beg[i][0] = pref[0][i] - pref[1][i - 1],
        sig[i][0] = pref[0][i] + pref[1][i] - pref[1][i - 1] + pref[2][N] - pref[2][i - 1];
    for( int j = 1 ; j <= lg2[N] ; j ++ )
        for( int i = 1 ; i + ( 1 << ( j - 1 ) ) <= N ; i ++ )
            beg[i][j] = MAX( beg[i][j - 1], beg[i + ( 1 << ( j - 1 ) )][j - 1] ),
            sig[i][j] = MAX( sig[i][j - 1], sig[i + ( 1 << ( j - 1 ) )][j - 1] );
}

LL QuerySig( const int l, const int r ) {
    int k = lg2[r - l + 1];
    return MAX( sig[l][k], sig[r - ( 1 << k ) + 1][k] );
}

LL QueryBeg( const int l, const int r ) {
    int k = lg2[r - l + 1];
    return MAX( beg[l][k], beg[r - ( 1 << k ) + 1][k] );
}

int main() {
    read( N ), read( Q );
    rep( i, 0, 2 ) rep( j, 1, N ) {
        int a; read( a );
        pref[i][j] = pref[i][j - 1] + a;
    }
    rep( i, 1, Q ) {
        int r; read( lef[i] ), read( r ), read( dec[i] );
        rig[r].push_back( i );
    }
    Init();
    Element tmp;
    LL ans = - INF, dp;
    rep( i, 1, N ) {
        dp = - INF; 
        int n = rig[i].size(), cur;
        for( int j = 0 ; j < n ; j ++ ) {
            cur = rig[i][j];
            tmp = Query( 1, 1, N, MAX( 1, lef[cur] - 1 ), i );
            ans = MAX( ans, tmp.mxRes - dec[cur] );
            ans = MAX( ans, QuerySig( lef[cur], i ) - dec[cur] );
            ans = MAX( ans, QueryStb( 1, 1, N, lef[cur], i ).mxRes - dec[cur] );
            dp = MAX( dp, tmp.mxL - dec[cur] );
            dp = MAX( dp, QueryBeg( lef[cur], i ) - dec[cur] );
        }
        Update( 1, 1, N, i, dp );
    }
    write( ans ), putchar( '\n' );
    return 0;
}