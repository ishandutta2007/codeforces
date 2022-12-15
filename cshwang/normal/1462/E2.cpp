#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 , mod = 1e9 + 7 ;

int C[MAX_N] , jc[MAX_N] , ny[MAX_N] ;
int T , n , m , k , a[MAX_N] , tre[2][MAX_N << 2] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;

    return s ;
}

int oper(int a , int b , int ty) {
    if (a == -1) return b ;
    else if (b == -1) return a ;

    if (ty) return std::max(a , b) ;
    else return std::min(a , b) ;
}

void build(int t , int x , int y) {
    if (x == y) {tre[0][t] = tre[1][t] = a[x] ; return ;}

    int mid = (x + y) >> 1 ;
    build(t << 1 , x , mid) ; build(t << 1 | 1 , mid + 1 , y) ;
    for (int i = 0 ; i < 2 ; ++i) tre[i][t] = oper(tre[i][t << 1] , tre[i][t << 1 | 1] , i) ;
}

int find(int t , int x , int y , int fx , int fy , int ty) {
    if (y < fx || fy < x) return -1 ;
    if (fx <= x && y <= fy) return tre[ty][t] ;

    int mid = (x + y) >> 1 ,
        s1 = find(t << 1 , x , mid , fx , fy , ty) ,
        s2 = find(t << 1 | 1 , mid + 1 , y , fx , fy , ty) ;

    return oper(s1 , s2 , ty) ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d %d" , &n , &m , &k) ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

        std::sort(a + 1 , a + 1 + n) ;
        if (m == 1) {printf("%d\n" , n) ; continue ;}

        ///

        jc[0] = ny[0] = 1 ;
        for (int i = 1 ; i <= n ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;
        ny[n] = qpow(jc[n] , mod - 2) ;
        for (int i = n - 1 ; i ; --i) ny[i] = (ll)ny[i + 1] * (i + 1) % mod ;

        C[0] = 0 ;
        for (int i = 1 ; i <= n ; ++i)
            if (i < m - 1) C[i] = 0 ;
            else C[i] = (ll)jc[i] * ny[m - 1] % mod * ny[i - m + 1] % mod ;

        ///

        build(1 , 1 , n) ;
        int p = 1 , ans = 0 ;
        for (int i = 1 ; i <= n ; ++i) {
            p = std::max(p , i) ;
            for (; p + 1 <= n && find(1 , 1 , n , i , p + 1 , 1) - find(1 , 1 , n , i , p + 1 , 0) <= k ; ++p) ;

            int l = p - i ;
            if (l >= 0) ans = (ans + C[l]) % mod ;
        }

        printf("%d\n" , ans) ;
    }

    return 0 ;
}