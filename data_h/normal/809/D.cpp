#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int N = 3e5 + 7;

int n;

struct Node {
	int fit;
	Node *l, *r;
	int val, lazy, sz;
	Node(int v = 0) {
		fit = rand();
		lazy = 0;
		l = r = NULL;
		val = v;
		sz = 1;
	}
	void update() {
		sz = 1;
		if (l != NULL) sz += l->sz;
		if (r != NULL) sz += r->sz;
	}
}pool[N << 1];
int used = 0;

void add(Node* x, int v) {
	if (x == NULL) return ;
	x->val += v;
	x->lazy += v;
}

void down(Node* x) {
	if (x->lazy > 0) {
		add(x->l, x->lazy);
		add(x->r, x->lazy);
		x->lazy = 0;
	}
}

Node* merge(Node* x, Node* y);

pair<Node*, Node*> split_size(Node* x, int m) {
	if (x == NULL) return {NULL, NULL};
	down(x);
	int lsz = (x->l == NULL ? 0 : x->l->sz);
	if (lsz >= m) {
		auto tmp = split_size(x->l, m);
		x->l = NULL; x->update();
		return {tmp.first, merge(tmp.second, x)};
	} else {
		auto tmp = split_size(x->r, m - lsz - 1);
		x->r = NULL; x->update();
		return {merge(x, tmp.first), tmp.second};
	}
}


pair<Node*, Node*> split_key(Node* x, int val) {
	if (x == NULL) return {NULL, NULL};
	down(x);
	if (x->val > val) {
		auto tmp = split_key(x->l, val);
		x->l = NULL; x->update();
		return {tmp.first, merge(tmp.second, x)};
	} else {
		auto tmp = split_key(x->r, val);
		x->r = NULL; x->update();
		return {merge(x, tmp.first), tmp.second};
	}
}

Node* merge(Node* x, Node* y) {
    if (x == NULL) return y;
	if (y == NULL) return x;
	if (x->fit < y->fit) {
		down(x);
		x->r = merge(x->r, y);
		x->update();
		return x;
	} else {
		down(y);
		y->l = merge(x, y->l);
		y->update();
		return y;
	}
}

int ans;

void dfs(Node *x, int w) {
	if (x == NULL) return ;
	int lsz = (x->l == NULL ? 0 : x->l->sz);
	if (x->val < INF) {
		ans = max(ans, w + 1 + lsz);
	}
	dfs(x->l, w);
	dfs(x->r, w + 1 + lsz);
}

void show(Node *root) {
	if (root == NULL) return ;
	down(root);
	show(root->l);
	printf("%d %d\n", root->val, root->sz);
	show(root->r);
}

int main() {
	scanf("%d", &n);
	Node* root = NULL;
	for (int i = 0; i < n; i++) {
		Node* t = new(pool + used++) Node(INF);
		root = merge(root, t);
		int l, r;
		scanf("%d %d", &l, &r);
		auto tmp = split_key(root, l - 1);
		auto tmp2 = split_key(tmp.second, r - 1);
		auto a = tmp.first, b = tmp2.first, c = tmp2.second;
		a = merge(a, new(pool + used++) Node(l));
		if (b != NULL) add(b, 1);
		c = split_size(c, 1).second;
		root = merge(a, merge(b, c));
		// show(root);
		// puts("");
	}
	ans = 0;
	dfs(root, 0);
	cout << ans << endl;
	return 0;
}