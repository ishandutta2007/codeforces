#include <bits/stdc++.h>

int T ;
char s[10][10] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        int n = 8 ;
        for (int i = 0 ; i < n ; ++i) scanf("%s" , s[i]) ;

        bool b = 0 , r = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            bool ck = 1 ;
            for (int j = 0 ; j < n ; ++j) ck &= (s[i][j] == 'R') ;
            r |= ck ;
        }

        for (int i = 0 ; i < n ; ++i) {
            bool ck = 1 ;
            for (int j = 0 ; j < n ; ++j) ck &= (s[j][i] == 'B') ;
            b |= ck ;
        }

        if (b) printf("B\n") ;
        else printf("R\n") ;
    }

    return 0 ;
}