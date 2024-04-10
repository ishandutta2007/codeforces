#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

struct Node;
typedef Node* PNode;

using db = long double;
const db eps = 1e-15;
const db inf = 1e100;

struct pt{
	int x, y;
	pt (int x = 0, int y = 0) : x(x), y(y) {}
};

ll vect(pt p, pt p1, pt p2) {
	return 1ll * (p1.x - p.x) * (p2.y - p.y) - 1ll * (p2.x - p.x) * (p1.y - p.y);
}

struct Node {
	PNode l, r;
	int val, pri, ma, cnt, x;
	db key;
	
	pt getPt() {
		return pt(x, ma);
	}
	
	Node(db ky = 0, int v = 0, int _x = 0) {
		l = r = 0, cnt = 1;
		key = ky;
		val = v, ma = v;
		x = _x;
		pri = rand();
	}
	
	~Node() {
		if (l) delete l;
		if (r) delete r;
	}
};

inline int getMa(PNode x) {
	return x ? x->ma : 0;
}

inline int getCnt(PNode x) {
	return x ? x->cnt : 0;
}

inline void up(PNode x) {
	x->ma = max(max(getMa(x->l), getMa(x->r)), x->val);
	x->cnt = getCnt(x->l) + getCnt(x->r) + 1;
}

PNode merge(PNode x, PNode y) {
	if (!x) return y;
	if (!y) return x;
	if (x->pri > y->pri) {
		x->r = merge(x->r, y);
		up(x);
		return x;
	}
	y->l = merge(x, y->l);
	up(y);
	return y;
}

void split(PNode x, db key, PNode& y, PNode& z) {
	if (!x) {
		y = z = 0;
		return;
	}
	if (x->key > key - eps) {
		split(x->l, key, y, x->l);
		z = x;
	}
	else {
		split(x->r, key, x->r, z);
		y = x;
	}
	up(x);
}

void __split(PNode u, int k, PNode& a, PNode& b) {
	if (k <= 0)		 {a = 0; b = u; return;}
	if (k >= u->cnt) {a = u; b = 0; return;}
	int uls = getCnt(u->l);
	if (k <= uls) {b = u; __split(u -> l, k, a, u -> l); }
	else		  {a = u; __split(u -> r, k - uls - 1, u -> r, b); }
	up(u);
}

struct Treap {
	PNode rt;
	
	void init() {
		delete rt;
		rt = 0;
	}
	
	void insert(db key, int v, int px) {
		PNode x;
		
		auto inc = inter(key);
		if (inc.first != inf && px < inc.first + eps) return;
		
		split(rt, key, rt, x);
		while (getCnt(rt) >= 2) {
			int cr = getCnt(rt);
			PNode y, z;
			__split(rt, cr-1, rt, z);
			__split(rt, cr-2, rt, y);
			pt p1 = y->getPt(), p2 = z->getPt(), p3 = pt(px, v);
			rt = merge(rt, y);
			if (vect(p1, p2, p3) < 0) {
				rt = merge(rt, z);
				break;
			}
		}
		while (getCnt(x) >= 2) {
			int cr = getCnt(x);
			PNode y, z;
			__split(x, 1, y, x);
			__split(x, 1, z, x);
			pt p1 = y->getPt(), p2 = z->getPt(), p3 = pt(px, v);
			x = merge(z, x);
			if (vect(p1, p2, p3) < 0) {
				x = merge(y, x);
				break;
			}
		}
		rt = merge(merge(rt, new Node(key, v, px)), x);
	}
		
	int get_Max(db key) {
		int rlt;
		PNode x;
		split(rt, key + eps * 2, rt, x);
		rlt = getMa(rt);
		rt = merge(rt, x);
		return rlt;
	}
	
	pair<db, db> inter(db key) {
		int rlt;
		PNode x;
		split(rt, key + eps * 2, rt, x);
		if (!rt || !x) {
			rt = merge(rt, x);
			return make_pair(inf, inf);
		}
		PNode y, z;
		__split(rt, getCnt(rt)-1, rt, y);
		__split(x, 1, z, x);
		pt p1 = y->getPt(), p2 = z->getPt();
		rt = merge(rt, y);
		rt = merge(rt, z);
		rt = merge(rt, x);
		db a = p2.y - p1.y, b = p1.x - p2.x, c = -a*p1.x -b*p1.y, d = tan(key);
		db _y = -c / (a * d + b), _x = _y * d;
		return make_pair(_x, _y);
	}
	
	void show() {
		int sz = getCnt(rt);
		vector<PNode> vec;
		cerr << "SHOW Start: " << endl;
		cerr << sz << endl;
		for (int i = 0; i < sz; i++) {
			PNode y;
			__split(rt, 1, y, rt);
			vec.push_back(y);
			pt pts = y->getPt();
			cerr << pts.x << ' ' << pts.y << endl;
		}
		cerr << "SHOW End: " << endl;
		for (int i = 0; i < sz; i++) {
			rt = merge(vec.back(), rt);
			vec.pop_back();
		}
	}
} Tree;

const int N = 110000, M = 1000000;
int x[N], y[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	Tree.init();
	int q, j = 0; ll m; cin >> q >> m;
	for (int time = 1; time <= q; time++) {
		int k, a, b; cin >> k >> a >> b;
		a = (a + j) % M + 1, b = (b + j) % M + 1;
		if (k == 1) {
			db ang = atan2l(b, a);
			Tree.insert(ang, a, b);
		} else {
			db ang = atan2l(m, b);
			int dam = Tree.get_Max(ang);
			if (1ll * a * dam >= b) {
				cout << "YES" << endl;
				j = time;
			} else {
				auto inc = Tree.inter(ang);
				if (inc.first == inf) {
					cout << "NO" << endl;
					continue;
				}
				db time = m / inc.first;
				if (time - a < eps) {
					cout << "YES" << endl;
					j = time;
				} else cout << "NO" << endl;
			}
		}
	}
}