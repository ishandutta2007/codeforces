#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int n;
ll res, cnt[4];
int main() {
	cin >> n;
	rep(i, 0, n) {
		int x, y;
		cin >> x >> y;
		cnt[2 * (x / 2 % 2) + y / 2 % 2]++;
	}
	res = 1ll * n * (n - 1) * (n - 2) / 6;
	res -= cnt[0] * cnt[1] * cnt[2];
	res -= cnt[0] * cnt[1] * cnt[3];
	res -= cnt[0] * cnt[2] * cnt[3];
	res -= cnt[1] * cnt[2] * cnt[3];
	cout << res << "\n";
	return 0;
}