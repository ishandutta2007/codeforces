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

typedef long long ll;

const int N = 2e5 + 5, M = N << 2;

int n, q, a[N], lst[M], tag[M];
ll sum[M];

void build(int l, int r, int p)
{
	if (l == r) return (void) (lst[p] = sum[p] = a[l]);
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	lst[p] = a[r]; sum[p] = sum[p2] + sum[p3];
}

void down(int l, int r, int mid, int p)
{
	if (tag[p] != -1)
	{
		tag[p2] = lst[p2] = tag[p]; sum[p2] = 1ll * (mid - l + 1) * tag[p];
		tag[p3] = lst[p3] = tag[p]; sum[p3] = 1ll * (r - mid) * tag[p];
		tag[p] = -1;
	}
}

int firs_les(int l, int r, int x, int p)
{
	if (l == r) return lst[p] <= x ? l : l + 1;
	int mid = l + r >> 1; down(l, r, mid, p);
	if (lst[p2] <= x) return firs_les(l, mid, x, p2);
	else return firs_les(mid + 1, r, x, p3);
}

ll ask(int l, int r, int x, int p)
{
	if (l == r) return x == l ? sum[p] : 0;
	int mid = l + r >> 1; down(l, r, mid, p);
	if (x <= mid) return ask(l, mid, x, p2);
	else return ask(mid + 1, r, x, p3) + sum[p2];
}

std::pair<ll, int> pres(int l, int r, ll x, int p)
{
	if (l == r) return sum[p] <= x ? std::make_pair(sum[p], l)
		: std::make_pair(0ll, l - 1);
	int mid = l + r >> 1; std::pair<ll, int> res; down(l, r, mid, p);
	if (sum[p2] <= x) return res = pres(mid + 1, r, x - sum[p2], p3),
		res.first += sum[p2], res;
	else return pres(l, mid, x, p2);
}

void change(int l, int r, int s, int e, int v, int p)
{
	if (e < l || s > r) return;
	if (s <= l && r <= e) return (void) (tag[p] = lst[p] = v,
		sum[p] = 1ll * (r - l + 1) * v);
	int mid = l + r >> 1; down(l, r, mid, p);
	change(l, mid, s, e, v, p2); change(mid + 1, r, s, e, v, p3);
	lst[p] = lst[p3]; sum[p] = sum[p2] + sum[p3];
}

int main()
{
	int op, x, y;
	read(n); read(q);
	for (int i = 1; i <= n; i++) read(a[i]);
	memset(tag, -1, sizeof(tag));
	build(1, n, 1);
	while (q--)
	{
		read(op); read(x); read(y);
		if (op == 2)
		{
			int res = 0;
			while (x <= n)
			{
				x = std::max(x, firs_les(1, n, y, 1));
				if (x > n) break; ll tmp = ask(1, n, x - 1, 1);
				std::pair<ll, int> nxt = pres(1, n, tmp + y, 1);
				res += nxt.second - x + 1; y -= nxt.first - tmp;
				x = nxt.second + 1;
			}
			printf("%d\n", res);
		}
		else
		{
			int tp = firs_les(1, n, y, 1);
			if (tp <= x) change(1, n, tp, x, y, 1);
		}
	}
	return 0;
}