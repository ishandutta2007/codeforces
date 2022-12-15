#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10 ;

int T , n , a[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

        int u = a[1] ;
        for (int i = 2 ; i <= n ; ++i) u = std::min(u , a[i]) ;

        if (u >= a[1]) printf("Bob\n") ;
        else printf("Alice\n") ;
    }

    return 0 ;
}