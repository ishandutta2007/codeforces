#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cout << #x << " = " << x << endl
 
using namespace std;

const int nax = 5e5 + 111;

int q;
int n, k;
int a, b, c;
vector <pair<int, int>> v[nax];
ll dp[nax][2];

void dfs(int u, int p) {
	vector <pair<int,int>> dif; // roznica i wierzcholek
	for(auto it : v[u]) {
		if(it.fi == p)
			continue;
			
		dfs(it.fi, u);
		dif.pb({dp[it.fi][0] + it.se - dp[it.fi][1], it.fi});
	}
	
	sort(dif.begin(), dif.end());
	reverse(dif.begin(), dif.end());
	
	for(int i = 0; i < ss(dif); ++i) {
		auto it = dif[i];
		if(i < k - 1)
			dp[u][0] += max(it.fi + dp[it.se][1], dp[it.se][1]);
		else
			dp[u][0] += max(dp[it.se][0], dp[it.se][1]);
		if(i < k)
			dp[u][1] += max(it.fi + dp[it.se][1], dp[it.se][1]);
		else
			dp[u][1] += max(dp[it.se][0], dp[it.se][1]);
	}
}
		
 
int main() {
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d", &n, &k);
		for(int i = 1; i < n; ++i) {
			scanf("%d %d %d", &a, &b, &c);
			v[a].pb({b, c});
			v[b].pb({a, c});
		}
		dfs(1, 0);
		printf("%lld\n", max(dp[1][0], dp[1][1]));
		for(int i = 1; i <= n; ++i) {
			v[i].clear();
			dp[i][0] = dp[i][1] = 0;
		}
	}
		
	
	
 
	return 0;
}