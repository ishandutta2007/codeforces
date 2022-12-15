#include <bits/stdc++.h>

#define ll long long

int T ;
ll l , r ;

ll calc(ll x) {
    ll num = (ll)sqrt(x) , res = (num - 1) * 3 ;
    if (num * num <= x) ++res ;
    if (num * num + num <= x) ++res ;
    if (num * num + 2 * num <= x) ++res ;
    return res ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%lld %lld" , &l , &r) ;
        ll ans = calc(r) - calc(l - 1) ;
        printf("%lld\n" , ans) ;
    }

    return 0 ;
}