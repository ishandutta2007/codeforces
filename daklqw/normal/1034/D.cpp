#include <bits/stdc++.h>

typedef long long LL;
const int MAXN = 300010;
const int INF = 0x3f3f3f3f;
void gma(int & x, int y) { x < y ? x = y : 0; }
void gmi(int & x, int y) { x > y ? x = y : 0; }
typedef std::pair<int, int> pi;
typedef std::set<pi> SS;
typedef SS::iterator SSI;
struct itv { int l, r, id; } ls[MAXN];
SS S;
SSI split(int x) {
	auto it = S.lower_bound(pi(x, 0)), t = it;
	if (it->first != x)
		it = S.emplace_hint(it, x, (--t)->second);
	return it;
}
pi opt[MAXN << 3];
int cur[MAXN], bak;
int n, K;
void predo() {
	S.emplace(0, 0);
	S.emplace(1e9 + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cur[i] = bak + 1;
		SSI l = split(ls[i].l), r = split(ls[i].r);
		for (SSI j = l, i; (i = j++) != r; ) if (i->second)
			opt[++bak] = pi(i->second, i->first - j->first);
		S.erase(l, r);
		opt[++bak] = pi(i, ls[i].r - ls[i].l);
		S.emplace(ls[i].l, ls[i].id);
	}
	cur[n + 1] = bak + 1;
}
int arr[MAXN], nowv, tov, now;
LL smk[MAXN], nowk;
void add(pi x) {
	int at, v; std::tie(at, v) = x;
	arr[at] += v;
	smk[at] += (LL) at * v;
	tov += v;
	if (at >= now) nowv += v;
	else nowk += (LL) at * v;
}
void shr() {
	nowv -= arr[now], nowk += smk[now++];
}
std::pair<LL, LL> solve(int len) {
	memset(arr, 0, n + 1 << 2);
	memset(smk, 0, n + 1 << 3);
	tov = nowv = nowk = 0; now = 1;
	LL cnt = 0, sum = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = cur[i]; j < cur[i + 1]; ++j) add(opt[j]);
		while (now <= i && nowv >= len) shr();
		cnt += now - 1;
		sum += nowv * (now - 1ll) + nowk;
	}
	return std::make_pair(cnt, sum);
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	int ll = INF, rr = 0;
	for (int i = 1; i <= n; ++i) {
		std::cin >> ls[i].l >> ls[i].r, ls[i].id = i;
		gmi(ll, ls[i].l), gma(rr, ls[i].r);
	}
	predo();
	int l = 0, r = rr - ll + 1, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (solve(mid).first >= K) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	auto tmp = solve(ans + 1);
	LL Ans = ans * (K - tmp.first) + tmp.second;
	std::cout << Ans << std::endl;
	return 0;
}