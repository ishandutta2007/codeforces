#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 4e5 + 10 ;

char s[MAX_N] ;
int T , n , m , cnt[MAX_N] ;

inline int calc(int x , int y) {return x ? cnt[y] - cnt[x - 1] : cnt[y] ;}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &m) ;
        scanf("%s" , s) ;

        for (int i = 0 ; i < n ; ++i) s[i + n] = s[i] ;
        cnt[0] = s[0] - '0' ;
        for (int i = 1 ; i < (n << 1) ; ++i) cnt[i] = cnt[i - 1] + s[i] - '0' ;

        ///

        int tot = cnt[n - 1] ;
        if ((ll)tot * m % n) {printf("-1\n") ; continue ;}

        int ned = (ll)tot * m / n , l = -1 , r = -1 ;
        for (int i = m - 1 ; i < n && l == -1 ; ++i)
            if (calc(i - m + 1 , i) == ned) {l = i - m + 1 ; r = i ; break ;}
        for (int i = n ; i < (n << 1) && l == -1 ; ++i)
            if (calc(i - m + 1 , i) == ned) {l = i - m + 1 ; r = i ; break ;}
        
        if (r < n) printf("1\n%d %d\n" , l + 1 , r + 1) ;
        else printf("2\n%d %d\n%d %d\n" , 1 , r - n + 1 , l + 1 , n) ;
    }

    return 0 ;
}