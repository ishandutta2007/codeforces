#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") -> " << #x << " is " << x << endl
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;
 
const int INF = 1e9 + 7, N = 3e5 + 7;
 
vi S[N], G[N];
int ans[N];
 
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
 
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int s;
		cin >> s;
		for(int j = 0; j < s; j++) {
			int x;
			cin >> x;
			S[i].PB(x);
		}
	}
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	int u = 1;
	for(int i = 1; i <= n; i++) {
		if(S[i].size() > S[u].size()) {
			u = i;
		}
	}
	int c = max((int)S[u].size(), 1);
	cout << c << endl;
	function<void(int, int)> dfs = [&] (int u, int p) {
		unordered_set<int> used;
		for(int x:S[u]) if(ans[x]) {
			used.insert(ans[x]);
		}
		int ptr = 1;
		for(int x:S[u]) if(ans[x] == 0) {
			while(used.count(ptr)) ptr++;
			assert(ptr <= c);
			ans[x] = ptr++;
		}
		for(int v:G[u]) if(v != p)
			dfs(v, u);
	};
	dfs(u, -1);
	for(int i = 1; i <= m; i++) {
		if(ans[i] == 0)
			ans[i] = 1;
		cout << ans[i] << " ";
	}
	cout << '\n';
}