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
int n, m;
vector<int>G[maxn];
int ans[maxn];
void dfs(int u, int fa){
	int cur = 1, pre;
	if(fa == -1)
		pre = -1;
	else
		pre = ans[fa];
	for(auto v: G[u]){
		if(v == fa)
			continue;
		while(cur == pre || cur == ans[u])
			cur++;
		ans[v] = cur;
		cur++;
		dfs(v, u);
	}
	return;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i = 1;i <= n; i++){
		m = max(m , (int)G[i].size() + 1);
	}
	ans[1] = 1;
	dfs(1, -1);
	printf("%d\n", m);
	for(int i = 1;i <= n; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}