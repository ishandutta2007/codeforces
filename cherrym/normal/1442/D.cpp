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
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 3005, E = 16;

int n, k, t[N], top;
ll s[N], stk[E][N], f[N][N], ans;
std::vector<ll> a[N];

void xyz32768(int l, int r)
{
	if (l == r)
	{
		for (int i = 0; i <= k; i++) f[l][i] = stk[top][i];
		return;
	}
	int mid = l + r >> 1;
	top++;
	for (int i = 0; i <= k; i++) stk[top][i] = stk[top - 1][i];
	for (int i = mid + 1; i <= r; i++)
		for (int j = k; j >= t[i]; j--)
			stk[top][j] = Max(stk[top][j], stk[top][j - t[i]] + s[i]);
	xyz32768(l, mid); top--;
	top++;
	for (int i = 0; i <= k; i++) stk[top][i] = stk[top - 1][i];
	for (int i = l; i <= mid; i++)
		for (int j = k; j >= t[i]; j--)
			stk[top][j] = Max(stk[top][j], stk[top][j - t[i]] + s[i]);
	xyz32768(mid + 1, r); top--;
}

int main()
{
	int x;
	read(n); read(k);
	for (int i = 1; i <= n; i++)
	{
		read(t[i]); a[i].push_back(0);
		for (int j = 1; j <= t[i]; j++) read(x), a[i].push_back(x);
		for (int j = 1; j <= t[i]; j++) a[i][j] += a[i][j - 1];
		s[i] = a[i][t[i]];
	}
	xyz32768(1, n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k && j <= t[i]; j++)
			ans = Max(ans, f[i][k - j] + a[i][j]);
	return std::cout << ans << std::endl, 0;
}