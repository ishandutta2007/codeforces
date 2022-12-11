#include <cstdio>
#include <vector>
#include <algorithm>

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

char str[MAXN];

std :: vector<LL> pref[MAXN];
std :: vector<int> que[MAXN], bnd[MAXN];

int stk[MAXN], siz[MAXN], top;

LL ans[MAXN];
int qL[MAXN];

int N, Q;

#define S( x ) 1ll * (x) * ( (x) + 1 ) / 2

int main() {
    read( N ), read( Q );
    scanf( "%s", str + 1 );
    rep( i, 1, Q ) {
        int t, r;
        read( t ), read( qL[i] ), read( r );
        que[r].push_back( i );
    }
    bnd[0].push_back( 0 );
    pref[0].push_back( 0 );
    rep( i, 1, N ) {
        if( str[i] == '(' ) {
            siz[++ top] = 0; 
            bnd[top].clear();
            bnd[top].push_back( i - 1 );
            pref[top].clear();
            pref[top].push_back( 0 );
        }
        else {
            if( ! top ) {
                siz[top] = 0;
                bnd[top].clear();
                bnd[top].push_back( i );
                pref[top].clear();
                pref[top].push_back( 0 );
                continue;
            }
            LL tmp = pref[top].back() + S( siz[top] );
            top --, siz[top] ++, bnd[top].push_back( i );
            pref[top].push_back( pref[top].back() + tmp );
        }
        for( int j = 0 ; j < ( int ) que[i].size() ; j ++ ) {
            int cur = que[i][j], l = qL[cur];
            int idx = std :: upper_bound( bnd[top].begin(), bnd[top].end(), l ) - bnd[top].begin() - 1;
            ans[cur] = pref[top].back() - pref[top][idx] + S( siz[top] - idx );
        }
    }
    rep( i, 1, Q ) write( ans[i] ), putchar( '\n' );
    return 0;
}