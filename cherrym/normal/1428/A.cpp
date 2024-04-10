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

int Abs(int x) {return x < 0 ? -x : x;}

void work()
{
	int sx, sy, tx, ty;
	read(sx); read(sy); read(tx); read(ty);
	int ans = Abs(sx - tx) + Abs(sy - ty);
	if (sx != tx && sy != ty) ans += 2;
	printf("%d\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}