#include <bits/stdc++.h>

#define ll long long

int main() {
    int T ; scanf("%d" , &T) ;
    for (; T-- ;) {
        int n ; scanf("%d" , &n) ;

        ll s1 = 0 , s2 = 0 ;
        for (; n-- ;) {
            int x ; scanf("%d" , &x) ;
            if (x > 0) s1 += x ;
            else s2 += x ;
        }

        printf("%lld\n" , abs(s1 + s2)) ;
    }

    return 0 ;
}