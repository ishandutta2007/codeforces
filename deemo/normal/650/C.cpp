#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>

using namespace std;

const int MAX = 1e6 + 1e5;

int n, m, cn[MAX], gec[MAX], ss[MAX], col[MAX], g;
pair<int, int>	sec[MAX];
vector<int>	adj[MAX], rev_adj[MAX], ssec[MAX], gg;
bool vis[MAX];
vector<pair<int, int>>	vec[MAX];
set<pair<int, int>>	st;

int hs(int a, int b){return a * m + b;}

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	for (int u:adj[v])
		dfs(u);
	gg.push_back(v);
}

void kosaraju(int v){
	if (vis[v])	return;
	vis[v] = 1;
	col[v] = g;
	ssec[g].push_back(v);
	for (int u:rev_adj[v])
		kosaraju(u);
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		vec[i].resize(m);
		for (int j = 0; j < m; j++)
			scanf("%d", &vec[i][j].first), vec[i][j].second = hs(i, j), sec[j] = vec[i][j];
		sort(sec, sec + m);
		
		for (int j = 0; j < m;){
			int w = j;
			while (w < m && sec[j].first == sec[w].first)
				if (w + 1 < m)	
					adj[sec[w].second].push_back(sec[w + 1].second), rev_adj[sec[w + 1].second].push_back(sec[w].second), w++;
				else w++;
			adj[sec[w - 1].second].push_back(sec[j].second), rev_adj[sec[j].second].push_back(sec[w - 1].second);
			j = w;
		}
	}

	for (int j = 0; j < m; j++){
		for (int i = 0; i < n; i++)
			sec[i] = vec[i][j];
		sort(sec, sec + n);
		
		for (int i = 0; i < n; ){
			int w = i;
			while (w < n && sec[w].first == sec[i].first)
				if (w + 1 < n)
					adj[sec[w].second].push_back(sec[w + 1].second), rev_adj[sec[w + 1].second].push_back(sec[w].second), w++;
				else
					w++;

			adj[sec[w - 1].second].push_back(sec[i].second), rev_adj[sec[i].second].push_back(sec[w - 1].second);
			i = w;
		}
	}

	for (int i = 0; i < n*m; i++)
		if (!vis[i])	dfs(i);
	reverse(gg.begin(), gg.end());

	memset(vis, 0, sizeof(vis));
	for (int u:gg)
		if (!vis[u]){
			g++;
			kosaraju(u);
		}

	for (int i = 0; i < n * m; i++)
		for (int u:adj[i])
			if (col[i] != col[u])	cn[col[u]]++;

	for (int i = 1; i <= g; i++)
		st.insert({cn[i], i});

	int cur = 1;
	while (st.size()){
		int t = 0;
		while (st.size()){
			if (st.begin()->first)	break;
			gec[t++] = st.begin()->second;
			st.erase(st.begin());
		}
	
		for (int i = 0; i < t; i++){
			ss[gec[i]] = cur;
			for (int u:ssec[gec[i]])
				for (int v:adj[u])
					if (col[u] != col[v]){
						st.erase({cn[col[v]]--, col[v]});
						st.insert({cn[col[v]], col[v]});
					}
		}
		cur++;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			printf("%d ", ss[col[hs(i, j)]]);
		printf("\n");
	}
	return	0;
}