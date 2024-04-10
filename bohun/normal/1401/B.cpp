#include <bits/stdc++.h>
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define cat(x) cerr << #x << " = " << x << endl
#define ss(x) (int) x.size()
using ll = long long;

using namespace std;

int main() {
	int T, a1, b1, c1, a2, b2, c2;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d%d%d%d%d", &a1, &b1, &c1, &a2, &b2, &c2);
		int out = min(c1, b2);
		
		c1 -= out;
		b2 -= out;
		
		out += out;
		
		int x = max(0, b1 - a2 - b2), y = max(0, c2 - a1 - c1);
		out -= min(x, y) * 2;
		printf ("%d\n", out);
	}
	return 0;
}