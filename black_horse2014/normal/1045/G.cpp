#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
vector<int> vx;
vector<int> vec[N], val[N];

void push(int x, int y) {
	for (x+=4; x < N; x += x & -x) {
		vec[x].push_back(y);
	}
}

void add(int x, int y, int v) {
	for (x+=4; x < N; x += x & -x) {
		int p = lower_bound(vec[x].begin(), vec[x].end(), y) - vec[x].begin();
		for (++p; p < vec[x].size()+1; p += p & -p) {
			val[x][p-1] += v;
		}
	}
}

int get(int x, int y) {
	int ret = 0;
	for (x+=4; x; x -= x & -x) {
		int p = upper_bound(vec[x].begin(), vec[x].end(), y) - vec[x].begin() - 1;
		for (++p; p; p -= p & -p) {
			ret += val[x][p-1];
		}
	}
	return ret;
}

int x[N], r[N], q[N], id[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> r[i] >> q[i];
		vx.push_back(x[i]);
		id[i] = i;
	}
	sort(id, id + n, [](int a, int b) { return q[a] < q[b]; });
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	for (int i = 0; i < n; i++) {
		x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
	}
	for (int i = 0; i < n; i++) {
		push(x[i], -r[i]);
	}
	for (int i = 0; i < N; i++) {
		sort(vec[i].begin(), vec[i].end());
		vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
		val[i].resize(vec[i].size());
	}
	long long ans = 0;
	int f = 0, t = 0;
	for (int j = 0; j < n; j++) {
		int i = id[j];
		int iq = q[i];
		while (f < n && q[id[f]] < iq - k) {
			add(x[id[f]], -r[id[f]], -1);
			++f;
		}
		while (t < n && q[id[t]] <= iq + k) {
			add(x[id[t]], -r[id[t]], 1);
			++t;
		}
		int To = upper_bound(vx.begin(), vx.end(), vx[x[i]] + r[i]) - vx.begin() - 1;
		int Fr = lower_bound(vx.begin(), vx.end(), vx[x[i]] - r[i]) - vx.begin() - 1;
		ans += get(To, -r[i]);
		ans -= get(Fr, -r[i]);
		ans += get(To, -r[i] - 1);
		ans -= get(Fr, -r[i] - 1);
	}
	ans -= n;
	cout << ans / 2 << endl;
	return 0;
}