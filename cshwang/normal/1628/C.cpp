#include <bits/stdc++.h>

const int MAX_N = 1e3 + 10 ;

int T , n , a[MAX_N][MAX_N] ;

int work() {
    int res = 0 , prev = 0 ;
    for (int i = 1 ; i <= n ; i += 2) {
        int x = i , y = 1 , r = prev ;
        for (; x > 0 && x <= n && y > 0 && y <= n ;) {
            r ^= a[x][y] ;
            x -= 2 ; y += 2 ;
        }
        res ^= r ; prev = r ;
    }
    for (int i = 2 ; i <= n ; i += 2) {
        int x = n , y = i , r = prev ;
        for (; x > 0 && x <= n && y > 0 && y <= n ;) {
            r ^= a[x][y] ;
            x -= 2 ; y += 2 ;
        }
        res ^= r ; prev = r ;
    }
    return res ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i)
            for (int j = 1 ; j <= n ; ++j) scanf("%d" , &a[i][j]) ;
        
        int res = work() ;
        for (int i = 1 ; i <= n ; ++i) std::reverse(a[i] + 1 , a[i] + n + 1) ;
        res ^= work() ;
        printf("%d\n" , res) ;
    }

    return 0 ;
}