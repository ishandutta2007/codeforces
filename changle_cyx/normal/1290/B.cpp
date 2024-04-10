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
	static char buf[45], *tail = buf; 
	if (!x)
		putchar('0'); 
	else
	{
		if (x < 0)
			putchar('-'), x = ~x + 1; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y)
{
	return y < x ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

using std::min; 
using std::max; 
using std::pair; 
using std::cin; 
using std::cout; 
using std::vector; 
typedef long long s64; 
typedef long double ld; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 2e5 + 5; 

int n; 
char s[MaxN]; 
int cnt[MaxN][26]; 

int lst[MaxN][26], nxt[MaxN][26]; 

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	scanf("%s", s + 1); 
	n = strlen(s + 1); 

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			lst[i][j] = lst[i - 1][j]; 
			cnt[i][j] = cnt[i - 1][j]; 
		}
		++cnt[i][s[i] - 'a']; 
		lst[i][s[i] - 'a'] = i; 
	}

	for (int i = n; i >= 1; --i)
	{
		for (int j = 0; j < 26; ++j)
			nxt[i][j] = nxt[i + 1][j]; 
		nxt[i][s[i] - 'a'] = i; 
	}

	int Q; 
	read(Q); 
	while (Q--)
	{
		int l, r; 
		read(l), read(r); 

		static int c[26]; 

		bool flg = false; 
		int kind = 0; 
		for (int i = 0; i < 26; ++i)
		{
			c[i] = cnt[r][i] - cnt[l - 1][i]; 
			if (c[i] == r - l + 1)
				flg = true; 
			kind += c[i] > 0; 
		}

		char fir = s[l]; 
		if (l == r)
		{
			puts("Yes"); 
			continue; 
		}

		if (flg)
		{
			puts("No"); 
			continue; 
		}

		if (s[r] != fir)
			puts("Yes"); 
		else
		{
			// bool flg = false; 
			// for (int i = 0; i < 26; ++i)
			// for (int j = 0; j < 26; ++j)
			// 	if (nxt[l][i] && lst[r][j])
			// 		if (nxt[l][i] > lst[r][j])
			// 		{
			// 			flg = true; 
			// 			break; 
			// 		}
			puts(kind > 2 ? "Yes" : "No"); 
		}
	}

	return 0; 
}