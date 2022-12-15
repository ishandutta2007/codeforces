#include <bits/stdc++.h>

const int MAX_N = 1e4 + 10 ;

int n , k , lef , a[MAX_N] , b[MAX_N] , num[MAX_N] ;

int ask(int ty , int x , int y) {
    if (!ty) {
        printf("and %d %d\n" , x , y) ;
        fflush(stdout) ;
    }
    else {
        printf("or %d %d\n" , x , y) ;
        fflush(stdout) ;
    }

    int tmp ; scanf("%d" , &tmp) ;
    return tmp ;
}

int main() {
    scanf("%d %d" , &n , &k) ;
    for (int i = 2 ; i <= n ; ++i) {
        a[i] = ask(0 , 1 , i) ;
        b[i] = ask(1 , 1 , i) ;
    }
    lef = ask(0 , 2 , 3) ;

    ///

    int S = (1 << 30) - 1 ;
    for (int i = 2 ; i <= n ; ++i) S &= (b[i] - a[i]) ;

    num[1] = 0 ;
    for (int i = 2 ; i <= n ; ++i) num[1] |= a[i] ;

    ///

    lef = S - (lef & S) ; num[1] |= lef ;
    for (int i = 2 ; i <= n ; ++i) {
        int tmp = (b[i] - a[i]) & num[1] ;
        tmp = (b[i] - a[i]) - tmp ; num[i] = a[i] + tmp ;
    }

    ///

    std::sort(num + 1 , num + 1 + n) ;

    printf("finish %d\n" , num[k]) ;
    fflush(stdout) ;

    return 0 ;
}