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
		x = ~x + 1; 
		putchar('-'); 
	}

	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline void tense(T &x, const T &y)
{
	if (x > y)
		x = y; 
}

const int MaxN = 2e5 + 5; 
const int INF = 0x3f3f3f3f; 

int n; 
char s[MaxN], t[MaxN]; 

int pos1[MaxN], pos2[MaxN]; 

int anscnt; 
int ans[MaxN * 20][2]; 

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	read(n); 
	scanf("%s%s", s + 1, t + 1); 

	for (int i = 1; i <= n; ++i)
	{
		int a = s[i] - 'a', b = t[i] - 'a'; 
		if (a == 0 && b == 1)
			pos1[++pos1[0]] = i; 
		else if (a != b)
			pos2[++pos2[0]] = i; 
	}

	while (pos1[0] > 1)
	{
		++anscnt; 
		ans[anscnt][0] = pos1[pos1[0]--]; 
		ans[anscnt][1] = pos1[pos1[0]--]; 
	}

	while (pos2[0] > 1)
	{
		++anscnt; 
		ans[anscnt][0] = pos2[pos2[0]--]; 
		ans[anscnt][1] = pos2[pos2[0]--]; 
	}

	if (pos1[0] && pos2[0])
	{
		++anscnt; 
		ans[anscnt][0] = pos1[pos1[0]]; 
		ans[anscnt][1] = pos1[pos1[0]]; 
		++anscnt; 
		ans[anscnt][0] = pos1[pos1[0]--]; 
		ans[anscnt][1] = pos2[pos2[0]--]; 
	}
	else if (pos1[0] + pos2[0])
		return puts("-1"), 0; 

	putint(anscnt), putchar('\n'); 
	for (int i = 1; i <= anscnt; ++i)
	{
		putint(ans[i][0]), putchar(' '); 
		putint(ans[i][1]), putchar('\n'); 
	}

	return 0; 
}