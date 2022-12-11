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

typedef long long ll;

ll a, b, n;

void work()
{
	read(a); read(b); read(n);
	int res = 0;
	while (a <= n && b <= n)
	{
		if (a > b) std::swap(a, b);
		a += b; res++;
	}
	printf("%d\n", res);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}