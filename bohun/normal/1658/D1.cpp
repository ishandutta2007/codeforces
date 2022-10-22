#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= int(b); i++)
#define per(i, a, b) for (int i = b; i >= int(a); i--)
#define cat(x) cerr << #x << ": " << x << endl
#define sz(x) int(x.size())
using namespace std;
using ll = long long;

int l, r, a[1 << 20], c[17];

void solve() {
	cin >> l >> r;
	rep(i, 1, r - l + 1) cin >> a[i];
	rep(i, 0, 16) c[i] = 0;
	rep(i, 0, r) rep(j, 0, 16) if (i >> j & 1) c[j]++;
	rep(i, 1, r - l + 1) rep(j, 0, 16) if (a[i] >> j & 1) c[j]--;
	int x = 0;
	rep(i, 0, 16) if (c[i]) x += 1 << i;
	cout << x << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}