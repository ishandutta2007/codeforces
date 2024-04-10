#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const int max_n = 300 + 10;

int n, w, m;
int par[max_n], seen[max_n], g;
bool mark[max_n];
vector<int>	adj[max_n];
vector<int>	gec, sec, vec;
ll sum1, sum2;
int a[max_n], b[max_n];
vector<pair<pair<int, int>, int>>	ans;

void dfs(int v, int p = -1){
	mark[v] = 1;
	sum1 += a[v];
	sum2 += b[v];
	seen[v] = g;
	par[v] = p;
	for (int u:adj[v])
		if (seen[u] == 0)
			dfs(u, v);
}

void flow(int s, int val){
	if (s == gec.size() - 1)	return;
	int rem = w - a[gec[s + 1]];
	int p1 = min(val, rem);
	ans.push_back({{gec[s], gec[s + 1]}, p1});
	a[gec[s]] -= p1;
	a[gec[s + 1]] += p1;
	flow(s + 1, val);

	ans.push_back({{gec[s], gec[s + 1]}, val - p1});
	a[gec[s]] -= val - p1;
	a[gec[s + 1]] += val - p1;
}

void get_path(int v){
	if (par[v] == -1){
		gec.push_back(v);
		return;
	}
	get_path(par[v]);
	gec.push_back(v);
}

int main(){
	scanf("%d%d%d", &n, &w, &m);
	for (int i = 0; i < n; i++)		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)		scanf("%d", &b[i]);

	for (int i = 0; i < m; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++){
		if (mark[i])	continue;
		g++;
		sum1 = sum2 = 0;
		dfs(i);
		if (sum1 != sum2){
			printf("NO\n");
			return 0;
		}
		
		vec.clear();
		sec.clear();
		for (int j = 0; j < n; j++){
			if (seen[j] != g)	continue;
			if (a[j] > b[j])	vec.push_back(j);
			if (a[j] < b[j])	sec.push_back(j);
		}

		for (int j = 0; j < vec.size(); j++){
			while (a[sec.back()] == b[sec.back()])	sec.pop_back();
			int f = vec[j], gg = sec.back();
			int dif = min(a[f] - b[f], b[gg] - a[gg]);

			gec.clear();
			memset(seen, 0, sizeof(seen));
			dfs(f);
			get_path(gg);
			flow(0, dif);
			if (a[vec[j]] != b[vec[j]])	j--;
		}
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d %d\n", ans[i].first.first + 1, ans[i].first.second + 1, ans[i].second);
	return 0;
}