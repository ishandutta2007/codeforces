#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long s64; 

template <class T>
inline void read(T &x)
{
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt) x = ~x + 1; 
}

const int MaxN = 3e5 + 5; 
const int mod = 1e9 + 9; 
const int MaxNode = MaxN << 2; 

#define lc (x << 1)
#define rc (x << 1 | 1)

int n, m; 
int a[MaxN], f[MaxN], g[MaxN], pre[MaxN]; 
int tag1[MaxNode], tag2[MaxNode], sum[MaxNode]; 

inline void add(int &x, const int &y)
{
	x += y; 
	if (x >= mod) x -= mod; 
}

inline void add_tag(const int &x, const int &f1, const int &f2, const int &l, const int &r)
{
	int len = r - l + 1; 
	if (len == 1)
	{
		add(tag1[x], f1); 
		add(sum[x], f1); 
		return; 
	}
	
	add(tag1[x], f1); 
	add(tag2[x], f2); 
	add(sum[x], 1LL * (g[len - 2] + 1) * f1 % mod); 
	add(sum[x], 1LL * g[len - 1] * f2 % mod); 
}

inline void upt(const int &x)
{
	sum[x] = sum[lc] + sum[rc]; 
	if (sum[x] >= mod) sum[x] -= mod; 
}

inline void dnt(const int &x, const int &l, const int &r)
{
	if (l < r && tag1[x])
	{
		int mid = l + r >> 1; 
		int len = r - l + 2 >> 1; 
		add_tag(lc, tag1[x], tag2[x], l, mid); 
		add_tag(rc, (1LL * f[len - 1] * tag1[x] + 1LL * f[len] * tag2[x]) % mod, 
		            (1LL * f[len + 1] * tag2[x] + 1LL * f[len] * tag1[x]) % mod, mid + 1, r); 
		//p1 = 1+len, p2 = 2+len
		tag1[x] = tag2[x] = 0; 
	}
}

inline void modify(const int &x, const int &l, const int &r, const int &u, const int &v, 
                   const int &p1, const int &p2)
{
	if (u == l && r == v)
	{
	//	printf("%d %d:%d %d\n", l, r, p1, p2); 
		add_tag(x, f[p1], f[p2], l, r); 
		return; 
	}
	dnt(x, l, r); 
	
	int mid = l + r >> 1; 
	if (v <= mid)
		modify(lc, l, mid, u, v, p1, p2); 
	else if (u > mid)
		modify(rc, mid + 1, r, u, v, p1, p2); 
	else
	{
		int len = mid - u + 1; 
		modify(lc, l, mid, u, mid, p1, p2); 
		modify(rc, mid + 1, r, mid + 1, v, p1 + len, p2 + len); 
	}
	upt(x); 
}

inline int query(const int &x, const int &l, const int &r, const int &u, const int &v)
{
	if (u <= l && r <= v)
		return sum[x]; 
	dnt(x, l, r); 
	
	int res = 0, mid = l + r >> 1; 
	if (u <= mid)
		add(res, query(lc, l, mid, u, v)); 
	if (v > mid)
		add(res, query(rc, mid + 1, r, u, v)); 
	return res; 
}

int main()
{
	read(n), read(m); 
	for (int i = 1; i <= n; ++i) 
	{
		read(a[i]); 
		add(pre[i] = pre[i - 1], a[i]); 
	}
	
	f[1] = f[2] = g[1] = 1; 
	g[2] = 2; 
	for (int i = 3; i <= n; ++i)
	{
		f[i] = f[i - 1] + f[i - 2]; 
		if (f[i] >= mod) f[i] -= mod; 
		g[i] = g[i - 1] + f[i]; 
		if (g[i] >= mod) g[i] -= mod; 
	}
	
	int opt, x, y; 
	while (m--)
	{
		read(opt), read(x), read(y); 
		if (opt == 1)
			modify(1, 1, n, x, y, 1, 2); 
		else
		{
			int res = query(1, 1, n, x, y); 
			add(res, pre[y]); 
			res -= pre[x - 1]; 
			if (res < 0) res += mod; 
			printf("%d\n", res); 
		}
	
	//	for (int i = 1; i <= n; ++i)
	//		printf("%d%c", query(1, 1, n, i, i) + a[i], " \n"[i == n]); 
	}
	
	fclose(stdin); 
	fclose(stdout); 
	return 0; 
}