#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10 ;

int T , n , a[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

        ///

        bool ok = 1 ;
        for (int i = n ; i ; --i) {
            int p = -1 ;
            for (int j = i ; j ; --j) if (a[j] % (j + 1)) {p = j ; break ;}

            if (p == -1) {ok = 0 ; break ;}
            for (int j = p ; j < i ; ++j) a[j] = a[j + 1] ;
        }

        if (ok) printf("YES\n") ;
        else printf("NO\n") ;
    }

    return 0 ;
}