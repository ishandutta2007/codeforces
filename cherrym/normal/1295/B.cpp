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

int n, x;
char s[N];

void work()
{
	read(n); read(x);
	scanf("%s", s + 1);
	int now = 0, sum = 0, ans = 0;
	for (int i = 1; i <= n; i++) if (s[i] == '0') sum++; else sum--;
	for (int i = 1; i <= n; i++)
	{
		if (sum == 0 && now == x) return (void) puts("-1");
		if (sum)
		{
			int tmp = (x - now) / sum;
			if (tmp >= 0 && 1ll * sum * tmp + now == x) ans++;
		}
		if (s[i] == '0') now++; else now--;
	}
	printf("%d\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}