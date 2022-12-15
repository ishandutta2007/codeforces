#include <bits/stdc++.h>

int T , a[3] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        for (int i = 0 ; i < 3 ; ++i) scanf("%d" , &a[i]) ;
        std::sort(a + 0 , a + 3) ;
        if (a[0] + a[1] == a[2]) printf("YES\n") ;
        else printf("NO\n") ;
    }

    return 0 ;
}