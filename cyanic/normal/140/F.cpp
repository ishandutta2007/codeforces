#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;
typedef long long LL;

const int maxn = 200099, seed = 2000000005, base = 1000000005;
LL a[maxn], x, y; set<LL> ans; int n, K;

bool check(LL x) {
	int l = 1, r = n, cnt = 0; LL L, R;
	while (l <= r) {
		L = x - a[l]; R = a[r] - x;
		if (L == R) l++, r--;
		else if (L > R) l++, cnt++;
		else r--, cnt++;
		if (cnt > K) return 0;
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &K);
	if (n <= K) return puts("-1"), 0;
	rep (i, 1, n) scanf("%lld%lld", &x, &y), a[i] = (x * 2 + base) * seed + y * 2 + base;
	sort(a + 1, a + n + 1);
	rep (i, 1, K+1) rep (j, n-K, n) if (check((a[i] + a[j]) / 2)) ans.insert((a[i] + a[j]) / 2);
	printf("%d\n", ans.size());
	for (set<LL>::iterator it=ans.begin(); it!=ans.end(); it++)
		printf("%.1lf %.1lf\n", (*it/seed-base)*0.5, (*it%seed-base)*0.5);
	return 0;
}