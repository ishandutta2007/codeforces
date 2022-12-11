#include <bits/stdc++.h>
const int MaxN = 1.5e6 + 5;

int n, m, a[MaxN], b[MaxN], s[MaxN];
int x[MaxN], c[MaxN], d[MaxN];

using data = std::array<int, 2>;
data operator + (data a, data b)
{
	if(a[0] == b[0]) return { a[0], a[1] + b[1] };
	else return (a[0] < b[0] ? a : b);
}

#define mid ((l + r) / 2)
#define ls (k << 1)
#define rs (k << 1 | 1)

int add[MaxN * 4]; data val[MaxN * 4];
void apply(int k, int v) { add[k] += v; val[k][0] += v; }
void pushdown(int k)
{
	if(add[k])
	{
		apply(ls, add[k]);
		apply(rs, add[k]);
		add[k] = 0;
	}
}

void modify(int ql, int qr, int v, int k = 1, int l = 1, int r = n + m + 1)
{
	if(ql <= l && r <= qr) return apply(k, v);
	pushdown(k);
	if(ql <= mid) modify(ql, qr, v, ls, l, mid);
	if(mid < qr) modify(ql, qr, v, rs, mid + 1, r);
	val[k] = val[ls] + val[rs];
}

void update(int p, int k = 1, int l = 1, int r = n + m + 1)
{
	if(l == r) return val[k][1] ^= 1, void();
	pushdown(k);
	(p <= mid ? update(p, ls, l, mid) : update(p, rs, mid + 1, r));
	val[k] = val[ls] + val[rs];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++i) std::cin >> b[i], a[i] = i;
	for(int i = 1; i <= m; ++i) std::cin >> x[i] >> d[i], c[i] = x[i];
	
	std::copy(b + 1, b + n + 1, s + 1);
	std::copy(d + 1, d + m + 1, s + n + 1);
	std::sort(s + 1, s + n + m + 1);
	for(int i = 1; i <= n; ++i) b[i] = std::lower_bound(s + 1, s + n + m + 1, b[i]) - s;
	for(int i = 1; i <= m; ++i) d[i] = std::lower_bound(s + 1, s + n + m + 1, d[i]) - s;
	
	std::set<std::array<int, 2>> S;
	S.insert({ 0, n + m + 1 }); S.insert({ int(1e9) + 1, 0 });
	modify(1, n + m + 1, 1);
	
	auto upd = [&](int x, int y, int t)
	{
		auto it = S.insert({ x, y }).first;
		update(y);
		int a = std::prev(it) -> at(1), b = std::next(it) -> at(1);
		for(auto z : { a, b }) modify(std::min(y, z) + 1, std::max(y, z), t);
		modify(std::min(a, b) + 1, std::max(a, b), (-t));
		if(t == -1) S.erase(it);
	};
	
	for(int i = 1; i <= n; ++i) upd(a[i], b[i], 1);
	for(int i = 1; i <= m; ++i)
	{
		upd(a[x[i]], b[x[i]], -1);
		a[x[i]] = c[i]; b[x[i]] = d[i];
		upd(a[x[i]], b[x[i]], 1);
		std::cout << val[1][1] << "\n";
	}
	return 0;
}