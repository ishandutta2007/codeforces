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

const int MAXN = 110000;

int n, h[MAXN], a[MAXN];

int lowbit(int x) {
	return x & -x;
}

int ask(int pos) {
	int res = 0;
	for(int i = pos; i; i -= lowbit(i)) {
		res = max(res, h[i]);
	}
	return res;
}

void ins(int pos, int val) {
	for(int i = pos; i <= n; i+= lowbit(i)) {
		h[i] = max(h[i], val);
	}
}

int f[MAXN], ans;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		f[i] = ask(a[i] - 1) + 1;
		ans = max(ans, f[i]);
		ins(a[i], f[i]);
	}
	printf("%d\n", ans);
	return 0;
}