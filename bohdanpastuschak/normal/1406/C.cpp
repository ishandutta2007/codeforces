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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<vector<int>> g(n + 1);
		PII E;
		FOR(i, 1, n){
			int u, v;
			cin >> u >> v;
			E = {u, v};
			g[u].PB(v);
			g[v].PB(u);
		}

		vector<int> sz(n + 1, 0);
		vector<int> P(n + 1, -1);
		
		function<void(int, int)> dfs_sz = [&](int x, int p){
			sz[x] = 1;
			P[x] = p;
			for(auto i: g[x]) if (i != p){
				dfs_sz(i, x);
				sz[x] += sz[i];
			}
		};

		dfs_sz(1, -1);		
		int u = -1, v = -1;
		if (n % 2 == 0){
			FOR(i, 1, n + 1) for(auto j: g[i]) if (P[j] == i && sz[j] == n / 2){
				assert(u == -1 && v == -1);
				u = i;
				v = j;
			}
		}

		if (u == -1){
			FOR(it, 0, 2) cout << E.X << ' ' << E.Y << endl;
		}else{
			int leaf = -1;
			P = VI(n + 1, -1);
			function<bool(int, int)> dfs_leaf = [&](int x, int p){
				P[x] = p;
				if (SZ(g[x]) == 1){
					leaf = x;
					return 1;				
				}

				for(auto i: g[x]) if (i != p){
					if (dfs_leaf(i, x)) return 1;
				}
				return 0;
			};

			dfs_leaf(v, u);
			assert(leaf != v && leaf != u && leaf != -1 && P[leaf] != -1);	
			cout << P[leaf] << ' ' << leaf << endl;
			cout << u << ' ' << leaf << endl;
		}
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;	
	return 0;
}