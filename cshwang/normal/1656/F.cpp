#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 2e5 + 10 ;

int T , n ;
ll a[MAX_N] , s[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 0 ; i < n ; ++i) scanf("%lld" , &a[i]) ;
        std::sort(a + 0 , a + n) ;

        ///

        s[0] = a[0] ;
        for (int i = 1 ; i < n ; ++i) s[i] = s[i - 1] + a[i] ;

        ll tot = s[n - 1] , subs = s[n - 2] - s[0] ;
        if ((subs + a[n - 1]) + (n - 1) * a[0] > 0) printf("INF\n") ;
        else if ((subs + a[0]) + (n - 1) * a[n - 1] < 0) printf("INF\n") ;
        else {
            ll ans = -1e18 ;
            for (int i = 0 ; i < n ; ++i) {
                ll t = a[i] ,
                   p1 = i ? (s[i - 1] - i * t) * (a[n - 1] - t) : 0 ,
                   p2 = (tot - s[i] - (n - 1 - i) * t) * (a[0] - t) ,
                   p3 = (a[0] - t) * (a[n - 1] - t) ,
                   p4 = (n - 1) * t * t ;
                
                ans = std::max(ans , p1 + p2 - p3 - p4) ;
            }

            printf("%lld\n" , ans) ;
        }
    }

    return 0 ;
}