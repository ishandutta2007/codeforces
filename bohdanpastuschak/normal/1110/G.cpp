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

bool solve(int n, const vector<vector<int>>& g, const string& s, const int tc){
	if (n < 3) return false;
	if (n == 3) return count(ALL(s), 'W') == 2;
	FOR(i, 0, n) if (SZ(g[i]) >= 4) return true;
	FOR(i, 0, n) for(auto j: g[i]) if (s[i] == 'W' && s[j] == 'W') return true;
	FOR(i, 0, n) if (s[i] == 'W' && SZ(g[i]) > 1) return true;
	FOR(i, 0, n) if (s[i] == 'W') for(auto j: g[i]) if (SZ(g[j]) >= 3) return true;
	vector<int> color(n, -1);
	vector<int> d(n, 0);
	function<void(int, int)> dfs = [&](int v, int col){
		color[v] = col;
		for(auto i: g[v]) if (color[i] == -1){
			d[i] = d[v] + 1;
			dfs(i, col ^ 1);
		}
	};

	dfs(0, 0);
	int cnt3[] = {0, 0};
	FOR(i, 0, n) if (SZ(g[i]) == 3) cnt3[color[i]]++;
	if (cnt3[0] > 1 || cnt3[1] > 1) return true;
	int cntW[] = {0, 0};
	FOR(i, 0, n) if (s[i] == 'W') cntW[color[i]]++;
	if (cntW[0] > 1 || cntW[1] > 1) return true;

	bool dbg = tc == 107;
	if (cnt3[0] == 0 && cnt3[1] == 0) return false;
	if (cnt3[0] ^ cnt3[1]){
		int v = -1;
		FOR(i, 0, n) if (SZ(g[i]) == 3) v = i;
		d[v] = 0;
		color.assign(n, -1);
		dfs(v, 0);
		vector<pair<int, int>> leafs;
		FOR(i, 0, n) if (SZ(g[i]) == 1){
			leafs.PB({d[i], i});
		}
		assert(SZ(leafs) == 3);
		sort(ALL(leafs));
		if (leafs[1].X >= 2) return true;
		if (cntW[0] + cntW[1] == 0) return false;
		assert(s[leafs.back().Y] == 'W');
		return leafs.back().X % 2 == 1;
	}else{
		int v = -1, u = -1;
		FOR(i, 0, n) if (SZ(g[i]) == 3){
			if (v == -1) v = i;
			else u = i;
		}
		
		assert(u != -1 && v != -1);		
		int cntU = 0, cntV = 0;
		for(auto i: g[u]) cntU += SZ(g[i]) == 2;
		for(auto i: g[v]) cntV += SZ(g[i]) == 2;
		if (cntU == 2 || cntV == 2) return true;
		color.assign(n, -1);
		d[v] = 0;
		dfs(v, 0);
		if (d[u] > 1) cntU--, cntV--;
		if (d[u] >= 3 && (cntU || cntV)) return true;
		if (d[u] == 1) return cntU || cntV;
		return false;
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	
	FOR(t, 1, tc + 1){
		int n; cin >> n;
		vector<vector<int>> g(n);
		FOR(i, 1, n){
			int u, v;
			cin >> u >> v;
			--u; --v;
			g[u].PB(v);
			g[v].PB(u);
		}
		string s; cin >> s;
		cout << (solve(n, g, s, t) ? "White\n" : "Draw\n");		
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}