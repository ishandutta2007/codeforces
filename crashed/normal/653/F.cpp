#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;

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
_T Max( const _T &a, const _T &b ) {
    return a > b ? a : b;
}

struct Value {
    int val, cnt;

    Value(): val( INF ), cnt( 0 ) {}
    Value( int V ): val( V ), cnt( 1 ) {}
    Value( int V, int C ): val( V ), cnt( C ) {}
};

Value tre[MAXN << 2];
int tag[MAXN << 2];

int ch[MAXN][2], mx[MAXN], fail[MAXN];
int ntot = 0, rt = 0, lst = 0;

char buf[MAXN];
int str[MAXN];

LL ans = 0;
int N;

inline Value operator + ( const Value &a, const Value &b ) {
    if( a.val < b.val ) return a;
    if( a.val > b.val ) return b;
    return Value( a.val, a.cnt + b.cnt );
}

inline int NewNode( const int &t = 0 ) {
    int r = ++ ntot;
    mx[r] = mx[t], fail[r] = fail[t];
    memcpy( ch[r], ch[t], sizeof ch[t] );
    return r;
}

void Build() {
    rt = lst = ++ ntot;
    rep( i, 1, N ) {
        int x = str[i], cur = NewNode(), p = lst;
        mx[cur] = mx[lst] + 1, lst = cur;
        while( p && ! ch[p][x] ) ch[p][x] = cur, p = fail[p];
        if( ! p ) { fail[cur] = rt; continue ; }
        int q = ch[p][x];
        if( mx[q] == mx[p] + 1 ) { fail[cur] = q; continue ; }
        int nq = NewNode( q );
        mx[nq] = mx[p] + 1, fail[q] = fail[cur] = nq;
        while( p && ch[p][x] == q ) ch[p][x] = nq, p = fail[p];
    }
}

inline void Upt( const int &x ) {
    tre[x] = tre[x << 1] + tre[x << 1 | 1];
}

void Build( const int &x, const int &l, const int &r ) {
    if( l > r ) return ;
    if( l == r ) { tre[x] = Value( INF, 1 ); return ; }
    int mid = ( l + r ) >> 1;
    Build( x << 1, l, mid );
    Build( x << 1 | 1, mid + 1, r );
    Upt( x );
}

inline void Add( const int &x, const int &delt ) {
    tre[x].val += delt, tag[x] += delt;
}

inline void Normalize( const int &x ) {
    if( ! tag[x] ) return ;
    Add( x << 1, tag[x] );
    Add( x << 1 | 1, tag[x] );
    tag[x] = 0;
}

void Set( const int x, const int l, const int r, const int p, const int nVal ) {
    if( l == r ) { tre[x].val = nVal; return ; }
    int mid = ( l + r ) >> 1; Normalize( x );
    if( p <= mid ) Set( x << 1, l, mid, p, nVal );
    else Set( x << 1 | 1, mid + 1, r, p, nVal );
    Upt( x );
}

void Update( const int x, const int l, const int r, const int segL, const int segR, const int delt ) {
    if( segL > segR ) return ;
    if( segL <= l && r <= segR ) { Add( x, delt ); return ; }
    int mid = ( l + r ) >> 1; Normalize( x );
    if( segL <= mid ) Update( x << 1, l, mid, segL, segR, delt );
    if( mid  < segR ) Update( x << 1 | 1, mid + 1, r, segL, segR, delt );
    Upt( x );
}

int GetPos( const int x, const int l, const int r ) {
    if( l == r ) return tre[x].val < 0 ? l : 0;
    int mid = ( l + r ) >> 1; Normalize( x );
    if( tre[x << 1 | 1].val < 0 ) return GetPos( x << 1 | 1, mid + 1, r );
    return GetPos( x << 1, l, mid );
}

Value Query( const int x, const int l, const int r, const int segL, const int segR ) {
    if( segL <= l && r <= segR ) return tre[x];
    int mid = ( l + r ) >> 1; Normalize( x );
    if( segR <= mid ) return Query( x << 1, l, mid, segL, segR );
    if( mid  < segL ) return Query( x << 1 | 1, mid + 1, r, segL, segR );
    return Query( x << 1, l, mid, segL, segR ) + Query( x << 1 | 1, mid + 1, r, segL, segR );
}

void DFS( const int u ) {
    int lim = GetPos( 1, 1, N );
    if( lim < mx[u] - mx[fail[u]] ) {
        Value tmp = Query( 1, 1, N, lim + 1, mx[u] - mx[fail[u]] );
        if( tmp.val == 0 ) ans += tmp.cnt;
    }
    for( int d = 0 ; d < 2 ; d ++ )
        if( mx[ch[u][d]] == mx[u] + 1 ) {
            int coe = d ? -1 : 1;
            Set( 1, 1, N, mx[u] + 1, 0 );
            Update( 1, 1, N, 1, mx[u] + 1, coe );
            DFS( ch[u][d] );
            Update( 1, 1, N, 1, mx[u] + 1, - coe );
            Set( 1, 1, N, mx[u] + 1, INF );
        }
}

int main() {
    read( N );
    scanf( "%s", buf + 1 );
    rep( i, 1, N ) str[i] = buf[i] == '(';
    Build();
    Build( 1, 1, N );
    DFS( rt );
    write( ans ), putchar( '\n' );
    return 0;
}