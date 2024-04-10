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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 1e5 + 5;

int n, a[N], ans = 20050131;

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	if (n > 64) return puts("1"), 0;
	for (int i = 1; i <= n; i++) a[i] ^= a[i - 1];
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			for (int k = i + 1; k <= n; k++)
				if ((a[i] ^ a[j]) > (a[k] ^ a[i]))
					ans = Min(ans, k - j);
	return std::cout << (ans == 20050131 ? -1 : ans - 2) << std::endl, 0;
}