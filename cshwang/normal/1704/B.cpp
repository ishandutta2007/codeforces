#include <bits/stdc++.h>

const int MAX_N = 2e5 + 10 ;

int T , n , x , a[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &x) ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

        ///

        int r = 0 , L = a[1] , R = a[1] ;
        for (int i = 2 ; i <= n ; ++i) {
            int nL = std::min(L , a[i]) , nR = std::max(R , a[i]) ;
            if (nR - nL > (x << 1)) {
                ++r ;
                L = a[i] ; R = a[i] ;
            }
            else L = nL , R = nR ;
        }

        printf("%d\n" , r) ;
    }

    return 0 ;
}