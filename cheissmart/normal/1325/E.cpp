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

const int INF = 1e9 + 7, N = 1e6 + 7;

V<pi> G[N];
bitset<N> vis;
int d[N], pa[N];

int BFS(int s) {
	vis = 0;
	int ret = INF;
	vis[s] = 1, d[s] = 0, pa[s] = -1;
	queue<int> q({s});
	while(q.size()) {
		int u = q.front(); q.pop();
		for(pi p:G[u]) if(p.S != pa[u]) {
			int v = p.F;
			if(!vis[v]) {
				vis[v] = 1;
				d[v] = d[u] + 1;
				pa[v] = p.S;
				q.push(v);
			} else {
				ret = min(ret, d[u] + d[v] + 1);
			}
		}
	}
	return ret;
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int tt, t, ttt = 1;
		cin >> tt;
		t = tt;
		vi v;
		for(int j=2;j*j<=t;j++) {
			if(t % j == 0) {
				int cnt = 0;
				while(t % j == 0) t /= j, cnt++;
				if(cnt & 1) v.PB(j), ttt *= j;
			}
		}
		if(t != 1) v.PB(t), ttt *= t;
		if(v.size() == 0) {
			cout << 1 << endl;
			return 0;
		} else if(v.size() == 1) {
			G[ttt].EB(1, i);
			G[1].EB(ttt, i);
		} else {
			G[v[0]].EB(v[1], i);			
			G[v[1]].EB(v[0], i);
		}
	}
	int ans = INF;
	for(int i=1;i<=1000;i++) ans = min(ans, BFS(i));
	if(ans == INF) ans = -1;
	cout << ans << endl;
	
}