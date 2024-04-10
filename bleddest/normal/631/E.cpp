#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstdio>

using namespace std;

typedef long long li;
typedef pair<li, li> func;

#define x first
#define y second

li get(func f, int x)
{
	return f.x * x + f.y;
}

const li INF64 = li(1e18);
const int N = 200043;
func T[4 * N];

void build(int v, int l, int r)
{
	T[v] = { 0, -INF64 };
	if (l != r - 1)
	{
		int m = (l + r) / 2;
		build(v * 2 + 1, l, m);
		build(v * 2 + 2, m, r);
	}
}

li getMax(int v, int l, int r, int x)
{
	li cur = get(T[v], x);
	if (l != r - 1)
	{
		int m = (l + r) / 2;
		if (x < m)
			cur = max(cur, getMax(v * 2 + 1, l, m, x));
		else
			cur = max(cur, getMax(v * 2 + 2, m, r, x));
	}
	return cur;
}

void upd(int v, int l, int r, func f)
{
	int m = (l + r) / 2;
	if (get(f, m) > get(T[v], m))
		swap(T[v], f);
	if (l == r - 1)
		return;
	if (get(f, l) > get(T[v], l))
		upd(v * 2 + 1, l, m, f);
	else
		upd(v * 2 + 2, m, r, f);
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	li C = 0;
	for (int i = 1; i <= n; i++)
		C += i * 1ll * a[i];
	vector<li> p(n + 1);
	for (int i = 1; i <= n; i++)
		p[i] = p[i - 1] + a[i];
	build(0, 0, n + 1);
	li ans = C;
	for (int r = 1; r <= n; r++)
	{
		ans = max(ans, C - p[r] + getMax(0, 0, n + 1, r));
		upd(0, 0, n + 1, { a[r], p[r] - a[r] * 1ll * r });
	}
	build(0, 0, n + 1);
	for (int l = n; l >= 1; l--)
	{
		ans = max(ans, C - p[l - 1] + getMax(0, 0, n + 1, l));
		upd(0, 0, n + 1, {a[l], p[l - 1] - a[l] * 1ll * l});
	}
	printf("%lld\n", ans);
	return 0;
}