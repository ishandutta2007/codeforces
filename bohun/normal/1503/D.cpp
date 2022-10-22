#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
const int N = 200005;
int n, p[N], c[N];
int main() {
	cin >> n;
	rep(i, 0, n) {
		int a, b;
		cin >> a >> b;
		if (max(a, b) <= n) {
			cout << -1 << "\n";
			return 0;
		}
		int x = max(a, b) - n - 1;
		c[x] = a <= b;
		p[x] = n - min(a, b);
	}

	int ans = 0;
	int a = -1, b = -1;
	int x = 0, y = 0;

	rep(i, 0, n) {
		if (b < p[i]) {
			b = p[i];
			(c[i] ? x++ : y++);
		}
		else if (a < p[i]) {
			a = p[i];
			(c[i] ? y++ : x++);
		}
		else {
			cout << "-1\n";
			return 0;
		}
		if (max(a, b) == i) {
			ans += min(x, y);
			x = 0, y = 0;
			a = -1, b = -1;
		}
	}
	cout << ans << "\n";
	return 0;
}