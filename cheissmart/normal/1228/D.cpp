#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int ans[100005], two_or_3[100005], u[300005], v[300005];
vi x, y, z;
map<pi, bool> ok;
vi G[100005];

bool dfs(int u, int c = 2) {
	ans[u] = c;
	if(c == 2)
		y.PB(u);
	else
		z.PB(u);
	for(int v:G[u]) {
		if(!two_or_3[v]) continue;
		if(!ans[v]) {
			bool ret = dfs(v, c^2^3);
			if(!ret) return false;
		} else if(ans[v] == c) {
			return false;
		}
	}
	return true;
}

int32_t main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		cin >> u[i] >> v[i];
		ok[MP(u[i], v[i])] = ok[MP(v[i], u[i])] = true;
		G[u[i]].PB(v[i]);
		G[v[i]].PB(u[i]);
	}
	vi vs;
	for(int u:G[1]) {
		two_or_3[u] = 1;
		vs.PB(u);
	}
	for(int i=1;i<=n;i++) {
		if(!two_or_3[i]) {
			ans[i] = 1;
			x.PB(i);
		}
	}
	for(int u:vs) {
		if(!ans[u]) {
			if(!dfs(u)){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for(int i=0;i<m;i++) {
		if(ans[u[i]] == ans[v[i]]) {
			cout << -1 << endl;
			return 0;
		}
	}
	if(x.empty() || y.empty() || z.empty() || (ll)x.size()*(ll)y.size() > m || (ll)x.size()*(ll)z.size() > m || (ll)z.size()*y.size() > m) {
		cout << -1 << endl;
		return 0;
	}
	for(int xx:x)
		for(int yy:y)
			if(!ok[MP(xx, yy)]) {
				cout << -1 << endl;
				return 0;
			}
	for(int xx:x)
		for(int zz:z)
			if(!ok[MP(xx, zz)]) {
				cout << -1 << endl;
				return 0;
			}
	for(int zz:z)
		for(int yy:y)
			if(!ok[MP(zz, yy)]) {
				cout << -1 << endl;
				return 0;
			}
	for(int i=1;i<=n;i++) {
		cout << ans[i] << " ";
	}
}