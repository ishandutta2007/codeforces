#include <bits/stdc++.h>

#define ll long long

const int N = 2e3 , MAX_N = 2e3 + 10 , mod = 1e9 + 7 ;

int T , n , m , k , f[MAX_N][MAX_N] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    
    return s ;
}

int main() {
    f[0][0] = 0 ;
    for (int i = 1 ; i <= N ; ++i) f[i][0] = i , f[i][i] = 0 ;

    int ny = qpow(2 , mod - 2) ;
    for (int i = 1 ; i <= N ; ++i)
        for (int j = 1 ; j < i ; ++j) f[i][j] = ((ll)f[i - 1][j] + f[i - 1][j - 1]) * ny % mod ;

    ///
    
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d %d" , &n , &m , &k) ;
        printf("%lld\n" , (ll)f[n][n - m] * k % mod) ;
    }

    return 0 ;
}