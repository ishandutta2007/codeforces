#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10 ;

int T , n , a[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;

        ///

        int c0 = 0 , c1 = 0 ;
        for (int i = 0 ; i < n ; ++i)
            if (a[i] == 1) ++c1 ;
            else if (a[i] == 0) ++c0 ;
        
        bool neq = 1 ;
        std::sort(a + 0 , a + n) ;
        for (int i = 1 ; i < n ; ++i)
            if (a[i - 1] + 1 == a[i]) neq = 0 ;
        
        if (!c1) printf("YES\n") ;
        else if (!c0 && neq) printf("YES\n") ;
        else printf("NO\n") ;
    }

    return 0 ;
}