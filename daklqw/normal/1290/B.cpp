#include <bits/stdc++.h>

const int MAXN = 200010;
char buf[MAXN];
int n, Q, pre[MAXN][26];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf + 1; n = strlen(buf + 1);
	for (int i = 1; i <= n; ++i) {
		memcpy(pre[i], pre[i - 1], 104);
		++pre[i][buf[i] - 'a'];
	}
	std::cin >> Q;
	while (Q --> 0) {
		int l, r; std::cin >> l >> r;
		int typ = 0;
		for (int i = 0; i != 26; ++i)
			if (pre[r][i] - pre[l - 1][i])
				++typ;
		if (l != r && buf[l] == buf[r]) {
			int ch = buf[l] - 'a';
			if (typ <= 2) {
				std::cout << "No\n";
				continue;
			}
		}
		std::cout << "Yes\n";
	}
	return 0;
}