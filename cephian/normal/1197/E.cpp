#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

struct top_sort {
	vector<vector<int>> G; //stores G; take it out if you want to use it elsewhere
	vector<int> order; //stores the topological sort
	vector<short> seen;
	void init(int n) { G.resize(n); seen.resize(n); }
	top_sort(int n) { init(n); }
	top_sort() {}
	
	//add a new edge
	inline void add_edge(int u, int v) { G[u].push_back(v); }

	bool visit(int u) {
		if(seen[u] == 2) return true;
		if(seen[u] == 1) return false;
		for(int v : G[u])
			if(!visit(v))
				return false;
		seen[u] = 2;
		order.push_back(u);
		return true;
	}
	//topologically sort
	bool sort() {
		for(int i = 0; i < (int)G.size(); ++i)
			if(!visit(i))
				return false;
		reverse(order.begin(),order.end());
		return true;
	}
};

top_sort T;
vector<int> first_end;
vector<tuple<int,int,int>> edges;

const int N = 3e5+5;
int t[N<<2];
int ctr;
pair<int,int> all[N];
int mn_out[N];
int n;

void build(int v, int i, int j) {
	if(i == j) {
		t[v] = ctr++;
		edges.emplace_back(t[v], i, all[i].first);
		return;
	}
	int md = (i+j)/2;
	build(v*2, i, md);
	build(v*2+1, md+1, j);
	t[v] = ctr++;
	edges.emplace_back(t[v], t[v*2], 0);
	edges.emplace_back(t[v], t[v*2+1], 0);
}

void attach(int from, int v, int l, int r, int i, int j, int wt) {
	if(j < l || i > r) return;
	if( i <= l && r <= j) {
		edges.emplace_back(from, t[v], wt);
		return;
	}
	if(l == r) return;
	const int m = (l+r)/2;
	attach(from, v*2, l, m, i, j, wt);
	attach(from, v*2+1, m+1, r, i, j, wt);
}

int ffsg(int x) {
	int lo = -1, hi = n;
	while(hi-lo > 1) {
		int md = (lo+hi)/2;
		if(all[md].first <= x)
			lo = md;
		else hi = md;
	}
	return hi;
}

bool attach_out(int from, int out) {
	// first first thing strictly greater than out
	const int L = ffsg(out-1);
	if(L == n) return false;
	//cout << "ffst(" << out << ") is " << L << endl;
	const int R = ffsg(mn_out[L]-1)-1;
	attach(from, 1, 0, n-1, L, R, -out);
	return true;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> all[i].second >> all[i].first;
	}
	sort(all, all + n);
	mn_out[n] = 2e9;
	for(int i=n-1; i >= 0; --i)
		mn_out[i] = min(mn_out[i+1], all[i].second);

	ctr = n;
	build(1, 0, n-1);
	vector<int> END;
	for(int i = 0; i < n; ++i)
		if(!attach_out(i, all[i].second))
			END.push_back(i);
	const int START = ctr;
	attach_out(ctr++, 0);
	// find # of ways to get min dist from START to something in END

	top_sort T(ctr);
	vector<vector<pair<int,int>>> incoming(ctr);
	vector<pair<ll,int>> dp(ctr);
	for(int i = 0; i < (int)edges.size(); ++i) {
		int u, v, w;
		tie(u, v, w) = edges[i];
		T.add_edge(u, v);
		incoming[v].emplace_back(u, w);
	}
	//return 0;
	assert(T.sort());
	for(int x : T.order) {
		if(x != START) {
			dp[x].first = 1LL<<40;
			dp[x].second = 0;
			for(auto& y : incoming[x]) {
				const ll val = dp[y.first].first + y.second;
				const int cnt = dp[y.first].second;
				if(dp[x].first > val) {
					dp[x].first = val;
					dp[x].second = cnt;
				} else if (dp[x].first == val) {
					dp[x].second = (dp[x].second + cnt) % MOD;
				}
			}
		} else {
			dp[x].first = 0;
			dp[x].second = 1;
		}
	}

	// finish this up
	ll best_space = 1LL << 60;
	for(int x : END) {
		best_space = min(best_space, dp[x].first);
	}

	int ans = 0;
	for(int x : END) {
		if(dp[x].first == best_space) {
			ans = (ans + dp[x].second) % MOD;
		}
	}
	cout << ans << '\n';
}