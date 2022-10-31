#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

vector <int> e[maxn];
int ecnt[maxn];
queue <int> q;

bool vis[maxn];

int dep[maxn];
int ec[maxn];
bool flag;

int f[maxn];
int g[maxn];
int cnt[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int x, int fa){
	int y;
	
	if(!ec[dep[x]]){
		ec[dep[x]] = e[x].size();
	}else{
		if(ec[dep[x]] != e[x].size()){
			flag = false;
			return 0;
		}
	}
	
	for(auto y : e[x]){
		if(y == fa)continue;
		dep[y] = dep[x] + 1;
		dfs(y, x);
		if(!flag){
			return 0;
		}
	}
	
	return 0;
}

bool check(int x){
	memset(ec, 0, sizeof(ec));
	memset(dep, 0, sizeof(dep));
	flag = true;
	dep[x] = 1;
	dfs(x, -1);
	
	return flag;
}

int solve(){
	int i, j;
	int x, y;
	vector <int> ans;
	memset(vis, 0, sizeof(vis));
	
	for(i=1;i<=n;i++){
		ecnt[i] = e[i].size();
		if(e[i].size() == 1){
			vis[i] = true;
			q.push(i);
			f[i] = 1;
			g[i] = i;
			cnt[i] = 1;
		}
	}
	
	while(!q.empty()){
		x = q.front();
		q.pop();
		
		for(auto y : e[x]){
			if(vis[y])continue;
			ecnt[y]--;
			if(ecnt[y] == 1){
				q.push(y);
				vis[y] = true;
			}
		}
		
		for(auto y : e[x]){
			if(!vis[y])continue;
			if(!f[y])continue;
			if(f[x]){
				if(f[y] + 1 != f[x]){
					if(cnt[x] < cnt[y]){
						ans.push_back(g[x]);
					}else if(cnt[x] > cnt[y]){
						ans.push_back(g[y]);
					}else{
						ans.push_back(g[x]);
						ans.push_back(g[y]);
					}
					break;
				}else{
					cnt[x] += cnt[y];
				}
			}else{
				f[x] = f[y] + 1;
				g[x] = g[y];
				cnt[x] += cnt[y];
			}
		}
		
		if(q.empty() and ans.size() == 0){
			for(auto y : e[x]){
				if(!vis[y])continue;
				if(!f[y])continue;
				if(cnt[y] == 1){
					ans.push_back(g[y]);
				}
			}
		}
		
		if(ans.size())break;
	}
	
	for(auto x : ans){
		if(check(x)){
			printf("%d\n", x);
			return 0;
		}
	}
	
	printf("-1\n");
	
	return 0;
}

int main(){
	int i, j;
	int x = 1, y;
	
	n = read();
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		e[x].push_back(y);
		e[y].push_back(x);
		ecnt[x]++;
		ecnt[y]++;
	}
	
	for(i=1;i<=n;i++){
		if(e[i].size() == 1){
			vis[i] = true;
			q.push(i);
		}
	}
	
	while(!q.empty()){
		x = q.front();
		q.pop();
		
		for(auto y : e[x]){
			if(vis[y])continue;
			ecnt[y]--;
			if(ecnt[y] == 1){
				q.push(y);
				vis[y] = true;
			}
		}
	}
	
	if(check(x)){
		printf("%d\n", x);
	}else{
		solve();
	}
	
	return 0;
}