#include <iostream>
#include <random>
#define null NULL

using namespace std;

mt19937 rnd(rand());

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
		int res = 0;
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

int n, sz, t, ans;
treap<int> s;

int main()
{
    sz = 0;
    ans = 0;
    cin >> n;
    for (int i = 0; i < (2 * n); ++i) {
        cin >> t;
        if (s.find(t) == null) {
            sz++;
            s.insert(t);
        }
        else {
            sz--;
            s.erase(t);
        }
        ans = max(ans, sz);
    }
    cout << ans;
    return 0;
}