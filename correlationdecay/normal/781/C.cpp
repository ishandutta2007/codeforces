#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define maxn 300009
using namespace std;
int p[maxn];
int findset(int x){
	return x == p[x] ? x : p[x] = findset(p[x]);
}
void unionset(int x, int y){
	p[findset(x)] = findset(y);
}
vector<int>G[maxn];
vector<int>ans;
void dfs(int u, int fa){
	ans.push_back(u);
	for(auto v: G[u]){
		if(v == fa)
			continue;
		dfs(v, u);
		ans.push_back(u);
	}
}
int main(){
	int n , m ,k;
	cin >> n >> m >> k;
	for(int i = 1;i <= n; i++){
		p[i] = i;
	}	
	for(int i = 1; i <=m ;i++){
		int x,y;
		scanf("%d%d", &x, &y);
		if(findset(x) != findset(y)){
			unionset(x, y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
	}
	dfs(1, -1);
	int tot = ans.size();
	int cur = 0;
	for(int i = 1; i <= k; i++){
		if(i <= tot % k){
			printf("%d", tot / k + 1);
			for(int j = 0 ; j < tot / k + 1; j++)
				printf(" %d", ans[cur++]);
			puts("");
		}
		else{
			printf("%d", tot / k);
			for(int j = 0 ; j < tot / k; j++)
				printf(" %d", ans[cur++]);
			puts("");
		}
	}
	return 0;
}