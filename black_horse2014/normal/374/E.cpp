#include <bits/stdc++.h>
using namespace std;

const int N = 4400;
const int emt = 1e8, mul = -1e8;

int x[N], y[N], r[N], R[N], B[N];

vector<pair<int, pair<int, int>>> vec;

vector<int> V[N];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n+m; i++) {
		r[i] = i;
		V[i].push_back(i);
		if (i < n) B[i] = x[i] + y[i], R[i] = emt;
		else R[i] = x[i] - y[i], B[i] = emt;
		cin >> x[i] >> y[i];
		x[i] *= 2, y[i] *= 2;
	}
	for (int i = 0; i < n; i++) {
		for (int j = n; j < n+m; j++) {
			int s = x[i] + y[i], d = x[j] - y[j];
			int _x = (s + d) / 2, _y = (s - d) / 2;
			int r = max(abs(x[i] - _x), abs(x[j] - _x));
			vec.emplace_back(r, make_pair(i, j));
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int s1 = x[i] + y[i], s2 = x[j] + y[j];
			if (s1 != s2) continue;
			int r = abs(x[j] - x[i]) / 2;
			vec.emplace_back(r, make_pair(i, j));
		} 
	}
	for (int i = n; i < n+m; i++) {
		for (int j = n; j < i; j++) {
			int d1 = x[i] - y[i], d2 = x[j] - y[j];
			if (d1 != d2) continue;
			int r = abs(x[j] - x[i]) / 2;
			vec.emplace_back(r, make_pair(i, j));
		}
	}
	sort(vec.begin(), vec.end());
	for (auto t : vec) {
		int v = t.first, p = r[t.second.first], q = r[t.second.second];
		if (p == q) {
			if (R[p] == mul && B[p] == mul) return cout << (v + 1) / 2 << endl, 0;
			continue;
		}
		if (V[p].size() > V[q].size()) swap(p, q);
		for (int a : V[p]) {
			V[q].push_back(a);
			r[a] = q;
			if (a < n) {
				if (B[q] == mul) continue;
				if (B[q] == emt) B[q] = x[a] + y[a];
				else if (x[a] + y[a] != B[q]) B[q] = mul;
			} else {
				if (R[q] == mul) continue;
				if (R[q] == emt) R[q] = x[a] - y[a];
				else if (x[a] - y[a] != R[q]) R[q] = mul;
			}
		}
		V[p].clear();
	}
	cout << "Poor Sereja!" << endl;
}