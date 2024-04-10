#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int d[N], x[N], y[N], bid[N];
long long ay[N], by[N];;
pair<double, int> pa[N], pb[N];

void add(int x) {
	for (; x; x -= x & -x) d[x]++;
}

int query(int x) {
	int ret = 0;
	for (; x < N; x += x & -x) ret += d[x];
	return ret;
}

int main() {
	int n, w; scanf("%d%d", &n, &w);
	for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
	for (int i = 0; i < n; i++) {
		ay[i] = -(y[i] + w), by[i] = -(y[i] - w);
		if (x[i] < 0) x[i] = -x[i], ay[i] = -ay[i], by[i] = -by[i];
		pa[i] = make_pair(1.0 * ay[i] / x[i], i);
		pb[i] = make_pair(1.0 * by[i] / x[i], i);
	}
	sort(pa, pa + n);
	sort(pb, pb + n);
	long long ans = 0;
	for (int k = 0, i = 0, j; i < n; i = j) {
		for (j = i; j < n; j++) {
			int u = pb[i].second, v = pb[j].second;
			if (by[u] * x[v] != by[v] * x[u]) break;
			bid[v] = k;
		}
		ans += (j - i) * 1LL * (j - i - 1) / 2;
		k++;
	}
	for (int k = 0, i = 0, j; i < n; i = j) {
		for (j = i; j < n; j++) {
			int u = pa[i].second, v = pa[j].second;
			if (ay[u] * x[v] != ay[v] * x[u]) break;
			ans += query(bid[v] + 1);
		}
		for (j = i; j < n; j++) {
			int u = pa[i].second, v = pa[j].second;
			if (ay[u] * x[v] != ay[v] * x[u]) break;
			add(bid[v]);
		}
		k++;
		ans += (j - i) * 1LL * (j - i - 1) / 2;
	}
	if (w == 0) ans /= 2;
	cout << ans << endl;
	return 0;
}