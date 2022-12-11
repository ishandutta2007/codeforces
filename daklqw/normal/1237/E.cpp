#include <bits/stdc++.h>

const int MAXN = 2000010;
void bye() { std::cout << 0 << std::endl; exit(0); }
int n;
int coef[MAXN], chk[MAXN], bak;
void solve(int u, int b) {
	if (u < 0) {
		coef[++bak] = b;
		chk[bak] = true;
	} else {
		solve(u - 1, b ^ 1);
		coef[++bak] = b;
		solve(u - 1, b);
	}
}
int dep;
int calc(int cho1) {
	int cv = cho1 ^ (dep & 1) ^ 1;
	for (int i = 1; i <= bak; ++i) coef[i] ^= cv;
	int cur = 2 + (!cho1), tr = !cho1;
	for (int i = 2; i <= n; ++i) {
		if (chk[cur] && cur + 1 <= bak) {
			if (coef[cur + 1] == (i & 1)) cur += 2, ++tr;
			else ++cur;
		} else if (cur <= bak) {
			if ((i & 1) != coef[cur]) tr = n, i = n + 1;
			else ++cur, ++tr;
		} else tr = n, i = n + 1;
	}
	for (int i = 1; i <= bak; ++i) coef[i] ^= cv;
	return tr == (1 << dep + 1) - 1;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n; dep = std::__lg(n + 1) - 1;
	solve(dep, 0);
	int ans = calc(false) + calc(true);
	std::cout << ans << std::endl;
	return 0;
}