#include <bits/stdc++.h>

const int N = 21 , MAX_N = (1 << N) + 10 ;

struct data {
    int mx1 , mx2 ;
}f[MAX_N] ;

int n , a[MAX_N] ;

data merge(data *a , data *b) {
    int mx1 = std::max(a->mx1 , b->mx1) ,
        mx2 = std::max(a->mx1 + b->mx1 - mx1 , std::max(a->mx2 , b->mx2)) ;
    return (data){mx1 , mx2} ;
}

int main() {
    scanf("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i) {
        scanf("%d" , &a[i]) ;
        if (f[a[i]].mx1 < i) {
            f[a[i]].mx2 = f[a[i]].mx1 ;
            f[a[i]].mx1 = i ;
        }
        else f[a[i]].mx2 = std::max(f[a[i]].mx2 , i) ;
    }

    ///

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < (1 << N) ; ++j)
            if (!(j & (1 << i))) f[j] = merge(&f[j] , &f[j + (1 << i)]) ;

    int ans = 0 ;
    for (int i = 1 ; i <= n ; ++i) {
        bool ok = f[0].mx2 > i ;
        int r = a[i] , st = 0 ;

        for (int j = N - 1 ; j >= 0 ; --j) {
            if (r & (1 << j)) continue ;
            if (f[st + (1 << j)].mx2 > i) {
                r += (1 << j) ; st += (1 << j) ; ok = 1 ;
            }
        }

        if (ok) ans = std::max(ans , r) ;
    }
    printf("%d\n" , ans) ;

    return 0 ;
}