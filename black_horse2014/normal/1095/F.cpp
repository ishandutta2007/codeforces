#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

long long a[N], w[N], ww[N], tot;
int x[N], y[N], f[N], idx[N], id[N];

set<pair<long long, int> > S;
int getf(int x) {
	return x == f[x] ? x : f[x] = getf(f[x]);
};


int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> x[i] >> y[i] >> w[i], idx[i] = i;
	sort(idx + 1, idx + m + 1, [](int u, int v) {
		return w[u] < w[v];
	});
	int ptr = 1;
	for (int i = 1; i <= n; i++) f[i] = i, ww[i] = a[i], id[i] = i, S.insert(make_pair(ww[i], i));
	while (S.size() >= 2) {
		pair<long long, int> f1 = *S.begin();
		pair<long long, int> f2 = *S.upper_bound(f1);
		if (ptr <= m && w[idx[ptr]] < f1.first + f2.first) {
			int u = x[idx[ptr]], v = y[idx[ptr]];
			ptr++;
			int fu = getf(u), fv = getf(v);
			if (fu == fv) continue;
			f[fu] = fv;
			S.erase(make_pair(ww[fu], id[fu]));
			S.erase(make_pair(ww[fv], id[fv]));
			tot += w[idx[ptr - 1]];
			if (ww[fv] > ww[fu]) {
				ww[fv] = ww[fu];
				id[fv] = id[fu];
			}
			S.insert(make_pair(ww[fv], id[fv]));
		} else {
			int u = f1.second, v = f2.second;
			int fu = getf(u), fv = getf(v);
			assert(fu != fv);
			f[fu] = fv;
			S.erase(make_pair(ww[fu], id[fu]));
			S.erase(make_pair(ww[fv], id[fv]));
			tot += (ww[fu] + ww[fv]);
			if (ww[fv] > ww[fu]) {
				ww[fv] = ww[fu];
				id[fv] = id[fu];
			}
			S.insert(make_pair(ww[fv], id[fv]));
		}
	}
	cout << tot << endl;
	return 0;
}