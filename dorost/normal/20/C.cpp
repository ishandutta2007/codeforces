/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
vector <pair <int, int>> g[N];
ll dis[N];
int par[N];

void dijkstra (int s) {
    for (int i = 0; i < N; i++) {
        dis[i] = LLONG_MAX;
    }   
    dis[s] = 0;
    priority_queue <pair <ll, int>> q;
    q.push(make_pair(-1 * dis[s], s));
    while (!q.empty()) {
        pair <ll, int> p = (q.top());
        int x = p.S;
        q.pop();
        if (dis[x] != -1 * p.F)
            continue;
        ll d = dis[x];
        for (auto [y, w] : g[x]) {
            if (dis[y] <= d + w) {
                continue;
            }
			par[y] = x;
            dis[y] = d + w;
            q.push(make_pair(-1 * dis[y], y));
        }
    }   
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	dijkstra(n);
	if (dis[1] == LLONG_MAX) {
		cout << -1;
		return 0;
	}
	int x = 1;
	cout << 1;
	while (par[x] != 0) {
		x = par[x];
		cout << ' ' << x;
	}
}