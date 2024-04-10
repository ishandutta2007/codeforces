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

const int INF = 1e9 + 7, M = 1e4 + 3, G = 1003;

int d[M];
int dist[M][G];

signed main()
{
	IO_OP;
	
	int n, m, g, r;
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> d[i];
	sort(d, d+m);
	cin >> g >> r;
	deque<pi> dk; // 0/1 BFS
	memset(dist, 0x3f, sizeof dist);
	dk.PB({0, 0});
	dist[0][0] = 0;
	int ans = INF;
	while(dk.size()) {
		pi p = dk.front(); dk.pop_front();
		if(p.S == 0) {
			if(n - d[p.F] <= g) {
				ans = min(ans, dist[p.F][p.S] * (r + g) + n - d[p.F]);
			}
		}
		auto add = [&] (pi v, int nw_dist, bool one) {
			if(dist[v.F][v.S] > nw_dist) {
				dist[v.F][v.S] = nw_dist;
				if(one) dk.PB(v);
				else dk.push_front(v);
			}
		};
		if(p.F > 0) { // has left
			pi v;
			v.F = p.F - 1;
			if(p.S + d[p.F] - d[v.F] < g) {
				v.S = p.S + d[p.F] - d[v.F];
				add(v, dist[p.F][p.S], 0);
			} else if(p.S + d[p.F] - d[v.F] == g) {
				v.S = 0;
				add(v, dist[p.F][p.S] + 1, 1);
			}
		}
		if(p.F < m - 1) { // has right
			pi v;
			v.F = p.F + 1;
			if(p.S + d[v.F] - d[p.F] < g) {
				v.S = p.S + d[v.F] - d[p.F];
				add(v, dist[p.F][p.S], 0);
			} else if(p.S + d[v.F] - d[p.F] == g) {
				v.S = 0;
				add(v, dist[p.F][p.S] + 1, 1);
			}
		}
	}
	if(ans == INF) ans = -1;
	cout << ans << endl;
	
}