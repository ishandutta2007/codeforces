//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		string s, t;
		cin >> s >> t;

		int res = 0;
		int last = -1;
		FOR(i, n) {
			int x = s[i] - '0' + 2 * (t[i] - '0');
			if (1 <= x && x <= 2) {
				if (last == 0)
					res += 1;
				res += 2;
				last = -1;
			}
			else if (x == 0) {
				if (last == 0) {
					res += 1;
					last = 0;
				}
				else if (last == 3) {
					res += 2;
					last = -1;
				}
				else
					last = 0;
			}
			else {
				if (last == 0) {
					res += 2;
					last = -1;
				}
				else if (last == 3) {
					last = 3;
				}
				else
					last = 3;
			}
		}
		if (last == 0)
			res++;
		cout << res << '\n';
	}
	return 0;
}