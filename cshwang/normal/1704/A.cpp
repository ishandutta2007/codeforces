#include <bits/stdc++.h>

const int MAX_N = 50 + 5 ;

int T , n , m ;
char a[MAX_N] , b[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &m) ;
        scanf("%s %s" , a + 1 , b + 1) ;

        if (n < m) {printf("NO\n") ; continue ;}

        int i , j ;
        bool ok = 1 , ex = 0 ;
        for (j = m , i = n ; j > 1 ; --j , --i)
            if (a[i] != b[j]) ok = 0 ;
        for (; i ; --i)
            if (a[i] == b[1]) ex = 1 ;
        ok &= ex ;

        if (ok) printf("YES\n") ;
        else printf("NO\n") ;
    }

    return 0 ;
}