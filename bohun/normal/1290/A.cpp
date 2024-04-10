#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 3511;

int T;

int n, m, k;
int a[nax];
int ans[nax];

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; ++i)
			scanf ("%d", a + i);
		for (int i = 0; i <= k; ++i)
			ans[i] = 1e9 + 11;
		int przed = m - 1;
		k = min(k, przed);
		int w = przed - k;
		for (int i = 1; i <= w + 1; ++i) {
			int r = (w - i + 1);
			int R = n - r;
			for (int j = 0; j <= k; ++j)
				ans[j] = min(ans[j], max(a[i + j], a[R - (k - j)]));
		}
		int best = 0;
		for (int j = 0; j <= k; ++j)
			best = max(best, ans[j]);
		printf ("%d\n", best);
	}



	return 0;
}