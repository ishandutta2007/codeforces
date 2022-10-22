#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
#include<numeric>

using namespace std;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, m, mx[MAXN], sg[MAXN], depth[MAXN], mp[MAXN], sec[MAXN];
bool nr[MAXN], fail, mark[MAXN];
vector<int>	adj[MAXN];

void dfs(int v, int de = 0){
	depth[v] = de;
	for (int u:adj[v])
		dfs(u, de + 1);
}

bool cmp(int u, int v){return depth[u] > depth[v];}

void go(int v, pair<int, int> ss = {1e9, -1}){
	if (mark[v])
		ss = min(ss, {mp[v], v});
	if (ss.S != sg[v])
		fail = 1;
	for (int u:adj[v])
		go(u, ss);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		nr[b] = 1;
	}
	for (int i = 0; i < n; i++)
		if (!nr[i])	dfs(i);
	for (int i = 0; i < n; i++){
		cin >> sg[i], sg[i]--;
		mark[sg[i]] = 1;
	}

	int sz = 0;
	for (int i = 0; i < n; i++)
		if (mark[i])	sec[sz++] = i;
	sort(sec, sec + sz, cmp);
	memset(mp, -1, sizeof(mp));
	for (int i = 0; i < sz; i++)
		mp[sec[i]] = i;
	for (int i = 0; i < n ;i++)
		if (!nr[i])
			go(i);
	if (fail)
		cout << "-1\n";
	else{
		cout << sz <<"\n";
		for (int i = 0; i < sz; i++)
			cout << sec[i] + 1 << "\n";
	}
	return 0;
}