#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
void bye() {
	std::cout << "NO" << std::endl;
	exit(0);
}

int n;
int ansl[MAXN];
int cnt[MAXN], val[MAXN], at[MAXN], top;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n * 2; ++i) {
		static char opt[20];
		std::cin >> opt;
		if (*opt == '+') {
			static int sx;
			++top;
			val[top] = 0;
			cnt[top] = 1;
			at[top] = ++sx;
		} else {
			int v; std::cin >> v;
			if (!top || val[top] > v) bye();
			ansl[at[top]] = v;
			val[top - 1] = std::max(val[top - 1], val[top]);
			--top;
			val[top] = std::max(val[top], v + 1);
		}
	}
	std::cout << "YES" << std::endl;
	for (int i = 1; i <= n; ++i)
		std::cout << ansl[i] << (" \n" [i == n]);
	return 0;
}