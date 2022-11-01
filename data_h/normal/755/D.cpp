#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cassert>
using namespace std;

const int N = 1e6 + 7;

int n, k;
int h[N];

inline int lowbit(int x) {
	return x & -x;
}

void ins(int pos, int v) {
	for (int i = pos; i <= n; i += lowbit(i)) {
		h[i] += v;
	}
}

int ask(int pos) {
	int ret = 0;
	for (int i = pos; i; i -= lowbit(i)) {
		ret += h[i];
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &k);
	k = min(k, n - k);
	int cur = 1;
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		int nxt = cur + k;
		if (nxt <= n) {
			ans += 1 + ask(nxt - 1) - ask(cur);
		} else {
			nxt -= n;
			ans += 1 + ask(n) - ask(cur) + ask(nxt - 1);
		}
		ins(cur, 1);
		ins(nxt, 1);
		cur = nxt;
		printf("%lld%c", ans, i == n ? '\n' : ' ');
	}
	return 0;
}