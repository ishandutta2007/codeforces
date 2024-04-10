#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 20 + 5 , MAX_M = 1e5 + 10 , MAX_S = (1 << 20) + 10 , mod = 998244353 ;

char s[MAX_N][MAX_M] ;
int N , n , m , f[MAX_S] , g[MAX_S] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

void DFT(int *F , int P = mod) {
    for (int L = 2 ; L <= N ; L <<= 1)
        for (int i = 0 ; i < N ; i += L) {
            int hf = L >> 1 ;
            for (int j = 0 ; j < hf ; ++j) {
                int t1 = F[i + j] + F[i + j + hf] , t2 = F[i + j] - F[i + j + hf] ;
                if (t1 >= P) t1 -= P ;
                if (t2 < 0) t2 += P ;

                F[i + j] = t1 ; F[i + j + hf] = t2 ;
            }
        }
}

void IDFT(int *F , int P = mod) {
    int ny = qpow(2 , P - 2) ;
    for (int L = 2 ; L <= N ; L <<= 1)
        for (int i = 0 ; i < N ; i += L) {
            int hf = L >> 1 ;
            for (int j = 0 ; j < hf ; ++j) {
                int t1 = F[i + j] + F[i + j + hf] , t2 = F[i + j] - F[i + j + hf] ;
                if (t1 >= P) t1 -= P ;
                if (t2 < 0) t2 += P ;

                F[i + j] = (ll)t1 * ny % P ; F[i + j + hf] = (ll)t2 * ny % P ;
            }
        }
}

int main() {
    scanf("%d %d" , &n , &m) ; N = (1 << n) ;
    for (int i = 0 ; i < n ; ++i) scanf("%s" , s[i]) ;
    for (int j = 0 ; j < m ; ++j) {
        int sum = 0 ;
        for (int i = 0 ; i < n ; ++i) if (s[i][j] == '1') sum += (1 << i) ;
        ++f[sum] ;
    }
    for (int i = 0 ; i < N ; ++i) {
        int c = __builtin_popcount(i) ;
        g[i] = std::min(n - c , c) ;
    }

    DFT(f) ; DFT(g) ;
    for (int i = 0 ; i < N ; ++i) f[i] = (ll)f[i] * g[i] % mod ;
    IDFT(f) ;

    int r = f[0] ;
    for (int i = 1 ; i < N ; ++i) r = std::min(r , f[i]) ;
    printf("%d\n" , r) ;
    
    return 0 ;
}