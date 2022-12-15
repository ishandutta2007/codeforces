#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e6 + 10 , mod = 1e9 + 7 ;

int T , n , pw[MAX_N] , ans[MAX_N] , BIT[MAX_N] ;

inline int lowbit(int x) {return x & (-x) ;}

int calc(int x) {
    int s = 0 ;
    for (; x ; x -= lowbit(x)) (s += BIT[x]) %= mod ;
    return s ;
}

void add(int x , int a) {
    if (!x) return ;
    for (; x <= n ; x += lowbit(x)) (BIT[x] += a) %= mod ;
}

int main() {
    int N = 1e6 ;
    pw[0] = 1 ; pw[1] = (mod + 1) >> 1 ;
    for (int i = 2 ; i <= N ; ++i) pw[i] = (ll)pw[i - 1] * pw[1] % mod ;

    ///

    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i) BIT[i] = 0 ;

        add(n >> 1 , ans[n] = pw[n - (n >> 1) - 1]) ;
        for (int i = n - 1 ; i ; --i) {
            int r = (calc(n) - calc(i - 1) + mod) % mod ;
            add(i >> 1 , ans[i] = (ll)pw[i - (i >> 1)] * (mod + 1 - r) % mod) ;
        }
        for (int i = 1 ; i <= n ; ++i) printf("%d\n" , ans[i]) ;
    }

    return 0 ;
}