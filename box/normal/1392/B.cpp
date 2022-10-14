
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
        int n; ll k; cin >> n >> k;
        if(k >= 2) k = 2 + k % 2;
        vector<ll> a(n);
        rep(i, n) cin >> a[i];
        auto apply = [&]() {
            ll mx = a[0];
            rep(i, n) mx = max(mx, a[i]);
            rep(i, n) a[i] = mx - a[i];
        };
        while(k--) apply();
        rep(i, n) cout << a[i] << " \n"[i==n-1];
    }
}