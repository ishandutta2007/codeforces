#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXE = 5e3 + 10;

int n, m, from[MAXE], to[MAXE], d[MAXN];
short mark[MAXN];
bool vis[MAXN];
vector<int>	adj[MAXN], radj[MAXN];

void dfs(int v){
	if (mark[v])	return;
	mark[v] = 1;
	for (int e:adj[v])
		dfs(to[e]);
}

void rdfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	mark[v]++;
	for (int e:radj[v])
		rdfs(from[e]);
}

bool relax(int e){
	bool ret = 0;
	if (d[from[e]] + 2 < d[to[e]])
		d[to[e]] = d[from[e]] + 2, ret = 1;
	if (d[from[e]] + 1 > d[to[e]])
		d[from[e]] = d[to[e]] - 1;
	return ret;
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &from[i], &to[i]), from[i]--, to[i]--
			, adj[from[i]].push_back(i), radj[to[i]].push_back(i);
	dfs(0);
	rdfs(n-1);
	fill(d, d + MAXN, 1e9);
	d[0] = 0;
	bool fail = 0;
	for (int i = 0; i < n; i++)
		for (int e = 0; e < m; e++)
			if (mark[from[e]] + mark[to[e]] == 4)
				fail |= relax(e) && i == n - 1;
	if (fail){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for (int e = 0; e < m; e++)
		printf("%d\n", max(1, min(2, d[to[e]] - d[from[e]])));
	return 0;
}