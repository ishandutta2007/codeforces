#include <map>
#include <vector>
#include <cstdio>
#include <iostream>

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

struct Change {
    int u, l, r;

    Change(): u( 0 ), l( 0 ), r( 0 ) {}
    Change( int U, int L, int R ): u( U ), l( L ), r( R ) {}
};

typedef std :: pair<int, int> Edge;
typedef std :: pair<int, int> Range;

std :: map<Edge, int> ever;
std :: vector<int> upt[MAXN << 2];

LL ans[MAXN];

Change stk[MAXN << 1]; int top = 0;
int fa[MAXN << 1], lef[MAXN << 1], rig[MAXN << 1];
LL res = 0;

Edge edg[MAXN];
int lst[MAXN];

int Q, M;

int FindSet( int u ) { for( ; u ^ fa[u] ; u = fa[u] ); return u; }

void MakeSet( const int n ) {
    rep( i, 1, n ) fa[i] = i, lef[i] = 1, rig[i] = 0;
    rep( i, n + 1, n << 1 ) fa[i] = i, lef[i] = 0, rig[i] = 1;
}

void UnionSet( int u, int v ) {
    u = FindSet( u ), v = FindSet( v );
    if( u == v ) return ;
    res -= 1ll * lef[u] * rig[u];
    res -= 1ll * lef[v] * rig[v];
    if( lef[u] + rig[u] > lef[v] + rig[v] ) std :: swap( u, v );
    stk[++ top] = Change( u, lef[v], rig[v] );
    fa[u] = v, lef[v] += lef[u], rig[v] += rig[u];
    res += 1ll * lef[v] * rig[v];
}

void Withdraw( const int &but ) {
    for( ; top > but ; top -- ) {
        int u = stk[top].u, v = fa[u];
        res -= 1ll * lef[v] * rig[v];
        fa[u] = u, lef[v] = stk[top].l, rig[v] = stk[top].r;
        res += 1ll * lef[u] * rig[u];
        res += 1ll * lef[v] * rig[v];
    }
}

void HangUp( const int x, const int l, const int r, const int segL, const int segR, const int id ) {
    if( segL <= l && r <= segR ) { upt[x].push_back( id ); return ; }
    int mid = ( l + r ) >> 1;
    if( segL <= mid ) HangUp( x << 1, l, mid, segL, segR, id );
    if( mid  < segR ) HangUp( x << 1 | 1, mid + 1, r, segL, segR, id );
}

void Divide( const int x, const int l, const int r ) {
    int but = top;
    for( const int &e : upt[x] )
        UnionSet( edg[e].first, edg[e].second );
    if( l == r ) ans[l] = res;
    else {
        int mid = ( l + r ) >> 1;
        Divide( x << 1, l, mid );
        Divide( x << 1 | 1, mid + 1, r );
    }
    Withdraw( but );
}

int main() {
    read( Q );
    rep( i, 1, Q ) {
        int u, v;
        read( u ), read( v ), v += 3e5;
        if( ever.find( { u, v } ) == ever.end() )
            M ++, ever[edg[M] = { u, v }] = M, lst[M] = -1;
        int cur = ever[{ u, v }];
        if( lst[cur] == -1 ) lst[cur] = i;
        else HangUp( 1, 1, Q, lst[cur], i - 1, cur ), lst[cur] = -1;
    }
    rep( i, 1, M )
        if( ~ lst[i] )
            HangUp( 1, 1, Q, lst[i], Q, i );
    MakeSet( 3e5 );
    Divide( 1, 1, Q );
    rep( i, 1, Q ) write( ans[i] ), putchar( " \n"[i == Q] );
    return 0;
}