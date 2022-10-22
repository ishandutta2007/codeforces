#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

const int N = 1 << 20;
int n, a[N], m;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		rep(i, 1, n)
			cin >> a[i];
		int g = 0;
		while (m--) {
			int x;
			cin >> x;
			g = __gcd(g, x);
		}
		ll res = 0;
		rep(q, 0, 1) {
			rep(i, 1, g) a[i] = -a[i];
			ll cur = 0;
			rep(r, 0, g - 1) {
				int cneg = 0;
				ll S = 0;
				int M = 1e9;
				for (int i = (r == 0 ? g : r); i <= n; i += g) {
					S += abs(a[i]);
					if (a[i] < 0)
						cneg++;
					M = min(M, abs(a[i]));
				}
				if (cneg % 2 == 0)
					cur += S;
				if (cneg % 2 == 1)
					cur += S - 2 * M;
			}
			res = max(res, cur);
		}
		cout << res << endl;
	}

	return 0;
}