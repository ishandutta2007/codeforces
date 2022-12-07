#include<bits/stdc++.h>
using namespace std;

const int maxn = 200100;
int n, m, s;
vector<int> g[maxn], gg[maxn];
int f[maxn][2], from[maxn][2], vis[maxn];

bool dfs(int t){
	vis[t] = 1;
	for(int v : gg[t])
		if(!vis[v]){
			if(!dfs(v)) return 0;
		}else return 0;
	vis[t] = 0;
	return 1;
}

int main(){
	scanf("%d%d", &n, &m);
	queue<int> q;
	for(int i = 1; i <= n; ++i){
		int k, v;
		scanf("%d", &k);
		if(!k){
			q.push(i);
			f[i][0] = 1;
		}
		while(k--){
			scanf("%d", &v);
			g[v].push_back(i);
			gg[i].push_back(v);
		}
	}
	scanf("%d", &s);

	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int v : g[t]){
			for(int i = 0; i < 2; ++i)
				if(f[t][i] && !f[v][i ^ 1]){
					f[v][i ^ 1] = 1;
					from[v][i ^ 1] = t;
					q.push(v);
				}
		}
	}

	if(f[s][1]){
		puts("Win");
		int cur = 1;
		printf("%d", s);
		while(from[s][cur]){
			s = from[s][cur];
			cur ^= 1;
			printf(" %d", s);
		}
	}else{
		if(dfs(s)) puts("Lose");
		else puts("Draw");
	}
	return 0;
}