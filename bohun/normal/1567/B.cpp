//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int x[300300];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	rep(i, 1, 300000)
		x[i] = x[i - 1] ^ i;

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		int xo = x[a - 1];
		int res;
		if (xo == b)
			res = a;
		else {
			if ((xo ^ b) != a)
				res = a + 1;
			else
				res = a + 2;
		}
		cout << res << '\n';
	}

	return 0;
}