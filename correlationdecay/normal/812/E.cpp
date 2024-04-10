#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#define maxn 100009
using namespace std;
int n, a[maxn];
vector<int>G[maxn];
vector<int>odd, eve;
int L[maxn];
map<int,int>mp;
void dfs(int u){
	if((int)G[u].size() == 0)
		L[u] = 1;
	for(auto v: G[u]){
		dfs(v);
		L[u] = L[v] ^ 1;
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 2; i <= n; i++){
		int p;
		scanf("%d", &p);
		G[p].push_back(i);
	}
	dfs(1);
	int sum = 0;
	long long sz1 = 0, sz2 = 0;
	for(int i = 1; i <= n; i++){
		if(L[i] & 1){
			odd.push_back(a[i]);
			sum ^= a[i];
			sz1++;
		}
		else{
			mp[a[i]]++;	
			sz2++;
		}
	}
	long long ans = 0;
	
	if(sum != 0){
		for(auto x: odd){
			ans += mp[sum ^ x];
		}
	}
	else{
		for(auto x: odd){
			ans += mp[sum ^ x];
		}
		ans += sz1 * (sz1 - 1) / 2;
		ans += sz2 * (sz2 - 1) / 2;
	}
	
	cout << ans << endl;
	return 0;
}