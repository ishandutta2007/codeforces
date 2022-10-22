/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1023;
bool vis[N];
int a[N], b[N];
vector <int> g[N];

int32_t main() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue <int> q;
	q.push(s);
	vis[s] = true;
	a[s] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto y : g[x]) {
			if (!vis[y]) {
				vis[y] = true;
				q.push(y);
				a[y] = a[x] + 1;
			}
		}
	}
	q.push(t);
	for (int i = 0; i < N; i++)
		vis[i] = false;
	vis[t] = true;
	b[t] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto y : g[x]) {
			if (!vis[y]) {
				vis[y] = true;
				q.push(y);
				b[y] = b[x] + 1;
			}
		}
	}
	int d = a[t];
	int ans = -(m);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] + 1 + b[j] >= d && a[j] + 1 + b[i] >= d) {
				ans++;
			}
		}
	}
	cout << ans;
}