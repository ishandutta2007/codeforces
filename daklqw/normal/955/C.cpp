#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAXN 1003479 + 10000
long long li[MAXN], bak, t1, t2;
inline long long solve(long long x) { return (long long) (sqrt(x) + 1e-10) + (upper_bound(li + 1, li + 1 + bak, x) - li - 1); }
inline bool issq(long long x) {
	long long t = sqrt(x);
	return t * t == x;
}
int main() {
	for (int i = 2; i <= 1000000; ++i) if (!issq(i)) {
		long long k = 1ll * i * i; long double t = k;
		for (t *= i; t <= 1e18; t *= i) { k *= i; if (!issq(k)) li[++bak] = k; }
	}
	sort(li + 1, li + 1 + bak);
	bak = unique(li + 1, li + 1 + bak) - li - 1;
	ios_base::sync_with_stdio(false);
	int Q; cin >> Q;
	while (Q --> 0) {
		cin >> t1 >> t2;
		cout << solve(t2) - solve(t1 - 1) << endl;
	}
	return 0;
}