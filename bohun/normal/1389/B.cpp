#include <bits/stdc++.h>
#define ll long long
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

const int N = 111111;

int n, k, z;
int a[N];

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d%d", &n, &k, &z);
		rep(i, 1, n) scanf ("%d", a + i);	
		int maks = -1, best = 0, sum = a[1];
		rep(i, 2, n) {
			int r = k - (i - 1);
			sum += a[i];
			maks = max(maks, a[i] + a[i - 1]);
			if ((r + 1) / 2 > z || r < 0) continue;
			best = max(best, sum + maks * (r / 2) + (r & 1 ? a[i - 1] : 0));
		}
		printf ("%d\n", best);	
	}
	return 0;
}