#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 30;

int n, m;
bool vis[MAXN], block[MAXN];
vector<int>	adj[MAXN];
pair<pii, int> ans[MAXN];
int sz;

int dfs(int v = 0){
	vis[v] = 1;
	block[v] = 1;
	vector<int>	zz;
	for (int u:adj[v])
		if (!block[u]){
			int ind = -1;
			if (!vis[u])
				ind = dfs(u);
			if (ind == -1)
				zz.push_back(u);
			else
				ans[sz++] = {{ind+1, u+1}, v+1};
		}
	
	while (zz.size() > 1){
		ans[sz].F = {zz.back()+1, v+1};
		zz.pop_back();
		ans[sz++].S = zz.back()+1;
		zz.pop_back();
	}
	
	int ret = -1;
	if (zz.size() & 1)
		ret = zz.back(), zz.pop_back();
	block[v] = 0;
	return ret;
}

int main(){
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++){
			int a, b; scanf("%d %d", &a, &b), a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	{
		for (int v = 0; v < n; v++)
			if (!vis[v])
				dfs(v);
		printf("%d\n", sz);
		for (int i = 0; i < sz; i++)
			printf("%d %d %d\n", ans[i].F.F, ans[i].F.S, ans[i].S);
	}
	return 0;
}