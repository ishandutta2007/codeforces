#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int left;
	int right;
	int sum;
	int dirty;
}*NodePtr;
struct Node nodes[15000000];
int nodes_top = 1;
int allocNode() {
	return nodes_top++;
}
void pushUp(NodePtr node) {
	node->sum = nodes[node->left].sum + nodes[node->right].sum;
}
void setDirty(NodePtr node, int dirty, int l, int r) {
	node->dirty = dirty;
	node->sum = dirty == 1 ? 0 : r - l + 1;
}
void pushDown(NodePtr node, int l, int r) {
	if (node->dirty) {
		int m = (l + r) >> 1;
		setDirty(nodes + node->left, node->dirty, l, m);
		setDirty(nodes + node->right, node->dirty, m + 1, r);
		node->dirty = 0;
	}
}

void update(int f, int t, int l, int r, int dirty, NodePtr node) {
	if (f <= l && t >= r) {
		setDirty(node, dirty, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	if (node->left == 0) {
		node->left = allocNode();
		node->right = allocNode();
	}
	pushDown(node, l, r);
	if (mid >= f) {
		update(f, t, l, mid, dirty, nodes + node->left);
	}
	if (mid < t) {
		update(f, t, mid + 1, r, dirty, nodes + node->right);
	}
	pushUp(node);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\DataBase\\TESTCASE\\codeforces\\CF915E.in", "r",
	stdin);
#endif

	int n, q;
	scanf("%d %d", &n, &q);

	NodePtr root = nodes + allocNode();
	setDirty(root, 2, 1, n);

	int l, r, k;
	for (int i = 1; i <= q; i++) {
		scanf("%d %d %d", &l, &r, &k);
		update(l, r, 1, n, k, root);
		printf("%d ", root->sum);
	}
	fflush(stdout);
	return 0;
}