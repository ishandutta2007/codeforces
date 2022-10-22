#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 4e5 + 10;
const int B[2] = {701, 721};
const int MOD[2] = {int(1e9) + 7, int(1e9) + 9};

int n, sz, id[MAXN], cnt[MAXN], tt, rem[MAXN];
vector<int>	adj[MAXN];
ll ss[2][MAXN];
pair<ll, ll> svl[MAXN], svr[MAXN];
map<pair<ll, ll>, int> mp;
pair<int, int> mx(-1, -1);

bool cmp(int u, int v){return id[u] < id[v];}

void plant(int v, int p = -1){
	int fl = 0;
	for (int u:adj[v])
		if (u^p){
			plant(u, v);
			fl++;
		}
	sort(adj[v].begin(), adj[v].end(), cmp);
	pair<ll, ll> cur(0, 0);
	for (int u:adj[v])
		if (u^p){
			svl[u] = cur;
			rem[u] = --fl;
			cur.F = (cur.F*B[0] + id[u]) % MOD[0];
			cur.S = (cur.S*B[1] + id[u]) % MOD[1];
		}
	auto temp = cur;

	cur = {0, 0};
	reverse(adj[v].begin(), adj[v].end());
	fl = 0;
	for (int u:adj[v])
		if (u^p){
			svr[u] = cur;
			cur.F = (ss[0][fl] * id[u] + cur.F) % MOD[0];
			cur.S = (ss[1][fl] * id[u] + cur.F) % MOD[1];
			fl++;
		}

	reverse(adj[v].begin(), adj[v].end());
	cur = temp;

	if (mp.count(cur))
		id[v] = mp[cur];
	else
		id[v] = mp[cur] = ++sz;


	cnt[id[v]]++;
}

void dfs(int v, int p = -1){
	if (~p){
		int fl = adj[v].size();
		sort(adj[v].begin(), adj[v].end(), cmp);
		pair<ll, ll> cur(0, 0);
		for (int u:adj[v]){
			svl[u] = cur;
			rem[u] = --fl;
			cur.F = (cur.F*B[0] + id[u]) % MOD[0];
			cur.S = (cur.S*B[1] + id[u]) % MOD[1];
		}
		auto temp = cur;

		cur = {0, 0};
		reverse(adj[v].begin(), adj[v].end());
		fl = 0;
		for (int u:adj[v]){
			svr[u] = cur;
			cur.F = (ss[0][fl] * id[u] + cur.F) % MOD[0];
			cur.S = (ss[1][fl] * id[u] + cur.F) % MOD[1];
			fl++;
		}

		reverse(adj[v].begin(), adj[v].end());
		cur = temp;

		cnt[id[v]]--;
		if (cnt[id[v]] == 0) tt--;
		if (mp.count(cur))
			id[v] = mp[cur];
		else
			id[v] = mp[cur] = ++sz;
		cnt[id[v]]++;
		if (cnt[id[v]] == 1) tt++;
	}

	mx = max(mx, {tt, v+1});
	for (int u:adj[v])
		if (u^p){
			int temp = id[v], temp2 = tt;
			cnt[id[v]]--;
			if (cnt[id[v]] == 0) tt--;
			auto hs = svl[u];
			hs.F = (hs.F*ss[0][rem[u]] + svr[u].F) % MOD[0];
			hs.S = (hs.S*ss[1][rem[u]] + svr[u].S) % MOD[1];
			if (mp.count(hs))
				id[v] = mp[hs];
			else
				id[v] = mp[hs] = ++sz;
			cnt[id[v]]++;
			if (cnt[id[v]] == 1) tt++;

			dfs(u, v);

			cnt[id[v]]--;
			id[v] = temp;
			cnt[id[v]]++;
			tt = temp2;
		}
}

int main(){
	for (int w = 0; w < 2; w++){
		ss[w][0] = 1;
		for (int i = 1; i < MAXN; i++)
			ss[w][i] = ss[w][i - 1] * B[w] % MOD[w];
	}

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (n == 1){
		cout << 1 << "\n";
		return 0;
	}
	plant(0);
	tt = sz;
	dfs(0);

	cout << mx.S << "\n";
	return 0;
}