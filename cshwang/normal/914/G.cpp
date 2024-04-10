#include <bits/stdc++.h>

#define ll long long
#define poly std::vector<int>

const int N = 17 , S = (1 << N) , MAX_N = N + 5 , MAX_S = S + 10 , mod = 1e9 + 7 ;

int n , a[MAX_S] , fib[MAX_S] ;
poly f[MAX_N] , tr[MAX_N] , r , g , h[2] ;

void FWT(poly &a , int ty) {
    for (int L = 2 ; L <= S ; L <<= 1)
        for (int hf = L >> 1 , i = 0 ; i < S ; i += L)
            for (int j = 0 ; j < hf ; ++j) {
                int x = a[i + j] , y = a[i + j + hf] ;
                if (!ty)
                    a[i + j] = (x + y) >= mod ? x + y - mod : x + y ,
                    a[i + j + hf] = (x - y) < 0 ? x - y + mod : x - y ;
                else if (ty == 1) a[i + j] = (x + y) >= mod ? x + y - mod : x + y ;
                else a[i + j + hf] = (x + y) >= mod ? x + y - mod : x + y ;
            }
}

void UFWT(poly &a , int ty) {
    ll ny = (mod + 1) >> 1 ;
    for (int L = 2 ; L <= S ; L <<= 1)
        for (int hf = L >> 1 , i = 0 ; i < S ; i += L)
            for (int j = 0 ; j < hf ; ++j) {
                int x = a[i + j] , y = a[i + j + hf] ;
                if (!ty)
                    a[i + j] = (x + y) * ny % mod ,
                    a[i + j + hf] = (x - y + mod) * ny % mod ;
                else if (ty == 1) a[i + j] = (x - y) < 0 ? x - y + mod : x - y ;
                else a[i + j + hf] = (y - x) < 0 ? y - x + mod : y - x ;
            }
}

int main() {
    scanf("%d" , &n) ;
    for (int i = 0 ; i < n ; ++i) {
        int v ; scanf("%d" , &v) ;
        ++a[v] ;
    }

    fib[0] = 0 ; fib[1] = 1 ;
    for (int i = 2 ; i < S ; ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % mod ;

    ///

    for (int i = 0 ; i <= N ; ++i) f[i].resize(S) , tr[i].resize(S) ;
    r.resize(S) ; g.resize(S) ; h[0].resize(S) ; h[1].resize(S) ;

    for (int i = 0 ; i <= N ; ++i)
        for (int j = 0 ; j < S ; ++j) {
            tr[i][j] = 0 ;
            if (__builtin_popcount(j) == i) f[i][j] = a[j] ;
            else f[i][j] = 0 ;
        }
    for (int i = 0 ; i < S ; ++i) g[i] = h[0][i] = h[1][i] = a[i] ;

    // part1
    for (int i = 0 ; i <= N ; ++i) FWT(f[i] , 2) ;
    for (int i = 0 ; i <= N ; ++i)
        for (int j = 0 ; j <= i ; ++j)
            for (int s = 0 ; s < S ; ++s) tr[i][s] = (tr[i][s] + (ll)f[j][s] * f[i - j][s]) % mod ;
    for (int i = 0 ; i <= N ; ++i) UFWT(tr[i] , 2) ;
    for (int s = 0 ; s < S ; ++s) r[s] = tr[__builtin_popcount(s)][s] ;

    // part3
    FWT(h[0] , 0) ; FWT(h[1] , 0) ;
    for (int s = 0 ; s < S ; ++s) h[0][s] = (ll)h[0][s] * h[1][s] % mod ;
    UFWT(h[0] , 0) ;

    for (int s = 0 ; s < S ; ++s) {
        r[s] = (ll)r[s] * fib[s] % mod ;
        g[s] = (ll)g[s] * fib[s] % mod ;
        h[0][s] = (ll)h[0][s] * fib[s] % mod ;
    }
    FWT(r , 1) ; FWT(g , 1) ; FWT(h[0] , 1) ;
    for (int s = 0 ; s < S ; ++s) r[s] = (ll)r[s] * g[s] % mod * h[0][s] % mod ;
    UFWT(r , 1) ;

    int ans = 0 ;
    for (int s = 1 ; s < S ; s <<= 1) (ans += r[s]) %= mod ;
    printf("%d\n" , ans) ;

    return 0 ;
}