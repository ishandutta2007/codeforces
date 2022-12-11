#include <bits/stdc++.h>

const int MAXN = 300010;
typedef long long LL;

int A[MAXN], B[MAXN], n, rk[MAXN];
int xs[MAXN << 3], ys[MAXN << 3], vs[MAXN << 3], tot;
int dta[MAXN], st[MAXN], top;

void bye() {
	std::cout << "NO\n";
	exit(0);
}

bool cmp(int a, int b) {
	return A[a] < A[b];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	std::cin >> n;
	LL tsum = 0;
	for (int i = 1; i <= n; ++i) std::cin >> A[i], tsum += A[rk[i] = i];
	for (int i = 1; i <= n; ++i) std::cin >> B[i], tsum -= B[i];
	if (tsum) bye();
	std::sort(rk + 1, rk + 1 + n, cmp);
	std::sort(B + 1, B + 1 + n);
	for (int i = 1; i <= n; ++i) dta[rk[i]] = B[i] - A[rk[i]];
	for (int i = 1; i <= n; ++i) {
		int & dd = dta[rk[i]];
		if (dd == 0) continue;
		if (dd > 0) st[++top] = rk[i];
		else {
			while (dd) {
				if (!top) bye();
				int t = st[top--];
				int dv = std::min(dta[t], -dd);
				++tot; dd += dv;
				if (dta[t] -= dv) st[++top] = t;
				xs[tot] = t, ys[tot] = rk[i], vs[tot] = dv;
			}
		}
	}
	if (top) bye();
	std::cout << "YES\n" << tot << '\n';
	for (int i = 1; i <= tot; ++i)
		std::cout << xs[i] << ' ' << ys[i] << ' ' << vs[i] << '\n';
	return 0;
}