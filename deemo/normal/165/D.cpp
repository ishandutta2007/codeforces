#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN = 3e5 + 10;

int n, from[MAXN], to[MAXN], s_t[MAXN], f_t[MAXN], tm, fen[MAXN], depth[MAXN], rt;
vector<int>	adj[MAXN];

void add(int v, int val){
	for (v++; v < MAXN; v += v&-v)
		fen[v] += val;}

int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

void dfs(int v = rt, int p = -1, int de = 0){
	depth[v] = de;
	s_t[v] = tm++;
	for (int u:adj[v])
		if (u^p)	dfs(u, v, de + 1);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d %d", &a, &b), a--, b--;
		from[i] = a, to[i] = b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		if (2 < (int)adj[i].size())	rt = i;
	dfs();
	
	int q;	scanf("%d", &q);
	while (q--){
		int type;	scanf("%d", &type);
		if (type == 3){
			int u, v;	scanf("%d %d", &u, &v), u--, v--;
			if (s_t[u] > s_t[v])	swap(u, v);

			if (depth[v] >= depth[u] && depth[v] - depth[u] + s_t[u] == s_t[v]){
				int cnt = get(s_t[v] + 1) - get(s_t[u] + 1);
				if (cnt)
					printf("%d\n", -1);
				else
					printf("%d\n", depth[v] - depth[u]);
			}	
			else{
				int cnt = get(s_t[v] + 1) - get(s_t[v] + 1 - depth[v]);
				cnt += get(s_t[u] + 1) - get(s_t[u] + 1 - depth[u]);
				if (cnt)
					printf("%d\n", -1);
				else
					printf("%d\n", depth[u] + depth[v]);
			}
		}
		else if (type == 2){
			int e;	scanf("%d", &e), e--;
			int u = (depth[from[e]] < depth[to[e]]?to[e]:from[e]);
			add(s_t[u], 1);
		}
		else{
			int e;	scanf("%d", &e), e--;
			int u = (depth[from[e]] < depth[to[e]]?to[e]:from[e]);
			add(s_t[u], -1);
		}
	}
	return 0;	
}