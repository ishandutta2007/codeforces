#include <bits/stdc++.h>

const int MAXN = 3010;
typedef long long LL;
std::vector<int> V[MAXN];
int n, m, K, P, hav[MAXN], lans[MAXN];
LL ans, now;
int pre[MAXN], suc[MAXN];
std::set<int> pos;
void ins(int x) {
	if (!hav[x]) {
		auto it = pos.insert(x).first, ti = it;
		int & px = pre[x], & sx = suc[x];
		px = it == pos.begin() ? 0 : *--it;
		++ti, sx = ti == pos.end() ? 0 : *ti;
		if (px) suc[px] = x;
		if (sx) {
			::now -= lans[sx];
			lans[sx] /= (sx - pre[sx]);
			pre[sx] = x;
			lans[sx] *= (sx - pre[sx]);
			::now += lans[sx];
		}
	}
	++hav[x];
	static int li[30]; int bak = 0, nb;
	int now = x;
	for (int i = 1; i <= P + 1 && now; ++i) li[++bak] = now = pre[now];
	std::reverse(li + 1, li + 1 + bak);
	now = suc[li[++bak] = x];
	for (int i = 2; i <= bak; ++i) ::now -= lans[li[i]], lans[li[i]] = 0;
	nb = bak;
	for (int i = 1; i <= P && now; ++i) li[++nb] = now, now = suc[now];
	int cur = 1; now = 0;
	for (int i = 2; i <= bak; ++i) {
		while (now < P && cur < nb) now += hav[li[++cur]];
		if (now >= P)
		::now += lans[li[i]] = (li[i] - li[i - 1]) * (m - li[cur] + 1);
		now -= hav[li[i]];
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> K >> P;
	for (int i = 1, t1, t2; i <= K; ++i) {
		std::cin >> t1 >> t2;
		V[t1].push_back(t2);
	}
	for (int L = 1; L <= n; ++L) {
		now = 0; pos.clear();
		memset(hav, 0, m + 1 << 2);
		memset(pre, 0, m + 1 << 2);
		memset(suc, 0, m + 1 << 2);
		memset(lans, 0, m + 1 << 2);
		for (int R = L; R <= n; ++R) {
			for (auto t : V[R]) ins(t);
			ans += now;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}