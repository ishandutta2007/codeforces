#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

int n;

void work()
{
	read(n);
	if (n & 1)
	{
		putchar('7');
		for (int i = 1; i <= (n - 2 >> 1); i++) putchar('1');
	}
	else for (int i = 1; i <= (n >> 1); i++) putchar('1');
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}