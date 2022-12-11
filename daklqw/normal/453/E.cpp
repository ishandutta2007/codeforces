#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;

typedef std::vector<std::pair<int, int> > VI;
VI add[MAXN], rem[MAXN];
int n, m;
int ss[MAXN], ms[MAXN], rs[MAXN];
const int UP = 1e5 + 5;
std::map<int, std::set<int> > S;
LL trm[MAXN], trv[MAXN];
void addmul(int x, int v) {
	for (; x; x &= x - 1) trm[x] += v;
}
void addval(int x, LL v) {
	for (; x <= UP; x += x & -x) trv[x] += v;
}
LL qrymul(int x) {
	LL r = 0;
	for (; x <= UP; x += x & -x) r += trm[x];
	return r;
}
LL qryval(int x) {
	LL r = 0;
	for (; x; x &= x - 1) r += trv[x];
	return r;
}
int at[MAXN]; LL bm[MAXN], bv[MAXN], ansl[MAXN];
void ins(int x, int L) {
	at[x] = std::min(L, UP);
	bm[x] = qrymul(at[x]);
	bv[x] = qryval(at[x]);
}
void del(int x) {
	if (!at[x]) return ;
	bm[x] = qrymul(at[x]) - bm[x];
	bv[x] = qryval(at[x]) - bv[x];
	ansl[x] += bv[x] + at[x] * bm[x];
	at[x] = 0;
}
typedef std::map<int, std::set<int> >::iterator IT;
void _upd(IT x, int v) {
	if (x == S.begin()) return ;
	int id = *(x->second.begin());
	if (v == -1) del(id);
	else ins(id, x->first - std::prev(x)->first);
}
void update(int x, int v) {
	auto it = S.lower_bound(x);
	if (it == S.end()) return ;
	_upd(it, v);
	if (it->first == x && ++it != S.end()) _upd(it, v);
}
void mdf(int x, int v, int id) {
	update(x, -1);
	if (v == 1) S[x].insert(id);
	else {
		if (S[x].size() == 1) S.erase(x);
		else S[x].erase(id);
	}
	update(x, 1);
}
int main() { 
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> ss[i] >> ms[i] >> rs[i];
	std::cin >> m;
	for (int i = 1, t, l, r; i <= m; ++i) {
		std::cin >> t >> l >> r;
		add[l].emplace_back(t, i);
		rem[r + 1].emplace_back(t, i);
	}
	for (int i = 1; i <= n; ++i) {
		for (auto t : add[i]) mdf(t.first, 1, t.second);
		for (auto t : rem[i]) mdf(t.first, -1, t.second);
		if (S.empty()) continue;
		int at = S.begin()->first, tar = *(S.begin()->second.begin());
		ansl[tar] += std::min<LL>((LL) at * rs[i] + ss[i], ms[i]);
		if (rs[i] && ms[i]) {
			int br = (ms[i] + rs[i] - 1) / rs[i];
			addmul(br - 1, rs[i]);
			addval(br, ms[i]);
		}
	}
	for (int i = 1; i <= m; ++i) del(i);
	for (int i = 1; i <= m; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}