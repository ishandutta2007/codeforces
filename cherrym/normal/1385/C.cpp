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

const int N = 2e5 + 5;

int n, a[N], ri[N];
bool is[N];

void work()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = n; i >= 1; i--) is[i] = i == n || (is[i + 1] && a[i] >= a[i + 1]);
	for (int i = n; i >= 1; i--) ri[i] = i == n || a[i] > a[i + 1] ?
		i : ri[i + 1];
	for (int i = 1; i <= n; i++) if (is[ri[i]]) return
		(void) printf("%d\n", i - 1);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}