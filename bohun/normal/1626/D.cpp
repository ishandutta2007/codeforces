#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << "\n";
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 1 << 20;
int t, n, p[N], resA[N], resB[N], res[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	per(i, 0, N - 2) {
		if (__builtin_popcount(i) == 1)
			res[i] = 0;
		else
			res[i] = res[i + 1] + 1;
	}

	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n) p[i] = 0;
		rep(i, 1, n) {
			int x;
			cin >> x;
			p[x]++;
		}

		p[n + 1] = 0;
		rep(i, 1, n) p[i] += p[i - 1];
		rep(i, 0, n) resA[i] = res[p[i]];
		per(i, 1, n + 1) resB[i] = res[p[n] - p[i - 1]];

		int ans = 1e9;
		rep(i, 1, n) {
			rep(bit, 0, 18) {
				int x = upper_bound(p + 1, p + n + 1, p[i - 1] + (1 << bit)) - p - 1;
				ans = min(ans, resA[i - 1] + resB[x + 1] + res[p[x] - p[i - 1]]);
			}
		}
		cout << ans << endl;
	}

	return 0;
}