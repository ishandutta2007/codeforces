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

ll a[200005];
ll por[200005], sor[200005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, x; cin >> n >> k >> x;
    rep1(i, n) {
    	cin >> a[i];
    	por[i] = a[i] | por[i-1];
    }
    for(int i = n; i >= 1; i--) {
    	sor[i] = a[i] | sor[i+1];
    }
    ll v = 1;
    rep(i, k) v *= x;
    ll ans = por[n];
    rep1(i, n) {
    	ans = max(ans, por[i-1] | (a[i] * v) | sor[i+1]);
    }
    cout << ans << endl;
}