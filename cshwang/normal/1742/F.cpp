#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 'z' + 5 , MAX_L = 5e5 + 10 ;

int T , q ;
char s[MAX_L] ;
ll cnt[2][MAX_N] ;

bool check() {
    int mi = 'a' , ma = 'a' ;
    for (int i = 'z' ; i > 'a' ; --i)
        if (cnt[1][i]) {ma = i ; break ;}
    if (ma > mi) return 1 ;
    else {
        if (cnt[0][mi] >= cnt[1][mi]) return 0 ;
        for (int i = 'b' ; i <= 'z' ; ++i)
            if (cnt[0][i]) {mi = i ; break ;}
        
        if (mi != 'a') return 0 ;
        else return 1 ;
    }
    
    return 0 ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        for (int i = 'a' ; i <= 'z' ; ++i) cnt[0][i] = cnt[1][i] = 0 ;

        scanf("%d" , &q) ;
        for (; q-- ;) {
            int op , k ;
            scanf("%d %d %s" , &op , &k , s) ;

            int n = strlen(s) ; --op ;
            for (int i = 0 ; i < n ; ++i) cnt[op][s[i]] += k ;

            if (check()) printf("YES\n") ;
            else printf("NO\n") ;
        }
    }

    return 0 ;
}