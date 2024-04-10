#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 5;

int n, m, t;

int f[maxn];
int p[maxn];

vector <int> e[maxn];
pair <int, int> edge[maxn];
bool vis[maxn];
int w[maxn];

void dfs(int x, int fa){
	w[x] = 1;
	for(auto i : e[x]){
		if(vis[i]) continue;
		int y = (edge[i].first == x) ? edge[i].second : edge[i].first;
		if(y == fa) continue;
		dfs(y, x);
		w[x] += w[y];
	}
}

int dfsb(int x, int fa, int s, int a, int b){
	for(auto i : e[x]){
		if(vis[i]) continue;
		int y = (edge[i].first == x) ? edge[i].second : edge[i].first;
		if(y == fa) continue;
		if(s + w[x] - w[y] == a or s + w[x] - w[y] == b){
			return i;
		}
		int ans = dfsb(y, x, s + w[x] - w[y], a, b);
		if(ans) return ans;
	}
	return 0;
}

void solve(int x){
	dfs(x, -1);
	if(w[x] == 1) return;
	if(p[w[x]] == 0){
		printf("NO\n");
		exit(0);
	}
	int ans = dfsb(x, -1, 0, f[p[w[x]] - 1], w[x] - f[p[w[x]] - 1]);
	if(!ans){
		printf("NO\n");
		exit(0);
	}
	
	vis[ans] = true;
	solve(edge[ans].first);
	solve(edge[ans].second);
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &n);
	
	f[0] = 1, f[1] = 1;
	p[1] = 1;
	m = 1;
	
	while(f[m] < n){
		m++;
		f[m] = f[m - 1] + f[m - 2];
		p[f[m]] = m;
	}
	
	if(f[m] != n){
		printf("NO\n");
		return 0;
	}
	
	for(i=1;i<n;i++){
		scanf("%d%d", &x, &y);
		edge[i] = {x, y};
		e[x].push_back(i);
		e[y].push_back(i);
	}
	
	solve(1);
	
	printf("YES\n");
	
	return 0;
}