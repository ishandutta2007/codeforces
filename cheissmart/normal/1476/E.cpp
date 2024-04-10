#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

map<string, int> id;
string s[N];
vi G[N], ans;

int vis[N];

void dfs(int u) {
	vis[u] = 1;
	for(int v:G[u]) {
		if(!vis[v]) dfs(v);
		else if(vis[v] == 1) {
			cout << "NO" << endl;
			exit(0);
		}
	}
	ans.PB(u);
	vis[u] = 2;
}

signed main()
{
	IO_OP;

	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		id[s[i]] = i;
	}
	auto get = [&] (string& t) -> vi {
		vi v;
		for(int mask = 0; mask < (1 << k); mask++) {
			string r = t;
			for(int i = 0; i < k; i++) if(mask >> i & 1)
				r[i] = '_';
			if(id.count(r))
				v.PB(id[r]);
		}
		return v;
	};
	for(int i = 0; i < m; i++) {
		string t;
		int j;
		cin >> t >> j;
		for(int l = 0; l < k; l++) {
			if(s[j][l] != '_' && s[j][l] != t[l]) {
				cout << "NO" << endl;
				exit(0);
			}
		}
		vi v = get(t);
		for(int l:v) if(l != j)
			G[l].PB(j);
	}
	for(int i = 1; i <= n; i++)
		if(vis[i] == 0)
			dfs(i);
	cout << "YES" << endl;
	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";

}