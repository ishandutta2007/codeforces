#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const double INF = 1.0 / 0.0;

int n, k, a[200005];
double dp[55][200005];

double ps[200005], psv[200005], ptot[200005];

double cost(int l, int r)
{
	return ptot[r] - ptot[l - 1] - ps[l - 1] * (psv[r] - psv[l - 1]);
}

void solve(int id, int l, int r, int lp, int rp)
{
	if(l > r) return;
	int mid = l + r >> 1;
	
	int cpos = -1;
	for(int i = lp; i <= min(rp, mid - 1); i ++) {
		double cc = dp[id - 1][i] + cost(i + 1, mid);
		if(cc < dp[id][mid]) {
			dp[id][mid] = cc;
			cpos = i;
		}
	}
	
	solve(id, l, mid - 1, lp, cpos);
	solve(id, mid + 1, r, cpos, rp);
}

void gen_dp(int id)
{
	for(int i = 0; i <= n; i ++) dp[id][i] = INF;
	solve(id, id, n, 0, n - 1);
}

int main()
{
	scanf("%d%d", &n, &k);
	rep1(i, n) scanf("%d", &a[i]);
	rep1(i, n) {
		ps[i] = ps[i - 1] + a[i];
		psv[i] = psv[i - 1] + 1.0 / a[i];
		ptot[i] = ptot[i - 1] + ps[i] / a[i];
	}
	
	dp[0][0] = 0;
	rep1(i, n) dp[0][i] = INF;
	rep1(i, k) gen_dp(i);
	printf("%.10lf\n", dp[k][n]);
	return 0;
}