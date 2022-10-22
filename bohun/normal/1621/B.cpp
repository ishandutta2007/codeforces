#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, b, a) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << "\n";
using ll = long long;
using namespace std;

int n;

void solve() {
	cin >> n;
	pair<int, int> L = {2e9, 0};
	pair<int, int> R = {-2e9, 0};
	pair<int, int> B = {-1, 0};
	rep(i, 1, n) {
		int a, b, c;
		cin >> a >> b >> c;
		L = min(L, {a, c});
		R = max(R, {b, -c});
		B = max(B, {b - a, -c});
		cout << min(L.second - R.second, (B.first == R.first - L.first ? -B.second : int(2e9))) << "\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}