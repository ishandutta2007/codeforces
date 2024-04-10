#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int t, l, r;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> l >> r;
		int x = (r + 1) / 2;
		cout << max(r - max(l, (x + 1)), (l <= x ? x - 1 : 0)) << '\n';
	}
	return 0;
}