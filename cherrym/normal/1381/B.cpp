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

const int N = 2005, M = N << 1;

int n, p[M], m, a[M];
std::bitset<M> f;

void work()
{
	read(n); m = 0;
	for (int i = 1; i <= (n << 1); i++) read(p[i]);
	for (int i = 1, mx = 0; i <= (n << 1); i++)
		if (p[i] > mx) mx = p[i], a[++m] = 1;
		else a[m]++;
	f.reset(); f[0] = 1;
	for (int i = 1; i <= m; i++) f |= f << a[i];
	puts(f[n] ? "YES" : "NO");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}