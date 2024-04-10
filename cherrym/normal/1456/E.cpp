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

const int N = 55;
const ll INF = 1e18;

int n, k, w[N][N];
ll c[N], f[N][N][N][4][4];
std::vector<int> fa[N][N];
std::vector<bool> is[N][N];
std::vector<ll> a[N][N];

void orz(ll l, ll r, ll s, ll e, int i, int j, int f)
{
	if (e < l || s > r) return;
	a[i][j].push_back(l); fa[i][j].push_back(f); w[i][j]++;
	if (s <= l && r <= e) return (void) is[i][j].push_back(1);
	else is[i][j].push_back(0);
	ll mid = l + r >> 1; int tmp = w[i][j] - 1;
	orz(l, mid, s, e, i, j - 1, tmp);
	orz(mid + 1, r, s, e, i, j - 1, tmp);
}

ll dp(int l, int r, int num, int x, int y)
{
	if (num == k && l > r) return 0;
	if (f[l][r][num][x][y] != -1) return f[l][r][num][x][y];
	ll res = num < k ? dp(l, r, num + 1,
		fa[l - 1][num][x], fa[r + 1][num][y]) : INF;
	if (res < INF && l > 1 && r < n && ((a[l - 1][num][x] >> num) & 1)
		!= ((a[r + 1][num][y] >> num) & 1)) res += c[num];
	for (int i = l; i <= r; i++) for (int j = 0; j < w[i][num]; j++)
	{
		if (!is[i][num][j]) continue;
		ll lc = dp(l, i - 1, num, x, j), rc = dp(i + 1, r, num, j, y);
		if (lc + rc < res) res = lc + rc;
	}
	return f[l][r][num][x][y] = res;
}

int main()
{
	ll l, r;
	read(n); read(k);
	for (int i = 0; i <= k; i++) fa[0][i].push_back(0),
		fa[n + 1][i].push_back(0);
	for (int i = 1; i <= n; i++) read(l), read(r),
		orz(0, (1ll << k) - 1, l, r, i, k, 0);
	for (int i = 0; i < k; i++) read(c[i]);
	memset(f, -1, sizeof(f));
	return std::cout << dp(1, n, 0, 0, 0) << std::endl, 0;
}