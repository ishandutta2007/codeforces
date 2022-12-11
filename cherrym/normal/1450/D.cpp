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

const int N = 3e5 + 5;

int n, a[N], L[N], R[N], cnt[N];
bool is[N], ans[N];

void work()
{
	read(n);
	for (int i = 1; i <= n; i++) is[i] = ans[i] = 0, cnt[i] = 0;
	for (int i = 1; i <= n; i++) read(a[i]), is[a[i]] = 1, cnt[a[i]]++;
	ans[n] = is[1]; ans[1] = 1;
	for (int i = 1; i <= n; i++) if (!is[i]) ans[1] = 0;
	for (int i = 1, l = 1, r = n; i < n; i++)
	{
		if (cnt[i] != 1 || (a[l] != i && a[r] != i)) break;
		ans[n - i] = 1; if (a[l] == i) l++; else r--;
		L[n - i] = l; R[n - i] = r;
	}
	for (int i = 2, cur = n + 1; i < n; i++)
		if (ans[i])
		{
			if (cur == n + 1)
				for (int j = L[i]; j <= R[i]; j++) cur = Min(cur, a[j]);
			else cur = Min(cur, Min(a[L[i]], a[R[i]]));
			if (cur != n - i + 1) ans[i] = 0;
		}
	for (int i = 1; i <= n; i++) printf("%d", ans[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}