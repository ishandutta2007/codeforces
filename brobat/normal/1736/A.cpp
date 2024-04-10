#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) x.begin(), x..end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
const int N = 200100;
const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int ans1 = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = 0; i < n; i++) {
		ans1 += a[i] ^ b[i];
		cnt1 += a[i];
		cnt2 += b[i];
	}
	cout << min(ans1, 1 + abs(cnt1 - cnt2)) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}