#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mod 998244353
#define maxn 300005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int col[maxn],n,m,num2,num1;
vector <int> adj[maxn];
bool dfs(int u,int c){
	col[u] = c;
	if(c > 0) num1++;
	else num2++;
	for(int i=0;i<(int)adj[u].size();i++){
		int v = adj[u][i];
		if(col[u] == col[v]) return false;
		else if(!col[v] && !dfs(v,-c)) return false;
	}
	return true;
}
int modpow(int x,int y){
	int res = 1;
	while(y){
		if(y & 1) res = (ll)res * x % mod;
		y >>= 1;
		x = (ll)x * x % mod;
	}
	return res;
}
int solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) adj[i].clear(), col[i] = 0;
	int res = 1;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!col[i]){
			num1 = num2 = 0;
			if(!dfs(i,1)) return 0;
			res = (ll)res * (modpow(2,num1) + modpow(2,num2)) % mod;
		}
	}
	return res;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) printf("%d\n",solve());
	return 0;
}