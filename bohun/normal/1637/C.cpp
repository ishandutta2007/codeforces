#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

int t, n, a[200200];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n;
		ll s = 0, o = 0;
		rep(i, 1, n) {
			cin >> a[i];
			if (2 <= i && i <= n - 1) {
				s += a[i] + a[i] % 2;
				o += a[i] == 1;
			}
		}

		if (o == n - 2 || (n == 3 && a[2] % 2)) {
			cout << "-1\n";
		}
		else {
			cout << s / 2 << "\n";
		}
	}

	return 0;
}