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
	{
		putchar('-'); 
		x = ~x + 1; 
	}
	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

typedef long long s64; 

const int MaxN = 5e5 + 5; 

struct node
{
	int t, a, b; 
	node(){}
	node(int x, int y, int z):
		t(x), a(y), b(z) {}
	inline void scan()
	{
		read(t), read(a), read(b); 
	}
	inline bool operator < (const node &rhs) const
	{
		return t < rhs.t; 
	}
}p[MaxN]; 

int n, m, c0, c; 

inline s64 solve()
{
	std::map<int, int> map_cnt; 
	map_cnt.clear(); 

	read(n), read(m), read(c), read(c0); 
	for (int i = 1; i <= n; ++i)
		p[i].scan(); 
	p[++n] = node(m, 0, 0); 

	std::sort(p + 1, p + n + 1); 

	#define x first
	#define y second

	map_cnt[0] = c0; 
	s64 ans = 0, sum = c0; 
	for (int i = 1; i <= n; ++i)
	{
		int need = p[i].t - p[i - 1].t; 

	//	printf("%d: %d\n", i, need); 
		while (!map_cnt.empty() && need)
		{
			if (map_cnt.begin()->y <= need)
			{
				sum -= map_cnt.begin()->y; 
				need -= map_cnt.begin()->y; 
				ans += 1LL * map_cnt.begin()->x * map_cnt.begin()->y; 

				map_cnt.erase(map_cnt.begin()); 
			}
			else
			{
				ans += 1LL * map_cnt.begin()->x * need; 
				sum -= need; 
				map_cnt.begin()->y -= need; 
				need = 0; 
			}
		}

		if (need)
			return -1; 

		map_cnt[p[i].b] += p[i].a; 
		sum += p[i].a; 

		while (!map_cnt.empty() && sum > c)
		{
			int del = sum - c; 
			if (map_cnt.rbegin()->y <= del)
			{
				sum -= map_cnt.rbegin()->y; 
				map_cnt.erase(--map_cnt.end()); 
			}
			else
			{
				sum -= del; 
				map_cnt.rbegin()->y -= del; 
			}
		}
	}

	return ans; 

	#undef x
	#undef y
}

int main()
{
	int T; 
	read(T); 
	while (T--)
		putint(solve()), putchar('\n'); 
	return 0; 
}