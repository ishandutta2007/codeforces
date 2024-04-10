#include <bits/stdc++.h>

const int MAXN = 5010;
int fail[MAXN], cnts[MAXN], cntt[MAXN];
char S[MAXN], T[MAXN];
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> S + 1 >> T + 1;
	const int LS = strlen(S + 1), LT = strlen(T + 1);
	int ans = LS + 1;
	for (int i = 1; i <= LS; ++i) {
		static char buf[MAXN];
		std::reverse_copy(S + 1, S + 1 + i, buf + 1);
		buf[i + 1] = 0;
		for (int j = 1; j <= i; ++j) {
			int now = fail[j - 1];
			while (now && (now + 1 == j || buf[now + 1] != buf[j]))
				now = fail[now];
			++now;
			fail[j] = now != j && buf[now] == buf[j] ? now : 0;
			cnts[j] = cntt[j] = 0;
		}
		int now = 0;
		for (int j = LS; j; --j) {
			while (now && buf[now + 1] != S[j]) now = fail[now];
			if (buf[now + 1] == S[j]) ++now;
			++cnts[now];
		}
		now = 0;
		for (int j = LT; j; --j) {
			while (now && buf[now + 1] != T[j]) now = fail[now];
			if (buf[now + 1] == T[j]) ++now;
			++cntt[now];
		}
		for (int j = i; j; --j) {
			cnts[fail[j]] += cnts[j];
			cntt[fail[j]] += cntt[j];
			if (cnts[j] == 1 && cntt[j] == 1) ans = std::min(ans, j);
		}
	}
	if (ans > LS) ans = -1;
	std::cout << ans << std::endl;
	return 0;
}