#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<deque>

using namespace std;

#define FAILURE {printf("NO\n"); return 0;}

const int max_n = 2e5 + 10;

int n, m, vc, dc;
vector<vector<int>>	vec;
bool mark[max_n], picked[max_n], ans[max_n], seen[max_n];
vector<int>	neg[max_n], pos[max_n];
deque<int>	saf;
vector<int>	sec;
vector<pair<int, int>>	adj[max_n];
pair<int, int>	par[max_n], save;

void remove(){
	for (int i = 1; i <= m; i++)
		if (pos[i].empty() || neg[i].empty()){
			saf.push_back(i);	
			picked[i] = 1;
		}
	
	while (saf.size()){
		int f = saf.front();
		saf.pop_front();
		if (neg[f].empty())	
			ans[f] = 1;
		else
			ans[f] = 0;

		sec.resize(neg[f].size() + pos[f].size());
		copy(neg[f].begin(), neg[f].end(), sec.begin());
		copy(pos[f].begin(), pos[f].end(), sec.begin() + neg[f].size());
	
		for (int u:sec){
			if (mark[u])	continue;
			mark[u] = 1;
			for (int i = 0; i < vec[u].size(); i++){
				int y = vec[u][i];
				if (y > 0)
					pos[y].erase(find(pos[y].begin(), pos[y].end(), u));
				else{
					y = -y;
					neg[y].erase(find(neg[y].begin(), neg[y].end(), u));
				}
				if (!picked[y])	saf.push_back(y), picked[y] = 1;
			}
		}
	}
}

void dfs(int v, int p, int x){
	vc++, dc += adj[v].size();
	par[v] = {p, x};
	seen[v] = 1;

	bool fl = 0;
	for (pair<int, int>	e: adj[v]){
		if (e == par[v])	continue;

		int u = e.first;
		if (seen[u]){
			save = e;
			continue;
		}

		int y = e.second;
		if (pos[y].back() == u)	ans[y] = 1;
		dfs(u, v, y);
	}
}

void rev(){
	int v = save.first, y = save.second;
	if (pos[y].back() == v)	ans[y] = 1;

	while (par[v].first != -1){
		ans[par[v].second] = !ans[par[v].second];
		v = par[v].first;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	vec.resize(n);
	for (int i = 0; i < n; i++){
		int t;	scanf("%d", &t);
		vec[i].resize(t);
		for (int j = 0; j < t; j++){
			int temp;	scanf("%d", &temp);
			if (temp > 0)
				pos[temp].push_back(i);
			else
				neg[-temp].push_back(i);
			vec[i][j] = temp;
		}
	}
	remove();
	
	for (int i = 1; i <= m; i++){
		if (picked[i])	continue;
		int a = neg[i].back(), b = pos[i].back();
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
	}

	for (int i = 0; i < n; i++){
		if (mark[i])	continue;
		if (seen[i])	continue;
		vc = dc = 0;
		dfs(i, -1, -1);
		if (dc == 2 * vc - 2)	FAILURE//XXX
		rev();
	}

	printf("YES\n");
	for (int i = 1; i <= m; i++)
		printf("%d", (int)ans[i]);
	printf("\n");
	return 0;
}