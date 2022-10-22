#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

int n, m;
char a[100], b[100];

void solve() {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, m) cin >> b[i];
	int d = n - m;
	bool ok = false;
	rep(i, 1, d + 1) {
		ok |= b[1] == a[i];
	}
	rep(i, 2, m) {
		ok &= b[i] == a[i + d];
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}