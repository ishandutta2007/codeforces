#include <bits/stdc++.h>

const int MAXN = 1010;
char buf[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf + 1; int n = strlen(buf + 1);
	int ans = n, sp = 0;
	for (int i = 0; i <= n; ++i) {
		int t1 = 0, t2 = 0;
		for (int j = 1; j <= i; ++j) t1 += buf[j] == '(';
		for (int j = i + 1; j <= n; ++j) t2 += buf[j] == ')';
		if (t1 == t2 && t1 + t2 <= ans) { ans = t1 + t2, sp = i; }
	}
	std::cout << (ans != 0) << std::endl;
	if (ans > 0) {
		std::cout << ans << std::endl;
		for (int i = 1; i <= sp; ++i) if (buf[i] == '(')
			std::cout << i << ' ';
		for (int i = sp + 1; i <= n; ++i) if (buf[i] == ')')
			std::cout << i << ' ';
	}
	return 0;
}