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

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 	
 	int t; cin >> t;
 	while(t--){
		int p; cin >> p;
		int n = 1 << p;
		vector<vector<PII>> g(n);
		FOR(i, 0, n - 1){
			int u, v; cin >> u >> v; --u; --v;
			g[u].PB({v, i});
			g[v].PB({u, i});
		}
		
		int root = -1;
		FOR(i, 0, n) if (SZ(g[i]) == 1) root = i;
		
		vector<int> label(n, -1);
		vector<int> edgeLabel(n - 1, -1);
		int small = 2, big = n + 2;
		vector<int> curr(n, -1);
				
		function<void(int, int)> dfs = [&](int v, int parent){
			
			if (parent == -1){
				for(auto to: g[v]){
					edgeLabel[to.Y] = n + 1;
					label[to.X] = n;
					curr[to.X] = 0;
					dfs(to.X, v);
				}
				
				return;
			}
			
			for(auto to: g[v]){
				if (to.X == parent) continue;
				
				if (curr[v] < n){
					edgeLabel[to.Y] = small++;
					label[to.X] = big++;					
				}else{
					edgeLabel[to.Y] = big++;
					label[to.X] = small++;					
				}
				
				curr[to.X] = curr[v] ^ label[to.X] ^ edgeLabel[to.Y];
				//cout << v << ' ' << to.X << ' ' << curr[to.X] << endl;
				//assert(curr[to.X] == 0);
				dfs(to.X, v);
			}
		};
		
		curr[root] = 1;
		label[root] = 1;
		dfs(root, -1);
		
		//cout << "JA" << endl;
		//print<VI>(curr, cerr);
		cout << root + 1 << endl;
		FOR(i, 0, n) cout << label[i] << ' ';
		cout << endl;
		FOR(i, 0, n - 1) cout << edgeLabel[i] << ' ';
		cout << endl;
	}
 	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}