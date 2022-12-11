#include <cstdio>
#include <vector>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 2e5 + 5, MAXQ = 5e5 + 5;

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
_T Abs( const _T &a ) {
    return a < 0 ? -a : a;
}

template<typename _T>
_T Sgn( const _T &a ) {
    return a < 0 ? -1 : 1;
}

std :: vector<int> qry[MAXN];
int ans[MAXQ], qK[MAXQ];
int BIT[MAXN];

std :: vector<int> son[MAXN];
int DFN[MAXN], siz[MAXN], ID = 0;

int ch[MAXN][26], fail[MAXN];
int ntot = 0;

char pool[MAXN], *ptr = pool;
int len[MAXN], ed[MAXN];
char *str[MAXN]; 

int N, Q;

inline void Down( int &x ) { x &= x - 1; }
inline void Up( int &x ) { x += x & ( - x ); }
inline void Update( int x, int v ) { for( ; x <= ID ; Up( x ) ) BIT[x] += v; }
inline  int Query( int x ) { int ret = 0; for( ; x ; Down( x ) ) ret += BIT[x]; return ret; }
inline  int Query( const int &l, const int &r ) { return Query( r ) - Query( l - 1 ); }

int Insert( const char *s, const int n ) {
    int p = 0, x;
    for( int i = 0 ; i < n ; i ++ ) {
        x = s[i] - 'a';
        if( ! ch[p][x] ) ch[p][x] = ++ ntot;
        p = ch[p][x];
    }
    return p;
}

void Build() {
    static int q[MAXN] = {};

    int h = 1, t = 0;
    rep( i, 0, 25 ) if( ch[0][i] )
        fail[q[++ t] = ch[0][i]] = 0;
    while( h <= t ) {
        int u = q[h ++], v;
        rep( i, 0, 25 )
            if( ( v = ch[u][i] ) )
                fail[q[++ t] = v] = ch[fail[u]][i];
            else ch[u][i] = ch[fail[u]][i];
        son[fail[u]].push_back( u );
    }
}

void Init( const int u ) {
    DFN[u] = ++ ID, siz[u] = 1;
    for( const int &v : son[u] )
        Init( v ), siz[u] += siz[v];
}

int main() {
    read( N ), read( Q );
    rep( i, 1, N ) {
        scanf( "%s", str[i] = ptr );
        ptr += len[i] = strlen( str[i] );
        ed[i] = Insert( str[i], len[i] );
    }
    Build();
    Init( 0 );
    rep( i, 1, Q ) {
        int l, r;
        read( l ), read( r ), read( qK[i] );
        qry[r].push_back( i ), qry[l - 1].push_back( - i );
    }
    rep( i, 1, N ) {
        int p = 0;
        rep( j, 0, len[i] - 1 ) {
            p = ch[p][str[i][j] - 'a'];
            Update( DFN[p], 1 );
        }
        for( const int &q : qry[i] ) {
            int id = ed[qK[Abs( q )]];
            ans[Abs( q )] += Sgn( q ) * Query( DFN[id], DFN[id] + siz[id] - 1 );
        }
    }
    rep( i, 1, Q ) write( ans[i] ), putchar( '\n' );
    return 0;
}