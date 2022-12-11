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

const int N = 150005, M = N << 2, E = 6;

int n, q, p, a[N], tag[M], m;

struct elem
{
	int val[E], cnt[E];
	
	void addtag(int T, int c)
	{
		memset(val, -1, sizeof(val));
		val[1] = T; cnt[1] = c;
	}
	
	friend inline elem operator + (elem a, elem b)
	{
		for (int i = 1; i <= m; i++)
		{
			if (b.val[i] == -1) break;
			bool is = 0;
			for (int j = 1; j <= m; j++)
				if (b.val[i] == a.val[j]) {is = 1; a.cnt[j] += b.cnt[i]; break;}
			if (is) continue; int lst = 1;
			while (lst <= m && a.val[lst] != -1) lst++;
			if (lst <= m) {a.val[lst] = b.val[i]; a.cnt[lst] = b.cnt[i]; continue;}
			int mc = 1;
			for (int j = 1; j <= m; j++) if (a.cnt[j] < a.cnt[mc]) mc = j;
			if (b.cnt[i] < a.cnt[mc])
				for (int j = 1; j <= m; j++) a.cnt[j] -= b.cnt[i];
			else
			{
				int tmp = a.cnt[mc]; a.val[mc] = b.val[i]; a.cnt[mc] = b.cnt[i];
				for (int j = 1; j <= m; j++) a.cnt[j] -= tmp;
			}
		}
		return a;
	}
} T[M];

void build(int l, int r, int p)
{
	if (l == r) return T[p].addtag(a[l], 1);
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	T[p] = T[p2] + T[p3];
}

void down(int l, int r, int mid, int p)
{
	if (tag[p] != -1)
	{
		tag[p2] = tag[p]; tag[p3] = tag[p];
		T[p2].addtag(tag[p], mid - l + 1); T[p3].addtag(tag[p], r - mid);
		tag[p] = -1;
	}
}

void change(int l, int r, int s, int e, int v, int p)
{
	if (e < l || s > r) return;
	if (s <= l && r <= e) return tag[p] = v, T[p].addtag(v, r - l + 1);
	int mid = l + r >> 1; down(l, r, mid, p);
	change(l, mid, s, e, v, p2); change(mid + 1, r, s, e, v, p3);
	T[p] = T[p2] + T[p3];
}

elem ask(int l, int r, int s, int e, int p)
{
	if (l == s && r == e) return T[p];
	int mid = l + r >> 1; down(l, r, mid, p);
	if (e <= mid) return ask(l, mid, s, e, p2);
	else if (s > mid) return ask(mid + 1, r, s, e, p3);
	else return ask(l, mid, s, mid, p2) + ask(mid + 1, r, mid + 1, e, p3);
}

int main()
{
	int x, op, l, r, id;
	read(n); read(q); read(p); m = 100 / p;
	memset(tag, -1, sizeof(tag));
	for (int i = 1; i <= n; i++) read(a[i]);
	build(1, n, 1);
	while (q--)
	{
		read(op); read(l); read(r);
		if (op == 1) read(id), change(1, n, l, r, id, 1);
		else
		{
			elem res = ask(1, n, l, r, 1); int lst = 1;
			while (lst <= m && res.val[lst] != -1) lst++;
			printf("%d ", lst - 1);
			for (int i = 1; i < lst; i++) printf("%d ", res.val[i]);
			puts("");
		}
	}
	return 0;
}