#include <bits/stdc++.h>

using namespace std;

class rtree_t {
	struct node_t {
		int v = 0, set = 0;
		node_t * l = nullptr, * r = nullptr;
		
		void update_me(int s) {
			if(s > set) {
				set = s;
				v = max(v, set);
			}
		}
		void propagate() {
			if(!l) {
				l = new node_t;
				r = new node_t;
			}
			if(set > 0) {
				l->update_me(set);
				r->update_me(set);
				set = 0;
			}
		}
		void merge() {
			if(!l) return;
			v = max(l->v, r->v);
		}
	} root;
public:
	int query(int w) {
		node_t * n = &root;
		int l = 0, r = 1 << 30;
		while(l != w || l + 1 != r) {
			if(!n->l) {
				if(n->set > 0) return n->set;
				return 0;
			}
			n->propagate();
			int mid = (l + r) >> 1;
			if(mid > w) {
				r = mid;
				n = n->l;
			} else {
				l = mid;
				n = n->r;
			}
		}
		return n->v;
	}
	void update(int b, int e, int s, node_t * n = nullptr, int l = 0, int r = 1 << 30) {
		if(!n) n = &root;
		if(e <= l || r <= b) return;
		if(b <= l && r <= e) {
			n->update_me(s);
			return;
		}
		n->propagate();
		int mid = (l + r) >> 1;
		update(b, e, s, n->l, l, mid);
		update(b, e, s, n->r, mid, r);
		n->merge();
	}
} rtU, rtL;

int N, Q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> Q;
	while(Q--) {
		int x, y;
		char k;
		cin >> x >> y >> k;
		if(k == 'L') {
			int p = rtL.query(y);
			cout << x - p << '\n';
			rtL.update(y, y + 1, x);
			rtU.update(p + 1, x + 1, y);
		} else if(k == 'U') {
			int p = rtU.query(x);
			cout << y - p << '\n';
			rtU.update(x, x + 1, y);
			rtL.update(p + 1, y + 1, x);
		}
	}
}