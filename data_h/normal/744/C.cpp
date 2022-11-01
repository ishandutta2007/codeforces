#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

const int N = 16;
const int INF = 1e9 + 7;

int color[N], n, r[N], b[N];
map<int, int> f[1 << N][2];

void update(int mask, int who, int amount, int v) {
	//printf("update %d %d %d %d\n", mask, who, amount, v);
	if (f[mask][who].count(amount)) {
		int &ret = f[mask][who][amount];
		ret = min(ret, v);
	} else {
		f[mask][who][amount] = v;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c[20];
		scanf("%s %d %d", c, &r[i], &b[i]);
		color[i] = (c[0] == 'B');
	}
	f[0][0][0] = 0;
	f[0][1][0] = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		int cnt_r = 0, cnt_b = 0;
		for (int i = 0; i < n; i++) {
			if (mask >> i & 1) {
				if (color[i] == 1) cnt_b++;
				if (color[i] == 0) cnt_r++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (mask >> i & 1) continue;
			for (int who = 0; who < 2; who ++) {
				for (auto it = f[mask][who].begin(); it != f[mask][who].end(); ++it) {
					int cur_r, cur_b, op;
					if (who == 0) {
						 cur_r = 0;
						 cur_b = it->first;
					} else {
						cur_r = it->first;
						cur_b = 0;
					}
					int cost_r = max(r[i] - cnt_r, 0);
					int cost_b = max(b[i] - cnt_b, 0);
					op = max(0, max(cost_r - cur_r, cost_b - cur_b));
					if (cur_r + op == cost_r) {
						update(mask | (1 << i), 0, cur_b + op - cost_b, it->second + op);
					} else if (cur_b + op == cost_b) {
						update(mask | (1 << i), 1, cur_r + op - cost_r, it->second + op);
					} else {
						//printf("%d %d %d %d\n", cur_b + op, cur_r + op, b[i], r[i]);
						assert(false);
					}
				}
			}
		}
	}
	int all = (1 << n) - 1, ans = INF;
	for (int who = 0; who < 2; who++) {
		for (auto it = f[all][who].begin(); it != f[all][who].end(); ++it) {
			ans = min(ans, it->second);
		}
	}
	printf("%d\n", ans + n);
	return 0;
}