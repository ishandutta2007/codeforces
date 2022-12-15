#include <bits/stdc++.h>

#define ll long long

ll n ;
int T ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%lld" , &n) ;
        
        ll pw = 2 ;
        for (; !(n % 2) ; n /= 2 , pw *= 2) ;

        if (n == 1) printf("-1\n") ;
        else printf("%lld\n" , std::min(pw , n)) ;
    }

    return 0 ;
}