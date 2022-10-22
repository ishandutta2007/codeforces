#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n, f[MAXN], q[MAXN], t, g, cc[MAXN], ss[MAXN], sz;
pair<int, int>	vec[MAXN];
vector<int>	adj[MAXN];
vector<pair<int, int>>	ans;
bool vis[MAXN];

void dfs(int v){
	q[t++] = v;
	vis[v] = 1;
	for (int u:adj[v])
		if (!vis[u])	dfs(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> f[i], f[i]--, adj[i].push_back(f[i]), adj[f[i]].push_back(i), cc[f[i]]++;
	
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			dfs(i);
			t = 0, g++;
		}

	memset(vis, 0, sizeof(vis));
	if (g == 1){
		dfs(0);
		for (int i = 0; i < t; i++)
			vis[q[i]] = 0;

		int v = 0;
		while (!vis[v])
			vis[v] = 1, v = f[v];

		for (int i = 0; i < t; i++)
			if (!cc[q[i]])
				ans.push_back({v, q[i]});
	}
	else{
		for (int i = 0; i < n; i++)
			if (!vis[i]){
				dfs(i);
				for (int j = 0; j < t; j++)
					vis[q[j]] = 0;
				int v = i, cnt = 0;
				while (!vis[v])
					vis[v] = 1, v = f[v];
				int u = v;

				for (int j = 0; j < t; j++){
					vis[q[j]] = 1;
					if (!cc[q[j]])	cnt++, u = q[j];
				}

				for (int j = 0; j < t && cnt > 1; j++)
					if (!cc[q[j]]){
						ans.push_back({v, q[j]});
						cnt--;
					}
					
				t = 0;
				vec[sz++] = {u, v};
			}

		for (int i = 0; i < g; i++)
			ans.push_back({vec[i].second, vec[(i + 1) % g].first});
	}

	cout << (int)ans.size() << "\n";
	for (auto v:ans)
		cout << v.first + 1 << " " << v.second + 1 << "\n";
	return 0;
}