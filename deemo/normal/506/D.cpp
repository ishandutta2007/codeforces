#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
#include<map>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;
const int SQRT = 330;

int n, m, q;
vector<int>	adj[max_n];
int f[max_n][SQRT + 10];
int g, col, mark[max_n];
vector<int>	sec;
vector<pair<int, int>>	vec[max_n];
map<pair<int, int>, int>	mp;
vector<int>	gec;

void dfs(int v){
	if (mark[v] == g)	return;
	mark[v] = g;
	gec.push_back(v);
	for (int u:adj[v])
		dfs(u);
	adj[v].clear();
}

void init(){
	g = 1;
	for (int i = 0; i < m; i++, g++){
		for (pair<int, int>	e:vec[i])
			adj[e.first].push_back(e.second), adj[e.second].push_back(e.first);
			
		col = 1;
		for (pair<int, int>	e:vec[i]){
			if (mark[e.first] != g)	dfs(e.first);

			if (vec[i].size() >= SQRT)
				for (int u:gec)
					f[u][sec.size()] = col;
			else{
				for (int i = 0; i < gec.size(); i++)
					for (int j = i + 1; j < gec.size(); j++)
						if (gec[i] < gec[j])
							mp[{gec[i], gec[j]}] += 1;
						else
							mp[{gec[j], gec[i]}] += 1;
			}
			gec.clear();
			col++;
		}
		if (vec[i].size() >= SQRT)	sec.push_back(i);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int a, b, c;	scanf("%d%d%d", &a, &b, &c);	a--, b--, c--;
		vec[c].push_back({a, b});
	}
	init();

	scanf("%d", &q);
	while (q--){
		int u, v;	scanf("%d%d", &v, &u);	v--, u--;
		if (u > v)	swap(u, v);
		int ans = 0;
		if (mp.count({u, v}))	ans = mp[{u, v}];
		for (int z:sec)
			if (f[u][z] == f[v][z] && f[u][z])	ans++;
		printf("%d\n", ans);
	}
	return 0;
}