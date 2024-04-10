#include <bits/stdc++.h>

const int N = 1e6 + 5, djq = 1e9 + 7;

int n, a[N], f[N], ans, nxt[N], top, stk[N], pre[N], sum[N], endc;
char s[N];

int main()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	int lst = n + 1;
	while (s[n - endc] == '0') endc++;
	if (endc == n) return std::cout << n << std::endl, 0;
	for (int i = 1; i <= n; i++) a[i] = s[i] == '1' ? 0 : a[i - 1] + 1;
	for (int i = n; i >= 0; i--)
		if (nxt[i] = lst, s[i] == '1') lst = i;
	f[0] = sum[0] = 1; stk[top = 0] = -1;
	for (int i = 1; i <= n; i++)
	{
		while (top && a[stk[top]] < a[i]) top--;
		pre[i] = stk[top]; stk[++top] = i;
	}
	for (int i = 0; i <= n; i++)
	{
		if (i) sum[i] = sum[i - 1];
		if (s[i] == '0')
		{
			f[i] = sum[i];
			if (pre[i] >= 0) f[i] = (f[i] - sum[pre[i]] + djq) % djq;
			else if (a[i] < i) f[i] = (f[i] + djq - 1) % djq;
		}
		else if (i) sum[i] = (sum[i] + f[i]) % djq;
		f[nxt[i]] = (f[nxt[i]] + f[i]) % djq;
	}
	for (int i = 1; i <= n; i++) if (s[i] == '1')
		ans = (1ll * (endc + 1) * f[i] + ans) % djq;
	return std::cout << ans << std::endl, 0;
}