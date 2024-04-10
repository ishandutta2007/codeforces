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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		V<vi> G(n + 1);
		vi d(n + 1);
		for(int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			G[u].PB(v);
		}
		vi ans;
		for(int i = 1; i <= n; i++) {
			if(d[i] == 2) {
				ans.PB(i); // removed
				continue;
			}
			for(int j:G[i]) d[j] = max(d[j], d[i] + 1);
		}
		assert(ans.size() <= 4*n/7);
		cout << ans.size() << endl;
		for(int i:ans) cout << i << " ";
		cout << endl;
	}	

	
}