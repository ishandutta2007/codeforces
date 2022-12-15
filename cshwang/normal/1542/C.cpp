#include <bits/stdc++.h>

#define ll long long

const int mod = 1e9 + 7 ;

ll n ;
int T ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%lld" , &n) ;
        ll num = 1 , tot = n , r = 0 ;
        for (ll x = 2 ; ; ++x) {
            ll d = std::__gcd(num , x) , siz = tot / (x / d) ;
            r = (r + ((tot - siz) % mod) * x % mod) % mod ;

            tot = siz ; num = num / d * x ;
            if (!tot) break ;
        }
        printf("%lld\n" , r) ;
    }

    return 0 ;
}