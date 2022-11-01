#include <bits/stdc++.h>

using namespace std;

const int DEBUG = 0;
const int INF = 1e9 + 7;

int n, k;
vector<int> dish = {2, 3};

int ask(int l, int r) {
	if (DEBUG) {
		int lv = INF, rv = INF;
		for (auto d : dish) {
			lv = min(lv, abs(d - l));
			rv = min(rv, abs(d - r));
		}
		return lv <= rv ? 0 : 1;
	} else {
		printf("1 %d %d\n", l, r);
		fflush(stdout);
		static char buffer[10];
		scanf("%s", buffer);
		if (buffer[0] == 'T') return 0;
		return 1;
	}
}

int find(int l, int r) {
	if (l > r) return -1;
	while (l < r) {
		int mid = (l + r) / 2;
		int t = ask(mid, mid + 1);
		if (t == 0) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	assert(l != 0);
	return l;
}

int main() {
	scanf("%d %d", &n, &k);
	int p = find(1, n), pp;
	int a = find(1, p - 1), b = find(p + 1, n);
	if (a != -1 && ask(a, a + 1) == 0) pp = a;
	else {
		pp = b;
	}
	printf("2 %d %d\n", p, pp);
	fflush(stdout);
	if (DEBUG) {
		bool fp = false, fpp = false;
		for (auto d : dish) {
			if (d == p) fp = 1;
			if (d == pp) fpp = 1;
		}
		assert(fp && fpp);
	}
}