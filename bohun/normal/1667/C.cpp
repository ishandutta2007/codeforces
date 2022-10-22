#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl

using ll = long long;
using namespace std;

int n, k, x;
vector<pair<int, int>> res;

void add(int a, int b) {
	res.push_back({a + x, b + x});
}

bool check() {
	rep(i, 1, n) {
		rep(j, 1, n) {
			bool ok = 0;
			for (auto [x, y] : res) {
				ok |= i == x;
				ok |= j == y;
				ok |= i - x == j - y;
			}
			if (!ok) {
				cat(i);cat(j);
				return false;
			}
		}
	}
	return true;
}

void solve() {
	cin >> n;
	k = (n + 2) / 3;
	if (n % 3 == 0) {
		add(1, 1);
		x = 1;
	}
	rep(i, 0, k - 2) {
		add(k - 1 - i, 1 + i);
	}
	rep(i, 0, k - 1) {
		add(2 * k - 1 - i, k + i);
	}
	cout << res.size() << endl;
	for (auto [a, b] : res) cout << a << " " << b << endl;

	// assert(check());
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	// cin >> T;
	while (T--) solve();

	return 0;
}