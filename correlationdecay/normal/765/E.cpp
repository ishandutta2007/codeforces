#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <iostream>
#define maxn 200009
using namespace std;
vector<int>G[maxn];
int n;
int dep[maxn],d[maxn],T[maxn];
int dfs(int u, int fa){
	set<int>st;
	for(auto v: G[u]){
		if(v == fa)
			continue;
		if(dfs(v, u) == -1)
			return -1;
		st.insert(dep[v]);
	}
	if(fa == -1){
		if((int)st.size() > 2)
			return -1;
		int ans = 1;
		for(auto x: st)
			ans += x;
		return ans;
	}
	else{
		if((int)st.size() > 1)
			return -1;
		dep[u] = 1;
		for(auto x : st)
			dep[u] += x;
	}
	return 0;
}
int solve(int x){
	while(x & 1){
		x -= x / 2;
	}
	return x;
}
void dfs1(int u, int fa, int dep){
	T[u] = fa;
	d[u] = dep;
	for(auto v: G[u]){
		if(v == fa)
			continue;
		dfs1(v, u, dep + 1);
	}
}
int findroot(){
	dfs1(1, -1, 0);
	int cur = 0, pos = 1;
	for(int i = 1; i <= n ; i++){
		if(d[i] > cur){
			cur = d[i];
			pos = i;
		}
	}
	dfs1(pos, -1, 0);
	cur = 0, pos = 1;
	for(int i = 1; i <= n ;i++){
		if(d[i] > cur){
			cur = d[i];
			pos = i;
		}
	}
	for(int i = 1; i <= cur / 2; i++){
		pos = T[pos];
	}
	return pos;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int root = findroot();
	int ans = dfs(root, -1);
	if(ans != -1)
		printf("%d\n", solve(ans) - 1);
	else
		puts("-1");
	return 0;
}