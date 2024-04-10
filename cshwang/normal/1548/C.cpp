#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 3e6 + 10 , mod = 1e9 + 7 ;

int n , m , q , jc[MAX_N] , inv[MAX_N] , f[MAX_N][3] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

inline int C(int x , int y) {
    return (ll)jc[x] * inv[y] % mod * inv[x - y] % mod ;
}

int main() {
    scanf("%d %d" , &n , &q) ;
    m = n * 3 ;

    ///

    jc[0] = 1 ;
    for (int i = 1 ; i <= m + 1 ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;
    inv[m + 1] = qpow(jc[m + 1] , mod - 2) ;
    for (int i = m ; i >= 0 ; --i) inv[i] = (ll)inv[i + 1] * (i + 1) % mod ;

    f[0][0] = n + 1 ; f[0][1] = n ;
    int ny2 = qpow(2 , mod - 2) , ny3 = qpow(3 , mod - 2) ;
    for (int i = 1 ; i <= m ; ++i) {
        int tot = C(m + 1 , i + 1) , pretot = C(m + 1 , i) ;
        int c0 = ((ll)tot + pretot - f[i - 1][0] - f[i - 1][1] + (mod << 1)) % mod ,
            c1 = ((f[i - 1][0] - pretot + mod) % mod * 2) % mod ;
        int a1 = (ll)(c0 + c1) % mod * ny3 % mod ,
            a0 = (ll)(c0 - a1 + mod) % mod * ny2 % mod ;
        f[i][0] = a0 ; f[i][1] = a1 ;
    }

    ///

    for (; q-- ;) {
        int x ; scanf("%d" , &x) ;
        printf("%d\n" , f[x][0]) ;
    }

    return 0 ;
}