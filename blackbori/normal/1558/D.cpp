#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 998244353;
const ll M = 5e5;

namespace splay {
	struct node{
		node *l, *r, *p;
		int c, v;

		node(int v) : l(0), r(0), p(0), c(v), v(v) {}
		node() : node(0) {}

		bool left() { return this == p->l; }

		void up()
		{
			c = v;
			if(l) c += l->c;
			if(r) c += r->c;
		}

		void rotate()
		{
			if(left()) r && (r->p = p), p->l = r, r = p;
			else l && (l->p = p), p->r = l, l = p;
			if(p->p) (p->left()? p->p->l : p->p->r) = this;
			node *t = p; p = t->p; t->p = this;
			t->up(); up();
		}
	};

	node T[505050], *rt;
	int nd;

	void init() { nd = 0; rt = NULL; }

	node* newnode(int v) {
		T[++nd] = node(v);
		return T + nd;
	}

	void splay(node *u)
	{
		for(rt = u; u->p; u->rotate()){
			if(u->p->p) (u->left() ^ u->p->left()? u : u->p)->rotate();
		}
	}

	int kth(int k)
	{
		for(; ; rt = rt->r){
			for(; rt->l && rt->l->c >= k; rt = rt->l);
			if(rt->l) k -= rt->l->c;
			if(k <= rt->v) break;
			k -= rt->v;
		}
		splay(rt);
		return k;
	}

	void insert(int i, node *u)
	{
		if(!rt){
			rt = u; return;
		}
		kth(i);
		if(!rt->r) rt->r = u, u->p = rt;
		else{
			for(rt = rt->r; rt->l; rt = rt->l);
			rt->l = u; u->p = rt;
		}
		splay(u);
	}

	void update(int v) { rt->v += v; rt->up(); }

	void print(node *u) {
		if(u->l) print(u->l);
		if(u->v){
			cout << u->v << " ";
		}
		if(u->r) print(u->r);
	}

	void print() { print(rt); }
}

ll F[M + 100], IF[M + 100];

ll pow(ll x, ll y) {
	ll z = 1;
	for (; y; y >>= 1) {
		if (y & 1) z = z * x % mod;
		x = x * x % mod;
	}
	return z;
}

ll comb(ll n, ll k) { return F[n] * IF[n - k] % mod * IF[k] % mod; }

void tc() {
	int n, m, a;
	int i, x, y;
	int p = a = 0;
	cin >> n >> m;
	splay::init();
	splay::insert(0, splay::newnode(1));
	for (i = 0; i < m; i++) {
		cin >> x >> y;
		if (p == 0) {
			splay::insert(0, splay::newnode(x - p - 1));
		}
		else {
			splay::kth(p + 1);
			splay::update(x - p - 1);
		}
		// splay::print(); cout << endl;

		int t = splay::kth(y + 1);
//		cout << "t = " << t << endl;
		if (t == 1) {
			if (y == 1) {
				splay::insert(0, splay::newnode(1)); a++;
			}
			else {
				splay::kth(y);
				splay::update(1);
			}
		}
		else {
			splay::update(1 - t);
			splay::insert(y - t + 1, splay::newnode(t)); a++;
		}
		// splay::print(); cout << endl;
		p = x;
	}
//	cout << "<<<" << a << "\n";
	cout << comb(n + n - 1 - a, n) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int t = 1, i;

	for (i = F[0] = 1; i <= M; i++) {
		F[i] = F[i - 1] * i % mod;
	}
	IF[M] = pow(F[M], mod - 2);
	for (i = M; i >= 1; i--) {
		IF[i - 1] = IF[i] * i % mod;
	}

	cin >> t;

	for (; t--; ) tc();

	return 0;
}