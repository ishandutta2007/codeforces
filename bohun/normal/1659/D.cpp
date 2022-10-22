#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using ll = long long;
using namespace std;

const int N = 200200;
int n, a[N], c[N];

void solve() {
	cin >> n;
	rep(i, 1, n) cin >> c[i];
	rep(i, 1, n) a[i] = 1;

	int s = 1;
	while (s <= n && c[s] == 0) {
		a[s++] = 0;
	}

	a[s] = 1;
	int j = s;
	for (int i = s; i <= n && j <= n; i++) {
		int cnt = c[i] - (j - i + 1);
		if (a[i] == 1) cnt -= i - 1;
		j += cnt + 1;
		a[j] = 0;
	}

	rep(i, 1, n) cout << a[i] << " ";
	// rep(i, 1, n) {
	// 	sort(a + 1, a + i + 1);
	// 	rep(j, 1, n) c[j] -= a[j];
	// }
	// rep(i, 1, n) assert(c[i] == 0);
	cout << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}