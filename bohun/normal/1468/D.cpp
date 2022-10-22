#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int n, m, a, b, s[200200];

bool check(int k) {
	int e = (a < b ? b - 1 : n - b);
	rep(i, 0, k)
		if (s[k - 1 - i] + (i + 1) > e)
			return false;
	return true;
}

void solve() {
	cin >> n >> m >> a >> b;
	rep(i, 0, m)
		cin >> s[i];
	sort(s, s + m);

	int l = 0, r = min(m, abs(a - b) - 1);
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (check(m))
			l = m;
		else
			r = m - 1;
	}

	cout << l << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}