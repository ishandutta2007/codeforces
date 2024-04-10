// 387
#include <iostream>
#include <vector> 
#include <cassert> 
#include <functional> 
#include <algorithm> 
#include <map> 

bool home = true;
using namespace std;

typedef long long ll;

#define x first 
#define y second

ll solve(vector<pair<int, int>> v) {
	if (v.empty()) return 0;
	int n = (int)v.size();
	for (int i = 0; i < n; i++) {
		int sum = v[i].x + v[i].y;
		int dif = v[i].x - v[i].y;
		v[i] = { sum, dif };
	}
	int xmin = v[0].x, xmax = v[0].x;
	int ymin = v[0].y, ymax = v[0].y;
	for (int i = 1; i < n; i++) {
		xmin = min(xmin, v[i].x);
		ymin = min(ymin, v[i].y);

		xmax = max(xmax, v[i].x);
		ymax = max(ymax, v[i].y);
	}
	ll sol = 0;
	if (xmin % 2 != 0) xmin++;
	if (ymin % 2 != 0) ymin++;
	if (xmax % 2 != 0) xmax--;
	if (ymax % 2 != 0) ymax--;

	if (xmin > xmax || ymin > ymax) return 0;

	xmin /= 2;
	ymin /= 2;

	xmax /= 2;
	ymax /= 2;


	map<int, int> l0, r1, l2, r3;

	for (auto& p : v) {
		// p.x<=2*x
		int pos_x = p.x;
		if (pos_x % 2 != 0) {
			pos_x++;
		}
		assert(pos_x % 2 == 0);
		pos_x /= 2;
		if (!l0.count(pos_x)) {
			l0[pos_x] = p.y;
		}
		else {
			l0[pos_x] = min(l0[pos_x], p.y);
		}


		if (!r1.count(pos_x)) {
			r1[pos_x] = p.y;
		}
		else {
			r1[pos_x] = max(r1[pos_x], p.y);
		}
	}

	for (auto& p : v) {
		// p.x>=2*x
		int pos_x = p.x;
		if (pos_x % 2 != 0) {
			pos_x--;
		}
		assert(pos_x % 2 == 0);
		pos_x /= 2;
		if (!l2.count(-pos_x)) {
			l2[-pos_x] = p.y;
		}
		else {
			l2[-pos_x] = min(l2[-pos_x], p.y);
		}


		if (!r3.count(-pos_x)) {
			r3[-pos_x] = p.y;
		}
		else {
			r3[-pos_x] = max(r3[-pos_x], p.y);
		}
	}
	for (auto& it : l0) {
		if (it.first + 1 <= xmax) {
			if (!l0.count(it.first + 1)) {
				l0[it.first + 1] = it.second;
			}
			else {
				l0[it.first + 1] = min(l0[it.first + 1], it.second);
			}
		}
	}
	for (auto& it : r1) {
		if (it.first + 1 <= xmax) {
			if (!r1.count(it.first + 1)) {
				r1[it.first + 1] = it.second;
			}
			else {
				r1[it.first + 1] = max(r1[it.first + 1], it.second);
			}
		}
	}
	for (auto& it : l2) {
		if (-(it.first + 1) >= xmin) {
			if (!l2.count(it.first + 1)) {
				l2[it.first + 1] = it.second;
			}
			else {
				l2[it.first + 1] = min(l2[it.first + 1], it.second);
			}
		}
	}
	for (auto& it : r3) {
		if (-(it.first + 1) >= xmin) {
			if (!r3.count(it.first + 1)) {
				r3[it.first + 1] = it.second;
			}
			else {
				r3[it.first + 1] = max(r3[it.first + 1], it.second);
			}
		}
	}
	for (int x = xmin; x <= xmax; x++) {
		if (!l0.count(x)) continue;
		if (!r1.count(x)) continue;
		if (!l2.count(-x)) continue;
		if (!r3.count(-x)) continue;
		int low = ymin;
		int high = ymax;
		if (l0[x] % 2 == 0) low = max(low, l0[x] / 2); else low = max(low, (l0[x] + 1) / 2);
		if (l2[-x] % 2 == 0) low = max(low, l2[-x] / 2); else low = max(low, (l2[-x] + 1) / 2);
		if (r1[x] % 2 == 0) high = min(high, r1[x] / 2); else high = min(high, (r1[x] - 1) / 2);
		if (r3[-x] % 2 == 0) high = min(high, r3[-x] / 2); else high = min(high, (r3[-x] - 1) / 2);
		if (low <= high) {
			sol += high - low + 1;
		}
	}

	return sol;
}

int main() {

#ifdef ONLINE_JUDGE
	home = 0;
#endif
	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}

	int n;
	cin >> n;
	vector<vector<pair<int, int>>> v(2);

	for (int i = 0; i < n; i++) {
		pair<int, int> p;
		cin >> p.x >> p.y;
		p.x += (int)1e5;
		p.y += (int)1e5;
		assert(p.x >= 0);
		assert(p.y >= 0);
		v[(p.x + p.y) % 2].push_back(p);
	}
	for (auto& it : v[0]) {
		it.y++;
	}
	ll sol = 0;
	sol += solve(v[0]);
	sol += solve(v[1]);
	cout << sol << "\n";
}