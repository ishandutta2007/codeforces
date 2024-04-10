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

const int N = 1e5 + 5, INF = 0x3f3f3f3f;

int n, p, k, x, y, sum[N];
char s[N];

void work()
{
	read(n); read(p); read(k);
	scanf("%s", s + 1); read(x); read(y);
	int ans = INF;
	for (int i = n; i >= 1; i--)
		sum[i] = s[i] == '0', sum[i] += i + k <= n ? sum[i + k] : 0;
	for (int i = 0; i <= n - p; i++)
		ans = Min(ans, y * i + x * sum[i + p]);
	printf("%d\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}