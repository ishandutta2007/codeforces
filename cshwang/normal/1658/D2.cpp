#include <bits/stdc++.h>

const int L = 17 , MAX_L = L + 5 , MAX_N = (1 << 17) + 10 ;

int T , l , r , n , a[MAX_N] , cnt[MAX_L][MAX_N] , ncnt[MAX_L][MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &l , &r) ; n = r - l + 1 ;
        for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;

        for (int i = 0 ; i <= L ; ++i)
            for (int j = 0 ; j < n ; ++j) ++cnt[i][a[j] >> i] ;
        for (int i = 0 ; i <= L ; ++i)
            for (int j = l ; j <= r ; ++j) ++ncnt[i][j >> i] ;
        
        int res = 0 ;
        for (int i = L ; i >= 0 ; --i) {
            bool ok = 1 ;
            for (int j = 0 ; j < n && ok ; ++j)
                if (cnt[i][a[j] >> i] != ncnt[i][(a[j] ^ res) >> i]) ok = 0 ;
            if (!ok) res += (1 << i) ;
        }
        printf("%d\n" , res) ;

        for (int i = 0 ; i <= L ; ++i)
            for (int j = 0 ; j < n ; ++j) --cnt[i][a[j] >> i] ;
        for (int i = 0 ; i <= L ; ++i)
            for (int j = l ; j <= r ; ++j) --ncnt[i][j >> i] ;
    }

    return 0 ;
}