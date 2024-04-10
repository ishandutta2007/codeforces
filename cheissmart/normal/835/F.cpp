#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

template<class A, class B> string to_string(pair<A, B> p) {
	return "(" + to_string(p.F) + ", " + to_string(p.S) + ")";
}
template<class T> string to_string(T t) {
	string ans = "[";
	bool first_time = true;
	for(auto&e:t) {
		if(!first_time) ans += ", ";
		ans += to_string(e);
		first_time = false;
	}
	ans += "]";
	return ans;
}

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 2e5 + 7;
const ll oo = 1e18;

V<pi> G[N];
int deg[N];
ll d[N];

struct DS : deque<pair<ll, int>> {
	void add(ll x, int i) {
		while(size() && back().F <= x) pop_back();
		EB(x, i);
	}
	ll qry(int i) { // >= i
		while(size() && (*this)[0].S < i) pop_front();
		if(empty()) return -oo;
		debug(i, (*this)[0].F);
		return (*this)[0].F;
	}
};

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		G[u].EB(v, l);
		G[v].EB(u, l);
		deg[u]++, deg[v]++;
	}
	ll mx = 0;
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(deg[i] == 1)
			q.push(i);
	while(q.size()) {
		int u = q.front(); q.pop();
		for(auto [v, l]:G[u]) if(deg[v] > 1) {
			deg[v]--;
			mx = max(mx, d[u] + l + d[v]);
			d[v] = max(d[v], d[u] + l);
			if(deg[v] == 1)
				q.push(v);
		}
	}
	V<pair<ll, int>> cycle;
	int s = -1;

	for(int i = 1; i <= n; i++) {
		if(deg[i] == 2) s = i;
		assert(1 <= deg[i] && deg[i] <= 2);
	}
	assert(s != -1);
	for(int u = s, p = -1; ; ) {
		for(auto[v, l]:G[u]) if(v != p && deg[v] == 2) {
			cycle.EB(d[u], l);
			p = u, u = v;
			break;
		}
		if(u == s) break;
	}
	debug(cycle);
	int sz = SZ(cycle);
	assert(sz >= 3);
	for(int i = 0; i < sz; i++) cycle.PB(cycle[i]);

	V<ll> aux(sz, -oo);
	{
		ll x = 0, cur = -oo, cur2 = -oo;
		for(int i = sz - 1; i >= 0; i--) {
			x += cycle[i].S;
			cur = max(cur, cycle[i].F + x + cur2);
			cur2 = max(cur2, cycle[i].F - x);
			aux[i] = cur;
		}
	}


	ll x = 0, ans = oo;
	DS sa;
	for(int i = 0; i < sz; x += cycle[i].S, i++) sa.add(cycle[i].F - x, i);

	ll cur = -oo, cur2 = -oo, cur3 = -oo;
	for(int i = sz; i < sz * 2; x += cycle[i].S, i++) {
		cur3 = max(cur3, cycle[i].F + x);
		cur = max(cur, cycle[i].F + x + cur2);
		cur2 = max(cur2, cycle[i].F - x);
		ll cans = sa.qry(i - sz + 1) + cur3;
		debug(cans, i - sz + 1);
		cans = max(cans, cur);
		if(i - sz + 1 < sz)
			cans = max(cans, aux[i - sz + 1]);
		debug(cans);
		ans = min(ans, cans);
	}
	cout << max(mx, ans) << '\n';
}