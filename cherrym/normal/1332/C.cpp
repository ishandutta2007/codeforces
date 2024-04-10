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

int n, k, cnt[N][26], ans;
char s[N];

void work()
{
	read(n); read(k); ans = n;
	scanf("%s", s + 1);
	for (int i = 1; i <= k; i++) memset(cnt[i], 0, sizeof(cnt[i]));
	for (int i = 1; i <= n; i++)
	{
		int len = (i - 1) % k + 1;
		if (k - len + 1 < len) len = k - len + 1;
		cnt[len][s[i] - 'a']++;
	}
	for (int i = 1; i <= (k + 1 >> 1); i++)
	{
		int d = 0;
		for (int c = 0; c < 26; c++) d = std::max(d, cnt[i][c]);
		ans -= d;
	}
	printf("%d\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}