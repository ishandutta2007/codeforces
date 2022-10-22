//You still sound like a song..

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

#define FAILED printf("Impossible\n")

const int MAXN = 3 * 100 + 5;

int n, m;
vector<int>	adj[MAXN], rev_adj[MAXN];
bool seen[MAXN];
int comp[MAXN];
int ans[MAXN];
vector<int>	st;

void add(int u, int v){
	adj[u].push_back(v);
	rev_adj[v].push_back(u);
}

void dfs(int v){
	seen[v] = 1;
	for (int u:adj[v])
		if (!seen[u])	dfs(u);
	st.push_back(v);
}

void kosaraju(int v, int col){
	seen[v] = 1;
	for (int u:rev_adj[v])
		if (!seen[u])	kosaraju(u, col);
	comp[v] = col;
}

int main(){
	scanf("%d%d", &n, &m);
	while (m--){
		int a, b, type;	scanf("%d%d%d", &a, &b, &type);	a--, b--;
		if (type == 1){
			add(a + n, b + n);
			add(b, a);
			add(a, b);
			add(b + n, a + n);
		}	
		else{
			add(a + n, b);
			add(b + n, a);
			add(a, b + n);
			add(b, a + n);
		}
	}
	for (int i = 0; i < 2 * n; i++)
		if (!seen[i])	dfs(i);
	reverse(st.begin(), st.end());
	memset(seen, 0, sizeof(seen));
	int t = 0;
	for (int i:st)
		if (!seen[i])	kosaraju(i, ++t);

	bool flag = 0;
	for (int i = 0; i < n; i++)
		if (comp[i] == comp[i + n])	flag = 1;
	if (flag)
		FAILED;
	else{
		reverse(st.begin(), st.end());
		memset(seen, 0, sizeof(seen));
		for (int u:st){
			if (seen[comp[u]])	continue;
			int z = u + n;
			if (z >= 2 * n)	z -= 2 * n;
			if (seen[comp[z]]){
				seen[comp[u]] = 1;
				ans[comp[u]] = !ans[comp[z]];
				continue;
			}
			ans[comp[u]] = 1;
			seen[comp[u]] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (ans[comp[i]])	cnt++;
		printf("%d\n", cnt);
		for (int i = 0; i < n; i++)
			if (ans[comp[i]])	printf("%d ", i + 1);
		printf("\n");
	}
	return 0;
}