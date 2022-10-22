#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;

using namespace std;

const int N = 2e5 + 10;

int T, n, k;
int x[N], dp[N];

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) scanf ("%d", x + i);
		for (int i = 1; i <= n; ++i) {
			int y; scanf ("%d", &y);
		}
		sort(x + 1, x + n + 1);
		dp[n + 1] = 0;
		int out = 0;
		for (int i = n; 1 <= i; --i) {
			int j = upper_bound(x + 1, x + n + 1, x[i] + k) - x - 1;
			dp[i] = j - i + 1;
			out = max(out, dp[i] + dp[j + 1]);
			dp[i] = max(dp[i], dp[i + 1]);
		}
		printf ("%d\n", out);
	}
	return 0;
}