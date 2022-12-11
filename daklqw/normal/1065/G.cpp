#include <bits/stdc++.h>

typedef long long LL;
typedef std::string str;
const int MAXN = 210;
const LL MA = 2e18;
const int lim = 201;
void gmin(LL & x, LL y) { x > y ? x = y : 0; }
int match(str src, str c) {
	int res = 0;
	const int L = c.length();
	for (int i = (int) src.length() - L; i >= 0; --i)
		res += strncmp(src.c_str() + i, c.c_str(), L) == 0;
	return res;
}
struct fib {
	str pre, suc;
	std::map<str, LL> qry;
	fib * l, * r;
	int siz;
	LL query(str s) {
		if (s.length() > siz) return 0;
		if (siz <= 1) return match(pre, s);
		if (qry.count(s)) return qry[s];
		LL res;
		gmin(res = l->query(s) + r->query(s), MA);
		res += match(l->suc + r->pre, s) - match(l->suc, s) - match(r->pre, s);
		gmin(res, MA);
		return qry[s] = res;
	}
	bool qrysuc(str s) {
		if (s.length() > suc.length()) return false;
		return suc.substr(suc.length() - s.length()) == s;
	}
} f[MAXN];
int n, m; LL K;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K >> m;
	f[0].pre = f[0].suc = "0", f[0].siz = 1;
	f[1].pre = f[1].suc = "1", f[1].siz = 1;
	for (int i = 2; i <= n; ++i) {
		f[i].l = &f[i - 2], f[i].r = &f[i - 1];
		f[i].pre = f[i - 2].pre + f[i - 1].pre;
		if (f[i].pre.length() > lim)
			f[i].pre = f[i].pre.substr(0, lim);
		f[i].suc = f[i - 2].suc + f[i - 1].suc;
		if (f[i].suc.length() > lim)
			f[i].suc = f[i].suc.substr(f[i].suc.length() - lim);
		f[i].siz = std::min(f[i - 2].siz + f[i - 1].siz, 201);
	}
	str now;
	for (int i = 1; i <= m && K; ++i) {
		if (!(K -= now.length() && f[n].qrysuc(now))) break;
		LL v = f[n].query(now + '0');
		if (v >= K) now += '0';
		else now += '1', K -= v;
	}
	std::cout << now << std::endl;
	return 0;
}