#include <bits/stdc++.h>

int T , l , r , k ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d %d" , &l , &r , &k) ;
        if (l == r) {
            if (l > 1) printf("YES\n") ;
            else printf("NO\n") ;
        }
        else {
            int s = (r >> 1) - ((l - 1) >> 1) ;
            if (r - l + 1 - s <= k) printf("YES\n") ;
            else printf("NO\n") ;
        }
    }

    return 0 ;
}