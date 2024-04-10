#include <bits/stdc++.h>

int T , n , r[3] , c[3] , cr , cc , x , y ;

void check() {
    if (r[0] == r[1]) cr = r[0] ;
    else cr = r[2] ;
    if (c[0] == c[1]) cc = c[0] ;
    else cc = c[2] ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        scanf("%d %d %d %d %d %d" , &r[0] , &c[0] , &r[1] , &c[1] , &r[2] , &c[2]) ;
        scanf("%d %d" , &x , &y) ;

        check() ;
        if ((cr == 1 || cr == n) && (cc == 1 || cc == n)) {
            if (cr == x || cc == y) printf("YES\n") ;
            else printf("NO\n") ;
        }
        else if ((abs(cr - x) & 1) && (abs(cc - y) & 1)) printf("NO\n") ;
        else printf("YES\n") ;
    }

    return 0 ;
}