#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <string>

using namespace std;

const int MAXN = 1100;

long long axy[MAXN][MAXN], ax[MAXN][MAXN], ay[MAXN][MAXN], a[MAXN][MAXN];

int n, m;

inline int lowbit(const int &x) {
	return x & -x;
}

inline long long ask(long long a[MAXN][MAXN], int x, int y) {
	long long res = 0;
	for(int i = x; i; i -= lowbit(i))
		for(int j = y; j; j -= lowbit(j)) {
			res ^= a[i][j];
		}
	return res;
}

inline void ins(long long a[MAXN][MAXN], int x, int y, long long v) {
	for(int i = x; i <= n; i += lowbit(i))
		for(int j = y; j <= n; j += lowbit(j)) 
			a[i][j] ^= v;
}

void Ins(int x, int y, long long val) {
	//printf("%d %d %I64d\n", x, y, val);
	if (x == 0 || y == 0)
		return;
	if ((long long)x * y % 2 == 1)
		ins(axy, x, y, val);
	if (x % 2 == 1)
		ins(ax, x, y, val);
	if (y % 2 == 1)
		ins(ay, x, y, val);
	ins(a, x, y, val);
}

long long Ask(int x, int y) {
	if (x == 0 || y == 0)
		return 0;
	if (x == 1 && y == 1) {
		x = 1;
		y = 1;
	}
	long long res = ask(axy, x, y);
	if (x != n && x % 2 == 1) {
		res ^= ask(ay, n, y) ^ ask(ay, x, y);
	}
	if (y != m && y % 2 == 1) {
		res ^= ask(ax, x, n) ^ ask(ax, x, y);
	}
	if ((long long)x * y % 2 == 1) {
		res ^= ask(a, n, n) ^ ask(a, x, y) ^ ask(a, n, y) ^ ask(a, x, n);
	}
	//printf("Ask %d %d %I64d\n", x, y, res);
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int type;
		int x1, x2, y1, y2;
		long long v;
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%I64d\n", Ask(x2, y2) ^ Ask(x1 - 1, y1 - 1) ^ Ask(x1 - 1, y2) ^ Ask(x2, y1 - 1));
		} else {
			scanf("%d %d %d %d %I64d\n", &x1, &y1, &x2, &y2, &v);
			Ins(x2, y2, v);
			Ins(x1 - 1, y1 - 1, v);
			Ins(x2, y1 - 1, v);
			Ins(x1 - 1, y2, v);
		}
	}
	return 0;
}