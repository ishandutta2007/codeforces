#include <bits/stdc++.h>

const int MAX_N = 1e3 + 10 , mod = 998244353 ;

std::vector<int> eg[MAX_N] ;

int T , n , m , tot , que[MAX_N] , a[MAX_N] , deg[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &m) ;
        for (int i = 0 ; i < n ; ++i)
            scanf("%d" , &a[i]) , eg[i].clear() , deg[i] = 0 ;
        for (int i = 0 ; i < m ; ++i) {
            int x , y ; scanf("%d %d" , &x , &y) ;
            --x ; --y ; eg[x].push_back(y) ; ++deg[y] ;
        }

        ///

        tot = 0 ;
        for (int i = 0 ; i < n ; ++i)
            if (!deg[i]) que[++tot] = i ;
        for (int i = 1 ; i <= n ; ++i) {
            int x = que[i] ;
            for (auto &y : eg[x]) {
                --deg[y] ;
                if (!deg[y]) que[++tot] = y ;
            }
        }

        ///

        int r = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            bool nzro = 0 ;
            for (int j = n ; j ; --j) {
                int x = que[j] ;
                if (a[x]) {
                    --a[x] ; nzro = 1 ;
                    for (auto &y : eg[x]) ++a[y] ;
                }
            }
            if (nzro) ++r ;
            else break ;
        }

        if (r < n) printf("%d\n" , r) ;
        else {
            for (int i = 1 ; i <= n ; ++i) {
                int x = que[i] ;
                for (auto &y : eg[x]) (a[y] += a[x]) %= mod ;
            }
            printf("%d\n" , (a[que[tot]] + n) % mod) ;
        }
    }

    return 0 ;
}