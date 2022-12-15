#include <bits/stdc++.h>

const int MAX_N = 350 + 10 ;

int n , a[MAX_N][MAX_N] ;

int main() {
    scanf("%d" , &n) ;
    for (int i = 0 ; i < n ; ++i) {
        scanf("%d" , &a[i][i]) ;
        for (int c = 0 , j = (i + 1) % n ; c < n - 1 ; ++c , (++j) %= n) {
            int prev = (j + n - 1) % n ;
            a[i][j] = (a[i][prev] + i) % n ;
        }
    }
    for (int i = 0 ; i < n ; ++i , printf("\n"))
        for (int j = 0 ; j < n ; ++j) printf("%d " , a[i][j]) ;

    return 0 ;
}