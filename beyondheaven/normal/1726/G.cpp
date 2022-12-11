#include <bits/stdc++.h>
const int Mod = 998244353;
const int inf = 1e9;
#define all(x) x.begin(), x.end()

int pow_mod(int a, int b, int res = 1)
{
	for(; b; b >>= 1, a = 1LL * a * a % Mod)
	if(b & 1) res = 1LL * res * a % Mod;
	return res;
}

#define mid ((l + r) / 2)
#define ls (k << 1)
#define rs (k << 1 | 1)

std::vector<std::array<int, 2>> val;
std::vector<int> tag;

void apply(int k, int v) { val[k][0] += v; tag[k] += v; }
void pushdown(int k)
{
	if(tag[k])
	{
		apply(ls, tag[k]);
		apply(rs, tag[k]);
		tag[k] = 0;
	}
}

void pushup(int k)
{
	if(val[ls][0] == val[rs][0]) val[k] = val[rs];
	else val[k] = std::max(val[ls], val[rs]);
}

void build(const std::vector<std::array<int, 2>> &a, int k, int l, int r)
{
	if(l == r) return val[k] = a[l], void();
	build(a, ls, l, mid); build(a, rs, mid + 1, r);
	pushup(k);
}

void modify(int ql, int qr, int v, int k, int l, int r)
{
	if(ql <= l && r <= qr) return apply(k, v);
	pushdown(k);
	if(ql <= mid) modify(ql, qr, v, ls, l, mid);
	if(mid < qr) modify(ql, qr, v, rs, mid + 1, r);
	pushup(k);
}

void update(int p, int k, int l, int r)
{
	if(l == r) return val[k] = { -inf, -1 }, void();
	pushdown(k);
	(p <= mid ? update(p, ls, l, mid) : update(p, rs, mid + 1, r));
	pushup(k); 
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n; std::cin >> n;
	std::vector<int> a(n), b(n);
	for(int &x : a) std::cin >> x;
	for(int &x : b) std::cin >> x;
	
	std::vector<int> Fac(n + 1), FInv(n + 1);
	for(int i = Fac[0] = 1; i <= n; ++i) Fac[i] = 1LL * Fac[i - 1] * i % Mod;
	FInv[n] = pow_mod(Fac[n], Mod - 2);
	for(int i = n; i; --i) FInv[i - 1] = 1LL * FInv[i] * i % Mod;
	
	auto C = [&](int n, int m) -> int
	{
		if(m < 0 || m > n) return 0;
		return 1LL * Fac[n] * FInv[m] % Mod * FInv[n - m] % Mod;
	};
	
	if(*std::min_element(all(a)) == *std::max_element(all(a)))
	std::cout << Fac[n] << "\n", exit(0);
	
	int T = n - 1 + *std::min_element(all(a));
	if(*std::max_element(all(a)) > T) std::cout << 0 << "\n", exit(0);
	
	std::map<std::array<int, 2>, int> mp;
	for(int i = 0; i < n; ++i) ++mp[{ a[i], b[i] }];
	
	int ans = C(n, mp[{ T, 1 }]);
	for(auto p : mp)
	{
		ans = 1LL * ans * Fac[p.second] % Mod;
		if(p.first[0] != T && p.first[1] == 1
			&& p.second > 1) std::cout << 0 << "\n", exit(0);
	}
	
	if(mp.count({ *std::min_element(all(a)), 0 })) std::cout << 0 << "\n", exit(0);
	
	std::deque<int> v0;
	std::vector<int> v1;
	for(int i = 0; i < n; ++i)
	{
		if(b[i] == 0) v0.push_back(i);
		else if(a[i] != T) v1.push_back(i);
	}
	
	auto cmp = [&](int x, int y) { return std::tie(a[x], x) < std::tie(a[y], y); };
	std::sort(all(v0), cmp); std::sort(all(v1), cmp);
	
	auto pos = [&](int x) -> int
	{
		return std::partition_point(all(v1), [&](int i) { return a[i] < x; }) - v1.begin();
	};
	
	std::vector<int> c(T + 1);
	auto add = [&](int x, int v) { for(; x <= T; x += (x & -x)) c[x] += v; };
	auto sum = [&](int x) { int v = 0; for(; x; x -= (x & -x)) v += c[x]; return v; };
	
	for(int i = 0; i < n; ++i) add(a[i], 1);
	
	std::vector<std::array<int, 2>> z;
	for(int i : v1) z.push_back({ a[i] + sum(T) - sum(a[i]), i });
	
	int m = z.size();
	val.resize(4 * m); tag.resize(4 * m);
	build(z, 1, 0, m - 1);
	
	int q = v0.size() + v1.size();
	while(q--)
	{
		int x = -1;
		if(v0.size())
		{
			x = v0.front();
			if(a[x] + sum(a[x] - 1) != T) x = -1;
		}
		
		int y = val[1][1];
		if(val[1][0] > T) y = -1;
		
		if(x == -1 && y == -1) std::cout << 0 << "\n", exit(0);
		if(y == -1 || (x != -1 && a[x] > a[y]))
		{
			add(a[x], -1), add(T, 1);
			v0.pop_front();
			if(pos(a[x]) != m) modify(pos(a[x]), m - 1, 1, 1, 0, m - 1);
		}
		else
		{
			add(a[y], -1), add(T, 1);
			update(std::lower_bound(all(v1), y, cmp) - v1.begin(), 1, 0, m - 1);
			if(pos(a[y]) != m) modify(pos(a[y]), m - 1, 1, 1, 0, m - 1);
		}
	}
	
	std::cout << ans << "\n";
	return 0;
}