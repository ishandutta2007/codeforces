#include <bits/stdc++.h>

#define ll long long
#define pir std::pair<int , int>

const int MAX_N = 2e5 + 10 ;

std::vector<pir> dt ;

ll sum[MAX_N] ;
int T , n , q , a[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &q) ;
        sum[0] = 0 ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) , sum[i] = sum[i - 1] + a[i] ;

        ///

        dt.clear() ; dt.push_back({a[1] , 1}) ;
        for (int i = 2 ; i <= n ; ++i) {
            if (a[i] <= dt.rbegin()->first) continue ;
            dt.push_back({a[i] , i}) ;
        }

        for (; q-- ;) {
            int x ; scanf("%d" , &x) ;

            auto p = std::upper_bound(dt.begin() , dt.end() , std::make_pair(x , n + 1)) ;
            if (p == dt.end()) printf("%lld " , sum[n]) ;
            else printf("%lld " , sum[p->second - 1]) ;
        }
        printf("\n") ;
    }

    return 0 ;
}