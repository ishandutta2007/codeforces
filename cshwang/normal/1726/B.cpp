#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10 ;

int T , n , m , a[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &m) ;
        if (n == 1) {
            printf("Yes\n") ;
            printf("%d\n" , m) ;
        }
        else {
            if (n > m) printf("No\n") ;
            else {
                for (int i = 1 ; i <= n ; ++i) a[i] = 1 ;
                m -= n ;
                if (n % 2 == 0) {
                    if (m % 2) printf("No\n") ;
                    else {
                        printf("Yes\n") ;
                        a[n] += (m >> 1) ; a[n - 1] += (m >> 1) ;
                        for (int i = 1 ; i <= n ; ++i) printf("%d " , a[i]) ;
                        printf("\n") ;
                    }
                }
                else {
                    printf("Yes\n") ;
                    a[n] += m ;
                    for (int i = 1 ; i <= n ; ++i) printf("%d " , a[i]) ;
                    printf("\n") ;
                }
            }
        }
    }

    return 0 ;
}