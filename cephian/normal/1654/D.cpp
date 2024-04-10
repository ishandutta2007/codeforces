#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<tuple<int,int,int>>> T;
const int N = 2e5+5;
const int mod = 998244353;
int f[N];

map<int,int> mx;
map<int,int> worst;

void change_mx(int x, int mlt) {
	if(x == 1) return;
	int val = mx[f[x]] + mlt;
	worst[f[x]] = max(worst[f[x]], -val);
	mx[f[x]] = val;
	change_mx(x/f[x], mlt);
}

void dfs(int p, int u) {
	for(const auto& e : T[u]) {
		auto[v, x, y] = e;
		if(v == p) continue;
		change_mx(y, 1);
		change_mx(x, -1);
		dfs(u, v);
		change_mx(x, 1);
		change_mx(y, -1);
	}
}

ll pw(ll a, ll b) {
	if(b == 0) return 1;
	if(b&1) return a*pw(a, b-1) % mod;
	ll t = pw(a, b/2);
	return t * t % mod;
}

inline ll inv(ll a) {
	return pw(a, mod - 2);
}

void calc(int p, int u, ll cur_val, ll& ans) {
	ans = (ans + cur_val) % mod;
	for(const auto& e : T[u]) {
		auto[v, x, y] = e;
		if(v == p) continue;
		ll nxt_val = cur_val * inv(x) % mod * y % mod;
		calc(u, v, nxt_val, ans);
	}
}

void solve() {
	int n;
	cin >> n;
	T = vector<vector<tuple<int,int,int>>>(n);
	mx.clear();
	worst.clear();
	for(int i = 0; i < n-1; ++i) {
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		--u, --v;
		T[u].emplace_back(v, x, y);
		T[v].emplace_back(u, y, x);
	}
	dfs(-1, 0);
	ll node0_amt = 1, ans = 0;
	for(const auto& x : worst)
		node0_amt = (node0_amt * pw(x.first, x.second)) % mod;
	calc(-1, 0, node0_amt, ans);
	cout << ans << '\n';
}

int main() {
	f[1] = 1;
	for(int i = 2; i < N; ++i) {
		f[i] = i;
		for(int j = 2; j*j <= i; ++j) {
			if(i%j == 0) {
				f[i] = j;
				break;
			}
		}
	}
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}