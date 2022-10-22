#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

const int MAXN = 1e6 + 20;

int n, sec[MAXN * 2], t;
vector<int>	adj[MAXN];
set<int>	st;

void dfs(int v, int p = -1, int de = 0){
	if (p != -1 && adj[v].size() == 1)
		sec[t++] = de;
	for (int u:adj[v])
		if (u != p)	dfs(u, v, de + 1);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d %d", &a, &b);	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ans = 0;
	for (int u:adj[0]){
		t = 0;
		dfs(u, 0, 1);
		sort(sec, sec + t);
		
		int cur = 0;
		for (int i = 0; i < t; i++){
			if (sec[i] > cur)
				cur = sec[i] + 1;
			else
				cur++;
		}
		ans = max(ans, cur - 1);
	}

	printf("%d\n", ans);
	return	0;
}