#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <map>
#define maxn 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,type[maxn],m,k;
map <string,int> mp;
string s[maxn];
bool app[45];
ll adj[45];
map <ll,int> memo;
int solve(ll S){
	if(S == 0) return 0;
	if(memo.find(S) != memo.end()) return memo[S];
	int u = __builtin_ctzll(S & -S), res = 0;
	res = max(res,solve(S - (S & -S)));
	res = max(res,solve(S & adj[u]) + 1);
	return memo[S] = res;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0;i<m;i++) adj[i] = (1ll << m) - 1 - (1ll << i);
	for(int i=1;i<=n;i++){
		cin >> type[i];
		if(type[i] == 2){
			cin >> s[i];
			if(mp.find(s[i]) == mp.end()) mp[s[i]] = k++;
		}
	}
	int i = 1;
	while(i <= n){
		while(i <= n && type[i] == 1) i++;
		memset(app,0,sizeof(app));
		while(i <= n && type[i] == 2){
			app[mp[s[i]]] = true;
			i++;
		}
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				if(i == j) continue;
				if(app[i] && app[j]) adj[i] &= ~(1ll << j);
			}
		}
	}
	printf("%d\n",solve((1ll << m) - 1));
	return 0;
}