#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long 
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)x.size())
#define rep(i, a, n) for (int i = a; i <= n; i ++ )
#define dep(i, a, n) for (int i = n; i >= a; i -- )
#define dbg(x) cerr << "debug: " << #x << ": " << (x) << '\n';
#define dbg2(x, y) cerr << "debug: " << #x << ": " << (x) << " " << #y << ": " << y << '\n';
 
const int P = 998244353;
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<int> a(n + 2);
    rep(i, 1, n) {
        cin >> a[i];
    }
 
    int ans = 1;
    rep(i, 1, k) {
        (ans *= i) %= P;
    }
 
    rep(i, k + 1, n) {
        if (a[i - k] == -1) {
            (ans *= i) %= P;
        } else if (a[i - k] == 0) {
            (ans *= (k + 1)) %= P;
        }
    }
 
    rep(i, n - k + 1, n) {
        if (a[i] != 0 && a[i] != -1) {
            ans = 0;
        }
    }
 
    cout << ans << '\n';
}
 
signed main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
    cin >> t;
	while (t -- ) {
		solve();
	}
	return 0;
}