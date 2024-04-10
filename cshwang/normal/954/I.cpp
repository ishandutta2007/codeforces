#include <bits/stdc++.h>

const int MAX_N = 125e3 + 10 , INF = 0x3f3f3f3f ;

int n , m , trans[10] , nxt[MAX_N] , ans[MAX_N] ;
char s[MAX_N] , t[MAX_N] , ts[MAX_N] , tt[MAX_N] ;

void check(int c) {
    for (int i = 0 ; i < n ; ++i)
        ts[i] = trans[s[i] - 'a'] + 'a' ;
    for (int i = 0 ; i < m ; ++i)
        tt[i] = trans[t[i] - 'a'] + 'a' ;
    tt[m] = 'z' ;
    
    ///

    int p = -1 ;
    nxt[0] = -1 ;
    for (int i = 1 ; i < m ; ++i) {
        for (; p != -1 && tt[p + 1] != tt[i] ; p = nxt[p]) ;
        if (tt[p + 1] == tt[i]) ++p ;
        nxt[i] = p ;
    }

    p = -1 ;
    for (int i = 0 ; i < n ; ++i) {
        for (; p != -1 && tt[p + 1] != ts[i] ; p = nxt[p]) ;
        if (tt[p + 1] == ts[i]) ++p ;
        if (p == m - 1) ans[i] = std::min(ans[i] , c) ;
    }
}

void bell(int x , int ed , int c) {
    if (x == 6) {
        check(c) ;
        return ;
    }

    trans[x] = ed + 1 ;
    bell(x + 1 , ed + 1 , c) ;
    for (int i = 0 ; i <= ed ; ++i) {
        trans[x] = i ;
        bell(x + 1 , ed , c + 1) ;
    }
}

int main() {
    scanf("%s %s" , s , t) ;
    n = strlen(s) ; m = strlen(t) ;

    for (int i = m - 1 ; i < n ; ++i) ans[i] = INF ;
    trans[0] = 0 ;
    bell(1 , 0 , 0) ;

    for (int i = m - 1 ; i < n ; ++i) printf("%d " , ans[i]) ;
    printf("\n") ;

    return 0 ;
}