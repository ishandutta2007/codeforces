#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
#define bignum vector <int>
 
 
using namespace std;
const int nax = 2e5 + 111;
int n, m;
int cost[nax];
int a, b;
vector <int> v[nax];

struct Fen{
	int t[nax];
	void init() {
		FOR(i, 1, n)
			t[i] = 0;
	}
			
	void add(int p, int x)
	{
		for(int i = p; nax > i; i += i & -i)
			t[i] += x;
	}
	int sum(int p)
	{
		int s = 0;
		for(int i = p; i > 0; i -= i & -i)
			s += t[i];
		return s;
	}
	
	int query(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

Fen ja;

int in[nax], out[nax], Pre = 1;
int s;
ll dp[nax];
ll dp2[nax];
bool odw[nax];

bool ok(int u) {
	return ja.query(in[u], out[u]) > 0;
}

void dfs(int u, int p) {
	odw[u] = 1;
	dp2[u] = cost[u];
	in[u] = Pre++;
	ll best = cost[u];
	for(auto it: v[u]) {
		if(odw[it] == 0) {
			dfs(it, u);
			best = max(best, dp2[it] + cost[u]);
		}
		else if(it != p)
			ja.add(in[u], 1);
	}
	
	dp2[u] = best;		
	out[u] = Pre - 1;
}

vector <int> eee;

void solve(int u, int p) {
	dp[u] = cost[u];
	odw[u] = 1;
	for(auto it: v[u]) {
		if(!odw[it]) {
			solve(it, u);
			if(ok(it))
				dp[u] += dp[it];
		}
	}
	if(!ok(u))
		eee.pb(u);
}
	

int main() {
	ios;
	ja.init();
	cin >> n >> m;
	FOR(i, 1, n)
		cin >> cost[i];
	FOR(i, 1, m) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	cin >> s;
	dfs(s, 0);
	
	FOR(i, 1, n)
		odw[i] = 0;
	
	solve(s, 0);
	
	ll ans = 0;
	for(auto it: eee) {
		if(it != s) {
			ans = max(ans, dp2[it]);
		}
	}
	
	cout << ans + dp[s];
	
	
	
	
	
	return 0;
}