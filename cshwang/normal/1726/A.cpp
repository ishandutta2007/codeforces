#include <bits/stdc++.h>

const int MAX_N = 2e3 + 10 ;

int T , n , a[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

        if (n == 1) {
            printf("0\n") ;
            continue ;
        }

        int val = std::max(a[1] - a[2] , a[n] - a[1]) ;
        for (int i = 2 ; i < n ; ++i)
            val = std::max(val , std::max(a[i] - a[1] , std::max(a[n] - a[i] , a[i] - a[i + 1]))) ;
        printf("%d\n" , val) ;
    }

    return 0 ;
}