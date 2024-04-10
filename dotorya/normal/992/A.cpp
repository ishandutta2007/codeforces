class RBNode {
public:
	static const int RED = 0;
	static const int BLACK = 1;
	int key;
	int color;
	RBNode *left;
	RBNode *right;
	RBNode *p;
};

class RBTree {
public:
	RBNode *root;
	RBNode *nil;
	RBTree() {
		nil = new RBNode;
		nil->left = nil->right = nil->p = nil;
		nil->key = 0;
		nil->color = RBNode::BLACK;
		root = nil;
	}

	RBNode* search(int key);
	RBNode* minimum(RBNode* cur);
	RBNode* maximum(RBNode* cur);
	RBNode* successor(RBNode* cur);
	RBNode* predecessor(RBNode* cur);
	void left_rotate(RBNode* z);
	void right_rotate(RBNode* z);

	void insert_fixup(RBNode* z);
	bool insert(int key); // true if inserted, false if already exist -> not inserted

	void transplant(RBNode* u, RBNode* v);
	void erase_fixup(RBNode* z);
	bool erase(int key);
};

#include <limits.h>
#include <assert.h>

RBNode* RBTree::search(int key) {
	RBNode* n = root;
	while (n != nil) {
		if (n->key == key) return n;
		else if (n->key > key) n = n->left;
		else n = n->right;
	}
	return nil;
}

RBNode* RBTree::minimum(RBNode* n = NULL) {
	if (n == NULL) n = root;
	while (n->left != nil) n = n->left;
	return n;
}

RBNode* RBTree::maximum(RBNode* n = NULL) {
	if (n == NULL) n = root;
	while (n->right != nil) n = n->right;
	return n;
}

RBNode* RBTree::successor(RBNode* cur) {
	if (cur->right != nil) {
		cur = cur->right;
		while (cur->left != nil) cur = cur->left;
		return cur;
	}
	while (cur->p != nil) {
		if (cur->p->left == cur) return cur->p;
		cur = cur->p;
	}
	return nil;
}

RBNode* RBTree::predecessor(RBNode* cur) {
	if (cur->left != nil) {
		cur = cur->left;
		while (cur->right != nil) cur = cur->right;
		return cur;
	}
	while (cur->p != nil) {
		if (cur->p->right == cur) return cur->p;
		cur = cur->p;
	}
	return nil;
}

void RBTree::left_rotate(RBNode* x) {
	RBNode* y = x->right;
	assert(y != nil);

	x->right = y->left;
	if (y->left != nil) y->left->p = x;
	y->p = x->p;
	if (x->p == nil) root = y;
	else if (x->p->left == x) x->p->left = y;
	else x->p->right = y;
	y->left = x;
	x->p = y;
}
void RBTree::right_rotate(RBNode* x) {
	RBNode* y = x->left;
	assert(y != nil);

	x->left = y->right;
	if (y->right != nil) y->right->p = x;
	y->p = x->p;
	if (x->p == nil) root = y;
	else if (x->p->right == x) x->p->right = y;
	else x->p->left = y;
	y->right = x;
	x->p = y;
}
void RBTree::insert_fixup(RBNode* z) {
	while (z->p->color == RBNode::RED) {
		if (z->p == z->p->p->left) {
			RBNode* y = z->p->p->right;
			if (y->color == RBNode::RED) {
				z->p->color = RBNode::BLACK;
				y->color = RBNode::BLACK;
				z->p->p->color = RBNode::RED;
				z = z->p->p;
			}
			else {
				if (z == z->p->right) {
					z = z->p;
					left_rotate(z);
				}
				z->p->color = RBNode::BLACK;
				z->p->p->color = RBNode::RED;
				right_rotate(z->p->p);
			}
		}
		else {
			RBNode* y = z->p->p->left;
			if (y->color == RBNode::RED) {
				z->p->color = RBNode::BLACK;
				y->color = RBNode::BLACK;
				z->p->p->color = RBNode::RED;
				z = z->p->p;
			}
			else {
				if (z == z->p->left) {
					z = z->p;
					right_rotate(z);
				}
				z->p->color = RBNode::BLACK;
				z->p->p->color = RBNode::RED;
				left_rotate(z->p->p);
			}
		}
	}
	root->color = RBNode::BLACK;
}
bool RBTree::insert(int key) {
	RBNode* y = nil;
	RBNode* x = root;
	while (x != nil) {
		y = x;
		if (key == x->key) return false;
		if (key < x->key) x = x->left;
		else x = x->right;
	}

	RBNode* z = new RBNode();
	z->key = key;
	z->left = nil;
	z->right = nil;
	z->color = RBNode::RED;
	z->p = y;
	if (y == nil) root = z;
	else if (z->key < y->key) y->left = z;
	else y->right = z;
	RBTree::insert_fixup(z);
	return true;
}

