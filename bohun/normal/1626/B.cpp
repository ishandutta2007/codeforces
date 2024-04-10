#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << "\n";
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int t, n;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> s;
		n = sz(s);

		bool ok = 0;
		per(i, 0, n - 2) {
			int x = (s[i] - '0') + (s[i + 1] - '0');
			if (x >= 10) {
				s[i] = x / 10 + '0';
				s[i + 1] = x % 10 + '0';
				ok = 1;
				break;
			}
		}

		if (!ok) {
			rep(i, 0, n - 2) {
				if (s[i + 1] != '0' || i + 1 == n - 1) {
					s[i] += s[i + 1] - '0';
					s.erase(s.begin() + i + 1);
					ok = 1;
					break;
				}
			}
		}

		assert(ok);
		cout << s << endl;
	}

	return 0;
}