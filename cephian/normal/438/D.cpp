#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e5+5;
int a[N];
int rmax[4*N];
ll rsum[4*N];
int l[4*N], r[4*N];

inline void recalc(int v) {
	rsum[v] = rsum[v*2] + rsum[v*2+1];
	rmax[v] = max(rmax[v*2], rmax[v*2+1]);
}

void build(int v, int i, int j) {
	l[v] = i, r[v] = j;
	if(i == j) {
		rsum[v] = a[i];
		rmax[v] = a[i];
	} else {
		build(v*2, i, (i+j)/2);
		build(v*2+1, (i+j)/2+1, j);
		recalc(v);
	}
}

ll get_sum(int v, int i, int j) {
	if(r[v] < i || j < l[v])
		return 0;
	if(i <= l[v] && r[v] <= j)
		return rsum[v];
	return get_sum(v*2, i, j) + get_sum(v*2+1, i, j);
}

void crawl(int v, int i, int j, int x) {
	if(rmax[v] < x || r[v] < i || j < l[v]) {
		return;
	} else if(l[v] == r[v]) {
		rsum[v] = rmax[v] = rsum[v] % x;
	} else {
		crawl(v*2, i, j, x);
		crawl(v*2+1, i, j, x);
		recalc(v);
	}
}

void point_set(int v, int i, int x) {
	if(r[v] < i || i < l[v]) {
		return;
	} else if(l[v] == i && i == r[v]) {
		rsum[v] = rmax[v] = x;
	} else {
		point_set(v*2, i, x);
		point_set(v*2+1, i, x);
		recalc(v);
	}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	build(1, 1, n);
	while(m--) {
		int t, l, r, x;
		cin >> t;
		if(t == 1) {
			cin >> l >> r;
			cout << get_sum(1, l, r) << "\n";
		} else if(t == 2) {
			cin >> l >> r >> x;
			crawl(1, l, r, x);
		} else {
			cin >> r >> x;
			point_set(1, r, x);
		}
	}
}