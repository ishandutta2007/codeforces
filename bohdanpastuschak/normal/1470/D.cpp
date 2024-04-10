#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

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

int n, m;
vector<vector<int>> g;
vector<int> used;

inline void dfs(int v){
	used[v] = 1;
	for(auto i: g[v]) if (!used[i]){
		dfs(i);
	}
}

bool check(vector<int>& ans){
	vector<vector<int>> h(n);
	vector<int> is(n, 0);
	for(auto i: ans) is[i] = 1;
	FOR(i, 0, n) if (is[i]) for(auto j: g[i]) if (is[j]) return false;
	FOR(i, 0, n){
		if (is[i]) h[i] = g[i];
		else{
			for(auto j: g[i]){
				if (is[j]){
					h[i].PB(j);
				}
			}
		}
	}

	used.assign(n, 0);
	swap(g, h);
	dfs(0);
	bool answer = true;
	FOR(i, 0, n) if (!used[i]) answer = false;
	swap(g, h);
	return answer;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		g.clear();
		g.resize(n);
		while(m--){
			int u, v; cin >> u >> v;
			--u; --v;
			if (u != v){
				g[u].PB(v);
				g[v].PB(u);
			}
		}

		/*FOR(i, 0, n){
			sort(ALL(g[i]));
			g[i].resize(unique(ALL(g[i])) - g[i].begin());
		}*/

		used.assign(n, 0);
		int c = 0;
		FOR(i, 0, n) if (!used[i]){
			c++;
			dfs(i);
		}

		if (c > 1){
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		
		vector<int> color(n, 0);
		queue<int> q;
		q.push(0);
		color[0] = 2;
		while(!q.empty()){
			int v = q.front(); q.pop();
			for(auto i: g[v]){
				if (color[i] == 0){
					color[i] = 3 - color[v];
					q.push(i);
				}else if (color[i] == 2 && color[v] == 2){
					color[i] = 1;
				}
			}
		}

		vector<int> ans;
		FOR(i, 0, n) if (color[i] == 2){
			ans.PB(i);
		}

		//assert(check(ans));
		
		cout << SZ(ans) << '\n';
		for(auto i: ans) cout << i + 1 << ' ';
		cout << '\n';
	}
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}