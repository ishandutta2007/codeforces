#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int t, n, p[4] = {2, 3, 5, 7};
string s;
vector<int> v;

void rec(int p = 0, int x = 0) {
	if (p > 0) {
		int ok = 0;
		rep(i, 2, x)
			ok += x % i == 0;
		if (ok)
			v.push_back(x);
	}
	if (p == 4)
		return;
	for (auto d : {2, 3, 5, 7})
		rec(p + 1, 10 * x + d);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	rec();
	sort(v.begin(), v.end());

	cin >> t;
	while (t--) {
		cin >> n >> s;

		bool ok = 0;
		for (auto c : s) {
			int x = c - '0';
			if (x != 2 && x != 3 && x != 5 && x != 7) {
				cout << 1 << '\n' << x << '\n';
				ok = 1;
				break;
			}
		}
		if (ok)
			continue;

		for (auto x : {'2', '3', '5', '7'})
			if (count(s.begin(), s.end(), x) > 1) {
				cout << 2 << '\n' << x << x << '\n';
				ok = 1;
				break;
			}
		if (ok)
			continue;

		for (auto x : v) {
			int p = n - 1;
			int y = x;
			int cnt = 0;
			bool ok = 1;
			while (y > 0) {
				while (p >= 0 && s[p] - '0' != y % 10)
					p--;
				if (p < 0)
					ok = 0;
				p--;
				y /= 10;
				cnt++;
			}
			if (ok) {
				cout << cnt << '\n' << x << '\n';
				break;
			}
		}
	}
	return 0;
}