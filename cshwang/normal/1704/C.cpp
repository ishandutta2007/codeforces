#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10 ;

std::vector<int> vt ;

int T , n , m , a[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &m) ;
        for (int i = 1 ; i <= m ; ++i) scanf("%d" , &a[i]) ;
        std::sort(a + 1 , a + 1 + m) ;

        vt.clear() ;
        a[m + 1] = a[1] + n ;
        for (int i = 1 ; i <= m ; ++i) {
            int l = a[i] + 1 , r = a[i + 1] - 1 ;
            if (l <= r) vt.push_back(r - l + 1) ;
        }

        ///

        int t = 0 , r = 0 ;
        std::sort(vt.begin() , vt.end() , std::greater<int>()) ;
        for (auto &x : vt) {
            int lef = x - (t << 1) ;
            if (lef <= 0) continue ;

            ++r ; ++t ; lef -= 2 ;
            if (lef > 0) {r += lef ; ++t ;}
        }

        printf("%d\n" , n - r) ;
    }

    return 0 ;
}