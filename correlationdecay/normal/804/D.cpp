#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
#define maxn 100009
using namespace std;
int n, m, q;
bool vis[maxn];
int dp1[maxn],dp2[maxn];
int mx[maxn], mxx[maxn];
int p[maxn];
vector<int>dis[maxn];
int sz[maxn];
vector<int>G[maxn];
map<pair<int,int>,double>mp;
const int INF = 1e9;

int findset(int x){
	return x == p[x] ? x : p[x] = findset(p[x]);
}

void unionset(int x, int y){
	p[findset(x)] = findset(y);
}

void dfs1(int u, int fa){
	vis[u] = 1;
	dp1[u] = 0;
	mx[u] = mxx[u] = -INF;
	for(auto v : G[u]){
		if(v == fa)
			continue;
		dfs1(v, u);
		dp1[u] = max(dp1[u], dp1[v] + 1);
		if(dp1[v] > mx[u]){
			mxx[u] = mx[u];
			mx[u] = dp1[v];
		}
		else if(dp1[v] > mxx[u]){
			mxx[u] = dp1[v];
		}
	}
}

void dfs2(int u, int fa){
	for(auto v: G[u]){
		if(v == fa)
			continue;
		dp2[v] = dp2[u] + 1;
		if(dp1[v] == mx[u])
			dp2[v] = max(dp2[v], mxx[u] + 2);
		else
			dp2[v] = max(dp2[v], mx[u] + 2);
		dfs2(v, u);
	}
}

void solve(int u, int v){
	if(sz[u] > sz[v])
		swap(u, v);
	if(sz[u] == sz[v] && u > v)
		swap(u, v);
	if(mp.count(make_pair(u, v))){
		printf("%.10f\n", mp[make_pair(u, v)]);
		return;
	}
	int sz1 = dis[u].size();
	int sz2 = dis[v].size();
	int cur = max(dis[u][sz1 - 1], dis[v][sz2 - 1]);
	double ans = 0;
	int q = sz2;
	double R = 0;
	for(int i = 0; i < sz1; i++){
		while(q - 1 >= 0 && dis[v][q - 1] + dis[u][i] + 1 >= cur){
			q--;
			R += dis[v][q];
		}
		if(q == sz2){
			ans += 1.0 / sz1 * q / sz2 * cur;
		}
		else{
			ans += 1.0 / sz1 * q / sz2 * cur;
			ans += 1.0 / sz1 * ((R + sz2 - q) / sz2 + 1.0 * dis[u][i] * (sz2 - q) / sz2);
		}
	}
	mp[make_pair(u, v)] = ans;
	printf("%.10f\n", ans);
	return;
}

int main(){
	scanf("%d%d%d", &n ,&m, &q);
	for(int i = 1; i <= n; i++)
		p[i] = i;
	for(int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		unionset(u, v);
	}
	
	for(int i = 1; i <= n; i++){
		if(vis[i])
			continue;
		dfs1(i, -1);
		dfs2(i, -1);
	}
	
	for(int i = 1; i <= n; i++){
		dis[findset(i)].push_back(max(dp1[i], dp2[i]));
	}
	
	for(int i = 1; i <= n; i++){
		if(findset(i) == i)
			sort(dis[i].begin(), dis[i].end());
		sz[findset(i)]++;
	}
	
	
	while(q--){
		int u, v;
		scanf("%d%d", &u, &v);
		u = findset(u);
		v = findset(v);
		if(u == v)
			puts("-1");
		else{
			solve(u, v);
		}
	}
	return 0;
}