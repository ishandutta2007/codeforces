#include <bits/stdc++.h>
#define ll long long
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

const int N = 4010;

int n, p[N];
bitset <N> dp[N], ep;

void solve() {
	scanf ("%d", &n);
	n *= 2;
	rep(i, 1, n) scanf ("%d", p + i);
	p[n + 1] = n + 1;
	
	rep(i, 0, n)
		dp[i].reset();
			
	dp[0][0] = 1;
	rep(i, 1, n) {
		per(j, 1, i) {
			if (p[j] > p[i + 1]) break;
			dp[i] = (dp[i] | (dp[j - 1] << ((i - j + 1))));
		}
		//rep(j, 0, 5) {
		//	printf ("%d", (int)dp[i][j]);
		//}
		//printf ("\n");
		ep = dp[i];
		rep(j, 0, i)
			dp[i][j] = ep[i - j];
	}
	printf ((int) dp[n][n / 2] == 1 ? "YES\n" : "NO\n");
}	

int main() {	
	int T;
	scanf ("%d", &T);
	while (T--)
		solve();
	
	return 0;
}