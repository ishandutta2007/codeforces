#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int n, f[MAXN], from[MAXN], to[MAXN];
vector<int>	adj[MAXN];
int cv, ce, vis[MAXN];
bool found;

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	cv++;
	ce += (int)adj[v].size();
	for (int e:adj[v])
		dfs(from[e]^to[e]^v);
}

int sec[MAXN], sz;

void go(int v, int p = -1){
	sec[sz++] = v;
	if (vis[v] == 2){
		found = 1;
		return;
	}
	vis[v] = 2;

	for (int e:adj[v])
		if (e^p){
			go(from[e]^to[e]^v, e);
			if (found)	return;
		}
	sz--;
}

ll get(int v){
	cv = ce = 0;
	dfs(v);
	ce/=2;
	sz = 0;
	found = 0;
	go(v);
	int head = sec[sz - 1];
	int cnt = 0;
	for (int i = sz - 2; ~i; i--){
		cnt++;
		if (sec[i] == head)	break;
	}
	ll ret = 1;
	for (int i = 0; i < ce - cnt; i++)	ret = ret * 2ll % MOD;
	ll temp = 1;
	for (int i = 0; i < cnt; i++)	temp = temp * 2ll % MOD;
	temp = (temp + MOD - 2) % MOD;
	return ret * temp % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> f[i], f[i]--;
		from[i] = i, to[i] = f[i];
		adj[from[i]].push_back(i);
		adj[to[i]].push_back(i);
	}
	ll ans = 1;
	for (int i = 0; i < n; i++)
		if (!vis[i])
			ans = ans * get(i) % MOD;
	cout << ans << "\n";
	return 0;
}