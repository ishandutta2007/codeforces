#include <bits/stdc++.h>

const int MAX_N = 300 + 10 ;

int T , n , a[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

        int r = -1 ;
        for (int i = 1 ; i <= n ; ++i)
            for (int j = 1 ; j <= n ; ++j)
                for (int k = 1 ; k <= n ; ++k) {
                    if (i == j || i == k || j == k) continue ;
                    int d = abs(a[i] - a[j]) + abs(a[i] - a[k]) ;
                    if (r == -1) r = d ;
                    else r = std::min(r , d) ;
                }
        printf("%d\n" , r) ;
    }

    return 0 ;
}