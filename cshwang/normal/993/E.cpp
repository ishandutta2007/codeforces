#include <bits/stdc++.h>

#define ll long long
#define i128 __int128

const int MAX_N = 1e6 + 10 ;
const ll mod = 31525197391593473ll ;

int n , x , ntt_n , rev[MAX_N] ;
ll f[MAX_N] , g[MAX_N] , omega[MAX_N] , omega_inv[MAX_N] ;

ll mul(ll a , ll b) {
    return (i128)a * (i128)b % mod ;
}

ll qpow(ll a , ll t) {
    ll s = 1 ;
    for (; t ; t >>= 1 , a = mul(a , a))
        if (t & 1) s = mul(s , a) ;
    return s ;
}

void NTT_init(int n) {
    ntt_n = n ;
    ll wn = qpow(3 , (mod - 1) / n) ;
    omega[0] = omega_inv[0] = 1 ;
    for (int i = 1 ; i < n ; ++i)
        omega_inv[n - i] = omega[i] = mul(omega[i - 1] , wn) ;
}

void NTT(ll *f , int n , int ty) {
    for (int i = 0 ; i < n ; ++i) if (i < rev[i]) std::swap(f[i] , f[rev[i]]) ;

    for (int L = 2 , m = ntt_n >> 1 ; L <= n ; L <<= 1 , m >>= 1)
        for (int i = 0 ; i < n ; i += L) {
            int hf = L >> 1 ;
            for (int j = 0 ; j < hf ; ++j) {
                ll w = (ty > 0 ? omega : omega_inv)[m * j] ;
                ll u = f[i + j] , v = mul(w , f[i + j + hf]) ;
                f[i + j] = u + v > mod ? u + v - mod : u + v ;
                f[i + j + hf] = u - v < 0 ? u - v + mod : u - v ;
            }
        }
    
    if (ty < 0) {
        ll inv = qpow(n , mod - 2) ;
        for (int i = 0 ; i < n ; ++i) f[i] = mul(f[i] , inv) ;
    }
}

int main() {
    scanf("%d %d" , &n , &x) ;

    f[0] = 1 ; g[n] = 1 ;
    int tot = 0 ;
    for (int i = 0 ; i < n ; ++i) {
        int v ; scanf("%d" , &v) ;
        if (v < x) ++tot ;

        ++f[tot] ; ++g[n - tot] ;
    }

    ///

    int N = 1 , L = 0 ;
    for (; N <= (n << 1) ; N <<= 1 , ++L) ;
    for (int i = 1 ; i < N ; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1)) ;

    NTT_init(N) ;
    NTT(f , N , 1) ; NTT(g , N , 1) ;
    for (int i = 0 ; i < N ; ++i) f[i] = mul(f[i] , g[i]) ;
    NTT(f , N , -1) ;

    f[n] = (f[n] - n - 1) >> 1 ;
    for (int i = n ; i <= (n << 1) ; ++i) printf("%lld " , f[i]) ;
    printf("\n") ;

    return 0 ;
}