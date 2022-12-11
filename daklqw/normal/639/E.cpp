#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long long LL;
struct P {
	int p, t, bel;
} ps[MAXN];
int n, bak;
LL pre[MAXN], hav[MAXN];

bool cmp1(P a, P b) {
	return (LL) a.p * b.t > (LL) b.p * a.t;
}
bool eq(P a, P b) {
	return (LL) a.p * b.t == (LL) b.p * a.t;
}
bool cmp2(P a, P b) {
	return a.p < b.p;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	LL sump = 0;
	for (int i = 1; i <= n; ++i) std::cin >> ps[i].p;
	for (int i = 1; i <= n; ++i) std::cin >> ps[i].t, sump += ps[i].t;
	std::sort(ps + 1, ps + 1 + n, cmp1);
	for (int i = 1; i <= n; ++i)
		if (i != 1 && eq(ps[i], ps[i - 1])) ps[i].bel = ps[i - 1].bel;
		else ps[i].bel = ++bak;
	for (int i = 1; i <= n; ++i) hav[ps[i].bel] += ps[i].t;
	for (int i = 1; i <= bak + 1; ++i) pre[i] = pre[i - 1] + hav[i - 1];
	std::sort(ps + 1, ps + 1 + n, cmp2);
	double l = 0, r = 1, ans = 0;
	for (int TC = 75; TC; --TC) {
		double mid = (l + r) / 2;
		double premax = 0;
		int cur = 1;
		bool can = true;
		for (int i = 1; i <= n; ++i) {
			while (ps[i].p != ps[cur].p) {
				double t = ps[cur].p * (1 - mid * (pre[ps[cur].bel] + ps[cur].t) / sump);
				premax = std::max(premax, t);
				++cur;
			}
			double t = ps[i].p * (1 - mid * pre[ps[i].bel + 1] / sump);
			if (t < premax) { can = false; break; }
		}
		if (can) ans = mid, l = mid; else r = mid;
	}
	std::cout << std::fixed << std::setprecision(12);
	std::cout << ans << std::endl;
	return 0;
}