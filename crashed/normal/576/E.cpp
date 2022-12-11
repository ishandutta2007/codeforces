#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXK = 55, MAXN = 5e5 + 5;

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

typedef std :: pair<int, int> Insertion;
typedef std :: pair<int, int> UniChange;
typedef std :: pair<int, std :: pair<int, int> > Change;

Change stk[MAXN << 1]; int top;

struct UFS {
    std :: vector<int> fa, wei, siz;

    void MakeSet( const int n ) {
        fa.resize( n ), siz.resize( n ), wei.resize( n );
        rep( i, 0, n - 1 ) fa[i] = i, siz[i] = 1, wei[i] = 0;
    }

    int FindSet( int u ) {
        for( ; u ^ fa[u] ; u = fa[u] );
        return u;
    }

    int GetWei( int u ) {
        int ret = 0;
        for( ; u ^ fa[u] ; ret ^= wei[u], u = fa[u] );
        return ret;
    }

    inline bool Chk( const int &u, const int &v ) {
        if( FindSet( u ) ^ FindSet( v ) ) return true;
        return GetWei( u ) ^ GetWei( v );
    }

    inline UniChange UnionSet( int u, int v ) {
        int rtU = FindSet( u ), rtV = FindSet( v );
        if( rtU == rtV ) return UniChange( -1, -1 );
        if( siz[rtU] > siz[rtV] ) 
            std :: swap( u, v ), std :: swap( rtU, rtV );
        UniChange ret( rtU, siz[rtV] );
        fa[rtU] = rtV, siz[rtV] += siz[rtU];
        wei[rtU] = GetWei( u ) ^ GetWei( v ) ^ 1;
        return ret;
    }
};

UFS ufs[MAXK];

std :: vector<int> brk[MAXN];
std :: vector<int> asso[MAXK];
std :: vector<Insertion> upt[MAXN << 2];

int optE[MAXN], optC[MAXN], idx[MAXN];
int edgU[MAXN], edgV[MAXN], old[MAXN];

int N, M, K, Q;

void HangUp( const int x, const int l, const int r, const int segL, const int segR, const Insertion nw ) {
    if( segL <= l && r <= segR ) { upt[x].push_back( nw ); return ; }
    int mid = ( l + r ) >> 1;
    if( segL <= mid ) HangUp( x << 1, l, mid, segL, segR, nw );
    if( mid  < segR ) HangUp( x << 1 | 1, mid + 1, r, segL, segR, nw );
}

bool TryInsert( const int col, const int id, const bool ins = true ) {
    int u = std :: lower_bound( asso[col].begin(), asso[col].end(), edgU[id] ) - asso[col].begin();
    int v = std :: lower_bound( asso[col].begin(), asso[col].end(), edgV[id] ) - asso[col].begin();
    if( ! ufs[col].Chk( u, v ) ) return false;
    if( ins ) {
        UniChange tmp = ufs[col].UnionSet( u, v );
        if( ~ tmp.first ) stk[++ top] = { col, tmp };
    }
    return true;
}

void ProcessUnit( const int id, const bool abv ) {
    int l = brk[optE[id]][idx[id]], r = brk[optE[id]][idx[id] + 1];
    bool flg = abv && TryInsert( optC[id], optE[id], false );
    puts( flg ? "YES" : "NO" );
    if( flg ) old[optE[id]] = optC[id];
    if( old[optE[id]] && l + 1 <= r - 1 ) 
        HangUp( 1, 1, Q, l + 1, r - 1, Insertion( old[optE[id]], optE[id] ) );
}

void Divide( const int x, const int l, const int r ) {
    int but = top; bool flg = true;
    for( const Insertion &e : upt[x] )
        if( ! TryInsert( e.first, e.second ) ) {
            flg = false; break;
        }
    if( ! flg ) {
        rep( i, l, r ) 
            ProcessUnit( i, false );
    } else if( l == r ) 
        ProcessUnit( l, true );
    else {
        int mid = ( l + r ) >> 1;
        Divide( x << 1, l, mid );
        Divide( x << 1 | 1, mid + 1, r );
    }
    for( ; top > but ; top -- ) {
        int c = stk[top].first, u = stk[top].second.first;
        ufs[c].siz[ufs[c].fa[u]] = stk[top].second.second;
        ufs[c].fa[u] = u, ufs[c].wei[u] = 0;
    }
}

int main() {
    read( N ), read( M ), read( K ), read( Q );
    rep( i, 1, M ) read( edgU[i] ), read( edgV[i] ), old[i] = 0;
    rep( i, 1, Q ) {
        read( optE[i] ), read( optC[i] );
        asso[optC[i]].push_back( edgU[optE[i]] );
        asso[optC[i]].push_back( edgV[optE[i]] );
        idx[i] = brk[optE[i]].size();
        brk[optE[i]].push_back( i );
    }
    rep( i, 1, M ) brk[i].push_back( Q + 1 );
    rep( i, 1, K ) {
        std :: sort( asso[i].begin(), asso[i].end() );
        asso[i].erase( std :: unique( asso[i].begin(), asso[i].end() ), asso[i].end() );
        ufs[i].MakeSet( asso[i].size() );
    }
    Divide( 1, 1, Q );
    return 0;
}