#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

int main() {
	int T, n, m, t[310][310], ans[310][310];
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &n, &m);
		bool good = 1;
		rep(i, 1, n)
			rep(j, 1, m) {
				scanf ("%d", &t[i][j]);
				int cnt = (i > 1) + (i < n) + (j > 1) + (j < m);
				if (t[i][j] > cnt) good = 0;
				ans[i][j] = cnt;
			}
		if (!good) {
			printf ("NO\n");
			continue;
		}
		printf ("YES\n");
		rep(i, 1, n) {
			rep(j, 1, m)
				printf ("%d ", ans[i][j]);
			printf ("\n");
		}
	}
	return 0;
}