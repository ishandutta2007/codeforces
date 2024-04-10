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

const int INF = 1e9 + 7, N = 2e5 + 7;

int p[N], c[N], vis[N], r[N];

void solve() {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> p[i];
	for(int i=1;i<=n;i++) cin >> c[i];
	fill(vis+1, vis+n+1, 0);
	int ans = INF;
	for(int i=1;i<=n;i++) {
		if(vis[i]) continue;
		int u = i;
		vi v;
		for(;!vis[u];u=p[u]) {
			vis[u] = 1;
			v.PB(c[u]);
		}
		for(int j=1;j*j<=v.size();j++) {
			if(v.size()%j) continue;
			for(int b:vi({j, v.size()/j})){
				vi ok(b, 1);
				for(int k=0;k<v.size();	k++) {
					int tt = k % b;
					if(r[tt] == 0) r[tt] = v[k];
					else if(r[tt] != v[k]) ok[tt] = 0;
				}
				if(count(ALL(ok), 1)) ans = min(ans, b);
				for(int k=0;k<b;k++) r[k] = 0;
			}
		}
	}
	cout << ans << '\n';
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) solve();

}