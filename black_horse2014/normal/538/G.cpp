#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int id[N];
map<int, int> H;
map<int, pair<long long, long long> > ans;
char str[N * 10];
long long t[N], x[N], y[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int N, L; cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		cin >> t[i] >> x[i] >> y[i];
		if ((t[i] + x[i] + y[i]) % 2 != 0) return puts("NO"), 0;
	}
	bool flg = 0;
	long long X = 0, Y = 0;
	H[0] = 0;
	for (int i = 1; i <= N; i++) {
		int r = t[i] % L;
		if (H.count(r)) {
			int j = H[r];
			long long k = (t[i] - t[j]) / L;
			if ((x[i] - x[j]) % k != 0 || (y[i] - y[j]) % k != 0) return puts("NO"), 0;
			if (!flg) {
				X = (x[i] - x[j]) / k;
				Y = (y[i] - y[j]) / k;
				if (abs(X) + abs(Y) > L) return puts("NO"), 0;
			} else {
				if (X != (x[i] - x[j]) / k) return puts("NO"), 0;
				if (Y != (y[i] - y[j]) / k) return puts("NO"), 0;
			}
			flg = 1;
		} else {
			H[r] = i;
		}
	}
	auto gen = [&](int from, int to, int dx, int dy) {
		for (int i = 0; i < abs(dx); i++) str[from + i] = (dx < 0 ? 'L' : 'R');
		for (int i = 0; i < abs(dy); i++) str[from + abs(dx) + i] = (dy < 0 ? 'D' : 'U');
		for (int i = abs(dx) + abs(dy); i < to - from; i++) str[i + from] = ((i & 1) ? 'L' : 'R');
	};
	if (!flg) {
		for (int i = 1; i <= N; i++) id[i] = i;
		sort(id + 1, id + N + 1, [&](int i, int j) {
			return t[i] % L < t[j] % L;
		});
		id[N + 1] = 0;
		long long Smin = -L, Smax = L;
		long long Dmin = -L, Dmax = L;
		for (int i = 1; i <= N + 1; i++) {
			int u = id[i - 1], v = id[i];
			long long D = t[u] / L - t[v] / L;
			int T = abs(t[v] % L - t[u] % L);
			if (i == N + 1) T = L - t[u] % L, D++;
			if (D < 0) swap(u, v), D = -D;
			long long smin = x[u] - x[v] + y[u] - y[v] - T;
			long long dmin = x[u] - x[v] - y[u] + y[v] - T;
			long long smax = x[u] - x[v] + y[u] - y[v] + T;
			long long dmax = x[u] - x[v] - y[u] + y[v] + T;
			if (D == 0) {
				if (smax < 0 || smin > 0 || dmax < 0 || dmin > 0) return puts("NO"), 0;
				continue;
			}
			smin = (smin + ((D - smin) % D + D) % D) / D;
			smax = (smax - (smax % D + D) % D) / D;
			dmin = (dmin + ((D - dmin) % D + D) % D) / D;
			dmax = (dmax - (dmax % D + D) % D) / D;
			Smin = max(Smin, smin);
			Smax = min(Smax, smax);
			Dmin = max(Dmin, dmin);
			Dmax = min(Dmax, dmax);
		}
		if (Dmin + L & 1) Dmin++;
		if (Dmax + L & 1) Dmax--;
		if (Smin + L & 1) Smin++;
		if (Smax + L & 1) Smax--;
		if (Dmin > Dmax || Smin > Smax) return puts("NO"), 0;
		X = (Dmin + Smin) / 2;
		Y = (Smin - Dmin) / 2;
	}
	ans[0] = {0, 0};
	ans[L] = {X, Y};
	for (int i = 1; i <= N; i++) ans[t[i] % L] = make_pair(x[i] - t[i] / L * X, y[i] - t[i] / L * Y);
	int last = -1;
	auto seen = make_pair(0, 0);
	for (auto t : ans) {
		if (last == -1) {
			last = t.first;
			seen = t.second;
			continue;
		}
		if (abs(t.second.first - seen.first) + abs(t.second.second - seen.second) > t.first - last) return puts("NO"), 0;
		gen(last, t.first, t.second.first - seen.first, t.second.second - seen.second); 
		last = t.first;
		seen = t.second;
	}
	puts(str);
	return 0;
}