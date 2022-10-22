#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 2e6 + 10;
const int MAXVAL = 2e6 + 10;

int n, q, val[MAXN], ans[MAXN];
vector<int>	query[MAXN];
vector<int>	vec[MAXVAL], save[MAXVAL];
vector<int>	adj[MAXN];
int depth[MAXN];

void init(){
	for (int i = 2; i < MAXVAL; i++){
		if (vec[i].size())	continue;
		for (int j = i; j < MAXVAL; j += i)
			vec[j].push_back(i);
	}
}

void dfs(int v, int p = -1, int de = 0){
	depth[v] = de;
	if (query[v].size()){
		int ret = -1, maxi = -1;
		for (int x:vec[val[v]])
			if (save[x].size() && maxi < depth[save[x].back()]){
				maxi = depth[save[x].back()];
				ret = save[x].back() + 1;
			}

		for (int i:query[v])	
			ans[i] = ret;
		query[v].clear();
	}

	for (int x:vec[val[v]])
		save[x].push_back(v);

	for (int u:adj[v])
		if (u != p)
			dfs(u, v, de + 1);

	for (int x:vec[val[v]])
		save[x].pop_back();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();

	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> val[i];
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	fill(ans, ans + MAXN, -2);
	for (int i = 0; i < q; i++){
		int type, v;	cin >> type >> v;	v--;
		if (type == 2){
			int x;	cin >> x;	
			dfs(0);
			val[v] = x;
		}
		else	query[v].push_back(i);
	}	
	dfs(0);

	for (int i = 0; i < q; i++)
		if (ans[i] != -2)
			printf("%d\n", ans[i]);
	return	0;
}