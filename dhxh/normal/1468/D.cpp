#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 410000;
int n, m, a, b, s[maxn];
bool ok(long long idx) {
	long long dist = abs(b - a);
	long long rest = a < b ? a - 1 : n - a;
	if (dist <= idx)
		return false;
	for (long long i = 1; i <= idx; ++i) {
		if (s[i] >= dist + rest - (idx - i))
			return false;
	}
	return true;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &n, &m, &a, &b);
		for (int i = 1; i <= m; ++i)
			scanf("%d", &s[i]);
		sort(s + 1, s + m + 1);
		int L = 0, R = m;
		while (L < R) {
			int M = L + (R - L + 1) / 2;
			if (ok(M)) L = M;
			else R = M - 1;
		}
		printf("%d\n", L);
	}
	return 0;
}