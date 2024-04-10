#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1505;
int n;
vector<int> G[N*2];

bool visited[N*2];
void find_cycle(int p, int u, vector<int>& ans) {
	if(!visited[u]) {
		visited[u] = true;
		for(int v : G[u]) {
			if(v == p) continue;
			ans.push_back(u);
			find_cycle(u, v, ans);
			return;
		}
	}
}

inline bool in_range(int a, int b, int x) {
	return a <= x && x <= b;
}

// get ways to choose intervals [i, j] containing [l, r]
// and intervals [I, J] containing [L, R]
// such that val1, val2 are NOT contained
ll get_ways(int& l, int& r, int& L, int& R, int val1, int val2) {
	ll l_lb[2] = {0, 0};
	ll r_ub[2] = {n-1, n-1};
	ll L_lb[2] = {n, n};
	ll R_ub[2] = {2*n-1, 2*n-1};
	// make sure both are not in bad range
	if(val1 >= n) {
		if(in_range(L, R, val1)) return 0 ;
		if(val1 < L) L_lb[0] = val1+1;
		else R_ub[0] = val1-1;
	} else {
		if(in_range(l, r, val1)) return 0 ;
		if(val1 < l) l_lb[0] = val1+1;
		else r_ub[0] = val1-1;
	}

	if(val2 >= n) {
		if(in_range(L, R, val2)) return 0;
		if(val2 < L) L_lb[1] = val2+1;
		else R_ub[1] = val2-1;
	} else {
		if(in_range(l, r, val2)) return 0;
		if(val2 < l) l_lb[1] = val2+1;
		else r_ub[1] = val2-1;
	}

	const ll l_ways = l-max(l_lb[0], l_lb[1])+1;
	const ll r_ways = min(r_ub[0], r_ub[1])-r+1;
	const ll L_ways = L-max(L_lb[0], L_lb[1])+1;
	const ll R_ways = min(R_ub[0], R_ub[1])-R+1;
	return l_ways * r_ways * L_ways * R_ways;
}

ll contains_entire(vector<int>& cycle) {
	int mx[2] = {-1, -1};
	int mn[2] = {n*2, n*2};
	const int sz = cycle.size();
	for(int j = 0; j < sz; ++j) {
		bool which = cycle[j] >= n;
		mx[which] = max(mx[which], cycle[j]);
		mn[which] = min(mn[which], cycle[j]);
	}
	const ll ways = get_ways(mn[0], mx[0], mn[1], mx[1], -1, -1);
	return ways * sz/2;
}

inline int advance(int i, int dir, int sz) {
	return (sz+i+dir) % sz;
}

ll solve_cycle(vector<int>& cycle) {
	ll ans = contains_entire(cycle);
	const int sz = cycle.size();
	for(int i = 0; i < sz; ++i) {
		int mx[2] = {-1, -1};
		int mn[2] = {n*2, n*2};
		for(int len = 1; len < sz; ++len) {
			// update lower bounds
			int j = (i+len-1) % sz;
			bool which = cycle[j] >= n;
			mx[which] = max(mx[which], cycle[j]);
			mn[which] = min(mn[which], cycle[j]);
			if(len == 1) continue;
			const int avoid1 = cycle[advance(i, -1, sz)];
			const int avoid2 = cycle[advance(j,  1, sz)];
			const ll ways = get_ways(mn[0], mx[0], mn[1], mx[1], avoid1, avoid2);
			ans = (ans + ways * (len/2));
		}
	}
	return ans;
}

vector<vector<int>> cycles;

int main() {
	cin >> n;
	for(int i = 0; i < 2*n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i = 0; i < n; ++i) {
		if(visited[i]) continue;
		cycles.push_back(vector<int>());
		find_cycle(-1, i, cycles.back());
	}

	ll ans = 0;
	for(vector<int>& cycle : cycles)
		ans += solve_cycle(cycle);
	cout << ans << '\n';
}