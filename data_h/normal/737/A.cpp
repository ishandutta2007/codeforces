#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2e5 + 7;

int n, k, s, t;
int price[N], cap[N], pos[N];

bool solve(int base) {
	int capacity = -1;
	for (int i = 1; i <= n; i++) {
		if (price[i] <= base) {
			capacity = max(capacity, cap[i]);
		}
	}
	long long tt = 0;
	for (int i = 0; i <= k; i++) {
		int len = (pos[i + 1] - pos[i]);
		if (capacity < len) return false;
		int x = min(capacity - len, len);
		tt += 2 * len - x;
	}
	return tt <= t;
}

int main() {
	scanf("%d %d %d %d", &n, &k, &s, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &price[i], &cap[i]);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &pos[i]);
	}
	pos[0] = 0, pos[k + 1] = s;
	sort(pos, pos + k + 1);
	int pl = 0, pr = 1e9;
	while (pl < pr) {
		int mid = (pl + pr) / 2;
		if (solve(mid)) {
			pr = mid;
		} else {
			pl = mid + 1;
		}
	}
	if (!solve(pl)) {
		puts("-1");
	} else {
		printf("%d\n", pl);
	}
	return 0;
}