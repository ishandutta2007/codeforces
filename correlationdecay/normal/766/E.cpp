#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#define maxn 100009
using namespace std;
int n, a[maxn];
vector<int>G[maxn];
long long one[maxn], zero[maxn];
long long ans1[maxn], ans0[maxn];
long long ans = 0;
void dfs(int u, int fa, int x){
	one[u] = zero[u] = 0;
	ans0[u] = ans1[u] = 0;
	for(auto v: G[u]){
		if(v == fa)
			continue;
		dfs(v, u, x);
		ans0[u] += zero[u] * zero[v] + one[u] * one[v] + ans0[v];
		ans1[u] += zero[u] * one[v] + zero[v] * one[u] + ans1[v];
		if(a[u] & (1 << x)){
			one[u] += zero[v];
			zero[u] += one[v];
		}
		else{
			one[u] += one[v];
			zero[u] += zero[v];
		}
	}
	ans0[u] += zero[u];
	ans1[u] += one[u];
	if(a[u] & (1 << x)){
		ans1[u]++;
		one[u]++;
	}
	else{
		ans0[u]++;
		zero[u]++;
	}
	//cout << u << " " << ans1[u] << endl;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 20; i >= 0; i--){
		dfs(1, -1, i);
		ans += ans1[1] * (1LL << i);
		//cout << ans1[i] << endl;
	}
	cout << ans << endl;
	return 0;
}