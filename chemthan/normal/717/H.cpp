#include <bits/stdc++.h>

#define pb push_back
#define ld double
#define ll long long
#define mp make_pair
#define fi first
#define se second

using namespace std;

const int nm = 1000010;

int n, m, T;
vector<int> adj[nm];
vector<int> a[nm];
int sl[nm];
int b[nm];
int c[nm];

bool xep() {
	for (int i = 1; i <= T; ++i)
		b[i] = rand() % 2 + 1;
	int st = rand() % n + 1;
	for (int i = 1; i <= n; ++i)
		c[i] = 0;
	c[st] = 1;
	queue<int> q;
	q.push(st);
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		for (int k = 0; k < adj[i].size(); ++k) {
			int j = adj[i][k];
			if (c[j] == 0) {
				c[j] = 3 - c[i];
				q.push(j);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		c[i] = rand() % 2 + 1;
	int d = 0;
	for (int i = 1; i <= n; ++i) {
		for (int k = 0; k < adj[i].size(); ++k) {
			int j = adj[i][k];
			if (c[i] != c[j])
				d++;
		}
	}
	if (d < m)
		return 0;
	for (int i = 1; i <= n; ++i) {
		bool found = 0;
		for (int k = 0; k < a[i].size(); ++k) {
			int j = a[i][k];
			if (b[j] == c[i]) {
				c[i] = j;
				found = 1;
				break;
			}
		}
		if (!found)
			return 0;
	}
	return 1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &sl[i]);
		for (int j = 1; j <= sl[i]; ++j) {
			int u;
			scanf("%d", &u);
			a[i].pb(u);
			T = max(T, u);
		}
	}
	srand(time(0));
	while (!xep()) {}
	for (int i = 1; i <= n; ++i)
		printf("%d ", c[i]);
	printf("\n");
	for (int i = 1; i <= T; ++i)
		printf("%d ", b[i]);
}