#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200 + 5;

int n, from[MAXN], to[MAXN], d[MAXN], gg;
bool del[MAXN], vis[MAXN];
vector<int>	adj[MAXN];

void go(int v, int p = -1){
	d[v] = 0;
	vis[v] = 1;
	int m1 = 0, m2 = 0;
	for (int e:adj[v])
		if (!del[e] && e^p){
			int u = from[e]^to[e]^v;
			go(u, e);
			d[v] = max(d[v], d[u] + 1);
			m2 = max(m2, d[u] + 1);
			if (m2 > m1)
				swap(m1, m2);
		}
	gg = max(gg, m1 + m2);
}

int get(){
	int ret = 1;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			gg = 0;
			go(i);
			ret *= gg;
		}
	return ret;
}

int main(){
	cin >> n;
	for (int i = 0; i < n - 1; i++)
		cin >> from[i] >> to[i], from[i]--, to[i]--, adj[from[i]].push_back(i), adj[to[i]].push_back(i);
	int ans = 0;

	for (int i = 0; i < n - 1; i++)
		del[i] = 1, ans = max(ans, get()), del[i] = 0;
	cout << ans << endl;
	return 0;
}