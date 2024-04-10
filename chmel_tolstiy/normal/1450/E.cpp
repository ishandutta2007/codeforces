#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef bitset<256> bs;

bool solve() {
	int n, m;
	if (!(cin >> n >> m)) return false;

	bs all, zero;
	for (int i = 0; i < n; ++i) all.set(i);
	zero.set(0);

	vector<pii> edges;
	vector<pii> arcs;
	for (int i = 0; i < m; ++i) {
		int x, y, z; cin >> x >> y >> z;
		if (z == 0) edges.emplace_back(x - 1, y - 1);
		else arcs.emplace_back(x - 1, y - 1);
	}

	int answer = -1;
	vector<int> w;
	for (int s = 0; s < n; ++s) {
		vector<bs> possible(n);
		for (int v = 0; v < n; ++v) possible[v] = all;
		possible[s] = zero;

		bool updated = true;
		while (updated) {
			updated = false;
			for (auto e : edges) {
				int x = e.first;
				int y = e.second;
				bs new_x = possible[x] & ((possible[y] << 1) | (possible[y] >> 1));
				if (new_x != possible[x]) {
					possible[x] = new_x;
					updated = true;
				}
				bs new_y = possible[y] & ((possible[x] << 1) | (possible[x] >> 1));
				if (new_y != possible[y]) {
					possible[y] = new_y;
					updated = true;
				}
			}
			for (auto e : arcs) {
				int x = e.first;
				int y = e.second;
				bs new_x = possible[x] & (possible[y] >> 1);
				if (new_x != possible[x]) {
					possible[x] = new_x;
					updated = true;
				}
				bs new_y = possible[y] & (possible[x] << 1);
				if (new_y != possible[y]) {
					possible[y] = new_y;
					updated = true;
				}
			}
		}

		bool bad = false;
		int best = 0, last = 0;
		for (int i = 0; i < n; ++i) {
			int lst = -1;
			for (int k = 0; k < n; ++k) if (possible[i].test(k)) lst = k;
			if (lst == -1) {
				bad = true;
			}
			if (lst > best) {
				best = lst;
				last = i;
			}
		}
		if (!bad && answer < best) {
			answer = max(answer, best);
			possible[last].reset();
			possible[last].set(best);

			bool updated = true;
			while (updated) {
				updated = false;
				for (auto e : edges) {
					int x = e.first;
					int y = e.second;
					bs new_x = possible[x] & ((possible[y] << 1) | (possible[y] >> 1));
					if (new_x != possible[x]) {
						possible[x] = new_x;
						updated = true;
					}
					bs new_y = possible[y] & ((possible[x] << 1) | (possible[x] >> 1));
					if (new_y != possible[y]) {
						possible[y] = new_y;
						updated = true;
					}
				}
				for (auto e : arcs) {
					int x = e.first;
					int y = e.second;
					bs new_x = possible[x] & (possible[y] >> 1);
					if (new_x != possible[x]) {
						possible[x] = new_x;
						updated = true;
					}
					bs new_y = possible[y] & (possible[x] << 1);
					if (new_y != possible[y]) {
						possible[y] = new_y;
						updated = true;
					}
				}

				if (!updated) {
					for (int i = 0; i < n; ++i) if (possible[i].count() > 1) {
						int v = 0;
						while (possible[i].test(v) == false) ++v;
						possible[i].reset();
						possible[i].set(v);
						updated = true;
						break;
					}
				}
			}

			vector<int> z(n);
			for (int i = 0; i < n; ++i) {
				while (possible[i].test(z[i]) == false) ++z[i];	
			}
			w = z;
		}
	}

	if (answer >= 0) {
		cout << "YES" << endl;
		cout << answer << endl;
		for (int x : w)
			cout << x << ' ';
		cout << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return true;
}

int main() {
	//int t; cin >> t;
	while (solve())
		;
	return 0;
}