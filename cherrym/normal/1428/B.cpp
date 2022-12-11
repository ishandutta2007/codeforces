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

const int N = 3e5 + 5;

int n;
char s[N];

void work()
{
	read(n); scanf("%s", s);
	bool flag0 = 1, flag1 = 1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '<') flag0 = 0; if (s[i] == '>') flag1 = 0;
	}
	if (flag0 || flag1) return (void) printf("%d\n", n);
	int res = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '-' || s[(i - 1 + n) % n] == '-') res++;
	printf("%d\n", res);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}