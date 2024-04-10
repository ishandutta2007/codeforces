#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

int n, m, a[100100], b[100100];

void solve() {
	cin >> n >> m;
	rep(i, 1, m) cin >> a[i];
	sort(a + 1, a + m + 1);
	rep(i, 2, m) b[i] = a[i] - a[i - 1] - 1;
	b[1] = n + a[1] - a[m] - 1;
	sort(b + 1, b + m + 1);
	reverse(b + 1, b + m + 1);
	int res = 0;
	rep(i, 1, m) {
		ll x = b[i] - 4LL * (i - 1);
		if (x == 1 || x == 2) {
			res++;
		}
		else if (x > 2) {
			res += x - 1;
		}
	}
	cout << n - res << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}