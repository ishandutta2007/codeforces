#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 300 + 10 ;

char s[MAX_N] ;
int T , n , tot , ty[3] , a[MAX_N][MAX_N] ;

void print(int a) {
    if (a == 1) printf("O") ;
    else if (a == 2) printf("X") ;
    else printf(".") ;
}

bool check() {
    for (int i = 0 ; i <= 2 ; ++i)
        for (int j = i + 1 ; j <= 2 ; ++j) if (ty[i] == ty[j]) return 0 ;

    int s = 0 ;
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < n ; ++j) {
            int nw = (i + j) % 3 ;
            if (!ty[nw] || !a[i][j]) continue ;
            if (ty[nw] != a[i][j]) ++s ;
        }

    return s <= tot / 3 ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ; tot = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            scanf("%s" , s) ;
            for (int j = 0 ; j < n ; ++j)
                if (s[j] == 'O') a[i][j] = 1 , ++tot ;
                else if (s[j] == 'X') a[i][j] = 2 , ++tot ;
                else a[i][j] = 0 ;
        }

        ///

        for (ty[0] = 0 ; ty[0] <= 2 ; ++ty[0])
            for (ty[1] = 0 ; ty[1] <= 2 ; ++ty[1])
                for (ty[2] = 0 ; ty[2] <= 2 ; ++ty[2])
                    if (check()) goto pt ;

        pt:
        for (int i = 0 ; i < n ; ++i , printf("\n"))
            for (int j = 0 ; j < n ; ++j) {
                int nw = (i + j) % 3 ;
                if (!ty[nw]) print(a[i][j]) ;
                else {
                    if (!a[i][j]) printf(".") ;
                    else print(ty[nw]) ;
                }
            }
    }

    return 0 ;
}