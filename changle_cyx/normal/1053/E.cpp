#include <bits/stdc++.h>

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
inline void putint(T x)
{
	static char buf[15], *tail = buf; 
	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

const int MaxN = 1e6 + 5; 

int n, m; 
int a[MaxN]; 

bool vis[MaxN]; 
std::vector<int> rest; 

int pre[MaxN], nxt[MaxN]; 
int lstsame[MaxN], nxtsame[MaxN]; 

inline void invalid()
{
	puts("no"); 
	exit(0); 
}

inline void same_init()
{
	static int lst[MaxN]; 
	for (int i = 1; i <= m; ++i)
		if (a[i])
		{
			lstsame[i] = lst[a[i]]; 
			lst[a[i]] = i; 
		}
	for (int i = 1; i <= n; ++i)
		lst[i] = m + 1; 
	for (int i = m; i >= 1; --i)
		if (a[i])
		{
			nxtsame[i] = lst[a[i]]; 
			lst[a[i]] = i; 
		}
}

inline int getnew()
{
	if (rest.empty())
		invalid(); 

	int res = *rest.rbegin(); 
	return rest.pop_back(), res; 
} 

inline void merge(int x, int y)
{
	nxt[x] = nxt[y], pre[nxt[y]] = x; 
}

inline void solve(int l, int r, int rt)
{
	if ((r - l) & 1)
		invalid(); 
	if (l > r)
		return; 

	// std::cout << l << ' ' << r << ' ' << rt << ':'; 
	// for (int x = l; x <= r; x = nxt[x])
	// 	printf("%d,%d|", a[x], x); 
	// puts(""); 

	for (int x = l; x <= r; x = nxt[x])
		if (a[x] && a[x] != rt)
		{
			if (lstsame[x] >= 1 && lstsame[x] < l)
				invalid(); 
			if (nxtsame[x] <= m && nxtsame[x] > r)
				invalid(); 
		}

	for (int x = l; x <= r; x = nxt[x])
		if (a[x] && lstsame[x] >= l)
		{
			int y = lstsame[x]; 
			solve(nxt[y], pre[x], a[x]); 
			merge(y, x); 

			lstsame[nxtsame[x]] = y; 
			nxtsame[y] = nxtsame[x]; 
		}

	// if (rt == 23)
	// {

	// std::cout << l << ' ' << r << ' ' << rt << ':'; 
	// for (int x = l; x <= r; x = nxt[x])
	// 	printf("%d ", a[x]); 
	// puts(""), std::cerr << "fuck\n"; 
	// }

	int cnt = 0, lim = 0; 
	for (int x = l; x <= r; x = nxt[x])
		cnt += (bool)a[x], ++lim; 
	lim = (lim >> 1) + 1; 

	if (cnt > lim)
		invalid(); 
	if (cnt < lim)
	{
		for (int x = l; x <= r && cnt < lim; x = nxt[x])
			if (!a[x])
			{
				a[x] = getnew(); 
				++cnt; 
			}
	}

	for (int x = l; x <= r; x = nxt[x])
	{
		int y = pre[x], z = pre[y]; 
		while (z >= l)
		{
			if ((!a[x] && a[y] && a[z]) || (a[x] && a[y] && !a[z]))
			{
				a[x] = a[z] = a[x] + a[z]; 
				merge(z, x), x = z; 
			}
			else
				break; 

			y = pre[x], z = pre[y]; 
		}
	}

	for (int x = l; x <= std::min(r + 1, m); x = nxt[x])
		if (!a[x])
			a[x] = rt; 

	// std::cerr << "fucked\n"; 
	// std::cout << l << ' ' << r << ' ' << rt << ':'; 
	// for (int x = l; x <= r; x = nxt[x])
	// 	printf("%d,%d|", a[x], x); 
	// puts(""); 
}

int main()
{
	read(n), m = (n << 1) - 1; 
	for (int i = 1; i <= m; ++i)
		read(a[i]), vis[a[i]] = true; 
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			rest.push_back(i); 
	
	for (int i = 1; i <= m; ++i)
	{
		pre[i] = i - 1; 
		nxt[i] = i + 1; 
	}

	if (a[1] && a[m])
	{
		if (a[1] != a[m])
			invalid(); 
	}
	else if (a[1] || a[m])
		a[1] = a[m] = a[1] + a[m]; 
	else
	{
		// if (!rest.empty())
			// a[1] = a[m] = getnew(); 
	}

	same_init(); 
	solve(1, m, 0); 

	puts("yes"); 
	for (int i = 1; i <= m; ++i)
		putint(a[i]), putchar(" \n"[i == m]); 	

	return 0; 
}