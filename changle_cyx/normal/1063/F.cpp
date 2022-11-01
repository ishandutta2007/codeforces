#include <bits/stdc++.h>

template <class T>
inline void relax(T &x, const T &y)
{
	if (x < y)
		x = y; 
}

const int MaxLog = 19; 
const int MaxN = 5e5 + 5; 

int n; 
int f[MaxN]; 
char s[MaxN]; 

namespace SA
{
	int minh[MaxLog + 1][MaxN], log_val[MaxN]; 
	int sa[MaxN], rank[MaxN], height[MaxN]; 

	inline bool is_equal(int x, int y, int k)
	{
		int p = x + k > n ? -1 : rank[x + k]; 
		int q = y + k > n ? -1 : rank[y + k]; 
		return rank[x] == rank[y] && p == q; 
	}

	inline void sa_init()
	{
		static int buc[MaxN], x[MaxN]; 
		for (int i = 1; i <= n; ++i)
			++buc[s[i]]; 
		for (int i = 1; i <= 255; ++i)
			buc[i] += buc[i - 1];
		for (int i = n; i >= 1; --i)
			sa[buc[s[i]]--] = i; 
		rank[sa[1]] = 1; 
		for (int i = 2; i <= n; ++i)
			rank[sa[i]] = rank[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]); 

		memset(buc, 0, sizeof(buc)); 
		for (int k = 1; rank[sa[n]] < n; k <<= 1)
		{
			int m = 0; 
			for (int i = n - k + 1; i <= n; ++i)
				x[++m] = i; 
			for (int i = 1; i <= n; ++i)
				if (sa[i] > k)
					x[++m] = sa[i] - k; 

			for (int i = 1; i <= n; ++i)
				buc[i] = 0; 
			for (int i = 1; i <= n; ++i)
				++buc[rank[i]]; 
			for (int i = 1; i <= n; ++i)
				buc[i] += buc[i - 1]; 
			for (int i = n; i >= 1; --i)
				sa[buc[rank[x[i]]]--] = x[i]; 

			x[sa[1]] = 1; 
			for (int i = 2; i <= n; ++i)
				x[sa[i]] = x[sa[i - 1]] + (!is_equal(sa[i - 1], sa[i], k)); 
			for (int i = 1; i <= n; ++i)
				rank[i] = x[i]; 
		}

		for (int i = 1, k = 0; i <= n; ++i)
		{
			if (k) --k; 
			int j = sa[rank[i] - 1]; 
			while (s[i + k] == s[j + k])
				++k; 
			minh[0][rank[i]] = height[rank[i]] = k; 
		}

		log_val[0] = -1; 
		for (int i = 1; i <= n; ++i)
			log_val[i] = log_val[i >> 1] + 1; 
		for (int j = 1; j <= MaxLog; ++j)
			for (int i = 1; i + (1 << j) - 1 <= n; ++i)
				minh[j][i] = std::min(minh[j - 1][i], minh[j - 1][i + (1 << (j - 1))]); 
	}

	inline int query_min(int l, int r)
	{
		int k = log_val[r - l + 1]; 
		return std::min(minh[k][l], minh[k][r - (1 << k) + 1]);
	}
}

namespace SEG
{
	const int MaxS = MaxN * 40; 

	struct node
	{
		int lc, rc, maxf; 
		#define lc(x) tr[x].lc
		#define rc(x) tr[x].rc
		#define maxf(x) tr[x].maxf
	}tr[MaxS]; 

	int nT; 

	inline void seg_insert(int lst, int &x, int l, int r, int pos, int val)
	{
		tr[x = ++nT] = tr[lst];
		relax(maxf(x), val); 

		if (l == r)
			return; 

		int mid = (l + r) >> 1; 
		if (pos <= mid)
			seg_insert(lc(lst), lc(x), l, mid, pos, val); 
		else
			seg_insert(rc(lst), rc(x), mid + 1, r, pos, val); 
	}

	inline int seg_query(int x, int l, int r, int u, int v)
	{
		if (!x)
			return 0; 
		if (u <= l && r <= v)
			return maxf(x); 
		int mid = (l + r) >> 1, res = 0; 
		if (u <= mid)
			relax(res, seg_query(lc(x), l, mid, u, v)); 
		if (v > mid)
			relax(res, seg_query(rc(x), mid + 1, r, u, v)); 
		return res; 
	}
}

int rt[MaxN]; 

inline bool find(int rt_seg, int p, int lim)
{
	int l = 1, r = p, mid, resl = p, resr = p; 
	while (l <= r)
	{
		mid = (l + r) >> 1; 
		if (SA::query_min(mid, p) >= lim)
			resl = r = mid - 1; 
		else
			l = mid + 1; 
	}
	l = p + 1, r = n; 
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (SA::query_min(p + 1, mid) >= lim)
			resr = mid, l = mid + 1; 
		else
			r = mid - 1; 
	}

	return SEG::seg_query(rt_seg, 1, n, resl, resr) >= lim;  
}

inline bool check(int i, int len)
{
	if (len == 1)
		return true; 
	else if (i + len > n)
		return false; 

	return find(rt[i + len], SA::rank[i], len - 1) || 
		   find(rt[i + len], SA::rank[i + 1], len - 1); 
}

int main()
{
	scanf("%d%s", &n, s + 1);
	SA::sa_init(); 

	int ans = 0; 
	for (int i = n; i >= 1; --i)
	{
		int cur = f[i + 1] + 1; 
		while (!check(i, cur))
			--cur; 

		relax(ans, f[i] = cur); 
		SEG::seg_insert(rt[i + 1], rt[i], 1, n, SA::rank[i], f[i]);
	}

	std::cout << ans << std::endl; 

	return 0; 
}