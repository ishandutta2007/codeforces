//
// Created by calabash_boy on 18-6-19.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 110005;
const int mod = 1e9+7;
typedef pair<long long ,long long> pll;
ll d[N];
ll l, r, x, y;
int cnt = 0;
inline ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}
ll power(ll a, ll b) {
    ll res = 1;
    while (b){
        if(b&1){
            res = res*a%mod;
        }
        b>>=1;
        a = a*a%mod;
    }
    return res;
}
inline bool ck(ll x) {
    return l <= x && x <= r;
}
void input(){
    cin >> l >> r >> x >> y;

    for (ll i = 1; i * i <= y; ++i) {
        if (y % i == 0) {
            d[cnt++] = i;
            d[cnt++] = y / i;
        }
    }
}
void solve(){
    sort(d, d + cnt);
    cnt = unique(d, d + cnt) - d;
    set<pll> ans;
    for (int i = 0; i < cnt; ++i) {
        ll dd = d[i];
        ll xx = x * dd;
        ll yy = y / dd;
        if (ck(xx) && ck(yy)) {
            if (__gcd(xx, yy) == x) {
                ans.insert({xx, yy});
            }
        }
    }
    cout << ans.size() << endl;
}
int main() {
    input();
    solve();
    return 0;
}