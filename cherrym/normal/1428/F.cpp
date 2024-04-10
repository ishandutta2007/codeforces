#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

typedef long long ll;

const int N = 5e5 + 5, M = N << 2;

int n, le[N], add[M], tag[M], lst[M];
char s[N];
ll sum[M], ans;

void addAdd(int l, int r, int p, int v)
{
	(tag[p] != -1 ? tag[p] : add[p]) += v;
	lst[p] += v; sum[p] += 1ll * (r - l + 1) * v;
}

void addTag(int l, int r, int p, int v)
{
	add[p] = 0; tag[p] = v;
	sum[p] = 1ll * (r - l + 1) * v; lst[p] = v;
}

void down(int l, int r, int mid, int p)
{
	if (tag[p] != -1) addTag(l, mid, p2, tag[p]), addTag(mid + 1, r, p3, tag[p]);
	else addAdd(l, mid, p2, add[p]), addAdd(mid + 1, r, p3, add[p]);
	add[p] = 0; tag[p] = -1;
}

void changeAdd(int l, int r, int s, int e, int v, int p)
{
	if (e < l || s > r) return;
	if (s <= l && r <= e) return addAdd(l, r, p, v);
	int mid = l + r >> 1; down(l, r, mid, p);
	changeAdd(l, mid, s, e, v, p2);
	changeAdd(mid + 1, r, s, e, v, p3);
	lst[p] = lst[p3]; sum[p] = sum[p2] + sum[p3];
}

void changeTag(int l, int r, int s, int e, int v, int p)
{
	if (e < l || s > r) return;
	if (s <= l && r <= e) return addTag(l, r, p, v);
	int mid = l + r >> 1; down(l, r, mid, p);
	changeTag(l, mid, s, e, v, p2);
	changeTag(mid + 1, r, s, e, v, p3);
	lst[p] = lst[p3]; sum[p] = sum[p2] + sum[p3];
}

int firs(int l, int r, int v, int p)
{
	if (l == r) return l;
	int mid = l + r >> 1; down(l, r, mid, p);
	if (lst[p2] <= v) return firs(l, mid, v, p2);
	else return firs(mid + 1, r, v, p3);
}

int main()
{
	std::cin >> n; scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) le[i] = s[i] == '1' ? le[i - 1] + 1 : 0;
	memset(tag, -1, sizeof(tag));
	for (int i = 1; i <= n; i++)
	{
		if (le[i])
		{
			int lk = firs(1, n, le[i] - 1, 1);
			changeTag(1, n, lk, i - le[i] + 1, le[i], 1);
			if (le[i] > 1) changeAdd(1, n, i - le[i] + 2, i, 1, 1);
		}
		ans += sum[1];
	}
	return std::cout << ans << std::endl, 0;
}