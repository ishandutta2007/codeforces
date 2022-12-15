#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int n, B, q;
int a[100005], inb[100005];
int beg[400];
int lzy[400];
vector<int> lis[400];
int fa[100005];
bool flg[100005];

int get_tgt(int x) {
	if (x == 1) return 1;
	if (flg[x]) return max(a[x] - lzy[inb[x]], 1LL);
	else return get_tgt(fa[x]);
}

void rebuild(int bid, int L, int R, int K) {
	for (int i = beg[bid]; i < beg[bid + 1]; i++)
		if (flg[i]) a[i] = max(a[i] - lzy[bid], 1LL);
	lzy[bid] = 0;
	lis[bid].clear();
	for (int i = beg[bid]; i < beg[bid + 1]; i++) {
		flg[i] = 0;
		if (i >= L && i <= R) a[i] = max(a[i] - K, 1LL);
		if (a[i] < beg[bid]) fa[i] = i, flg[i] = 1;
		else fa[i] = fa[a[i]], lis[bid].push_back(i);
	}
}

bool vis[100005];
int query(int u, int v) {
	while (get_tgt(u) != get_tgt(v)) {
		if (inb[u] < inb[v]) swap(u, v);
		u = get_tgt(u);
	}
	int fu = get_tgt(u);
	vector<int> mylis;
	while (u != fu) vis[u] = 1, mylis.push_back(u), u = flg[u] ? max(a[u] - lzy[inb[u]], 1LL) : a[u];
	vis[u] = 1, mylis.push_back(u);
	int ans = -1;
	while (1) {
		if (vis[v]) { ans = v; break; }
		v = flg[v] ? max(a[v] - lzy[inb[v]], 1LL) : a[v];
	}
	for (int i : mylis) vis[i] = 0;
	return ans;
}

signed main() {
	scanf("%lld%lld", &n, &q);
	B = sqrt(n);
	for (int i = 1; i <= n; i++) {
		if (i != 1) scanf("%lld", &a[i]);
		inb[i] = (i + B - 2) / B + 1;
		if (!beg[inb[i]]) beg[inb[i]] = i;
		if (i != 1) {
			if (a[i] < beg[inb[i]]) fa[i] = i, flg[i] = 1;
			else fa[i] = fa[a[i]], lis[inb[i]].push_back(i);
		}
		else fa[1] = 1;
	}
	beg[inb[n] + 1] = n + 1; inb[n + 1] = inb[n] + 1;
	while (q--) {
		int typ;
		scanf("%lld", &typ);
		if (typ == 2) {
			int u, v; scanf("%lld%lld", &u, &v);
			printf("%lld\n", query(u, v));
		}
		else {
			int L, R, K;
			scanf("%lld%lld%lld", &L, &R, &K);
			if (inb[L] == inb[R]) rebuild(inb[L], L, R, K);
			else {
				rebuild(inb[L], L, beg[inb[L] + 1] - 1, K);
				for (int bid = inb[L] + 1; bid < inb[R]; bid++) {
					lzy[bid] += K;
					vector<int> tlis;
					for (int i : lis[bid]) {
						a[i] = max(a[i] - K, 1LL);
						if (a[i] < beg[bid]) fa[i] = i, flg[i] = 1, a[i] += lzy[bid];
						else fa[i] = fa[a[i]], tlis.push_back(i);
					}
					lis[bid] = tlis;
				}
				rebuild(inb[R], beg[inb[R]], R, K);
			}
		}
	}
}