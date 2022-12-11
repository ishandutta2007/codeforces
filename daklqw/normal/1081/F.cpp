#include <bits/stdc++.h>

const int MAXN = 310;
int n, all, now;
int ansl[MAXN];
int qry(int l, int r) {
	std::cout << "? " << l << ' ' << r << std::endl;
	int res; std::cin >> res;
	res += now, now = res - now;
	return res;
}
int pre[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> all, now = all;
	for (int i = 1 + (n & 1); i <= n; ++i) {
		int mask = 0;
		while (mask != 1) mask ^= 1 << ((qry(i - (n & 1), i) ^ i) & 1);
		pre[i] = (i - now + all) / 2;
		while (mask) mask ^= 1 << ((qry(i - (n & 1), i) ^ i) & 1);
	}
	if (n == 1) pre[1] = all;
	else if (n & 1) {
		int mask = 0;
		while (mask != 1) mask ^= 1 << (qry(2, 3) & 1);
		pre[1] = pre[n] - (n - 1 - now + all) / 2;
	}
	std::cout << "! ";
	for (int i = 1; i <= n; ++i)
		std::cout << (pre[i] - pre[i - 1]);
	std::cout << std::endl;
	return 0;
}