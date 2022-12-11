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

const int N = 1e6 + 5;

int n, top, stk[N];
ll h[N], cur, cnt, ans[N];
bool is[N];

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(h[i]);
	cur = h[1];
	for (int i = 2; i <= n; i++)
	{
		cur = h[i] - (h[i - 1] - cnt); cnt = 0;
		while (top && cur > 1)
			if (i - stk[top] + 1 <= cur) cur -= i - stk[top] + 1,
				cnt += i - stk[top], top--;
			else
			{
				stk[top] += cur - 1; cnt += cur - 1; cur = 1; break;
			}
		if (!top && (cnt += cur / i * (i - 1), cur %= i) > 1)
			stk[++top] = cur, cnt += cur - 1, cur = 1;
		if (!cur) stk[++top] = i;
	}
	for (int i = 1; i <= top; i++) is[stk[i]] = 1;
	ans[n] = h[n] - cnt;
	for (int i = n - 1; i >= 1; i--) ans[i] = ans[i + 1] - (!is[i + 1]);
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return puts(""), 0;
}