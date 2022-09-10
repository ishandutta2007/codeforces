#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Tree{
public:	
	int n, lg, root;
	vector<vector<int>> g;
	vector<int> parent;
	vector<int> sz;
	vector<int> dist;
	vector<int> tin, tout;
	vector<vector<int>> dp;
	int timer;

	inline void dfs_dp(int v, int p){
		parent[v] = dp[v][0] = p;
		FOR(i, 1, lg) dp[v][i] = dp[dp[v][i - 1]][i - 1];
		sz[v] = 1;
		tin[v] = timer++;
		for(auto i: g[v]) if (i != p){
			dist[i] = dist[v] + 1;
			dfs_dp(i, v);
			sz[v] += sz[i];
		}
		
		tout[v] = timer - 1;
	}

	inline bool is_anc(int u, int v){
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	}

	inline int lca(int u, int v){
		if (is_anc(u, v)) return u;
		if (is_anc(v, u)) return v;
		RFOR(i, lg, 0) if (!is_anc(dp[u][i], v)){
			u = dp[u][i];
		}
		
		return dp[u][0];
	}

	inline int get_distance(int u, int v){
		return dist[u] + dist[v] - 2 * dist[lca(u, v)];
	}
	
	Tree(){}
	Tree(int _n){
		n = _n;
		lg = 0;
		root = 0;
		while((1 << lg) < n) lg++;
		
		timer = 0;
				
		g.resize(n);
		parent.assign(n, -1);
		sz.assign(n, 0);
		tin.assign(n, 0);
		tout.assign(n, 0);
		dp.assign(n, vector<int>(lg, 0));
		dist.assign(n, 0);
	}

	void build(){
		dfs_dp(0, 0);
	}
	
	void add_edge(int u, int v){
		g[u].PB(v);
		g[v].PB(u);
	}	
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while(tc--){
		int n, a, b, da, db; cin >> n >> a >> b >> da >> db;
		--a; --b;
		Tree t(n);
		FOR(i, 1, n){
			int u, v;
			cin >> u >> v;
			--u; --v;
			
			t.add_edge(u, v);
		}

		t.build();

		vector<int> D(n, 0);

		auto bfs = [&](int u){
			D = vector<int>(n, INF);
			D[u] = 0;
			queue<int> q; q.push(u);
			while(!q.empty()){
				u = q.front();
				q.pop();
				for(auto i: t.g[u]) if (D[i] > D[u] + 1){
					D[i] = D[u] + 1;
					q.push(i);
				}
			}
		};
		
		auto diam = [&](){
			bfs(0);
			int mx = 0;
			FOR(i, 1, n) if (D[i] > D[mx]) mx = i;
			bfs(mx);
			int mx2 = 0;
			FOR(i, 1, n) if (D[i] > D[mx2]) mx2 = i;

			return D[mx2];			
		};

		auto solve = [&](){
			if (t.get_distance(a, b) <= da) return true;
			if (da > db) return true;
			
			const int d = diam();
			if (da * 2 >= d) return true;

			if (da * 2 >= db) return true;
			
			return false;
		};
		
		cout << (solve() ? "Alice\n" : "Bob\n");
	}

	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;	
	return 0;
}