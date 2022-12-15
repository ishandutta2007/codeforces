#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 2e5 + 10 , mod = 998244353 ;

int n , k , jc[MAX_N] , inv[MAX_N] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

int C(int n , int m) {
    return (ll)jc[n] * inv[m] % mod * inv[n - m] % mod ;
}

int main() {
    scanf("%d %d" , &n , &k) ;
    if (k >= n) {printf("0\n") ; return 0 ;}

    jc[0] = 1 ;
    for (int i = 1 ; i <= n ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;
    inv[n] = qpow(jc[n] , mod - 2) ;
    for (int i = n - 1 ; i >= 0 ; --i) inv[i] = (ll)inv[i + 1] * (i + 1) % mod ;

    if (!k) printf("%d\n" , jc[n]) ;
    else {
        int c = n - k , res = 0 ;
        for (int i = 1 ; i <= c ; ++i) {
            int tmp = C(c , i) ;
            tmp = (ll)tmp * qpow(i , n) % mod ;
            if ((c - i) & 1) tmp = mod - tmp ;
            (res += tmp) %= mod ;
        }

        res = (((ll)res * C(n , k) % mod) << 1) % mod ;
        printf("%d\n" , res) ;
    }

    return 0 ;
}