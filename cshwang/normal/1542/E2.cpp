#include <bits/stdc++.h>

#define ll long long
#define g(i) g[i + m + 1]
#define f(i , j) f[i][j + m + 1]

const int MAX_N = 500 + 10 ;

int n , mod , P[MAX_N] , f[2][MAX_N * MAX_N] , g[MAX_N * MAX_N] ;

inline int Mul(int x , int y) {
    int r = (ll)x * y % mod ;
    return r < 0 ? r + mod : r ;
}

int main() {
    scanf("%d %d" , &n , &mod) ;
    P[0] = 1 ;
    for (int i = 1 ; i <= n ; ++i) P[i] = (ll)P[i - 1] * (n - i + 1) % mod ;

    int m = n * (n - 1) / 2 , mm = 0 , op = 0 , res = 0 ;
    f(op , 0) = 1 % mod ;
    for (int i = 1 ; i <= n ; ++i) {
        int sum = 0 ;
        mm += (i - 1) ; g(-mm - 1) = 0 ;
        for (int s = -mm ; s <= mm ; ++s) {
            g(s) = Mul(f(op , s) , s) ;
            (g(s) += g(s - 1)) %= mod ;
        }
        for (int s = -mm + 1 ; s <= mm ; ++s) (f(op , s) += f(op , s - 1)) %= mod ;
        for (int d = 1 ; d < i ; ++d) {
            int tmp = (ll)P[n - i] * (i - d) % mod * (f(op , mm) - f(op , d) + mod) % mod ;
            (res += tmp) %= mod ;
        }

        ///

        op ^= 1 ;
        for (int s = -mm ; s <= mm ; ++s) {
            int L = std::max(s - i + 1 , -mm) , R = s - 1 ;
            f(op , s) = (ll)(f(op ^ 1 , s) - f(op ^ 1 , s - 1) + mod) * i % mod ;
            if (L <= R) {
                int p1 = (f(op ^ 1 , R) - f(op ^ 1 , L - 1) + mod) % mod ,
                    p2 = (g(R) - g(L - 1) + mod) % mod ;
                p1 = Mul(p1 , i - s) ;
                f(op , s) = ((ll)f(op , s) + p1 + p2) % mod ;
            }

            L = s + 1 ; R = std::min(s + i - 1 , mm) ;
            if (L <= R) {
                int p1 = (f(op ^ 1 , R) - f(op ^ 1 , L - 1) + mod) % mod ,
                    p2 = (g(R) - g(L - 1) + mod) % mod ;
                p1 = Mul(p1 , i + s) ;
                f(op , s) = ((ll)f(op , s) + p1 - p2 + mod) % mod ;
            }
        }
    }

    printf("%d\n" , res) ;

    return 0 ;
}