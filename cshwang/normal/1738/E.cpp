#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 2e5 + 10 , mod = 998244353 ;

ll s1[MAX_N] , s2[MAX_N] ;
int T , n , a[MAX_N] , jc[MAX_N] , inv[MAX_N] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

int main() {
    int N = 2e5 ;
    jc[0] = 1 ;
    for (int i = 1 ; i <= N ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;
    inv[N] = qpow(jc[N] , mod - 2) ;
    for (int i = N - 1 ; i >= 0 ; --i) inv[i] = (ll)inv[i + 1] * (i + 1) % mod ;

    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
        s1[0] = s2[n + 1] = 0 ;
        for (int i = 1 ; i <= n ; ++i) s1[i] = s1[i - 1] + a[i] ;
        for (int i = n ; i ; --i) s2[i] = s2[i + 1] + a[i] ;

        int p1 = 1 , p2 = n , res = 1 ;
        for (; p1 < p2 ;) {
            if (s1[p1] < s2[p2]) ++p1 ;
            else if (s1[p1] > s2[p2]) --p2 ;
            else {
                int c1 = 1 , c2 = 1 ;
                for (; p1 < n && s1[p1] == s1[p1 + 1] ; ++p1 , ++c1) ;
                for (; p2 > 1 && s2[p2] == s2[p2 - 1] ; --p2 , ++c2) ;

                if (p1 >= p2) {
                    if (s1[p1]) res = (ll)res * qpow(2 , c1) % mod ;
                    else res = (ll)res * qpow(2 , c1 - 1) % mod ;
                }
                else res = (ll)res * jc[c1 + c2] % mod * inv[c1] % mod * inv[c2] % mod ;
                ++p1 ; --p2 ;
            }
        }
        printf("%d\n" , res) ;
    }

    return 0 ;
}