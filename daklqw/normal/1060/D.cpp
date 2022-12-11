#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100010
int ls[MAXN], rs[MAXN], n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &ls[i], &rs[i]);
	sort(ls + 1, ls + 1 + n);
	sort(rs + 1, rs + 1 + n);
	long long ans = n;
	for (int i = 1; i <= n; ++i) ans += max(ls[i], rs[i]);
	printf("%lld\n", ans);
	return 0;
}