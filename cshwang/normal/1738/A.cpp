#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 10 ;

int T , n , ty[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        std::vector<int> p1 , p2 ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &ty[i]) ;
        for (int i = 1 ; i <= n ; ++i) {
            int v ; scanf("%d" , &v) ;
            if (ty[i]) p1.push_back(v) ;
            else p2.push_back(v) ;
        }

        ///

        ll r1 = 0 , r2 = 0 ;
        std::sort(p1.begin() , p1.end() , std::greater<int>()) ;
        std::sort(p2.begin() , p2.end() , std::greater<int>()) ;

        int m1 = p1.size() , m2 = p2.size() ;
        for (int i = 0 ; i < std::max(m1 , m2) ; ++i) {
            if (i < m1) {
                if (i < m2) r1 += (p1[i] << 1) ;
                else r1 += p1[i] ;
                if (i < m2 - 1) r2 += (p1[i] << 1) ;
                else r2 += p1[i] ;
            }
            if (i < m2) {
                if (i < m1) r2 += (p2[i] << 1) ;
                else r2 += p2[i] ;
                if (i < m1 - 1) r1 += (p2[i] << 1) ;
                else r1 += p2[i] ;
            }
        }
        printf("%lld\n" , std::max(r1 , r2)) ;
    }

    return 0 ;
}