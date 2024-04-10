#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

int n, a[200111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		rep(i, 1, n)
			cin >> a[i];
		sort(a + 1, a + n + 1);

		rep(i, 1, n / 2) {
			cout << a[i + 1] << ' ' << a[1] << "\n";
		}
	}

	return 0;
}