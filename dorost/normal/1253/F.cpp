/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
const ll INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 2LL;
int so[N], dis[N], k;
vector <pair <int, int>> g[N], t[N];
map <int, bool> mp[N];
int w[N];
vector <int> v[N];
int ans[N * 3];

void merge(int x, int y, int wa) {
	x = w[x];
	y = w[y];
	if (x == y)
		return;
	if (v[x].size() + mp[x].size() > v[y].size() + mp[y].size())
		swap(x, y);
	int ww = x;
	for (auto a : v[ww]) {
		w[a] = y;
		v[y].push_back(a);
	}
	for (auto [a, s] : mp[ww]) {
		if (s && mp[y][a]) {
			ans[a] = wa;
		}
	}
	for (auto [a, s] : mp[ww]) {
		if (s && !mp[y][a])
			mp[y][a] = true;
	}
}

bool cmp (pair <pair <int, int>, int> p1, pair <pair <int, int>, int> q) {
	return p1.S < q.S;
}

void dijkstra () {
    for (int i = 0; i < N; i++) {
        dis[i] = INF;
    }  
    priority_queue <pair <int, int>> q;
	for (int i = 1; i <= k; i++) {
		so[i] = i;
		dis[i] = 0;
    	q.push(make_pair(-1 * dis[i], i));
	}
    while (!q.empty()) {
        pair <int, int> p = (q.top());
        int x = p.S;
        q.pop();
        if (dis[x] != -1 * p.F)
            continue;
        int d = dis[x];
        for (auto [y, w] : g[x]) {
            if (dis[y] <= d + w) {
                continue;
            }
            dis[y] = d + w;
			so[y] = so[x];
            q.push(make_pair(-1 * dis[y], y));
        }
    }   
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m, q;
	cin >> n >> m >> k >> q;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	dijkstra();
	vector <pair <pair <int, int>, int>> pe;
	for (int i = 1; i <= n; i++) {
		for (auto [j, w] : g[i]) {
			if (so[i] != so[j]) {
				t[so[i]].push_back(make_pair(so[j], w + dis[i] + dis[j]));
				if (i < j) {
					pe.push_back(make_pair(make_pair(so[i], so[j]), w + dis[i] + dis[j]));
				}
			}
		}
	}
	sort (pe.begin(), pe.end(), cmp);
	for (int i = 1; i <= k; i++) {
		mp[i].clear();
		v[i] = {i};
		w[i] = i;
	}
	for (int i = 0; i < q; i++) {
		int s, t;
		cin >> s >> t;
		mp[s][i] = true;
		mp[t][i] = true;
	}
	for (auto [x, y] : pe) {
		merge(x.F, x.S, y);
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
}