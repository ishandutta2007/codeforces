#include <bits/stdc++.h>

#define ll long long

int T , n , a , b ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d %d" , &n , &a , &b) ;
        bool ok = 0 ;
        if (a == 1) {
            if ((n - 1) % b) printf("No\n") ;
            else printf("Yes\n") ;
        }
        else {
            ll c = 1 ; bool ok = 0 ;
            for (; c <= n ; c *= a)
                if (c % b == n % b) ok = 1 ;
            if (ok) printf("Yes\n") ;
            else printf("No\n") ;
        }
    }

    return 0 ;
}