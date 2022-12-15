#include <bits/stdc++.h>

#define ll long long

const int N = 60 , MAX_N = N + 5 ;

int T ;
ll n , m , f[MAX_N][2][2][2][2] ;   

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%lld %lld" , &n , &m) ; --m ;
        for (int i = N ; i >= 0 ; --i)
            for (int st1 = 0 ; st1 < 2 ; ++st1)
                for (int st2 = 0 ; st2 < 2 ; ++st2)
                    for (int st3 = 0 ; st3 < 2 ; ++st3)
                        for (int st4 = 0 ; st4 < 2 ; ++st4)
                            f[i][st1][st2][st3][st4] = 0 ;
        f[N][1][0][0][0] = 1 ;
        for (int i = N ; i ; --i)
            for (int st1 = 0 ; st1 < 2 ; ++st1)
                for (int st2 = 0 ; st2 < 2 ; ++st2)
                    for (int st3 = 0 ; st3 < 2 ; ++st3)
                        for (int st4 = 0 ; st4 < 2 ; ++st4)
                            for (int v = 0 ; v < 2 ; ++v) {
                                int a = n >> (i - 1) & 1 , b = m >> (i - 1) & 1 ;
                                if (st1 && v > b) continue ;
                                int nst1 = st1 & (b == v) , nst4 = st4 ^ v , nst2 , nst3 ;
                                if (a && v) nst2 = 0 , nst3 = st2 ^ st3 ^ 1 ;
                                else if (a || v) nst2 = st2 ^ 1 , nst3 = st3 ^ 1 ;
                                else nst2 = 0 , nst3 = st3 ;
                                f[i - 1][nst1][nst2][nst3][nst4] += f[i][st1][st2][st3][st4] ;
                            }
        
        ll ans = 0 ;
        for (int st1 = 0 ; st1 < 2 ; ++st1)
            for (int st2 = 0 ; st2 < 2 ; ++st2)
                for (int st3 = 0 ; st3 < 2 ; ++st3)
                    ans += f[0][st1][st2][st3][st3 ^ 1] ;
        printf("%lld\n" , ans) ;
    }

    return 0 ;
}