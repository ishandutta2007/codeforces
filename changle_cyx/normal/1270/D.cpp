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

typedef long long s64; 
typedef long double ld; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

int main()
{
	int n, K; 
	read(n), read(K); 

	printf("? "); 
	for (int i = 1; i <= K; ++i)
		putint(i), putchar(' '); 
	puts(""); 
	fflush(stdout); 

	int mpos, mval; 
	read(mpos), read(mval); 

	printf("? "); 
	for (int i = 1; i <= K; ++i)
		if (i != mpos)
			putint(i), putchar(' '); 
	printf("%d\n", K + 1); 
	fflush(stdout); 

	int lespos, lesval; 
	read(lespos), read(lesval); 

	int m = 1; 
	for (int p = 1; p <= K; ++p)
		if (p != mpos)
		{
			printf("? "); 
			for (int i = 1; i <= K; ++i)
				if (i != p && i != mpos)
					printf("%d ", i); 
			printf("%d %d\n", mpos, K + 1); 

			fflush(stdout); 
			int curpos, curval; 
			read(curpos), read(curval); 

			if (lesval < mval)
			{
				if (curpos == mpos)
					++m; 
			}
			else
			{
				if (curpos != mpos)
					++m; 
			}
		}

	printf("! %d\n", m); 

	return 0; 
}