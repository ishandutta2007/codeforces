#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

bool solve(ll h1, ll d1, ll h2, ll d2) {
	auto x = (h1 + d2 - 1) / d2;
	auto y = (h2 + d1 - 1) / d1;
	return y <= x;
}

void solve() {
	ll h1, d1, h2, d2, k, hd, dd;
	cin >> h1 >> d1 >> h2 >> d2 >> k >> dd >> hd;
	rep(a, 0, k) {
		if (solve(h1 + a * hd, d1 + (k - a) * dd, h2, d2)) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}