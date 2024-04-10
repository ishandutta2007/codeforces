#include <bits/stdc++.h>

int T , n ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ; n <<= 1 ;
        int cnt[2] = {0 , 0} ;
        for (; n-- ;) {
            int v ; scanf("%d" , &v) ;
            ++cnt[v & 1] ;
        }

        if (cnt[0] == cnt[1]) printf("Yes\n") ;
        else printf("No\n") ;
    }

    return 0 ;
}