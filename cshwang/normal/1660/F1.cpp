#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 4e5 + 10 ;

char s[MAX_N] ;
int T , n , m , sum[MAX_N] , BIT[2][3][MAX_N] ;

inline int lowbit(int x) {return x & (-x) ;}

void add(int ty , int a , int p) {
    a = (a % 3 + 3) % 3 ;
    for (; p <= m ; p += lowbit(p)) ++BIT[ty][a][p] ;
}

int calc(int ty , int a , int p) {
    a = (a % 3 + 3) % 3 ;

    int s = 0 ;
    for (; p ; p -= lowbit(p)) s += BIT[ty][a][p] ;
    return s ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        scanf("%s" , s + 1) ; s[0] = '*' ;

        m = (n << 1) + 1 ; sum[0] = n + 1 ;
        for (int i = 1 ; i <= n ; ++i) sum[i] = sum[i - 1] + (s[i] == '-' ? 1 : -1) ;
        for (int i = 0 ; i < 2 ; ++i)
            for (int j = 0 ; j < 3 ; ++j)
                for (int k = 0 ; k <= m ; ++k) BIT[i][j][k] = 0 ;

        ///

        add(0 , 0 , n + 1) ;
        int p1 = 0 , p2 = 0 , op = 0 ; ll ans = 0 ;
        for (int i = 1 ; i <= n ; ++i) {
            if (s[i] == '+') ++p1 , ++p2 ;
            else {
                if (s[i] != s[i - 1]) op = 0 ;
                else op ^= 1 ;

                if (!op) --p1 , p2 += 2 ;
                else p1 += 2 , --p2 ;
            }

            ans += calc(0 , p1 , sum[i]) + calc(1 , p2 , sum[i]) ;

            if (s[i] == '+') add(0 , p1 , sum[i]) ;
            else if (op) add(0 , p1 , sum[i]) ;
            else add(1 , p2 , sum[i]) ;
        }

        printf("%lld\n" , ans) ;
    }

    return 0 ;
}