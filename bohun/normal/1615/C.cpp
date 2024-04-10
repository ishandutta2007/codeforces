#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

int n;
string a, b;

void solve() {
	cin >> n >> a >> b;

	int cnta = count(a.begin(), a.end(), '1');
	int cntb = count(b.begin(), b.end(), '1');

	int res1 = 1e9;
	if (cnta == cntb) {
		res1 = 0;
		for (int i = 0; i < n; i++)
			res1 += a[i] != b[i];
		assert(res1 % 2 == 0);
	}

	int res2 = 1e9;
	int c[2] = {};
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			c[a[i] - '0']++;
		}
	}

	if (c[0] + 1 == c[1])
		res2 = c[0] + c[1];
	
	int ans = min(res1, res2);
	cout << (ans == 1e9 ? -1 : ans) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}