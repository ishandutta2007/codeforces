#include <bits/stdc++.h>

const int MAX_N = 2e5 + 10 ;

std::stack<int> sta ;

char s[MAX_N] ;
int T , n , fa[MAX_N] , lef[MAX_N] ;

inline int findset(int x) {return fa[x] == -1 ? x : (fa[x] = findset(fa[x])) ;}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        scanf("%s" , s) ;
        n <<= 1 ;

        for (int i = 0 ; i < n ; ++i)
            if (s[i] == '(') {
                lef[i] = -1 ;
                sta.push(i) ;
            }
            else {
                lef[i] = sta.top() ;
                sta.pop() ;
            }
        
        for (int i = 0 ; i < n ; ++i) fa[i] = -1 ;
        for (int i = 0 ; i < n ; ++i)
            if (lef[i] != -1) {
                int j = lef[i] , x = findset(i) , y = findset(j) ;
                if (x != y) fa[x] = y ;
                if (j) j = lef[j - 1] ;
                else j = -1 ;
                
                if (j != -1) {
                    x = findset(i) ; y = findset(j) ;
                    if (x != y) fa[x] = y ;
                }
            }
        
        int ans = 0 ;
        for (int i = 0 ; i < n ; ++i) if (fa[i] == -1) ++ans ;
        printf("%d\n" , ans) ;
    }

    return 0 ;
}