#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 2e3 + 10;

int n, from[MAXN], to[MAXN];
vector<int>	adj[MAXN];
int cv;
bool flag, vis[MAXN], del[MAXN];
vector<pair<pair<int, int>, pair<int, int>>>	ans;
pair<pair<int, int>, pair<int, int>>	temp;

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	cv++;
	for (int e:adj[v])
		if (!del[e])
			dfs(from[e]^to[e]^v);
}

void go(int v, int p = -1, int ee = -1){
	if (vis[v]){
		temp.F.F = p + 1, temp.F.S = v + 1;
		del[ee] = 1;
		flag = 1;
		return;
	}

	vis[v] = 1;
	for (int e:adj[v]){
		if (del[e])	continue;
		int u = from[e]^to[e]^v;
		if (u^p)
			go(u, v, e);
		if (flag)
			return;
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		cin >> from[i] >> to[i], from[i]--, to[i]--;
		adj[from[i]].push_back(i);
		adj[to[i]].push_back(i);
	}
	int sz = n - 1;

	bool changed = 1;
	while (changed){
		changed = 0;
		memset(vis, 0, sizeof(vis));
		cv = 0;
		dfs(0);
		if (cv ^ n){
			for (int i = 0; i < n; i++)	
				if (!vis[i]){
					temp.S.F = 1, temp.S.S = i + 1;
					from[sz] = 0, to[sz] = i;
					adj[0].push_back(sz);
					adj[i].push_back(sz);
					sz++;
					break;
				}
		
			changed = 1;
			memset(vis, 0, sizeof(vis));
			flag = 0;
			for (int i = 0; !flag && i < n; i++)
				if (!vis[i])
					go(i);
			ans.push_back(temp);
		}
	}

	cout << ans.size() << "\n";
	for (auto v:ans)
		cout << v.F.F << " " << v.F.S << " " << v.S.F << " " << v.S.S << "\n";
	return 0;
}