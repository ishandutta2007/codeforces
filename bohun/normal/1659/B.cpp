#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using ll = long long;
using namespace std;

int T, n, k, ans[200200];
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> n >> k >> s;
		if (k % 2) {
			for (auto &x : s) {
				x = (x == '0' ? '1' : '0');
			}
		}

		rep(i, 0, n - 1) ans[i] = 0;

		rep(i, 0, n - 2) {
			if (k == 0) break;
			if (s[i] == '0') {
				ans[i]= 1;
				s[i] = '1';
				k--;
			}
		}

		ans[n - 1] = k;
		if (k % 2) s[n - 1] = (s[n - 1] == '0' ? '1' : '0');

		cout << s << "\n";
		rep(i, 0, n - 1) cout << ans[i] << " ";
		cout << "\n";
	}

	return 0;
}