#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;

using namespace std;

int main() {
	int T, x, y, n;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d%d", &n, &x, &y);
		int out = 1e9, start = 0, dd = 0;
		for (int dif = 1; dif <= 50; ++dif) {
			if ((y - x) % dif) continue;
			for (int s = 1; s <= 50; ++s) {
				int cnt = 0;
				for (int i = 1; i <= n; ++i) {
					int e = s + (i - 1) * dif;
					cnt += (e == x) + (e == y);
				}
				if (cnt == 2 && s + (n - 1) * dif < out) {
					out = s + (n - 1) * dif;
					start = s;
					dd = dif;
				}
			}
		}
		for (int i = 0; i < n; ++i)
			printf ("%d ", start + i * dd);
		printf ("\n");
	}
	return 0;
}