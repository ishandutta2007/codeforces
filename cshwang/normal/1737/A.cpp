#include <bits/stdc++.h>

const int MAX_N = 200 + 10 ;

char s[MAX_N] , ans[MAX_N] ;
int T , n , k , cnt['z' + 10] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &k) ;
        scanf("%s" , s) ;

        for (int i = 'a' ; i <= 'z' ; ++i) cnt[i] = 0 ;
        for (int i = 0 ; i < n ; ++i) ++cnt[s[i]] ;

        int ned = n / k ;
        for (int i = 1 ; i <= k ; ++i) {
            int j = 'a' ;
            for (int c = 0 ; c < ned ; ++c , --cnt[j++]) if (!cnt[j]) {break ;}
            ans[i] = j ;
        }
        for (int i = 1 ; i <= k ; ++i) printf("%c" , ans[i]) ;
        printf("\n") ;
    }

    return 0 ;
}