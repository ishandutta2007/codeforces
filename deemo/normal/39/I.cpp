//Can you help me unravel my latest mistake?

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
int depth[MAXN], vis[MAXN], mark[MAXN];
int vec[MAXN], sec[MAXN], sz, tt;
vector<int>	adj[MAXN];
int found;
bool failed;

void find(int v, int de = 0){
	if (vis[v]){
		if (vis[v] == 1)
			found = de - depth[v];
		return;
	}
	vis[v] = 1;
	depth[v] = de;
	for (int u:adj[v]){
		find(u, de + 1);
		if (found)	return;
	}	
	vis[v] = 2;
}

void go(int v, int x, int de = 0){
	if (vis[v]){
		if (de != mark[v])
			failed = 1;
		return;
	}

	vis[v] = 1;
	mark[v] = de;
	for (int u:adj[v])
		go(u, x, (de + 1) % x);
	vis[v] = 2;
}

void check(int x){
	memset(vis, 0, sizeof(vis));
	failed = 0;
	memset(mark, 0, sizeof(mark));
	go(0, x);
	if (!failed){
		printf("%d\n", x);
		sz = 0;
		for (int i = 0; i < n; i++)
			if (vis[i] && mark[i] == 0)	sec[sz++] = i + 1;
		printf("%d\n", sz);
		sort(sec, sec + sz);
		for (int i = 0; i < sz; i++)
			printf("%d ", sec[i]);
		printf("\n");
		exit(0);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	while (m--){
		int a, b;	scanf("%d %d", &a, &b), a--, b--;
		adj[a].push_back(b);
	}
	find(0);

	for (int i = 1; i <= found; i++)
		if (found % i == 0)	vec[tt++] = i;

	for (int i = tt - 1; ~i; i--)
		check(vec[i]);
	return 0;
}