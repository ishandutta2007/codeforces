#include <bits/stdc++.h>

const int MAXN = 2000010;
char buf[MAXN], str[MAXN];
int p[MAXN], bak, bel[MAXN];
int ans, al, ar, n;
void get(int L, int R) {
	if (L + 1 + n - R > ans) {
		ans = L + 1 + n - R, al = L, ar = R;
	}
}
void solve(char * cur) {
	int L = 0, R = n - 1;
	ans = 0;
	while (L < R && buf[L] == buf[R]) ++L, --R, ans += 2;
	al = L - 1, ar = R + 1;
	bak = 0;
	str[bak++] = '$';
	str[bak++] = '#';
	cur = buf; int cnt = 0;
	while (*cur) {
		bel[bak] = cnt++;
		str[bak++] = *cur;
		str[bak++] = '#';
		++cur;
	}
	str[bak++] = '*';
	int mid = 0, maxr = 0;
	// std::cout << "DDD " << L << ' ' << R << '\n';
	for (int i = 1; i != bak; ++i) {
		p[i] = i < maxr ? std::min(p[(mid << 1) - i], maxr - i) : 1;
		while (str[i - p[i]] == str[i + p[i]]) ++p[i];
		if (maxr < i + p[i]) maxr = i + p[i], mid = i;
		int tv = p[i] - 1, tl = bel[i - tv + 1], tr = bel[i + tv - 1];
		if (tl != -1 && tr != -1) {
			// std::cout << "NOW " << str[i] << ' ' << i << ' ' << tv << ' ' << tl << ' ' << tr << std::endl;
			if (tl <= L) {
				int xr = str[i] == '#' ? bel[i - 1] * 2 - L + 1 : bel[i] * 2 - L;
				// std::cout << "CL " << xr << std::endl;
				if (xr <= R) get(xr, R + 1);
			}
			if (tr >= R) {
				int xl = str[i] == '#' ? bel[i + 1] * 2 - R - 1 : bel[i] * 2 - R;
				// std::cout << "CR " << xl << std::endl;
				if (xl >= L) get(L - 1, xl);
			}
		}
	}
	// std::cout << "NOW " << ans << ' ' << al << ' ' << ar << '\n';
	for (int i = 0; i <= al; ++i)
		std::cout << buf[i];
	for (int i = ar; i < n; ++i)
		std::cout << buf[i];
	std::cout << '\n';
	memset(p, 0, bak + 1 << 2);
	memset(bel, -1, bak + 1 << 2);
}
int main() {
	memset(bel, -1, sizeof bel);
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	while (T --> 0) {
		std::cin >> buf; n = strlen(buf);
		solve(buf);
	}
	return 0;
}