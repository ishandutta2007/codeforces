#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 10;
const ll INF = 1e15;

int n, s, t, sec[MAXN];
ll x[MAXN], a[MAXN], b[MAXN], c[MAXN], d[MAXN];
ll dp[2][MAXN];

int main(){
	scanf("%d %d %d", &n, &s, &t), s--, t--;
	for (int i = 0; i < n; i++)	scanf("%lld", &x[i]);
	for (int i = 0; i < n; i++)	scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++)	scanf("%lld", &b[i]);
	for (int i = 0; i < n; i++)	scanf("%lld", &c[i]);
	for (int i = 0; i < n; i++)	scanf("%lld", &d[i]);
		
	bool cur = 0;
	for (int i = 0; i < MAXN; i++)	dp[cur][i] = INF;
	dp[cur][0] = 0;

	bool f1 = 0, f2 = 0;
	for (int i = 0; i < n; i++, cur = !cur){
		int v = i;
		ll dis = (i?x[i] - x[i-1]:0);

		for (int j = 0; j < MAXN; j++){
			dp[!cur][j] = INF;
			dp[cur][j] += dis * ll(j * 2ll - int(f1) - int(f2));
		}
		
		//cout << dp[!cur][0] << endl;
		for (int j = 0; j <= n; j++){
			if (v == s){
				f1 = 1;
				dp[!cur][j + 1] = min(dp[!cur][j + 1], dp[cur][j] + d[v]);
				if (j)
					dp[!cur][j] = min(dp[!cur][j], dp[cur][j] + c[v]);
			}
			else if (v == t){
				dp[!cur][j + 1] = min(dp[!cur][j + 1], dp[cur][j] + b[v]);
				if (j)
					dp[!cur][j] = min(dp[!cur][j], dp[cur][j] + a[v]);
				f2 = 1;
			}
			else{
				if (j > 1 || (!f1 || !f2))
					dp[!cur][j + 1] = min(dp[!cur][j + 1], dp[cur][j] + b[v] + d[v]);
				if (j){
					if (!f2 || j > 1)
						dp[!cur][j] = min(dp[!cur][j], dp[cur][j] + a[v] + d[v]);
					if (!f1 || j > 1)
						dp[!cur][j] = min(dp[!cur][j], dp[cur][j] + b[v] + c[v]);
					if (j > 1)
						dp[!cur][j - 1] = min(dp[!cur][j - 1], dp[cur][j] + a[v] + c[v]);
				}
			}
		}
//		cout << dp[!cur][1] << endl;
	}
	
	printf("%lld\n", dp[cur][1]);
	return 0;
}