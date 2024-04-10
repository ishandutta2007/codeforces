
// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);
        rep(i, n) cin >> a[i];
        vector<ll> pm(n);
        pm[0] = a[0];
        rep1(i, n-1) pm[i] = max(a[i], pm[i-1]);
        ll ans = 0;
        auto fix = [&](int l, int r) {
            assert(pm[l] == pm[r] && pm[l-1] == a[l-1]);
            iter(i, l-1, r) ans += max(0ll, a[i] - a[i+1]);
        };
        int l = 1;
        while(l < n) {
            if(a[l] == pm[l]) { l++; continue; }
            int r = l;
            while(r+1 != n && a[r+1] != pm[r+1]) r++;
            fix(l, r);
            l = r+1;
        } cout << ans << endl;
    }
}