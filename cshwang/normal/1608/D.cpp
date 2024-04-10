#include <bits/stdc++.h>

#define ll long long

const int mod = 998244353 ;

int n ;
char s[10] ;

int qpow(int a , int t = mod - 2) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

int jc(int n) {
    if (n < 0) return 0 ;
    int s = 1 ;
    for (int i = 2 ; i <= n ; ++i) s = (ll)s * i % mod ;
    return s ;
}

int main() {
    scanf("%d" , &n) ;
    int fbw = 1 , fwb = 1 , allsme = 1 , blk = 0 , wht = 0 ;
    for (int i = 0 ; i < n ; ++i) {
        scanf("%s" , s) ;
        if (s[0] == 'B' || s[1] == 'W') fwb = 0 ;
        if (s[0] == 'W' || s[1] == 'B') fbw = 0 ;
        if (s[0] == s[1]) {
            if (s[0] != '?') allsme = 0 ;
            else (allsme <<= 1) %= mod ;
        }
        for (int i = 0 ; i < 2 ; ++i)
            if (s[i] == 'B') ++blk ;
            else if (s[i] == 'W') ++wht ;
    }
    int tot = (n << 1) - blk - wht , lef = n - blk ;
    int ans = (ll)jc(tot) * qpow(jc(lef)) % mod * qpow(jc(tot - lef)) % mod ;
    ans = (ans - allsme + mod + fbw + fwb) % mod ;
    printf("%d\n" , ans) ;

    return 0 ;
}