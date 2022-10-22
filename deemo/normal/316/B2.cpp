#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 1e3 + 50;

int n, k, nxt[MAXN], sz;
bool vis[MAXN], fl, d[MAXN];
vector<int>	ans, adj[MAXN], vec;

void dfs(int v){
	if (v == k)	fl = 1;
	if (vis[v])	return;
	vis[v] = 1;
	sz++;
	for (int u:adj[v])
		dfs(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> nxt[i];
		if (nxt[i]){
			adj[i].push_back(nxt[i]);
			adj[nxt[i]].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]){
			fl = 0, sz = 0;
			dfs(i);
			if (!fl)	vec.push_back(sz);
		}

	d[0] = 1;
	ans.push_back(0);
	for (int x:vec)
		for (int i = MAXN - 1; i >= x; i--)
			if (d[i - x]){
				if (!d[i])
					ans.push_back(i);
				d[i] = 1;
			}


	sort(ans.begin(), ans.end());
	int v = k, z = 0;
	while (v){
		v = nxt[v];
		z++;
	}
	for (int u:ans)
		cout << u + z << "\n";
	return	0;
}