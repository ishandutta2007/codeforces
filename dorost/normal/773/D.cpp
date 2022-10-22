/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mk make_pair
#define int long long
const int N = 2012;
int mn[N], n;
int dis[N];
int M = INT_MAX;
vector <pii> g[N];

void dijkstra () {
    priority_queue <pair <int, int>> q;
	for (int s = 1; s <= n; s++)
	    q.push(make_pair(-1 * dis[s], s));
    while (!q.empty()) {
        pair <int, int> p = (q.top());
        int x = p.S;
        q.pop();
        if (dis[x] != -1 * p.F)
            continue;
        int d = dis[x];
        for (auto [y, w] : g[x]) {
            if (dis[y] <= d + w - M) {
                continue;
            }
            dis[y] = d + w - M;
            q.push(make_pair(-1 * dis[y], y));
        }
    }   
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	for (int i = 1; i <= n; i++)
		mn[i] = INT_MAX;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int x;
			cin >> x;
			mn[i] = min(mn[i], x);
			mn[j] = min(mn[j], x);
			g[i].push_back(make_pair(j, x));
			g[j].push_back(make_pair(i, x));
			M = min(M, x);
		}
	}
	for (int i = 1; i <= n; i++) {
		mn[i] -= M;
		dis[i] = 2 * mn[i];
	}
	dijkstra();
	for (int i = 1; i <= n; i++)
		cout << dis[i] + M * (n - 1) << '\n';
}