#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

const int nax = 2600;

int n;
int x[nax], y[nax];

LD dp[nax][nax][2];

LD dis(int a, int b) {
	return sqrtl((LL) (x[a] - x[b]) * (x[a] - x[b]) + (LL) (y[a] - y[b]) * (y[a] - y[b]));
}

int nas(int x) {
	return (x + 1) % n;
}

int pop(int x) {
	return (x - 1 + n) % n;
}

int main() {	
	scanf ("%d", &n);
	rep(i, 0, n - 1) scanf ("%d%d", x + i, y + i);
	
	rep(len, 1, n - 1)
		rep(i, 0, n - 1) {
			int j = (i + len - 1) % n;
			
			dp[pop(i)][j][0] = max(dp[pop(i)][j][0], dp[i][j][0] + dis(i, pop(i)));
			
			dp[pop(i)][j][0] = max(dp[pop(i)][j][0], dp[i][j][1] + dis(j, pop(i)));
			
			dp[i][nas(j)][1] = max(dp[i][nas(j)][1], dp[i][j][0] + dis(i, nas(j)));
			
			dp[i][nas(j)][1] = max(dp[i][nas(j)][1], dp[i][j][1] + dis(j, nas(j)));
		}
	LD best = 0.0;
	rep(i, 0, n - 1)
		rep(k, 0, 1)
			best = max(best, dp[i][(i + n - 1) % n][k]);
	printf ("%.10Lf\n", best);
			
	
	
	return 0;
}