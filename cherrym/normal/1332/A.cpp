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

int main()
{
	int T; read(T);
	while (T--)
	{
		int a, b, c, d, X, Y, xl, yl, xr, yr;
		read(a); read(b); read(c); read(d); read(X); read(Y); read(xl); read(yl);
		read(xr); read(yr);
		if (xl == xr && (a || b)) {puts("no"); continue;}
		if (yl == yr && (c || d)) {puts("no"); continue;}
		X += b - a; Y += d - c;
		puts(xl <= X && X <= xr && yl <= Y && Y <= yr ? "yes" : "no");
	}
	return 0;
}