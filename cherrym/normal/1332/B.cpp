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

const int N = 1005;

int n, a[N], minp[N], to[N];

int main()
{
	int T; read(T);
	for (int i = 4; i <= 1000; i++)
		for (int j = 2; j <= i; j++)
			if (i % j == 0) {minp[i] = j; break;}
	while (T--)
	{
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]), to[i] = minp[a[i]];
		std::sort(to + 1, to + n + 1);
		int m = std::unique(to + 1, to + n + 1) - to - 1;
		printf("%d\n", m);
		for (int i = 1; i <= n; i++)
			printf("%d ", std::lower_bound(to + 1, to + m + 1, minp[a[i]]) - to);
		puts("");
	}
	return 0;
}