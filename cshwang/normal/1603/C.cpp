#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 10 , mod = 998244353 ;

struct data {int mi , ma , ti ;} ;

std::vector<data> lst[2] ;

int T , n , res , a[MAX_N] , s[2] , f[2][MAX_N] ;

int devi(int p , int x) {
    lst[p].clear() ;
    for (int l = 1 ; l <= a[x] ;) {
        int mi = a[x] / l , r = a[x] / mi , off = a[x] % l ? 1 : 0 ;
        lst[p].push_back((data){mi , mi + off , l - 1}) ;
        if (l != r && !(a[x] % r)) lst[p].push_back((data){mi , mi , r - 1}) ;

        l = r + 1 ;
    }

    s[p] = lst[p].size() ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
        devi(0 , 1) ;

        ///

        int p = 1 ; res = 0 ;
        for (int i = 0 ; i < s[0] ; ++i) f[0][i] = lst[0][i].ti ;
        for (int i = 2 ; i <= n ; ++i , p ^= 1) {
            devi(p , i) ;

            int nw = 0 , ed = s[p ^ 1] ;
            for (int j = 0 ; j < s[p] ; ++j) {
                for (; nw < ed && lst[p][j].mi < lst[p ^ 1][nw].ma ; ++nw) ;
                if (nw >= ed) {f[p][j] = 0 ; continue ;}

                int cost = (ll)lst[p][j].ti * i % mod ;
                f[p][j] = (f[p^1][nw] + cost) % mod ;
            }

            (res += f[p][0]) %= mod ;
        }

        printf("%d\n" , res) ;
    }

    return 0 ;
}