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

const int N = 1e5 + 5;

int n, a[N], T;

void work()
{
	int sum = 0, cnt = 0;
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), sum ^= a[i];
	if (!sum) return (void) puts("DRAW");
	for (T = 30; !(sum >> T) & 1; T--);
	for (int i = 1; i <= n; i++) if ((a[i] >> T) & 1) cnt++;
	puts((n - cnt & 1) || !((cnt >> 1) & 1) ? "WIN" : "LOSE");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}