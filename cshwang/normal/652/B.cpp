#include <bits/stdc++.h>

const int MAX_N = 1e3 + 10 ;

int n , a[MAX_N] , b[MAX_N] ;

int main() {
    scanf("%d" , &n) ;
    for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;

    int m = n - 1 ;
    std::sort(a + 0 , a + n) ;
    for (int i = 2 ; i <= n ; i += 2) b[i] = a[m--] ;
    for (int i = 1 ; i <= n ; i += 2) b[i] = a[m--] ;

    for (int i = 1 ; i <= n ; ++i) printf("%d " , b[i]) ;

    return 0 ;
}