#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int n;

void solve() {
	cin >> n;
	map<pair<int, int>, long long> c;
	while (n--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int x = x2 - x1;
		int y = y2 - y1;
		int g = __gcd(abs(x), abs(y));
		x /= g;
		y /= g;
		c[make_pair(x, y)]++;
	}

	long long res = 0;
	for (auto [p, cnt] : c) {
		auto [x, y] = p;
		res += cnt * c[make_pair(-x, -y)];
	}

	cout << res / 2 << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}