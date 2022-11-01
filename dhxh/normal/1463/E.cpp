#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

int n, m, t;

vector <int> e[maxn];
vector <int> ed[maxn];
vector <int> pre[maxn];
vector <int> suf[maxn];
vector <int> son[maxn];

int c[maxn];
int dep[maxn];
int ecnt[maxn];

bool vis[maxn];

void dfs(int x, int s, int d){
	vis[x] = true;
	c[x] = s;
	dep[x] = d;
	son[s].push_back(x);
	for(auto y : suf[x]){
		if(vis[y]){
			printf("0\n");
			exit(0);
		}
		dfs(y, s, d + 1);
	}
	for(auto y : e[x]){
		if(c[y] == c[x] and dep[y] < dep[x]){
			printf("0\n");
			exit(0);
		}
	}
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=n;i++){
		scanf("%d", &x);
		e[x].push_back(i);
	}
	
	for(i=1;i<=m;i++){
		scanf("%d%d", &x, &y);
		suf[x].push_back(y);
		pre[y].push_back(x);
	}
	
	for(i=1;i<=n;i++){
		if(suf[i].size() > 1 or pre[i].size() > 1){
			printf("0\n");
			return 0;
		}
	}
	
	for(i=1;i<=n;i++){
		if(!pre[i].size()) dfs(i, i, 1);
	}
	
	for(i=1;i<=n;i++){
		if(!vis[i]){
			printf("0\n");
			return 0;
		}
	}
	
	for(i=0;i<=n;i++){
		for(auto y : e[i]){
			if(c[i] == c[y]) continue;
			ed[c[i]].push_back(c[y]);
			ecnt[c[y]]++;
		}
	}
	
	queue <int> q;
	q.push(0);
	vector <int> ans;
	
	while(q.size()){
		x = q.front();
		q.pop();
		
		for(auto y : ed[x]){
			ecnt[y]--;
			if(ecnt[y] == 0){
				q.push(y);
				for(auto z : son[y]){
					ans.push_back(z);
				}
			}
		}
	}
	
	if(ans.size() != n){
		printf("0\n");
		return 0;
	}
	
	for(auto x : ans){
		printf("%d ", x);
	}
	printf("\n");
	
	return 0;
}