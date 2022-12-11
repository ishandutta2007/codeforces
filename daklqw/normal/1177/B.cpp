#include <bits/stdc++.h>

typedef long long LL;
std::string x;
LL getlen(LL r) {
	LL now = 1, lst = 0, res = 0;
	int dig = 0;
	while (now <= r) {
		res += (now - 1 - lst) * dig;
		lst = now - 1;
		now *= 10; ++dig;
	}
	res += (r - lst) * dig;
	return res;
}
int main() {
	LL l = 1, r = 1000000000000ll, ans = 0;
	LL t; std::cin >> t;
	while (l <= r) {
		LL mid = l + r >> 1;
		if (getlen(mid) >= t) r = mid - 1;
		else l = mid + 1, ans = mid;
	}
	t -= getlen(ans);
	std::string st;
	for (LL i = ans + 1; i <= ans + 10; ++i)
		st += std::to_string(i);
	printf("%c\n", st[t - 1]);
	return 0;
}