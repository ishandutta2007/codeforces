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

int n, a[N], cnt[N];

void work()
{
	int ans = 0;
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), cnt[i] = 0;
	cnt[a[1]]++; cnt[a[n]]++;
	for (int i = 1; i < n; i++) if (a[i] == a[i + 1]) cnt[a[i]] += 2, ans++;
	int mx = 0, id = -1;
	for (int i = 1; i <= n; i++) if (cnt[i] > mx) mx = cnt[i], id = i;
	if (mx <= ans + 2) return (void) printf("%d\n", ans);
	for (int i = 1; i < n; i++)
		if (a[i] != id && a[i + 1] != id && a[i] != a[i + 1])
		{
			ans++;
			if (mx <= ans + 2) return (void) printf("%d\n", ans);
		}
	puts("-1");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}