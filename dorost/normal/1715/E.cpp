/* 	* In the name of GOD  */

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
int n, m, k;
const int N = 101234;
const ll INF = 100000LL * 10000LL * 1000LL * 100LL * 10LL * 69LL;
ll dis[N];
ll ndis[N];
vector <pair <int, int>> g[N];

void dijkstra () {
    priority_queue <pair <ll, int>, vector <pair <ll, int>>> q;
	for (int s = 0; s < n; s++)
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
            dis[y] = d + w;
            q.push(make_pair(-1 * dis[y], y));
        }
    }   
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	dis[0] = 0;
	for (int i = 1; i < n; i++)
		dis[i] = INF;
	dijkstra();
	for (int wef = 0; wef < k; wef++) {
		for (int j = 0; j < n; j++) {
			ndis[j] = dis[j] + (ll)j * j;
		}
		priority_queue<pair <int, int>, vector<pair <int, int>>, greater<pair <int, int>>> dist;
		set <int> st;
		for (int j = 0; j < n; j++) 
			st.insert(j);
		for (auto i = st.begin(); i != st.end(); i++) {
			if (i == st.begin())
				continue;
			else {
				int a = (*i);
				ll b = ndis[a];
				i--;
				int c = (*i);
				ll d = ndis[c];
				ll di = (b - d + 2 * (a - c)) / (2 * (a - c));
				di = max(di, 0LL);
				if (di <= N)
					dist.push({(int)di, a});
				i++;
			}
		}
		for (int i = 0; i < n; i++) {
			while (!dist.empty()) {
				pair <int, int> p = (dist.top());
				if (st.find(p.S) == st.end()) {
					dist.pop();
					continue;
				}
				if (p.F > i)
					break;
				dist.pop();
				auto few = st.lower_bound(p.S);
				few--;
				st.erase(few);
				few = st.lower_bound(p.S);
				if (few == st.begin())
					continue;
				int a = (*few);
				ll b = ndis[a];
				few--;
				int c = (*few);
				ll d = ndis[c];
				ll di = (b - d + 2 * (a - c)) / (2 * (a - c));
				di = max(di, 0LL);
				if (di <= N)
					dist.push({(int)di, a});
			}
			int x = (*st.begin());
			dis[i] = ndis[x] - 2LL * i * x;
		}
		for (int j = 0; j < n; j++)
			dis[j] += (ll)j * j;
		dijkstra();
	}
	for (int i = 0; i < n; i++)
		cout << dis[i] << ' ';
}