void RBTree::transplant(RBNode* u, RBNode* v) {
	if (u->p == nil) root = v;
	else if (u->p->left == u) u->p->left = v;
	else u->p->right = v;
	v->p = u->p;
}

void RBTree::erase_fixup(RBNode* x) {
	while (x != root && x->color == RBNode::BLACK) {
		if (x == x->p->left) {
			RBNode* w = x->p->right;
			if (w->color == RBNode::RED) {
				w->color = RBNode::BLACK;
				x->p->color = RBNode::RED;
				left_rotate(x->p);
				w = x->p->right;
			}
			if (w->left->color == RBNode::BLACK && w->right->color == RBNode::BLACK) {
				w->color = RBNode::RED;
				x = x->p;
			}
			else {
				if (w->right->color == RBNode::BLACK) {
					w->left->color = RBNode::BLACK;
					w->color = RBNode::RED;
					right_rotate(w);
					w = x->p->right;
				}
				w->color = x->p->color;
				x->p->color = RBNode::BLACK;
				w->right->color = RBNode::BLACK;
				left_rotate(x->p);
				x = root;
			}
		}
		else {
			RBNode* w = x->p->left;
			if (w->color == RBNode::RED) {
				w->color = RBNode::BLACK;
				x->p->color = RBNode::RED;
				right_rotate(x->p);
				w = x->p->left;
			}
			if (w->left->color == RBNode::BLACK && w->right->color == RBNode::BLACK) {
				w->color = RBNode::RED;
				x = x->p;
			}
			else {
				if (w->left->color == RBNode::BLACK) {
					w->right->color = RBNode::BLACK;
					w->color = RBNode::RED;
					left_rotate(w);
					w = x->p->left;
				}
				w->color = x->p->color;
				x->p->color = RBNode::BLACK;
				w->left->color = RBNode::BLACK;
				right_rotate(x->p);
				x = root;
			}
		}
	}
	x->color = RBNode::BLACK;
}
bool RBTree::erase(int key) {
	RBNode* z = search(key);
	if (z == nil) return false;

	RBNode* y = z;
	RBNode* x;
	int y_original_color = y->color;
	if (z->left == nil) {
		x = z->right;
		transplant(z, z->right);
	}
	else if (z->right == nil) {
		x = z->left;
		transplant(z, z->left);
	}
	else {
		y = successor(z);
		y_original_color = y->color;
		x = y->right;
		if (y->p == z) x->p = y;
		else {
			transplant(y, y->right);
			y->right = z->right;
			y->right->p = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->p = y;
		y->color = z->color;
	}
	if (y_original_color == RBNode::BLACK)
		erase_fixup(x);

	delete z;
	return true;
}

#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	RBTree* tr = new RBTree();
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		if (t) tr->insert(t);
	}

	RBNode* v = tr->minimum(tr->root);

	int cnt = 0;
	while (v != tr->nil) {
		cnt++;
		v = tr->successor(v);
	}
	return !printf("%d\n", cnt);
}