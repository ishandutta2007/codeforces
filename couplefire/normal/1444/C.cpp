#include <bits/stdc++.h>

using namespace std;

long long ans;
int n, m, k, c[500005], par[500005], gc;
bool f[500005], g[500005];
map<pair<int, int>, vector<pair<int, int>>> mm;
vector<pair<int, int>> rp, rf;

int find(int a, bool r) {
	if (par[a] == a) return a;
	find(par[a], r);
	if (r) {
		rf.emplace_back(a, f[a]);
		rp.emplace_back(a, par[a]);
	}
	f[a] ^= f[par[a]];
	return par[a] = par[par[a]];
}

bool merge(int a, int b, bool r) {
	find(a, r);
	find(b, r);
	if (par[a] == par[b]) 
		return f[a] != f[b];
	bool tb = f[a] ^ f[b];
	// printf("m %d %d  %d %d  %d  %d\n", a, b, par[a], par[b], r, tb);
	a = par[a];
	b = par[b];
	if (r) {
		rf.emplace_back(a, f[a]);
		rp.emplace_back(a, par[a]);
	}
	f[a] = tb ^ 1;
	par[a] = b;
	return 1;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		scanf("%d", c + i);
	}
	while (m--) {
		int ta, tb;
		scanf("%d%d", &ta, &tb);
		if (c[ta] == c[tb]) {
			if (!merge(ta, tb, 0) && !g[c[ta]]) {
				g[c[ta]] = 1;
				gc++;
			}
		} else {
			if (c[ta] > c[tb])
				swap(ta, tb);
			mm[{c[ta], c[tb]}].emplace_back(ta, tb);
		}
	}
	ans = (long long)(k - gc) * (k - gc - 1) / 2;
	for (int i = 1; i <= n; i++) find(i, 0);
	// for (int i = 1; i <= n; i++) printf("%d %d %d\n", i, par[i], f[i]);
	// for (int i = 1; i <= k; i++) printf("%d %d\n", i, g[i]);
	// printf("gc=%d\n", gc);
	for (auto& i : mm) {
		if (g[i.first.first] || g[i.first.second]) continue;
		bool pk = 0;
		for (auto& j : i.second)
			if (!merge(j.first, j.second, 1)) {
				pk = 1;
				break;
			}
		// printf("! %d %d %d\n", i.first.first, i.first.second, pk);
	// for (int i = 1; i <= n; i++) printf("A %d %d %d\n", i, par[i], f[i]);
		if (pk)
			ans--;
		reverse(rf.begin(), rf.end());
		for (auto& ii : rf)
			f[ii.first] = ii.second;
		rf.clear();
		reverse(rp.begin(), rp.end());
		for (auto& ii : rp)
			par[ii.first] = ii.second;
		rp.clear();
	// for (int i = 1; i <= n; i++) printf("B %d %d %d\n", i, par[i], f[i]);
	}
	printf("%lld\n", ans);
}