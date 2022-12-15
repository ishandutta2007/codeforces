#include <bits/stdc++.h>

#define ll long long
#define g(i , j) g[i][j + n + 1]

const int MAX_N = 500 + 10 , mod = 998244353 ;

int n , a[MAX_N] , f[2][MAX_N] , g[2][MAX_N << 1] ;

int work(int p , int x) {
    f[0][0] = 1 ;
    for (int i = 1 ; i <= n ; ++i) f[0][i] = 0 ;
    int o1 = 1 ;
    for (int i = 1 ; i < p ; ++i , o1 ^= 1) {
        for (int j = 0 ; j <= n ; ++j) f[o1][j] = f[o1 ^ 1][j] ;
        if (a[i] == -1) {
            (f[o1][0] += f[o1 ^ 1][0]) %= mod ;
            for (int j = 0 ; j <= n ; ++j) (f[o1][j] += f[o1 ^ 1][j + 1]) %= mod ;
        }
        else if (a[i] <= x) {
            for (int j = 1 ; j <= n ; ++j) (f[o1][j] += f[o1 ^ 1][j - 1]) %= mod ;
        }
        else {
            for (int j = 0 ; j <= n ; ++j) (f[o1][j] <<= 1) %= mod ;
        }
    }
    o1 ^= 1 ;

    ///

    for (int i = -n ; i <= n ; ++i) g(0 , i) = 0 ;
    g(0 , 0) = 1 ; int o2 = 1 ;
    for (int i = n ; i > p ; --i , o2 ^= 1) {
        for (int j = -n ; j <= n ; ++j) g(o2 , j) = g(o2 ^ 1 , j) ;
        if (a[i] == -1) {
            for (int j = -n ; j <= n ; ++j) {
                int st = std::min(j - 1 , -1) ;
                if (st >= -n) (g(o2 , st) += g(o2 ^ 1 , j)) %= mod ;
            }
        }
        else if (a[i] < x) {
            for (int j = -n ; j <= n ; ++j) (g(o2 , j) += g(o2 ^ 1 , j - 1)) %= mod ;
        }
        else {
            for (int j = -n ; j <= n ; ++j) (g(o2 , j) <<= 1) %= mod ;
        }
    }
    o2 ^= 1 ;

    int sum = 0 ;
    for (int i = 0 ; i <= n ; ++i)
        for (int j = -i ; j <= n ; ++j) {
            int tmp = (ll)f[o1][i] * g(o2 , j) % mod ;
            (sum += tmp) %= mod ;
        }
    sum = (ll)sum * x % mod ;
    return sum ;
}

int main() {
    scanf("%d" , &n) ; int cnt = 0 ;
    for (int i = 1 ; i <= n ; ++i) {
        getchar() ; char op ;
        scanf("%c" , &op) ;
        if (op == '-') a[i] = -1 , ++cnt ;
        else scanf("%d" , &a[i]) ;
    }

    int ans = 0 ;
    for (int i = 1 ; i <= n ; ++i)
        if (a[i] != -1) (ans += work(i , a[i])) %= mod ;
    printf("%d\n" , ans) ;

    return 0 ;
}