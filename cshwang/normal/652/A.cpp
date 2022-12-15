#include <bits/stdc++.h>

int h1 , h2 , a , b ;

int main() {
    scanf("%d %d %d %d" , &h1 , &h2 , &a , &b) ;
    int base = h1 , d = 0 ;
    while (1) {
        h1 += 8 * a ;
        if (h1 >= h2) break ;
        ++d ; h1 -= b * 12 ; h1 += 4 * a ;

        if (h1 <= base) {printf("-1\n") ; return 0 ;}
    }
    printf("%d\n" , d) ;

    return 0 ;
}