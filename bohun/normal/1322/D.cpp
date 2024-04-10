#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, l, r) for (int i = r; l <= i; --i)

using ll = long long;
using namespace std;

const int N = 5005;

int n, m, ag[N], cost[N], profit[N];
ll dp[N][N], out;

int main() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, n) scanf ("%d", ag + i);
	rep(i, 1, n) scanf ("%d", cost + i);
	rep(i, 1, n + m) scanf ("%d", profit + i);
	rep(val, 1, n + m) rep(ile, 0, n) dp[val][ile] = (!ile ? 0 : -1e18); 
	per(i, 1, n) {
		int a = ag[i];
		per(ile, 0, n - 1) 
			dp[a][ile + 1] = max(dp[a][ile + 1], dp[a][ile] + profit[a] - cost[i]);
		rep(ile, 0, n) {
			int c = ile, val = a;
			ll razem = dp[a][ile];
			do {
				c /= 2;
				++val;
				razem += profit[val] * c;
				dp[val][c] = max(dp[val][c], razem);
			} while (c != 0);
			out = max(out, razem);
		}
		rep(val, 1, n + m) dp[val][0] = max(dp[val][0], dp[val - 1][0]);
	}
	printf ("%lld\n", out);
	return 0;
}