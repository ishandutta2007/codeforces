#include <bits/stdc++.h>

typedef long long ll ;

const int N = 20 , MAX_N = (1 << N) + 10 , mod = 1e9 + 7 ;

int n , f[MAX_N] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

int main() {
    scanf("%d" , &n) ;
    for (int i = 0 ; i < n ; ++i) {
        int v ; scanf("%d" , &v) ;
        ++f[v] ;
    }

    ///

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < (1 << N) ; ++j)
            if (!(j >> i & 1)) f[j] += f[j + (1 << i)] ;
    for (int i = 0 ; i < (1 << N) ; ++i) f[i] = (qpow(2 , f[i]) + mod - 1) % mod ;

    int ans = 0 ;
    for (int i = 0 ; i < (1 << N) ; ++i)
        if (__builtin_popcount(i) & 1) ans = (ans + mod - f[i]) % mod ;
        else ans = (ans + f[i]) % mod ;
    printf("%d\n" , ans) ;
    
    return 0 ;
}