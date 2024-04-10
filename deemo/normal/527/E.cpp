//It's been a long time!

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<map>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 100;

int n, m;
vector<int>	adj[max_n];
vector<int>	ans, sec;
map<pair<int, int>, int>	mp;

pair<int, int>	get(int a, int b){
	if (a > b)	swap(a, b);
	return	{a, b};
}

void dfs(int v){
	while (adj[v].size()){
		int u = adj[v].back();
		adj[v].pop_back();
		if (mp[get(u, v)] == 0)	continue;
		mp[get(u, v)]--;
		dfs(u);
	}
	ans.push_back(v);
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int a, b;
		scanf("%d%d", &a, &b);	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		mp[get(a, b)]++;
	}
	for (int i = 0; i < n; i++)
		if (adj[i].size() % 2 == 1)
			sec.push_back(i);
	for (int i = 0; i < sec.size(); i += 2){
		adj[sec[i]].push_back(sec[i + 1]);
		adj[sec[i + 1]].push_back(sec[i]);
		mp[get(sec[i], sec[i + 1])]++;
		m++;
	}
	if (m % 2 == 1){
		adj[0].push_back(0);
		adj[0].push_back(0);
		mp[{0, 0}]++;
	}	
	dfs(0);
	printf("%d\n", (int)ans.size() - 1);
	for (int i = 1; i < ans.size(); i++){
		if (i % 2 == 1)	
			printf("%d %d\n", ans[i - 1] + 1, ans[i] + 1);
		else
			printf("%d %d\n", ans[i] + 1, ans[i - 1] + 1);
	}
	return 0;
}