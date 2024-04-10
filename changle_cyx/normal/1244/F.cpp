#include <bits/stdc++.h>

template <class T>
inline void read(T &x)
{
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt)
		x = ~x + 1; 
}

template <class T>
inline void putint(T x)
{
	static char buf[25], *tail = buf; 
	if (x < 0)
		x = ~x + 1, putchar('-'); 
	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y)
{
	return x > y ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

typedef unsigned u32; 
typedef long long s64; 
typedef unsigned long long u64; 
typedef std::pair<int, int> pii; 

#define mp(x, y) std::make_pair(x, y)

const int MaxN = 2e5 + 5; 

int n, K; 
char s[MaxN]; 
bool a[MaxN]; 

int lst[MaxN], nxt[MaxN]; 

int tot; 
//int lef[MaxN], rit[MaxN]; 
int ufs[MaxN], sze[MaxN]; 

std::set<int> S; 

bool bo[MaxN]; 

inline int ufs_find(int x)
{
	return ufs[x] == x ? x : ufs[x] = ufs_find(ufs[x]); 
}

inline void ufs_merge(int x, int y)
{
//	printf(":%d %d\n", x, y); 

	x = ufs_find(x); 
	y = ufs_find(y); 
	if (x != y)
	{
		// if (lef[x] == nxt[rit[y]])
		// 	std::swap(x, y); 

		ufs[x] = y; 
		sze[y] += sze[x]; 
		--tot; 

	//	lef[y] = lef[x]; 
	}
}

inline void ufs_init()
{
	tot = n; 
	for (int i = 1; i <= n; ++i)
	{
		ufs[i] = i; 
	//	lef[i] = rit[i] = i; 
		sze[i] = 1; 
	}
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == a[lst[i]])
			ufs_merge(i, lst[i]); 
	}
}

inline void print()
{
	for (int i = 1; i <= n; ++i)
	{
		putchar(a[ufs_find(i)] ? 'B' : 'W'); 
	}
}

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	read(n), read(K); 
	scanf("%s", s + 1); 
	for (int i = 1; i <= n; ++i)
		a[i] = s[i] == 'B'; 

	for (int x = 1; x <= n; ++x)
	{
		lst[x] = x == 1 ? n : x - 1; 
		nxt[x] = x == n ? 1 : x + 1;
	}

	ufs_init(); 

	for (int i = 1; i <= n; ++i)
	{
		int u = ufs_find(i);
		if (sze[u] == 1)
		{
			if (sze[ufs_find(lst[i])] > 1 || sze[ufs_find(nxt[i])] > 1)
				S.insert(i); 
		}
		else
			bo[i] = true; 
	}

//	print(); 

	int cur = K; 
	while (cur && !S.empty())
	{
		std::set<int> T; 
		T.clear(); 

		for (auto v : S)
		{
		//	printf("%d ", v); 

			int lef_u = ufs_find(lst[v]); 
			int rit_u = ufs_find(nxt[v]); 
			if (sze[lef_u] > 1 && bo[lst[v]])
				ufs_merge(v, lef_u); 
			if (sze[rit_u] > 1 && bo[nxt[v]])
				ufs_merge(v, rit_u); 
		}
		//puts(""); 

		for (auto v : S)
		{
			bo[v] = true; 
			int lef_u = ufs_find(lst[v]); 
			int rit_u = ufs_find(nxt[v]); 

			if (sze[lef_u] == 1)
			{
				if (T.find(lef_u) == T.end())
					T.insert(lef_u); 
			}
			if (sze[rit_u] == 1)
			{
				if (T.find(rit_u) == T.end())
					T.insert(rit_u); 
			}
		}

		S = T, --cur; 
	}

	for (int i = 1; i <= n; ++i)
		if (ufs_find(i) == i)
		{
			if (sze[i] == 1)
				a[i] = K & 1 ? a[i] ^ 1 : a[i]; 
		}
	//	else
	//		printf("ufs%d = %d\n", i, ufs_find(i)); 
	print(); 

	return 0; 
}