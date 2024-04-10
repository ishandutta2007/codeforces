#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 1e5 + 7;

mt19937 rng(time(0));

bool vis[N];

struct Node {
	int val, pri, sz;
	Node *l, *r, *p;
	Node(int _val) {
		val = _val;
		pri = rng();
		p = l = r = nullptr;
		sz = 1;
	}
};

int size(Node* t) {
	return t ? t -> sz : 0;
}

void pull(Node* t) {
	t -> sz = size(t -> l) + size(t -> r) + 1;
}

void merge(Node* l, Node* r, Node*& t, Node* p = nullptr) {
	if(!l || !r) {
		t = l ? l : r;
		if(t) t -> p = p;
		return;
	}
	if(l -> pri > r -> pri) {
		t = l;
		merge(l -> r, r, l -> r, l);
	} else {
		t = r;
		merge(l, r -> l, r -> l, r);
	}
	t -> p = p;
	pull(t);
}

void split(Node* t, Node*& l, Node*& r, int lsz, Node* lp = nullptr, Node* rp = nullptr) {
	if(!t) {
		l = r = nullptr;
		return;
	}
	if(size(t -> l) >= lsz) {
		r = t;
		split(t -> l, l, t -> l, lsz, lp, t);
	} else {
		l = t;
		split(t -> r, t -> r, r, lsz - size(t -> l) - 1, t, rp);
	}
	pull(t);
	if(l) l -> p = lp;
	if(r) r -> p = rp;
}

int rk(Node* t, bool flag = true) {
	if(!t -> p) return flag ? size(t -> l) + 1 : 0;
	int ans = 0;
	if(flag) ans += size(t -> l) + 1;
	if(t -> p -> r == t) flag = true;
	else flag = false;
	ans += rk(t -> p, flag);
	return ans;
}
Node* root(Node* t) {
	return t -> p ? root(t -> p) : t;
}

int find(Node* t, int pos) {
	assert(pos < size(t));
	if(size(t -> l) == pos)
		return t -> val;
	else if(size(t -> l) > pos)
		return find(t -> l, pos);
	else
		return find(t -> r, pos - size(t -> l) - 1);
}

void dfs(Node* t) {
	if(!t) return;
	dfs(t -> l);
	cerr << _yellow << t -> val + 1 << " " << _reset;
	dfs(t -> r);
}

int p[N];
Node* node[N];

signed main()
{
	IO_OP;

	int n, q;
	cin >> n >> q;

	for(int i = 0; i < n; i++) {
		cin >> p[i];
		node[i] = new Node(i);
		p[i]--;
	}
	for(int i = 0; i < n; i++) if(!vis[i]) {
		int j = i;
		Node* t = node[j];
		while(p[j] != i) {
			vis[j] = true;
			merge(t, node[p[j]], t);
			j = p[j];
		}
		vis[j] = true;
	}

	while(q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1) {
			x--, y--;
			Node *rtx = root(node[x]), *rty = root(node[y]);
			if(rtx != rty) {
				int rx = rk(node[x]) - 1, ry = rk(node[y]) - 1;
				Node* t;
				split(rtx, t, rtx, rx + 1);
				merge(rtx, t, rtx);
				split(rty, t, rty, ry + 1);
				merge(rty, t, rty);
				merge(rtx, rty, rtx);
			} else {
				int rx = rk(node[x]) - 1;
				Node* t;
				split(rtx, t, rtx, rx + 1);
				merge(rtx, t, rtx);
				int ry = rk(node[y]) - 1;
				split(rtx, rty, rtx, ry + 1);
			}
		} else {
			x--;
			Node *rtx = root(node[x]);
			int rx = rk(node[x]) - 1;
			// dfs(rtx); cerr << '\n';
			// debug(rx);
			Node* t;
			split(rtx, t, rtx, rx);
			merge(rtx, t, rtx);
			y %= size(rtx);
			// dfs(rtx); cerr << '\n';
			cout << find(rtx, y) + 1 << '\n';
		}
	}

}