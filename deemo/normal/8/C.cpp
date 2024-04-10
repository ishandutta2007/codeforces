#include<bits/stdc++.h>

using namespace std;

const int MAXN = 24;

int n, x[MAXN + 3], y[MAXN + 3], d[MAXN + 2][MAXN + 2];
int dp[1<<MAXN], par[1<<MAXN];

int dis(int a, int b){return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);}

void update(int a, int b, int p){
	if (dp[a] > b)
		dp[a] = b, par[a] = p;
}

int main(){
	int xx, yy;	cin >> xx >> yy;
	cin >> n;
	x[n] = xx, y[n] = yy;
	for (int i = 0; i < n; i++)	cin >> x[i] >> y[i];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			d[i][j] = dis(i, j);
	
	memset(par, -1, sizeof(par));
	memset(dp, 63, sizeof(dp));
	dp[0] = 0;
	for (int mask = 1; mask < 1<<n; mask++){
		int v = mask&-mask;
		int vv = __builtin_ctz(v);
		update(mask, dp[mask^v] + (d[n][vv]<<1), mask^v);

		for (int j = vv + 1; j < n; j++)
			if (mask>>j&1)
				update(mask, dp[mask^v^1<<j] + d[n][vv] + d[vv][j] + d[j][n], mask^v^1<<j);
	}

	int cur = (1<<n)-1;
	cout << dp[cur] << "\n";
	cout << "0 ";
	while (cur){
		int j = par[cur]^cur;
		for (int i = 0; i < n; i++)
			if (j>>i&1)
				cout << i + 1 << " ";
		cur = par[cur];
		cout << "0 ";
	}
	cout << "\n";
	return 0;
}