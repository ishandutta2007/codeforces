#include <iostream>
#include <random>
#define null NULL

using namespace std;

mt19937 rnd(rand());

//!TREAP

template<class T>
class treap {
private:
	struct node {
		T key;
		int y, sz;
		node *l, *r;
		node(T _key): key(_key), y(rnd()), sz(1), l(null), r(null) {}
	};
	node *root;
	int sz(node *t) {
		if (t == null)
			return 0;
		else
			return t->sz;
	}
	void upd(node *t) {
		t->sz = 1;
		t->sz += sz(t->l);
		t->sz += sz(t->r);
	}
	void split(node *t, T x, node *&l, node *&r, bool right = true) {
		if (t == null) {
			l = null;
			r = null;
			return;
		}
		if (x < t->key || (x == t->key && right)) {
			split(t->l, x, l, t->l, right);
			r = t;
			upd(r);
		}
		else {
			split(t->r, x, t->r, r, right);
			l = t;
			upd(l);
		}
	}
	node* merge(node *l, node *r) {
		if (l == null) return r;
		if (r == null) return l;
		if (l->y < r->y) {
			l->r = merge(l->r, r);
			upd(l);
			return l;
		}
		else {
			r->l = merge(l, r->l);
			upd(r);
			return r;
		}
	}
public:
	void insert(T x) {
		node *tl, *tm, *tr;
		split(root, x, tl, tm);
		split(tm, x, tm, tr, false);
		if (tm == null)
			tm = new node(x);
		root = merge(merge(tl, tm), tr);
	}
	void erase(T x) {
		node *tl, *tm, *tr;
		split(root, x, tl, tm);
		split(tm, x, tm, tr, false);
		root = merge(tl, tr);
	}
	node* kth_pointer(int k) {
		node *pos = root;
		if (k > root->sz - 1)
			k = root->sz - 1;
		while (true) {
			if (k == sz(pos->l))
                break;
			if (k < sz(pos->l))
				pos = pos->l;
			else {
				k -= (sz(pos->l) + 1);
				pos = pos->r;
			}
		}
		return pos;
	}
	T operator [] (int k) {
		node *pos = kth_pointer(k);
		return pos->key;
	}
	node* lower_bound(T x) {
		node *pos = root, *res = null;
		while (pos != null) {
			if (pos->key < x)
				pos = pos->r;
			else {
				if (res == null || pos->key < res->key)
					res = pos;
				pos = pos->l;
			}
		}
		return res;
	}
	node* upper_bound(T x) {
		node *pos = root, *res = null;
		while (pos != null) {
			if (pos->key <= x)
				pos = pos->r;
			else {
				if (res == null || pos->key < res->key)
					res = pos;
				pos = pos->l;
			}
		}
		return res;
	}
	node* find(T x) {
		node *pos = root;
		while (pos != null) {
			if (pos->key == x)
				break;
			if (pos->key > x)
				pos = pos->l;
			else
				pos = pos->r;
		}
		return pos;
	}
	int place(node* pos) {
		node *high = root;
		T x = pos->key;
		int res = sz(pos->l);
		while (high != pos) {
			if (high->key < pos->key) {
				res += sz(high->l);
				high = high->r;
			}
			else
				high = high->l;
		}
		return res;
	}
};

//!MULTITREAP

template<class T>
class multitreap {
private:
	struct node {
		T key;
		int y, sz, cnt;
		node *l, *r;
		node(T _key): key(_key), y(rnd()), sz(1), l(null), r(null), cnt(1) {}
	};
	node *root;
	int sz(node *t) {
		if (t == null)
			return 0;
		else
			return t->sz;
	}
	void upd(node *t) {
		t->sz = t->cnt;
		t->sz += sz(t->l);
		t->sz += sz(t->r);
	}
	void split(node *t, T x, node *&l, node *&r, bool right = true) {
		if (t == null) {
			l = null;
			r = null;
			return;
		}
		if (x < t->key || (x == t->key && right)) {
			split(t->l, x, l, t->l, right);
			r = t;
			upd(r);
		}
		else {
			split(t->r, x, t->r, r, right);
			l = t;
			upd(l);
		}
	}
	node* merge(node *l, node *r) {
		if (l == null) return r;
		if (r == null) return l;
		if (l->y < r->y) {
			l->r = merge(l->r, r);
			upd(l);
			return l;
		}
		else {
			r->l = merge(l, r->l);
			upd(r);
			return r;
		}
	}
public:
	void insert(T x) {
		node *tl, *tm, *tr;
		split(root, x, tl, tm);
		split(tm, x, tm, tr, false);
		if (tm == null)
			tm = new node(x);
		else {
			tm->cnt++;
			upd(tm);
		}
		root = merge(merge(tl, tm), tr);
	}
	void erase(T x) {
		node *tl, *tm, *tr;
		split(root, x, tl, tm);
		split(tm, x, tm, tr, false);
		if (tm == null || tm->cnt == 1)
			root = merge(tl, tr);
		else {
			tm->cnt--;
			upd(tm);
			root = merge(merge(tl, tm), tr);
		}
	}
	node* kth_pointer(int k) {
		node *pos = root;
		if (k > root->sz - 1)
			k = root->sz - 1;
		while (true) {
			if (k >= sz(pos->l) && k < sz(pos->l) + pos->cnt)
                break;
			if (k < sz(pos->l))
				pos = pos->l;
			else {
				k -= (sz(pos->l) + pos->cnt);
				pos = pos->r;
			}
		}
		return pos;
	}
	T operator [] (int k) {
		node *pos = kth_pointer(k);
		return pos->key;
	}
	node* lower_bound(T x) {
		node *pos = root, *res = null;
		while (pos != null) {
			if (pos->key < x)
				pos = pos->r;
			else {
				if (res == null || pos->key < res->key)
					res = pos;
				pos = pos->l;
			}
		}
		return res;
	}
	node* upper_bound(T x) {
		node *pos = root, *res = null;
		while (pos != null) {
			if (pos->key <= x)
				pos = pos->r;
			else {
				if (res == null || pos->key < res->key)
					res = pos;
				pos = pos->l;
			}
		}
		return res;
	}
	node* find(T x) {
		node *pos = root;
		while (pos != null) {
			if (pos->key == x)
				break;
			if (pos->key > x)
				pos = pos->l;
			else
				pos = pos->r;
		}
		return pos;
	}
	int place(node* pos) {
		node *high = root;
		T x = pos->key;
		int res = sz(pos->l);
		while (high != pos) {
			if (high->key < pos->key) {
				res += sz(high->l);
				high = high->r;
			}
			else
				high = high->l;
		}
		return res;
	}
	bool empty() {
	    return root == null;
	}
	T min_element() {
	    node *pos = root;
	    while (pos->l != null) {
            pos = pos->l;
	    }
	    return pos->key;
	}
};

const int mx = 500000;
multitreap<int> s[4][4];
int p[mx], a[mx], b[mx], n, m, cl;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i) {
        s[a[i]][b[i]].insert(p[i]);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> cl;
        int cf, cb, price = 2000000000;
        for (int i = 1; i < 4; ++i) {
            for (int j = 1; j < 4; ++j) {
                if ((!s[i][j].empty()) && ((i == cl) || (j == cl))) {
                    if (s[i][j].min_element() < price) {
                        price = s[i][j].min_element();
                        cf = i;
                        cb = j;
                    }
                }
            }
        }
        if (price == 2000000000)
            cout << -1 << ' ';
        else {
            cout << price << ' ';
            s[cf][cb].erase(s[cf][cb].min_element());
        }
    }
    return 0;
}