#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int t, n;
string s;

void ans(int a, int b, int c, int d) {
	cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}

void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		if (s[i] == '0') {
			if (2 * i < n)
				ans(i + 1, n, i + 2, n);
			else
				ans(1, i + 1, 1, i);
			return;
		}
	ans(1, (n + 1) / 2, (n + 1 + (n % 2 == 0)) / 2, n);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}