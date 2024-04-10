#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long double LD;
int n, T, Q;
int ps[MAXN], ls[MAXN], ins[MAXN];
LD adx[MAXN], dex[MAXN];
inline LD calc(int at, int i = -233) {
	if (i == -233) i = ins[at];
	i = std::min(i, ls[at]);
	if (i < 0) return -1e100;
	return (LD) ps[at] * i / (i + ls[at]);
}

int add[MAXN << 2], dec[MAXN << 2];
bool cmpa(int a, int b) { return adx[a] < adx[b]; }
bool cmpd(int a, int b) { return dex[a] < dex[b]; }
void upd(int u, int l, int r, int tar) {
	if (l == r) {
		adx[l] = calc(l, ins[l] + 1) - calc(l, ins[l]);
		dex[l] = calc(l, ins[l] - 1) - calc(l, ins[l]);
		add[u] = dec[u] = l;
		return ;
	}
	int mid = l + r >> 1;
	if (tar <= mid) upd(u << 1, l, mid, tar);
	else upd(u << 1 | 1, mid + 1, r, tar);
	add[u] = cmpa(add[u << 1], add[u << 1 | 1]) ? add[u << 1 | 1] : add[u << 1];
	dec[u] = cmpd(dec[u << 1], dec[u << 1 | 1]) ? dec[u << 1 | 1] : dec[u << 1];
}
LD ans = 0;
void mdf(int t, int v) {
	ans -= calc(t);
	ins[t] += v;
	ans += calc(t);
	upd(1, 1, n, t);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> T >> Q;
	for (int i = 1; i <= n; ++i) std::cin >> ps[i];
	for (int i = 1; i <= n; ++i) std::cin >> ls[i];
	for (int i = 1; i <= n; ++i) upd(1, 1, n, i);
	for (int i = 1; i <= T; ++i) mdf(add[1], 1);
	std::cout << std::fixed << std::setprecision(10);
	while (Q --> 0) {
		int typ, at;
		std::cin >> typ >> at;
		ans -= calc(at);
		ls[at] += typ == 1 ? 1 : -1;
		upd(1, 1, n, at);
		ans += calc(at);
		mdf(dec[1], -1);
		mdf(add[1], 1);
		std::cout << ans << '\n';
	}
	return 0;
}