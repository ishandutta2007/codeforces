#include <bits/stdc++.h>

const int MAX_N = 2e5 + 10 , mod = 998244353 ;

char s[MAX_N] ;
int n , f[MAX_N][8][4][2] ;

int main() {
    scanf("%s" , s) ;
    n = strlen(s) ;
    std::reverse(s + 0 , s + n) ;

    ///

    f[n][7][3][1] = 1 ;
    for (int i = n ; i ; --i)
        for (int sta1 = 0 ; sta1 < 8 ; ++sta1)
            for (int sta2 = 0 ; sta2 < 4 ; ++sta2)
                for (int sta3 = 0 ; sta3 < 2 ; ++sta3)
                    for (int a = 0 ; a < 2 ; ++a)
                        for (int b = 0 ; b < 2 ; ++b)
                            for (int c = 0 ; c < 2 ; ++c) {
                                int num = s[i - 1] - '0' , e1 = a ^ b , e2 = b ^ c , e3 = c ^ a ,
                                    c1 = sta1 & 1 , c2 = (sta1 >> 1) & 1 , c3 = (sta1 >> 2) & 1 ,
                                    m1 = sta2 & 1 , m2 = (sta2 >> 1) & 1 , t = sta3 ;
                                
                                if (c1 && a > num) continue ;
                                if (c2 && b > num) continue ;
                                if (c3 && c > num) continue ;
                                if (m1 && e1 > e2) continue ;
                                if (m2 && e2 > e3) continue ;
                                if (t && e1 + e2 < e3) continue ;
                                
                                c1 &= (a == num) ; c2 &= (b == num) ; c3 &= (c == num) ;
                                m1 &= (e1 == e2) ; m2 &= (e2 == e3) ; t &= (e1 + e2 == e3) ;
                                (f[i - 1][c1 + (c2 << 1) + (c3 << 2)][m1 + (m2 << 1)][t] += f[i][sta1][sta2][sta3]) %= mod ;
                            }
    
    int ans = 0 ;
    for (int i = 0 ; i < 8 ; ++i)
        for (int j = 0 ; j < 4 ; ++j)
            (ans += f[0][i][j][0]) %= mod ;
    ans = 6LL * ans % mod ;
    printf("%d\n" , ans) ;

    return 0 ;
}