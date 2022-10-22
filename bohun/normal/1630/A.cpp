#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

int t, n, k, a[1 << 20];

void add(int x, int y) {
	a[x] = y;
	a[y] = x;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		rep(i, 0, n - 1)
			a[i] = n - 1 - i;
		if (n == 4 && k == 3) {
			cout << -1 << endl;
			continue;
		}
		if (0 < k && k < n - 1) {
			add(n - 1 - k, 0);
			add(n - 1, k);
		}
		if (k == n - 1) {
			add(n - 1, n - 2);
			add(1, n / 2 + 1);
			add(n - 1 - (n / 2 + 1), 0);
		}
		rep(i, 0, n - 1) {
			if (i < a[i]) {
				cout << i << " " << a[i] << endl;
			}
		}
	}
	return 0;
}