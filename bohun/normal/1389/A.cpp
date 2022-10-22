#include <bits/stdc++.h>
#define ll long long
#define rep(i, j, n) for (int i = j; j <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

int main() {
	int T, l, r;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &l, &r);
		if (2 * l > r) printf ("-1 -1\n");
		else printf ("%d %d\n", l, 2 * l);
	}
	return 0;
}