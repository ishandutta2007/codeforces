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

const int N = 2e5 + 5;

int n, a[N], b[N], cnt[20];
ll ans;

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		for (int T = 19; T >= 0; T--)
			if ((a[i] >> T) & 1) cnt[T]++;
	}
	for (int T = 19; T >= 0; T--)
		for (int i = n - cnt[T] + 1; i <= n; i++)
			b[i] |= 1 << T;
	for (int i = 1; i <= n; i++) ans += 1ll * b[i] * b[i];
	return std::cout << ans << std::endl, 0;
}