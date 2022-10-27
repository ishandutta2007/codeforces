#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
  mt19937 rng(228);
#else
  mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = (int) 3e5 + 7;
const int K = 30;
int n;
int q;
int a[N];
int fent[K][N];
vector<int> ops[N];
vector<int> where[2 * N];
map<int, int> tvals;

void upd(int index, int val, int sgn) {
	for (auto &id : where[val]) {
		for (int i = index; i <= n; i += i & (-i)) {
			fent[id][i] += sgn;
		}
	}
}

bool check(int p1, int p2, int k) {
	for (int id = 0; id < K; id++) {
		int bal = 0;
		for (int i = p1; i; i -= i & (-i)) {
			bal += fent[id][i];
		}
		for (int i = p2; i; i -= i & (-i)) {
			bal -= fent[id][i];
		}
		if (bal % k != 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tvals[a[i]] = 0;
	}
	for (int iq = 1; iq <= q; iq++) {
		int type;
		cin >> type;
		if (type == 1) {
			int p, x;
			cin >> p >> x;
			ops[iq] = {p, x};
			tvals[x] = 0;
		} else {
			int l, r, k;
			cin >> l >> r >> k;
			ops[iq] = {l, r, k};
		}
	}
	
	{
		int ind = 0;
		for (auto &it : tvals) {
			it.second = ind++;
		}
		for (int i = 1; i <= n; i++) {
			a[i] = tvals[a[i]];
		}
		for (int iq = 1; iq <= q; iq++) {
			if ((int) ops[iq].size() == 2) {
				ops[iq][1] = tvals[ops[iq][1]];
			}
		}
	}
	
	for (int id = 0; id < K; id++) {
		for (int i = 0; i < (int) tvals.size(); i++) {
			if (rng() & 1) {
				where[i].push_back(id);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		upd(i, a[i], +1);
	}
	
	for (int iq = 1; iq <= q; iq++) {
		if ((int) ops[iq].size() == 2) {
			int i = ops[iq][0], x = ops[iq][1];
			upd(i, a[i], -1);
			upd(i, x, +1);
			a[i] = x;
		} else {
			int l = ops[iq][0], r = ops[iq][1], k = ops[iq][2];
			if (check(l - 1, r, k)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}