#include <bits/stdc++.h>

#define ll long long

const int N = 1e7 , MAX_N = N + 10 , mod = 1e9 + 7 ;

int T , n , m , f[MAX_N] , g[MAX_N] , h[MAX_N] , jc[MAX_N] , inv[MAX_N] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

inline int C(int n , int m) {
    if (n < m || m < 0) return 0 ;
    return (ll)jc[n] * inv[m] % mod * inv[n - m] % mod ;
}

int main() {
    jc[0] = 1 ;
    for (int i = 1 ; i <= N ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;
    inv[N] = qpow(jc[N] , mod - 2) ;
    for (int i = N - 1 ; i >= 0 ; --i) inv[i] = (ll)inv[i + 1] * (i + 1) % mod ;

    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &m) ;

        int t = n + m ;
        for (int i = 0 ; i <= t ; ++i) {
            f[i] = (ll)i * i % mod * C(n , i) % mod * C(m - 1 + i , m) % mod ;
            g[i] = (ll)i * C(n , i) % mod * C(m - 1 + i , m) % mod ;
            h[i] = (ll)C(n , i) * C(m - 1 + i , m) % mod ;
        }
        for (int i = 1 ; i <= t ; ++i)
            (f[i] += f[i - 1]) %= mod ,
            (g[i] += g[i - 1]) %= mod ,
            (h[i] += h[i - 1]) %= mod ;        

        int ny = qpow(n , mod - 2) , res = 0 ;
        for (int a = 0 ; a <= t ; ++a) {
            int t1 = (ll)ny * C(m , a) % mod , t2 = f[t - a] ;
            t2 = (t2 + (ll)(2 * a + 1) * g[t - a]) % mod ;
            t2 = (t2 + (ll)a * (a + 1) % mod * h[t - a]) % mod ;
            res = (res + (ll)t1 * t2) % mod ;
        }
        printf("%d\n" , res) ;
    }

    return 0 ;
}