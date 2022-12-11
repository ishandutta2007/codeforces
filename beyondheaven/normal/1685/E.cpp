#include <bits/stdc++.h>
const int MaxN = 4e5 + 5;

int n, q, m, a[MaxN], b[MaxN];
int sign(int x) { if(x == 0) return 0; return (x < 0 ? -1 : 1); }

#define Mid ((L + R) / 2) 
#define ls (k << 1)
#define rs (k << 1 | 1)

int sum[MaxN * 4];
std::array<int, 2> mn[MaxN * 4];

void pushup(int k)
{
	sum[k] = sum[ls] + sum[rs];
	mn[k] = std::min(mn[ls], { mn[rs][0] + sum[ls], mn[rs][1] });
}

void build(int k, int L, int R)
{
	if(L == R) return mn[k] = { (sum[k] = sign(a[L] - (n + 1))), L }, void();
	build(ls, L, Mid); build(rs, Mid + 1, R);
	pushup(k);
}

void update(int p, int k = 1, int L = 1, int R = m)
{
	if(L == R) return mn[k] = { (sum[k] = sign(a[L] - (n + 1))), L }, void();
	if(p <= Mid) update(p, ls, L, Mid);
	else update(p, rs, Mid + 1, R);
	pushup(k);
}

int query(int p, int k = 1, int L = 1, int R = m)
{
	if(L == R) return 0;
	if(p <= Mid) return query(p, ls, L, Mid);
	else return sum[ls] + query(p, rs, Mid + 1, R);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> q; m = 2 * n + 1;
	for(int i = 1; i <= m; ++i) std::cin >> a[i], b[a[i]] = i;
	build(1, 1, m);
	
	int s1 = 0, s2 = 0;
	for(int i = 1; i <= n + 1; ++i)
	{
		int nxt = (i == n + 1 ? 1 : i + 1);
		s1 += (b[nxt] - b[i] + m) % m;
	}
	
	for(int i = n + 1; i <= m; ++i)
	{
		int nxt = (i == m ? n + 1 : i + 1);
		s2 += (b[nxt] - b[i] + m) % m;
	}
	
	auto fix = [&](int i, int v)
	{
		if(i <= n + 1)
		{
			int pre = (i == 1 ? n + 1 : i - 1), nxt = (i == n + 1 ? 1 : i + 1);
			s1 += v * ((b[nxt] - b[i] + m) % m); s1 += v * ((b[i] - b[pre] + m) % m);
		}
		
		if(i >= n + 1)
		{
			int pre = (i == n + 1 ? m : i - 1), nxt = (i == m ? n + 1 : i + 1);
			s2 += v * ((b[nxt] - b[i] + m) % m); s2 += v * ((b[i] - b[pre] + m) % m);
		}
	};
	
	for(int i = 1, x, y; i <= q; ++i)
	{
		std::cin >> x >> y;
		fix(a[x], -1); b[a[x]] = y; fix(a[x], 1);
		fix(a[y], -1); b[a[y]] = x; fix(a[y], 1);
		std::swap(a[x], a[y]); update(x); update(y);
		if(mn[1][0] < query(b[n + 1])) std::cout << mn[1][1] % m << "\n";
		else if(s1 != m) std::cout << b[n + 1] % m << "\n";
		else if(s2 != m) std::cout << b[n + 1] - 1 << "\n";
		else std::cout << -1 << "\n";
	}
	return 0;
}