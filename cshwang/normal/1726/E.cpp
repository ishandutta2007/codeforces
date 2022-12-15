#include <bits/stdc++.h>

#define ll long long

const int N = 3e5 , MAX_N = N + 10 , mod = 998244353 ;

int T , n , f[MAX_N] , jc[MAX_N] , inv[MAX_N] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

int C(int n , int m) {return (ll)jc[n] * inv[m] % mod * inv[n - m] % mod ;}

int main() {
    jc[0] = 1 ;
    for (int i = 1 ; i <= N ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;
    inv[N] = qpow(jc[N] , mod - 2) ;
    for (int i = N - 1 ; i >= 0 ; --i) inv[i] = (ll)inv[i + 1] * (i + 1) % mod ;

    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        f[0] = 1 ; f[1] = 1 ; f[2] = 2 ;
        for (int i = 3 ; i <= n ; ++i) f[i] = (f[i - 1] + (ll)f[i - 2] * (i - 1)) % mod ;

        ///
        
        int ans = 0 ;
        for (int i = 0 ; i <= n ; i += 4) {
            int j = i >> 2 , r = f[n - i] ;
            r = (ll)r * C(n - (j << 1) , j << 1) % mod * C((j << 1) , j) % mod * jc[j] % mod ;
            (ans += r) %= mod ;
        }
        printf("%d\n" , ans) ;
    }

    return 0 ;
}