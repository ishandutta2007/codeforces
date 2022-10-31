#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MX = 5005;
const ll INF = 1000000000LL * 100000LL;
 
int x[MX];
pair<int, int> p[MX];
 
ll dp[2][MX];
ll S[MX];
 
void calc(int jl, int jr, int kl, int kr, int i)
{
	if (jl > jr) return;
	int m = (jl + jr) / 2;
	int nxt_k = -1;
	ll v = INF;
	for (int k = max(kl, m - p[i].second); k <= min(kr, m); k++) {
		ll tmp = dp[!(i&1)][k] + S[m] - S[k];
		if (nxt_k == -1 || tmp < v) {
			v = tmp;
			nxt_k = k;
		}
	}
	
	dp[i&1][m] = v;
	calc(jl, m - 1, kl, nxt_k, i);
	calc(m + 1, jr, nxt_k, kr, i);
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
 
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= m; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(x + 1, x + 1 + n);
	sort(p + 1, p + 1 + m);
	
	for (int i = 1; i <= n; i++) dp[0][i] = INF;
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			S[j] = S[j - 1] + abs(x[j] - p[i].first);
		}
		calc(1, n, 0, n, i);
	}
	if (dp[m&1][n] == INF) dp[m&1][n] = -1;
	cout << dp[m&1][n] << "\n";
}