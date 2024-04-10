#include <bits/stdc++.h>

const int MAXN = 1000010;
char buf[MAXN];
int n, tl;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> buf + 1;
	for (int i = 1; i <= n; ++i) tl += buf[i] == '(';
	if (tl != n / 2) return std::cout << -1 << std::endl, 0;
	int st = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (!st && buf[i] == ')') {
			++st;
			for (int j = i + 1; j <= n; ++j) {
				if (buf[j] == '(') --st; else ++st;
				if (!st) { ans += j - i + 1; i = j; break; }
			}
		} else {
			if (buf[i] == '(') ++st; else --st;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}