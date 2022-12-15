#include <bits/stdc++.h>

#define ll long long

const ll INF = 2e18 ;
const int MAX_N = 1e5 + 10 , MAX_M = 1e6 + 10 ;

struct data {
    int val , idx ;
} ;

std::vector<int> c[MAX_N] ;

int T , n , m ;

ll calcdis(int x , int y) {
    ll s = 0 , r = 0 ;
    for (int i = 0 ; i < m ; ++i) {
        int a = c[x][i] - c[y][i] ;
        s += a ; r += s ;
    }
    return r ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &m) ;
        for (int i = 1 ; i <= n ; ++i) c[i].resize(m) ;
        for (int i = 1 ; i <= n ; ++i)
            for (int j = 0 ; j < m ; ++j) scanf("%d" , &c[i][j]) ;
        
        ///
        
        int p = -1 ;
        if (calcdis(1 , 2) && calcdis(1 , 3)) p = 1 ;
        else {
            for (int i = 2 ; i <= n ; ++i)
                if (calcdis(1 , i)) {p = i ; break ;}
        }

        ll r = INF ;
        for (int i = 1 ; i <= n ; ++i)
            if (i != p) {r = calcdis(i , p) ; break ;}
        printf("%d %lld\n" , p , r) ;
    }

    return 0 ;
}