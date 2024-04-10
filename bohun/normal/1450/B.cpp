#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
#define mp make_pair

using ll = long long;
using namespace std;

int t, n, k, x[105], y[105];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		rep(i, 1, n) scanf("%d%d", x + i, y + i);
		int ans = -1;
		rep(i, 1, n) {
			bool ok = 1;
			rep(j, 1, n)
				ok &= abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k;
			if (ok) ans = 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}