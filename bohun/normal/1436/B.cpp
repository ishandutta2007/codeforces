#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

int T, n, ans[105][105];

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		if (n == 2) {
			printf ("1 1\n1 1\n");
			continue;
		}
		rep(i, 1, n) 
			rep(j, 1, n)
				ans[i][j] = 0;
				
		rep(i, 1, n - 1)
			ans[i][i] = ans[i + 1][i] = 1;
		ans[1][n] = ans[n][n] = 1;
		rep(i, 1, n) {
			rep(j, 1, n)
				printf ("%d ", ans[i][j]);
			puts("");
		}
	}
	return 0;
}