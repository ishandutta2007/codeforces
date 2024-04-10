#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1100000;

int hx[N], hn;

struct Line {
	ll a, b;
	Line (ll a = 0, ll b = 0) : a(a), b(b) {}
	ll get(int x) { return a * hx[x] + b; }
} L[N << 2];

void upt(Line nw, int u = 1, int l = 0, int r = hn) {
	int md = l + r >> 1;
	bool lft = nw.get(l) > L[u].get(l);
	bool mid = nw.get(md) > L[u].get(md);
	if (mid) swap(nw, L[u]);
	if (r - l == 1) return;
	if (lft != mid) upt(nw, u+u, l, md);
	else upt(nw, u+u+1, md, r);
}

ll get(int p, int u = 1, int l = 0, int r = hn) {
	int md = l + r >> 1;
	ll ret = L[u].get(p);
	if (r - l == 1) return ret;
	if (p < md) ret = max(ret, get(p, u+u, l, md));
	else ret = max(ret, get(p, u+u+1, md, r));
	return ret;
}

int x[N], y[N], id[N];
ll a[N]; 

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%lld", x+i, y+i, a+i);
		hx[i] = y[i];
	}
	hx[n] = 0;
	sort(hx, hx + n + 1);
	hn = unique(hx, hx + n + 1) - hx;
	for (int i = 0; i < n; i++) id[i] = i;
	sort(id, id + n, [](int p, int q) {
		return x[p] < x[q];
	});
	for (int i = 0; i < n; i++) {
		int j = id[i];
		int xx = lower_bound(hx, hx + hn, y[j]) - hx;
		ll v = get(xx);
		upt(Line(-x[j], v - a[j] + 1ll * x[j] * y[j]));
	}
	printf("%lld\n", get(0));
}