#include <bits/stdc++.h>

typedef long long ll ;

const int MAX_N = 2e5 + 10 , mod = 1e9 + 7 ;

int T , n , m , h , r , a[MAX_N] , val[MAX_N] , fa[MAX_N] ;

int findset(int x) {
    if (fa[x] == -1) return x ;
    int ff = findset(fa[x]) ;
    (val[x] += val[fa[x]]) %= h ;
    return (fa[x] = ff) ;
}

int qpow(int a , int t) {
    if (!a) return 0 ;

    int s = 1 ;
    for (; t ; a = (ll)a * a % mod , t >>= 1)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        int cnt = 0 ;
        scanf("%d %d %d" , &n , &m , &h) ; r = h ;
        for (int i = 0 ; i <= m ; ++i) fa[i] = -1 , val[i] = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            int prev = -1 ;
            for (int j = 0 ; j < m ; ++j) scanf("%d" , &a[j]) ;
            for (int j = 0 ; j < m ; ++j)
                if (a[j] != -1) {
                    if (prev == -1) {prev = j ; continue ;}

                    int fx = findset(prev) , fy = findset(j) , delt = (a[j] - a[prev] + h) % h ;
                    if (fx != fy) {
                        delt = (delt - (val[j] - val[prev] + h) % h + h) % h ;
                        val[fy] = delt ; fa[fy] = fx ;
                    }
                    else if ((val[j] - val[prev] + h) % h != delt) r = 0 ;
                    prev = j ;
                }
            
            if (prev == -1) ++cnt ;
        }

        for (int i = 0 ; i < m ; ++i) a[i] = 0 ;
        for (int i = 0 ; i < m ; ++i) a[findset(i)] = 1 ;
        for (int i = 0 ; i < m ; ++i) cnt += a[i] ;
        printf("%d\n" , qpow(r , cnt - 1)) ;
    }

    return 0 ;
}