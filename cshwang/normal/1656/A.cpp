#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10 ;

int T , n , a[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;

        int ma = a[0] , mi = a[0] , p = 0 , q = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            if (ma < a[i]) ma = a[i] , p = i ;
            if (mi > a[i]) mi = a[i] , q = i ;
        }

        printf("%d %d\n" , p + 1 , q + 1) ;
    }

    return 0 ;
}