#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iostream>
#define maxn 200009
using namespace std;
int n, m;
vector<int>G[maxn];
long long dp1[maxn][6],dp2[maxn][6],num1[maxn][6],num2[maxn][6];
void dfs1(int u, int fa){
	num1[u][0] = 1;
	for(auto v: G[u]){
		if(v == fa)
			continue;
		dfs1(v, u);
		for(int i = 0; i < m; i++){
			num1[u][(i+1) % m] += num1[v][i];
		}
		for(int i = 1; i < m; i++){
			dp1[u][(i + 1) % m] += dp1[v][i];
		}
		dp1[u][1 % m] += dp1[v][0] + num1[v][0];
	}
}
void dfs2(int u, int fa){
	for(auto v: G[u]){
		if(v == fa)
			continue;
		for(int i = 1; i < m; i++){
			dp2[v][(i + 1) % m] += dp2[u][i];
		}
		dp2[v][1 % m] += dp2[u][0] + num2[u][0]; 
		for(int i = 0; i < m; i++){
			num2[v][(i + 1) % m] += num2[u][i];
		}
	}
	for(auto v: G[u]){
		if(v == fa)
			continue;
		
		for(int i = 0; i < m; i++){
			num1[u][(i+1) % m] -= num1[v][i];
		}
		for(int i = 1; i < m; i++){
			dp1[u][(i + 1) % m] -= dp1[v][i];
		}
		dp1[u][1 % m] -= dp1[v][0] + num1[v][0];
		
		num1[u][0]--;
		
		for(int i = 1; i < m; i++){
			dp2[v][(i + 1) % m] += dp1[u][i];
		}
		dp2[v][1 % m] += dp1[u][0] + num1[u][0];
		for(int i = 0; i < m ;i++){
			num2[v][(i + 1) % m] += num1[u][i];
		}
		
		num1[u][0]++;
		
		for(int i = 0; i < m; i++){
			num1[u][(i+1) % m] += num1[v][i];
		}
		for(int i = 1; i < m; i++){
			dp1[u][(i + 1) % m] += dp1[v][i];
		}
		dp1[u][1 % m] += dp1[v][0] + num1[v][0];
	}
	
	for(auto v: G[u]){
		if(v == fa)
			continue;
		num2[v][0]++;
		dfs2(v, u);
	} 
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs1(1, -1);
	num2[1][0] = 1;
	dfs2(1, -1);
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			ans += dp1[i][j] + dp2[i][j];
		}
	}
	cout << ans / 2 << endl;
	return 0;
}