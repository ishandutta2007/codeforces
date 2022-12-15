#include <bits/stdc++.h>

const int MAX_N = 2e5 + 10 ;

std::map<int , int> idx[2] ;

int n , q , a[MAX_N] , s[MAX_N] , nxt[MAX_N] , pre[MAX_N] , cnt[MAX_N] ;

int main() {
    scanf("%d %d" , &n , &q) ;
    for (int i = 1 ; i <= n ; ++i)
        scanf("%d" , &a[i]) , cnt[i] = (a[i] == 0) ;
    
    s[0] = 0 ;
    for (int i = 1 ; i <= n ; ++i) s[i] = s[i - 1] ^ a[i] ;
    for (int i = 1 ; i <= n ; ++i) cnt[i] += cnt[i - 1] ;

    ///

    for (int i = 1 ; i <= n ; ++i) {
        int t = i & 1 ;
        
        if (idx[t ^ 1].count(s[i])) pre[i] = idx[t ^ 1][s[i]] ;
        else pre[i] = -1 ;
        idx[t][s[i]] = i ;
    }

    ///

    for (; q-- ;) {
        int l , r ; scanf("%d %d" , &l , &r) ;

        int res = s[r] ^ s[l - 1] ;
        if (cnt[r] - cnt[l - 1] == r - l + 1) printf("0\n") ;
        else if (res) printf("-1\n") ;
        else {
            if ((r - l + 1) & 1) printf("1\n") ;
            else if (pre[r] >= l) {
                if (!a[l] || !a[r]) printf("1\n") ;
                else printf("2\n") ;
            }
            else printf("-1\n") ;
        }
    }

    return 0 ;
}