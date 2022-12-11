#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

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

typedef long long ll;

const int N = 2e5 + 5, M = N << 2;

int n, p[N], a[N];
ll add[M], mx[M], ans = 1e18;

void down(int p)
{
	add[p2] += add[p]; mx[p2] += add[p];
	add[p3] += add[p]; mx[p3] += add[p];
	add[p] = 0;
}

void change(int l, int r, int s, int e, ll v, int p)
{
	if (e < l || s > r) return;
	if (s <= l && r <= e) return (void) (add[p] += v, mx[p] += v);
	int mid = l + r >> 1; down(p);
	change(l, mid, s, e, v, p2);
	change(mid + 1, r, s, e, v, p3);
	mx[p] = Min(mx[p2], mx[p3]);
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(p[i]);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) change(0, n, p[i], n, a[i], 1);
	for (int i = 1; i < n; i++)
	{
		change(0, n, p[i], n, -a[i], 1);
		change(0, n, 0, p[i] - 1, a[i], 1);
		ans = Min(ans, mx[1]);
	}
	return std::cout << ans << std::endl, 0;
}