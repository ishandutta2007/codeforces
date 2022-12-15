#include <bits/stdc++.h>

int T , n ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 0 ; i < n ; ++i , printf("\n"))
            for (int j = 0 ; j <= i ; ++j)
                if (!j || i == j) printf("1 ") ;
                else printf("0 ") ;
    }

    return 0 ;
}