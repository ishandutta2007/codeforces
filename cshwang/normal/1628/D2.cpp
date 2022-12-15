#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e6 + 10 , mod = 1e9 + 7 ;

int T , n , m , k , jc[MAX_N] , inv[MAX_N] , ny2[MAX_N] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

void init() {
    int N = 1e6 ;
    jc[0] = 1 ;
    ny2[0] = 1 ; ny2[1] = (mod + 1) >> 1 ;

    for (int i = 1 ; i <= N ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;
    for (int i = 2 ; i <= N ; ++i) ny2[i] = (ll)ny2[i - 1] * ny2[1] % mod ;
    inv[N] = qpow(jc[N] , mod - 2) ;
    for (int i = N - 1 ; i >= 0 ; --i) inv[i] = (ll)inv[i + 1] * (i + 1) % mod ;
}

inline int C(int n , int m) {
    return (ll)jc[n] * inv[m] % mod * inv[n - m] % mod ;
}

int main() {
    init() ;
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d %d" , &n , &m , &k) ;

        int prev = 0 , ans = 0 ;
        for (int i = m ; i >= 1 ; --i) {
            int r = C(n - i , m - i) ;
            r = (r - prev + mod) % mod ; prev = C(n - i , m - i) ;
            r = (ll)r * ny2[n - i] % mod * i % mod ;
            (ans += r) %= mod ;
        }
        ans = (ll)ans * k % mod ;
        printf("%d\n" , ans) ;
    }

    return 0 ;
}