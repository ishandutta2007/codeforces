#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 100100;
int n, k;
vector<pair<int, int> >g[maxn];
int dp[maxn], ddp[maxn];

void dfs(int t, int fa){
	for(auto e : g[t]){
		int v = e.fi;
		if(v == fa) continue;
		dfs(v, t);
	}
	vector<int> vec;
	for(auto e : g[t]){
		int v = e.fi, c = e.se;
		if(v == fa) continue;
		vec.pb(dp[v] + c);
	}
	sort(all(vec));
	reverse(all(vec));
	int m = min(k - 1, (int)vec.size());
	for(int i = 0; i < m; ++i) dp[t] += vec[i];
	
	ddp[t] = dp[t];
	for(auto e : g[t]){
		int v = e.fi, c = e.se;
		if(v == fa) continue;
		if(m && dp[v] + c >= vec[m - 1]) 
			ddp[t] = max(ddp[t], dp[t] - (dp[v] + c) + (m < vec.size() ? vec[m] : 0) + (ddp[v] + c));
		else ddp[t] = max(ddp[t], dp[t] + (ddp[v] + c));
	}
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; ++i){
		static int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		g[u].pb(mkp(v, c));
		g[v].pb(mkp(u, c));
	}
	dfs(0, -1);
	printf("%d\n", ddp[0]);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}