#include <bits/stdc++.h>

typedef long long ll ;

const int MAX_N = 3e5 + 10 ;

int n , m , idx[MAX_N] , mp[MAX_N] ;

int main() {
    scanf("%d %d" , &n , &m) ;
    for (int i = 1 ; i <= n ; ++i) {
        int v ; scanf("%d" , &v) ;
        idx[v] = i ;
    }
    for (int i = 1 ; i <= n ; ++i) mp[i] = n + 1 ;
    for (int i = 0 ; i < m ; ++i) {
        int x , y ; scanf("%d %d" , &x , &y) ;
        x = idx[x] ; y = idx[y] ;
        if (x > y) std::swap(x , y) ;
        mp[x] = std::min(mp[x] , y) ;
    }

    for (int i = n - 1 ; i ; --i) mp[i] = std::min(mp[i] , mp[i + 1]) ;

    ll ans = 0 ;
    for (int i = 1 ; i <= n ; ++i) ans += mp[i] - i ;
    printf("%lld\n" , ans) ;

    return 0 ;
}