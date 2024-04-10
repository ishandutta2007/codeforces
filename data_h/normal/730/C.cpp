#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
vector<int> G[N];
int d[N], p[N], k[N], c[N], id[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		-- u, -- v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int w;
	scanf("%d", &w);
	for (int i = 0; i < w; ++ i) {
		scanf("%d%d%d", &c[i], &k[i], &p[i]);
		c[i] --;
		id[i] = i;
	}
	sort(id, id + w, [&](int i, int j) {return p[i] < p[j];});
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++ i) {
		int g, rr, a;
		scanf("%d%d%d", &g, &rr, &a);
		-- g;
		memset(d, 0x3f, sizeof(d));
		queue<int> q;
		d[g] = 0;
		q.push(g);
		while (!q.empty()) {
			int p = q.front(); q.pop();
			for (int u : G[p]) {
				if (d[u] < 0x3f3f3f3f) continue;
				d[u] = d[p] + 1;
				q.push(u);
			}
		}
		//for (int i = 0; i < n; ++ i) printf("%d ", d[i]); puts("");
		int l = 0, r = n, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			int R = rr;
			long long A = a;
			for (int ii = 0; ii < w; ++ ii) {
				int i = id[ii];
				if (d[c[i]] > mid) continue;
				int buy = min(R, k[i]);
				R -= buy;
				A -= 1LL * buy * p[i];
			}
			if (A < 0 || R) {
				l = mid + 1;
			}
			else {
				ans = mid;
				r = mid - 1;
			}
		}
		printf("%d\n", ans);
	}
}