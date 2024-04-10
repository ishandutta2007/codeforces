#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <cmath>
#include <iostream>
#define maxn 2000009
using namespace std;
vector<int>G[maxn];
int n, t[maxn], root;
int fd = -1;
int a[maxn], L[maxn], R[maxn], tot, sum[maxn];
int T[maxn];
int cnt[maxn];
map<int,int>mp;
void dfs(int u){
	L[u] = ++tot;
	a[tot] = u;
	sum[u] = t[u];
	for(auto v: G[u]){
		dfs(v);
		sum[u] += sum[v];
	}
	R[u] = tot;
}
void dfs1(int u, int fa){
	T[u] = fa;
	if(u != root)
	mp[sum[u]]++;
	for(auto v: G[u]){
		dfs1(v, u);
	}
	mp[sum[u]]--;
	if(u != root && sum[u] == sum[root] / 3){
		if(mp[sum[u] * 2] != 0){
			fd = u;
		}
	}
}
int main(){
 	root = 1;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d%d", &x, &t[i]);
		if(x != 0)
			G[x].push_back(i);
		else
			root = i;
	}
	dfs(root);
	if(sum[root] % 3 != 0){
		puts("-1");
		return 0;
	}
	int ans = sum[root] / 3;
	int ans1 = -1, r = n + 1, ans2 = -1, l = -1;
	for(int i = 1; i <= n; i++){
		int u = a[i];
		if(u == root)
			continue;
		if(sum[u] == ans){
			if(R[u] < r){
				r = R[u];
				ans1 = u;
			}
			if(L[u] > l){
				l = L[u];
				ans2 = u;
			}
		}
	}
	if(r < l){
		printf("%d %d\n", ans1, ans2);
	}
	else{
		dfs1(root, 0);
		if(fd == -1){
			puts("-1");
			return 0;
		}
		else{
			ans1 = fd;
			int cur = T[fd];
			while(sum[cur] != ans * 2){
				cur = T[cur];
			}
			ans2 = cur;
			printf("%d %d\n", ans1, ans2);
		}
	}
	return 0;
}