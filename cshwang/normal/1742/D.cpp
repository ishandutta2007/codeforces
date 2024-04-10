#include <bits/stdc++.h>

#define ll long long

const int N = 1e3 , MAX_N = N + 10 ;

bool pri[MAX_N] ;
int T , n , cnt[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= N ; ++i) cnt[i] = 0 ;
        for (int i = 1 ; i <= n ; ++i) {
            int v ; scanf("%d" , &v) ;
            cnt[v] = i ;
        }

        int r = -1 ;
        for (int i = 1 ; i <= N ; ++i)
            for (int j = i ; j <= N ; ++j)
                if (std::__gcd(i , j) == 1) {
                    if (!cnt[i] || !cnt[j]) continue ;
                    r = std::max(cnt[i] + cnt[j] , r) ;
                }
        printf("%d\n" , r) ;
    }

    return 0 ;
}