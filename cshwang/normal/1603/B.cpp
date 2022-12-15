#include <bits/stdc++.h>

#define ll long long

int T ;
ll x , y ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%lld %lld" , &x , &y) ;

        if (x < y) printf("%lld\n" , y - (y - x) % x / 2) ;
        else if (x == y) printf("%lld\n" , x) ;
        else printf("%lld\n" , x + y) ;
    }

    return 0 ;
}