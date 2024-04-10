#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, K, l, r, mid;

LL calc(LL len, LL x) {
	if (len <= 2*x) return 0;
	LL cnt[2] = {1, 0}, a[2] = {len, len-1};
	LL res = 0, tmp;
	while (a[0] >= 2*x+1) {
		res += cnt[0]; res += (a[1] >= 2*x+1) * cnt[1];
		tmp = a[0] / 2;
		if (a[0]&1) cnt[0] = cnt[0] * 2 + cnt[1];
		else cnt[1] = cnt[1] * 2 + cnt[0];
		a[0] = tmp; a[1] = tmp - 1;
	}
	return res;
}

LL solve(LL l, LL r, LL limit, LL K) {
	LL mid = (l + r) >> 1, tmp, tmp2;
	if (K == 1) return mid;
	tmp = calc(mid-l, limit);
	tmp2 = calc(r-mid, limit + 1);
	if (K <= tmp + tmp2 + 1) return solve(l, mid-1, limit, K-tmp2-1);
	return solve(mid+1, r, limit, K-tmp-1);
}

int main() {
	scanf("%I64d%I64d", &n, &K);
	if (K == 1) return puts("1"), 0;
	if (K == 2) return printf("%I64d\n", n), 0;
	n -= 2; K -= 2;
	l = 0; r = (n + 1) / 2;
	while (l < r) {
		mid = (l + r + 1) >> 1;
		if (calc(n, mid) >= K) l = mid;
		else r = mid - 1;
	}
	printf("%I64d\n", solve(1, n, l, K) + 1);
	return 0;
}