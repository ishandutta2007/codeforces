#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 250 + 10 , mod = 998244353 ;

int n , k , f[MAX_N][MAX_N][MAX_N] , g[MAX_N][MAX_N] ;

inline int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    
    return s ;
}

int main() {
    scanf("%d %d" , &n , &k) ;
    for (int i = 1 ; i <= k ; ++i) f[1][i][1] = 1 , g[1][i] = 1 ;
    for (int i = 2 ; i < n ; ++i) {
        int sum = 0 ;
        for (int j = 1 ; j <= k ; ++j) {
            f[i][j][1] = (ll)sum * qpow(k - j + 1 , i - 1) % mod ;
            for (int p = 2 ; p <= i ; ++p)
                f[i][j][p] = (ll)f[i - 1][j][p - 1] * qpow(k - j + 1 , i - 1) % mod * qpow(p , mod - 2) % mod ;
            
            g[i][j] = 0 ;
            for (int p = 1 ; p <= i ; ++p) (g[i][j] += f[i][j][p]) %= mod ;
            (sum += g[i - 1][j]) %= mod ;
        }
    }

    int res = 0 ;
    for (int i = 1 ; i <= k ; ++i) (res += g[n - 1][i]) %= mod ;
    for (int i = 1 ; i < n ; ++i) res = (ll)res * i % mod ;
    printf("%d\n" , res) ;

    return 0 ;
}