#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define maxn 5009
using namespace std;
int n, m;
int d[maxn], c[maxn];
long long dp1[maxn][maxn], dp2[maxn][maxn], f[maxn];
vector<int>G[maxn];
multiset<int>st;
int sz[maxn];
vector<int>a;
const long long INF = 1e18;

void dfs1(int u){
	sz[u] = 1;
	for(auto v: G[u]){
		dfs1(v);
		sz[u] += sz[v];
	}
	int sum = 0;
	for(int i = 1; i <= sz[u]; i++)
		f[i] = INF;
	f[0] = 0;
	int last = sum;
	for(auto v: G[u]){
		sum += sz[v];
		for(int j = sum; j >= 0; j--){
			for(int i = max(0, j - last); i <= sz[v] && i <= j; i++)
				f[j] = min(f[j], f[j - i] + dp1[v][i]);
		}
		last = sum;
	}
	dp1[u][0] = 0;
	for(int i = 1; i <= sz[u]; i++){
		dp1[u][i] = min(f[i - 1] + c[u], f[i]);
	}
}

void dfs(int u){
	for(auto v: G[u])
		dfs(v);
	int sum = 0;
	for(int i = 1; i <= sz[u]; i++)
		f[i] = INF;
	f[0] = 0;
	int last = 0;
	for(auto v: G[u]){
		sum += sz[v];
		for(int j = sum; j >= 0; j--){
			for(int i = max(0, j - last); i <= sz[v] && i <= j; i++)
				f[j] = min(f[j], f[j - i] + min(dp1[v][i], dp2[v][i]));
		}
		last = sum;
	}
	dp2[u][0] = INF;
	for(int i = 1; i <= sz[u]; i++){
		dp2[u][i] = f[i - 1] + c[u] - d[u];	
	}
}


int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		if(i == 1){
			scanf("%d%d", &c[i], &d[i]);
		}
		else{
			int x;
			scanf("%d%d%d", &c[i], &d[i], &x);
			G[x].push_back(i);
		}
	}
	
	dfs1(1);
	dfs(1);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(dp1[1][i] <= m)
			ans = i;
		if(dp2[1][i] <= m)
			ans = i;
	}
	cout << ans << endl;
	return 0;
}