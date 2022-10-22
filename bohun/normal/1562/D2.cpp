#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int t, n, q;
string s;
int a[300300];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		map<int, vector<int>> m;
		cin >> n >> q >> s;
		rep(i, 0, n) {
			a[i + 1] = a[i] + (i % 2 ? -1 : 1) * (s[i] == '+' ? 1 : -1);
			m[a[i + 1]].push_back(i + 1);
		}
		auto print = [&](int x, int s) {
			if (s > 0)
				s = (s + 1) / 2;
			else
				s = -(-s + 1) / 2;
			s += a[x - 1];
			cout << *lower_bound(m[s].begin(), m[s].end(), x) << '\n';
		};
		while (q--) {
			int l, r;
			cin >> l >> r;
			int s = a[r] - a[l - 1];
			if (s == 0) {
				cout << 0 << '\n';
				continue;
			}
			if (s % 2) {
				cout << 1 << '\n';
				print(l, s);
			}
			else {
				cout << 2 << '\n';
				cout << r << ' ';
				print(l, a[r - 1] - a[l - 1]);
			}
		}
	}
	return 0;
}