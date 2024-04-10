#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

template <class T>
inline void read(T &x)
{
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline void tense(T &x, const T &y)
{
	if (x > y)
		x = y; 
}

typedef long long s64; 

const int MaxN = 2e5 + 5; 
const int MaxL = 30; 
const int MaxNode = MaxN * MaxL; 

const int INF = 0x7fffffff; 

struct node
{
	int trans[2]; 
	inline void init()
	{
		trans[0] = trans[1] = 0; 
	}
}tr[MaxNode]; 

int tot, n; 
int a[MaxN], val[MaxN]; 

bool vis[MaxN]; 

inline void init()
{
	tr[tot = 1].init(); 
}

inline void insert(int x)
{
	int u = 1; 
	for (int i = MaxL; i >= 0; --i)
	{
		int c = x >> i & 1; 
		if (!tr[u].trans[c])
			tr[tr[u].trans[c] = ++tot].init(); 
		u = tr[u].trans[c]; 
	}
}

inline int find_min(int x)
{
	int u = 1, res = 0; 
	for (int i = MaxL; i >= 0; --i)
	{
		int c = x >> i & 1; 
		if (tr[u].trans[c])
			u = tr[u].trans[c]; 
		else
			res |= 1 << i, u = tr[u].trans[c ^ 1]; 
	}
	return res; 
}

inline int find_mid(int l, int r)
{
	int t = 30; 
	for (; (a[l] >> t & 1) == (a[r] >> t & 1) && t >= 0; --t); 
	if (t < 0)
		return -1; 
	
	int mid, res = -1; 
	while (l <= r)
	{
		mid = l + r >> 1; 
		if (a[mid] >> t & 1)
			r = mid - 1; 
		else
			l = mid + 1, res = mid;  
	}
	return res; 
}

inline s64 solve(int l, int r)
{
	if (l >= r) return 0; 
	
	int mid = find_mid(l, r); 
	if (mid == -1) return 0; 
	
	s64 res = solve(l, mid) + solve(mid + 1, r); 
	if (mid == r)
		return res; 
	
	init(); 
	for (int i = l; i <= mid; ++i)
		insert(a[i]); 
	
	int minv = INF; 
	for (int i = mid + 1; i <= r; ++i)
		tense(minv, find_min(a[i])); 
	return res + minv; 
}

int main()
{
//	freopen("tree.in", "r", stdin); 
//	freopen("tree.out", "w", stdout); 
	
	read(n); 
	for (int i = 1; i <= n; ++i)
		read(a[i]); 
	std::sort(a + 1, a + n + 1); 
	
	std::cout << solve(1, n) << std::endl; 
	
	fclose(stdin); 
	fclose(stdout); 
	return 0; 
}