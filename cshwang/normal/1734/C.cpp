#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e6 + 10 ;

int T , n ;
char s[MAX_N] ;
bool tg[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %s" , &n , s + 1) ;
        for (int i = 1 ; i <= n ; ++i) tg[i] = 0 ;

        ///

        ll res = 0 ;
        for (int i = 1 ; i <= n ; ++i)
            for (int j = i ; j <= n ; j += i)
                if (s[j] == '0') {
                    if (!tg[j]) res += i , tg[j] = 1 ;
                }
                else break ;
        printf("%lld\n" , res) ;
    }

    return 0 ;
}