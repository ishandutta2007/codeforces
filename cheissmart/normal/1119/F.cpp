#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

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

const int INF = 1e9 + 7, N = 250007;

struct Sum_set {
	multiset<int> s;
	ll sum;
	Sum_set() { sum = 0LL; }
	void insert(int x) {
		sum += x;
		s.insert(x);
	}
	void erase(int x) {
		sum -= x;
		s.erase(s.find(x));
	}
	int size() {
		return s.size();
	}
	int top() { // pop max
		assert(s.size());
		return *s.rbegin();
	}
	void pop() { // pop max
		assert(s.size());
		sum -= *s.rbegin();
		s.erase(s.find(*s.rbegin()));
	}
} ds[N];

set<pi> G[N];
vi with_deg[N];
int vis[N], deg[N];
ll dp[N][2];


signed main()
{
	IO_OP;

	int n;
	cin >> n;
	ll tot_w = 0;
	for(int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		tot_w += w;
		G[u].emplace(v, w);
		G[v].emplace(u, w);
	}

	for(int i = 1; i <= n; i++)
		with_deg[deg[i] = int(G[i].size())].PB(i);

	set<int> alive;
	for(int i = 1; i <= n; i++)
		alive.insert(i);

	auto solve = [&] (int k) { // deg at most k
		function<void(int, int)> dfs = [&] (int u, int p) {
			vis[u] = 1;
			ll dp_val = 0;
			int del = max(deg[u] - k, 0);
			while(ds[u].size() > del) ds[u].pop();
			vi undo_ins, undo_del;
			for(pi e:G[u]) if(e.F != p) {
				int v, w;
				tie(v, w) = e;
				dfs(v, u);
				dp_val += dp[v][1];
				undo_ins.PB(w - (dp[v][1] - dp[v][0]));
				ds[u].insert(w - (dp[v][1] - dp[v][0]));
				while(ds[u].size() > del) {
					if(ds[u].top() < 0) dp_val += ds[u].top();
					undo_del.PB(ds[u].top()), ds[u].pop();
				}
			}
			dp_val += ds[u].sum;
			dp[u][0] = dp[u][1] = dp_val;
			if(ds[u].size() && ds[u].top() > 0) dp[u][0] = dp_val - ds[u].top(); 

			for(int x:undo_del) ds[u].insert(x);
			for(int x:undo_ins) ds[u].erase(x);
		};
		ll ans = 0;
		for(int i:alive) if(!vis[i]) {
			dfs(i, 0);
			ans += dp[i][1];
		}
		for(int i:alive)
			vis[i] = 0;
		return ans;
	};

	cout << tot_w << ' ';
	for(int i = 1; i < n; i++) {
		// all nodes with deg <= i are dead
		for(int u:with_deg[i]) { // mark u as dead
			alive.erase(u);
			for(pi e:G[u]) {
				int v, w;
				tie(v, w) = e;
				assert(alive.count(v));
				ds[v].insert(w);
				G[v].erase({u, w});
			}
		}
		cout << solve(i) << ' ';
	}

}