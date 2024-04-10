#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 1e5 + 5;

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

std :: vector<int> dvsr[MAXN];

int stk[MAXN], top;
int cnt[MAXN];

int mu[MAXN];
int prime[MAXN], pn;
bool isPrime[MAXN];

int A[MAXN], B[MAXN];
bool app[MAXN];

int N, M, L;

inline int Gcd( int x, int y ) { for( int z ; y ; z = x, x = y, y = z % y ); return x; }
inline LL Lcm( const int &x, const int &y ) { return 1ll * x / Gcd( x, y ) * y; }

inline void EulerSieve( const int &n ) {
    mu[1] = 1;
    for( int i = 2 ; i <= n ; i ++ ) {
        if( ! isPrime[i] ) 
            mu[prime[++ pn] = i] = -1;
        for( int j = 1 ; j <= pn && 1ll * i * prime[j] <= n ; j ++ ) {
            isPrime[i * prime[j]] = true;
            if( ! ( i % prime[j] ) ) break;
            mu[i * prime[j]] = - mu[i];
        }
    }
}

void Init() {
    EulerSieve( M );
    for( int d = 1 ; d <= M ; d ++ )
        for( int k = d ; k <= M ; k += d )
            dvsr[k].push_back( d );
}

inline int Calc( const int &x ) {
    int ret = 0;
    for( const int &d : dvsr[x] )
        ret += mu[d] * cnt[d];
    return ret;
}

inline void Modify( const int &x, const int &delt ) {
    for( const int &d : dvsr[x] ) cnt[d] += delt;
}

int main() {
    Read( N );
    rep( i, 1, N ) 
        Read( A[i] ), M = std :: max( M, A[i] );
    Init();
    rep( i, 1, N )
        for( const int &x : dvsr[A[i]] ) {
            if( ! app[x] ) B[++ L] = x;
            app[x] = true;
        }
    LL ans = M;
    std :: sort( B + 1, B + 1 + L );
    per( i, L, 1 ) {
        int x = B[i], d;
        while( ( d = Calc( x ) ) > 1 || ( d == 1 && Gcd( x, stk[top] ) > 1 ) ) {
            int z = stk[top --];
            Modify( z, -1 ), ans = std :: max( ans, Lcm( x, z ) );
        }
        if( top ) ans = std :: max( ans, Lcm( x, stk[top] ) );
        stk[++ top] = x, Modify( x, +1 );
    }
    Write( ans ), putchar( '\n' );
    return 0;
}