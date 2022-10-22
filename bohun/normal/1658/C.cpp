#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= int(b); i++)
#define per(i, a, b) for (int i = b; i >= int(a); i--)
#define cat(x) cerr << #x << ": " << x << endl
#define sz(x) int(x.size())
using namespace std;
using ll = long long;

int n, a[100100];

void solve() {
	cin >> n;
	rep(i, 0, n - 1)
		cin >> a[i];
	int s = find(a, a + n, 1) - a;
	int res = 1, lst;
	rep(i, 0, n - 1) {
		int p = (s + i) % n;
		int x = a[p];
		if (i == 0 && x != 1) res = 0;
		if (i == 1 && x != 2) res = 0;
		if (i > 1 && (x == 1 || x > lst + 1)) res = 0;
		lst = x;
	}
	cout << (res ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}