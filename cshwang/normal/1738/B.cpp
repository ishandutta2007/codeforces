#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 10 ;

int T , n , k , s[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &k) ;
        int lef = n - k + 1 ;
        for (int i = lef ; i <= n ; ++i) scanf("%d" , &s[i]) ;

        if (k == 1) {printf("YES\n") ; continue ;}
        for (int i = n ; i > lef ; --i) s[i] = s[i] - s[i - 1] ;

        bool ok = 1 ;
        for (int i = lef + 1 ; i < n ; ++i) ok &= (s[i] <= s[i + 1]) ;
        if (ok && (s[lef] <= s[lef + 1] * (ll)lef)) printf("YES\n") ;
        else printf("NO\n") ;
    }

    return 0 ;
}