#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 3 * 110000;

int p[MAXN], sa[MAXN];
int n, q;

struct Node {
	int l, r;
	int sum;
	void modify(int L, int R) {
		l = L; r = R;
	}
	friend Node operator +(Node a, Node b) {
		Node c;
		c.modify(a.l, b.r);
		c.sum = a.sum + b.sum;
		if (sa[a.r] < sa[b.l])
			c.sum--;
		return c;
	} 
}T[MAXN * 4];

void build(int root, int l, int r) {
	T[root].modify(l, r);
	T[root].sum = 1;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(root * 2, l, mid);
	build(root * 2 + 1, mid + 1, r);
	T[root] = T[root * 2] + T[root * 2 + 1];
}

void change(int root, int pos) {
	if (T[root].l == T[root].r) {
		T[root].sum = 1;
		return ;
	}
	int mid = (T[root].l + T[root].r) / 2;
	if (pos > mid)
		change(root * 2 + 1, pos);
	else if (pos <= mid)
		change(root * 2, pos);
	T[root] = T[root * 2] + T[root * 2 + 1];
}


Node ask(int root, int l, int r) {
	if (l <= T[root].l && T[root].r <= r) {
		return T[root];
	}
	int mid = (T[root].l + T[root].r) / 2;
	if (l > mid)
		return ask(root * 2 + 1, l, r);
	else if (r <= mid)
		return ask(root * 2, l, r);
	else
		return (ask(root * 2, l, r) + ask(root * 2 + 1, l, r));
}

int brute(int l, int r) {
	int res = 0;
	for(int i = l + 1; i <= r; i++)
		if (sa[i] < sa[i - 1])
			res++;
	return res + 1;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		sa[p[i]] = i;
	}
	build(1, 1, n);
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		int type, x, y;
		scanf("%d %d %d", &type, &x, &y);
		if (type == 1) {
			//if (brute(x, y) != ask(1, x, y).sum)
			//	printf("WA\n");
			printf("%d\n", ask(1, x, y).sum);
		} else {
			int xid = p[x], yid = p[y];
			swap(sa[xid], sa[yid]);
			swap(p[x], p[y]);
			change(1, xid);
			change(1, yid);
		}
	}
	return 0;
}