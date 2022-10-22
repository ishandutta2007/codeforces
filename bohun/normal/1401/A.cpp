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
	int T, n, k;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &n, &k);
		int out = max(0, k - n);
		n = max(n, k);
		while (n % 2 != k % 2 || n < k) n++, out++;
		printf ("%d\n", out);
	}
	return 0;
}