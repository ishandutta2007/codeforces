#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 2e5 + 10 , mod = 998244353 ;

int n ;
char s[MAX_N] ;

int main() {
    scanf("%d %s" , &n , s) ;
    int cnt1 = 1 , cnt2 = 1 ;
    for (int i = 1 ; i < n ; ++i)
        if (s[i] != s[i - 1]) break ;
        else ++cnt1 ;
    for (int i = n - 2 ; i >= 0 ; --i)
        if (s[i] != s[i + 1]) break ;
        else ++cnt2 ;
    
    if (s[0] == s[n - 1]) printf("%lld\n" , (ll)(cnt1 + 1) * (cnt2 + 1) % mod) ;
    else printf("%d\n" , cnt1 + cnt2 + 1) ;

    return 0 ;
}