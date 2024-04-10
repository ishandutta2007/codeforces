#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
const int N = 1 << 20;
int n, a[N], vis[N], xo[N], res[N];
int main() {
	cin >> n;

	if (n % 2 == 0) {
		cout << "First\n";
		rep(i, 1, n + 1) cout << i << " ";
		rep(i, 1, n + 1) cout << i << " ";
		return 0;
	}

	cout << "Second\n";

	rep(i, 1, 2 * n + 1) {
		cin >> a[i];
		xo[a[i]] ^= i;
	}

	rep(i, 1, 2 * n + 1) {
		if (vis[i % n]) continue;
		int x = i;
		while (!vis[x % n]) {
			vis[x % n] = 1;
			res[x] = 1;
			x = (x <= n ? x + n : x - n);
			x = xo[a[x]] ^ x;
		}
	}

	int odd = 0;
	rep(i, 1, 2 * n + 1)
		odd ^= res[i] && i % 2;

	rep(i, 1, 2 * n + 1)
		if (res[i] ^ odd)
			cout << i << " ";
	return 0;
}