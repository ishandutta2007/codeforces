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
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 2e5 + 5, M = N << 2, E = 20;

int n, q, a[N], top, stk[N], pre0[N], pre1[N], nxt0[N], nxt1[N], pre[N], nxt[N],
lt[N], mx[M], rmin[N][E], rmax[N][E], Log[N], ml[N], mr[N], l0[N], r0[N],
l1[N], r1[N];
std::vector<int> oz[N];

void change(int l, int r, int pos, int v, int p)
{
	mx[p] = Max(mx[p], v); if (l == r) return;
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, v, p2);
	else change(mid + 1, r, pos, v, p3);
}

int query(int l, int r, int x, int p)
{
	if (l == r) return mx[p];
	int mid = l + r >> 1;
	if (x <= mid) return query(l, mid, x, p2);
	else return Max(mx[p2], query(mid + 1, r, x, p3));
}

int qmin(int l, int r)
{
	int k = Log[r - l + 1];
	return a[rmin[l][k]] < a[rmin[r - (1 << k) + 1][k]]
		? rmin[l][k] : rmin[r - (1 << k) + 1][k];
}

int qmax(int l, int r)
{
	int k = Log[r - l + 1];
	return a[rmax[l][k]] > a[rmax[r - (1 << k) + 1][k]]
		? rmax[l][k] : rmax[r - (1 << k) + 1][k];
}

int main()
{
	int l, r;
	read(n); read(q);
	for (int i = 1; i <= n; i++) read(a[i]), rmin[i][0] = rmax[i][0] = i;
	Log[0] = -1;
	for (int i = 1; i <= n; i++) Log[i] = Log[i >> 1] + 1;
	for (int j = 1; j <= 17; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			rmin[i][j] = a[rmin[i][j - 1]] < a[rmin[i + (1 << j - 1)][j - 1]]
				? rmin[i][j - 1] : rmin[i + (1 << j - 1)][j - 1];
			rmax[i][j] = a[rmax[i][j - 1]] > a[rmax[i + (1 << j - 1)][j - 1]]
				? rmax[i][j - 1] : rmax[i + (1 << j - 1)][j - 1];
		}
	stk[top = 0] = 0;
	for (int i = 1; i <= n; i++)
	{
		while (top && a[stk[top]] >= a[i]) top--;
		pre0[i] = stk[top]; stk[++top] = i;
	}
	stk[top = 0] = 0;
	for (int i = 1; i <= n; i++)
	{
		while (top && a[stk[top]] <= a[i]) top--;
		pre1[i] = stk[top]; stk[++top] = i;
	}
	stk[top = 0] = n + 1;
	for (int i = n; i >= 1; i--)
	{
		while (top && a[stk[top]] >= a[i]) top--;
		nxt0[i] = stk[top]; stk[++top] = i;
	}
	stk[top = 0] = n + 1;
	for (int i = n; i >= 1; i--)
	{
		while (top && a[stk[top]] <= a[i]) top--;
		nxt1[i] = stk[top]; stk[++top] = i;
	}
	for (int i = 1; i <= n; i++) pre[i] = std::min(pre0[i], pre1[i]),
		nxt[i] = std::max(nxt0[i], nxt1[i]), oz[pre[i]].push_back(i);
	for (int i = 1; i <= n; i++)
	{
		if (nxt[i] <= n) change(1, n, nxt[i], i, 1);
		for (int j = 0; j < oz[i].size(); j++)
			lt[oz[i][j]] = query(1, n, oz[i][j], 1);
	}
	for (int i = 1; i <= n; i++)
	{
		ml[i] = ml[i - 1]; mr[i] = mr[i - 1];
		if (lt[i] > ml[i]) ml[i] = lt[i], mr[i] = i;
	}
	memset(mx, 0, sizeof(mx)); memset(lt, 0, sizeof(lt));
	for (int i = 1; i <= n; i++) oz[i].clear();
	for (int i = 1; i <= n; i++) oz[pre0[i]].push_back(i);
	for (int i = 1; i <= n; i++)
	{
		if (nxt0[i] <= n) change(1, n, nxt0[i], i, 1);
		for (int j = 0; j < oz[i].size(); j++)
			lt[oz[i][j]] = query(1, n, oz[i][j], 1);
	}
	for (int i = 1; i <= n; i++)
	{
		l0[i] = l0[i - 1]; r0[i] = r0[i - 1];
		if (lt[i] > l0[i]) l0[i] = lt[i], r0[i] = i;
	}
	memset(mx, 0, sizeof(mx)); memset(lt, 0, sizeof(lt));
	for (int i = 1; i <= n; i++) oz[i].clear();
	for (int i = 1; i <= n; i++) oz[pre1[i]].push_back(i);
	for (int i = 1; i <= n; i++)
	{
		if (nxt1[i] <= n) change(1, n, nxt1[i], i, 1);
		for (int j = 0; j < oz[i].size(); j++)
			lt[oz[i][j]] = query(1, n, oz[i][j], 1);
	}
	for (int i = 1; i <= n; i++)
	{
		l1[i] = l1[i - 1]; r1[i] = r1[i - 1];
		if (lt[i] > l1[i]) l1[i] = lt[i], r1[i] = i;
	}
	while (q--)
	{
		read(l); read(r);
		if (ml[r] >= l)
		{
			puts("4"); int x = qmin(ml[r], mr[r]), y = qmax(ml[r], mr[r]);
			if (x > y) std::swap(x, y);
			printf("%d %d %d %d\n", ml[r], x, y, mr[r]);
		}
		else if (l0[r] >= l)
			puts("3"), printf("%d %d %d\n", l0[r], qmin(l0[r], r0[r]), r0[r]);
		else if (l1[r] >= l)
			puts("3"), printf("%d %d %d\n", l1[r], qmax(l1[r], r1[r]), r1[r]);
		else puts("0");
	}
	return 0;
}