#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define MAXN 200010
int n, bak, deb[MAXN << 2];
LL ls[MAXN], rs[MAXN], li[MAXN << 2], ansl[MAXN];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld", &ls[i], &rs[i]);
		li[++bak] = ls[i]; li[++bak] = rs[i] + 1; li[++bak] = rs[i];
	}
	sort(li + 1, li + 1 + bak); bak = unique(li + 1, li + 1 + bak) - li - 1;
	for (int i = 1; i <= n; ++i) {
		int l = lower_bound(li + 1, li + 1 + bak, ls[i]) - li,
			r = lower_bound(li + 1, li + 1 + bak, rs[i]) - li;
		++deb[l]; --deb[r + 1];
	}
	for (int i = 1; i != bak; ++i) {
		deb[i] += deb[i - 1];
		ansl[deb[i]] += li[i + 1] - li[i];
	}
	for (int i = 1; i <= n; ++i) printf("%lld ", ansl[i]); putchar(10);
	return 0;
}