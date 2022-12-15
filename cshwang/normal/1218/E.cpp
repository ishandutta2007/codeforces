#include <bits/stdc++.h>

#define ll long long
#define poly std::vector<int>
#define ull unsigned long long

const int FFTN = 1 << 22 , mod = 998244353 ;

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

const int MAX_N = 2e4 + 10 ;

poly f[MAX_N] ;
int n , k , a[MAX_N] , b[MAX_N] ;

void work(int x , int y) {
    if (x > y) return ;
    if (x == y) {
        f[x].resize(2) ;
        f[x][0] = 1 ; f[x][1] = b[x] ;
        return ;
    }

    int mid = (x + y) >> 1 ;
    work(x , mid) ; work(mid + 1 , y) ;
    f[x] = FFT::Mul(f[x] , f[mid + 1]) ;
}

int main() {
    FFT::FFTinit() ;
    scanf("%d %d" , &n , &k) ;
    for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

    int q ; scanf("%d" , &q) ;
    for (; q-- ;) {
        int ty , q , x , y ;
        scanf("%d %d %d %d" , &ty , &q , &x , &y) ;
        for (int i = 1 ; i <= n ; ++i) b[i] = a[i] ;
        if (ty == 1) b[x] = y % mod ;
        else {
            int d ; scanf("%d" , &d) ;
            for (int i = x ; i <= y ; ++i) (b[i] += d) %= mod ;
        }

        for (int i = 1 ; i <= n ; ++i) b[i] = (q - b[i] + mod) % mod ;
        work(1 , n) ;
        printf("%d\n" , f[1][k]) ;
    }

    return 0 ;
}