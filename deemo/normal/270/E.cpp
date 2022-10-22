#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

const int MAXN = 2e5 + 20;

int n ,m;
vector<pair<int, int>>	adj[MAXN];
int ans[MAXN], save[MAXN];
int sum[MAXN];
bool mark[MAXN];
vector<pair<int, int>>	ed;
int q[MAXN], h, t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b, c;	cin >> a >> b >> c;	a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});

		sum[a] += c;
		sum[b] += c;
		ed.push_back({a, b});
	}
	for (int i = 1; i < n - 1; i++)
		sum[i] /= 2;
	ans[0] = 0;
	ans[n - 1] = n - 1;
	mark[0] = mark[n - 1] = 1;
	for (pair<int, int>	e:adj[0]){
		int u = e.first, w = e.second;
		if (mark[u])	continue;
		sum[u] -= w;
		if (sum[u] == 0)	
			q[t++] = u;
	}	

	int cur = 1;
	while (cur < n - 1){
		int v = q[h++];
		ans[cur++] = v;
		mark[v] = 1;
		for (pair<int, int>	e:adj[v]){
			int u = e.first, w = e.second;
			if (mark[u])	continue;
			sum[u] -= w;
			if (sum[u] == 0)
				q[t++] = u;
		}
	}
	
	for (int i = 0; i < n; i++)
		save[ans[i]] = i;

	for (int i = 0; i < m; i++){
		int a = ed[i].first, b = ed[i].second;
		if (save[a] < save[b])
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
	}
	return 0;
}