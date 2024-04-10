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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

vi G[N], ans;
int d[N], p[N], n;

void dfs(int u, int tt = 0) {
	cout << u << " ";
	for(int v:G[u]) {
		for(int i=0;i<tt;i++) ans.PB(v);
		dfs(v), tt = d[v]+1;
	}
}

signed main()
{
	cin >> n;
	for(int i=1;i<n;i++) G[(cin >> p[i]), p[i]].PB(i);	
	for(int i=n-1;i>=0;i--) {
		sort(ALL(G[i]), [](int u, int v){return d[u] < d[v];});
		if(G[i].size()) d[i] = d[G[i].back()]+1;
	} dfs(0);
	cout << endl << ans.size() << endl;
	for(int e:ans) cout << e << " ";
}