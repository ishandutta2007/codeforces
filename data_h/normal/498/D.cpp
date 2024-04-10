#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 111111;

struct Node {
	Node() {

	}
	int go[60];
	friend inline Node operator +(const Node &a, const Node &b) {
		Node c;
		for(int i = 0; i < 60; i++) {
			c.go[i] = a.go[i] + b.go[(i + a.go[i]) % 60];
		}
		return c;
	}
	void init(int v) {
		for(int i = 0; i < 60; i++) {
			go[i] = 1 + (i % v == 0);
		}
	}
};

int n;
Node tree[N << 1];
char buffer[N];
int period[N];

int getID(int l, int r) {
	return l + r | (l != r);
}

void build(int l, int r) {
	int x = getID(l, r);
	if (l == r) {
		tree[x].init(period[l]);
	} else {
		int mid = (l + r) >> 1;
		build(l, mid);
		build(mid + 1, r);
		tree[x] = tree[getID(l, mid)] + tree[getID(mid + 1, r)];
	}
}

void modify(int l, int r, int p, int v) {
	int x = getID(l, r);
	if (l == r) {
		tree[x].init(v);
		period[l] = v;
		return ;
	}
	int mid = (l + r) >> 1;
	if (p <= mid) {
		modify(l, mid, p, v);
	} else {
		modify(mid + 1, r, p, v);
	}
	tree[x] = tree[getID(l, mid)] + tree[getID(mid + 1, r)];
}

Node getNode(int l, int r, int ql, int qr) {
	int x = getID(l, r);
	if (ql <= l && r <= qr) {
		//printf("sector %d %d\n", l, r);
		return tree[x];
	}
	int mid = (l + r) >> 1;
	if (qr <= mid) {
		return getNode(l, mid, ql, qr);
	} else if (ql > mid) {
		return getNode(mid + 1, r, ql, qr);
	} else {
		return getNode(l, mid, ql, qr) + getNode(mid + 1, r, ql, qr);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &period[i]);
	}
	///period[10] = 6;
	build(1, n);

	//printf("%d\n", getNode(1, n, 9, 10).go[10]);
	int queries;
	scanf("%d", &queries);
	while(queries--) {
		int a, b;
		scanf("%s %d %d", buffer, &a, &b);
		if (buffer[0] == 'A') {
			printf("%d\n", getNode(1, n, a, b - 1).go[0]);
		} else {
			modify(1, n, a, b);
		}
	}
	return 0;
}