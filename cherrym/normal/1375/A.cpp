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

const int N = 100;

int n, a[N];

void work()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]); if (a[i] < 0) a[i] = -a[i];
		if (!(i & 1)) a[i] = -a[i];
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}