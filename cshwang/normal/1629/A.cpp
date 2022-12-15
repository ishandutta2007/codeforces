#include <bits/stdc++.h>

typedef std::pair<int , int> pir ;

const int MAX_N = 100 + 10 ;

pir a[MAX_N] ;
int T , n , k ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &k) ;
        for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i].first) ;
        for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i].second) ;
        std::sort(a + 0 , a + n) ;

        for (int i = 0 ; i < n ; ++i)
            if (k >= a[i].first) k += a[i].second ;
        printf("%d\n" , k) ;
    }

    return 0 ;
}