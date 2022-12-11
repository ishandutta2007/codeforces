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

void work()
{
	int x, y, z, mx;
	read(x); read(y); read(z); mx = std::max(std::max(x, y), z);
	if (x == mx && y == mx) return (void) printf("YES\n%d %d %d\n", mx, z, z);
	if (x == mx && z == mx) return (void) printf("YES\n%d %d %d\n", y, mx, y);
	if (y == mx && z == mx) return (void) printf("YES\n%d %d %d\n", x, x, mx);
	puts("NO");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}