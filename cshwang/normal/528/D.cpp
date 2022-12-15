#include <bits/stdc++.h>

#define ll long long
#define poly std::vector<int>
#define ull unsigned long long

const int MAX_N = 2e5 + 10 , FFTN = 1 << 20 , mod = 998244353 ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

namespace FFT {
    int w[FFTN + 5] , W[FFTN + 5] , R[FFTN + 5] ;
    void FFTinit() {
        W[0] = 1 ;
        W[1] = qpow(3 , (mod - 1) / FFTN) ;
        for (int i = 2 ; i <= FFTN ; ++i) W[i] = 1ll * W[i - 1] * W[1] % mod ;
    }
    int FFTinit(int n) {
        int L = 1 ;
        for (; L <= n ; L <<= 1) ;
        for (int i = 0 ; i <= L - 1 ; ++i) R[i] = (R[i >> 1] >> 1) | ((i & 1) ? (L >> 1) : 0) ;
        return L ;
    }

    ull p[FFTN + 5] ;
    int A[FFTN + 5] , B[FFTN + 5] ;
    void DFT(int *a , int n) {
        for (int i = 0 ; i < n ; ++i) p[R[i]] = a[i] ;
        for (int d = 1 ; d < n ; d <<= 1) {
            int len = FFTN / (d << 1) ;
            for (int i = 0 , j = 0 ; i < d ; ++i , j += len) w[i] = W[j] ;
            for (int i = 0 ; i < n ; i += (d << 1))
                for (int j = 0 ; j < d ; ++j) {
                    int y = p[i + j + d] * w[j] % mod ;
                    p[i + j + d] = p[i + j] + mod - y ;
                    p[i + j] += y ;
                }
            if (d == (1 << 15))
                for (int i = 0 ; i < n ; ++i) p[i] %= mod ;
        }
        for (int i = 0 ; i < n ; ++i) a[i] = p[i] % mod ;
    }
    void IDFT(int *a , int n) {
        for (int i = 0 ; i < n ; ++i) p[R[i]] = a[i] ;
        for (int d = 1 ; d < n ; d <<= 1) {
            int len = FFTN / (d << 1) ;
            for (int i = 0 , j = FFTN ; i < d ; ++i , j -= len) w[i] = W[j] ;
            for (int i = 0 ; i < n ; i += (d << 1))
                for (int j = 0 ; j < d ; ++j) {
                    int y = p[i + j + d] * w[j] % mod ;
                    p[i + j + d] = p[i + j] + mod - y ;
                    p[i + j] += y ;
                }
            if (d == (1 << 15))
                for (int i = 0 ; i < n ; ++i) p[i] %= mod ;
        }
        int val = qpow(n , mod - 2) ;
        for (int i = 0 ; i < n ; ++i) a[i] = p[i] * val % mod ;
    }
    poly Plus(const poly &a , const poly &b) {
        int sza = a.size() - 1 , szb = b.size() - 1 ;
        poly ans(std::max(sza , szb) + 1) ;
        for (int i = 0 ; i <= sza ; ++i) ans[i] = a[i] ;
        for (int i = 0 ; i <= szb ; ++i) ans[i] = (ans[i] + b[i]) % mod ;
        return ans ;
    }
    poly Minus(const poly &a , const poly &b) {
        int sza = a.size() - 1 , szb = b.size() - 1 ;
        poly ans(std::max(sza , szb) + 1) ;
        for (int i = 0 ; i <= sza ; ++i) ans[i] = a[i] ;
        for (int i = 0 ; i <= szb ; ++i) ans[i] = (ans[i] + mod - b[i]) % mod ;
        return ans ;
    }
    poly Mul(const poly &a , const poly &b) {
        int sza = a.size() - 1 , szb = b.size() - 1 ;
        poly ans(sza + szb + 1) ;
        if (sza <= 30 || szb <= 30) {
            for (int i = 0 ; i <= sza ; ++i)
                for (int j = 0 ; j <= szb ; ++j)
                    ans[i + j] = (ans[i + j] + 1ll * a[i] * b[j]) % mod ;
            return ans ;
        }
        int L = FFTinit(sza + szb) ;
        for (int i = 0 ; i < L ; ++i) A[i] = (i <= sza ? a[i] : 0) ;
        for (int i = 0 ; i < L ; ++i) B[i] = (i <= szb ? b[i] : 0) ;
        DFT(A , L) , DFT(B , L) ;
        for (int i = 0 ; i < L ; ++i) A[i] = 1ll * A[i] * B[i] % mod ;
        IDFT(A , L) ;
        for (int i = 0 ; i <= sza + szb ; ++i) ans[i] = A[i] ;

        return ans ;
    }
} ;

int n , m , k , r[MAX_N] ;
char s[MAX_N] , t[MAX_N] ;

void work(char c) {
    poly f(n) , g(n) ;
    int prev = -1 - k ;
    for (int i = 0 ; i < n ; ++i) f[i] = 2 ;
    for (int i = 0 ; i < n ; ++i)
        if (s[i] == c) prev = i , f[i] = 1 ;
        else if (i - prev <= k) f[i] = 1 ;
    int nxt = n + k ;
    for (int i = n - 1 ; i >= 0 ; --i)
        if (s[i] == c) nxt = i , f[i] = 1 ;
        else if (nxt - i <= k) f[i] = 1 ;
    
    ///

    for (int i = 0 ; i < m ; ++i)
        if (t[i] == c) g[i] = 1 ;
        else g[i] = 0 ;
    for (int i = m ; i < n ; ++i) g[i] = 0 ;
    std::reverse(g.begin() + 0 , g.begin() + m) ;

    poly h(n) ; h[0] = g[0] ;
    for (int i = 1 ; i < n ; ++i) h[i] = h[i - 1] + g[i] ;

    f = FFT::Mul(f , g) ;
    for (int i = m - 1 ; i < n ; ++i)
        if (f[i] - h[i]) r[i] = 0 ;
}

int main() {
    FFT::FFTinit() ;
    scanf("%d %d %d" , &n , &m , &k) ;
    scanf("%s %s" , s , t) ;

    char ch[4] = {'A' , 'G' , 'C' , 'T'} ;
    for (int i = m - 1 ; i < n ; ++i) r[i] = 1 ;
    for (auto &c : ch) work(c) ;

    int ans = 0 ;
    for (int i = 0 ; i < n ; ++i) ans += r[i] ;
    printf("%d\n" , ans) ;

    return 0 ;
}