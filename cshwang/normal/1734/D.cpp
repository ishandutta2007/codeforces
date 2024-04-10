#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 2e5 + 10 ;

ll sum[MAX_N] ;
int T , n , k , a[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &k) ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
        sum[0] = 0 ;
        for (int i = 1 ; i <= n ; ++i) sum[i] = sum[i - 1] + a[i] ;

        bool ok = 0 ;
        ll val = a[k] ;
        int pl , pr , l , r ;

        pl = pr = l = r = k ;
        do {
            ok = 0 ;
            for (; pl > 1 && val + sum[l - 1] - sum[pl - 2] >= 0 ; --pl) {
                ok = 1 ;
                if (sum[l - 1] - sum[pl - 2] >= 0)
                    val += sum[l - 1] - sum[pl - 2] , l = pl - 1 ;
            }
            for(; pr < n && val + sum[pr + 1] - sum[r] >= 0 ; ++pr) {
                ok = 1 ;
                if (sum[pr + 1] - sum[r] >= 0)
                    val += sum[pr + 1] - sum[r] , r = pr + 1 ;
            }
        }while(ok) ;

        if (pl == 1 || pr == n) printf("YES\n") ;
        else printf("NO\n") ;
    }

    return 0 ;
}