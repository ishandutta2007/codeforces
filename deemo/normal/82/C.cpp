#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

const short MAXN = 5e3 + 10;

short n, w[MAXN], g, tm[MAXN];
set<pair<short, short>>	st[MAXN];
vector<pair<short, short>>	adj[MAXN];

bool dfs(short v, short p = -1, short x = 0){
	if (st[v].empty())	return 0;
	bool ret = 0;
	if (v){
		ret = 1;
		while (st[v].size() && x--){
			auto z = *st[v].begin();
			st[v].erase(st[v].begin());
			if (p == 0)
				tm[z.second] = g + 1;
			else
				st[p].insert(z);
		}
	}

	for (auto u:adj[v])
		if (u.first^p)	ret |= dfs(u.first, v, u.second);
	return	ret;
}

int main(){
	cin >> n;
	for (short i = 0; i < n; i++){
		cin >> w[i];
		st[i].insert({w[i], i});
	}
	for (short i = 0; i < n - 1; i++){
		short a, b, c;	cin >> a >> b >> c;	a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	while (dfs(0))	g++;
	for (short i = 0; i < n; i++)
		cout << tm[i] << " ";
	cout << "\n";
	return	0;
}