#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int n, k;
vector<vector<short>>	vec;
vector<int>	sec;
bool mark[20];
vector<int>	adj[20];
int cnt = 0;

int dfs(int v){
	if (mark[v])	return	0;
	mark[v] = 1;
	int ret = 1;
	for (int u:adj[v])
		ret += dfs(u);
	return	ret;
}

void gen(int rem){
	if (rem == 0){
		memset(mark, 0, sizeof(mark));
		for (int i = 0; i < k; i++)	adj[i].clear();
		for (int i = 0; i < sec.size(); i++)
			adj[sec[i]].push_back(i);
		if (dfs(0) == k)	cnt++;
		return;
	}	

	for (int i = 0; i < k; i++){
		sec.push_back(i);
		gen(rem - 1);
		sec.pop_back();
	}
}

int main(){
	cin >> n >> k;
	ll ans = 1;
	for (int i = 0; i < n - k; i++)
		ans = (ans * (n - k)) % MOD;
	gen(k);
	ans = (ans * (ll)cnt) % MOD;
	cout << ans << endl;
	return 0;
}