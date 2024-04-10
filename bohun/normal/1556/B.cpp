#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

const ll inf = 1e18;
int a[100100];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		rep(i, 0, n)
			cin >> a[i];
		long long res = inf;
		rep(p, 0, 2) {
			int cnt = 0;
			int s = 0;
			long long cur = 0;
			rep(i, 0, n) {
				if (a[i] % 2 == p) {
					cur += abs(cnt - s);
					cnt++;
				}
				else s++;
			}
			if ((n + 1) / 2 == cnt)
				res = min(res, cur);
		}
		if (res == inf)
			res = -1;
		cout << res << '\n';
	}
	return 0;
}