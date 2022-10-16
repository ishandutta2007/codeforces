#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 5;

int x[N], r[N], f[N];
struct Treap{
	struct node{
		node *l, *r;
		int val, p, size;
		node() {
			l = r = nullptr;
			size = 0, val = 0;
			p = rand();
		}
		node(int _val) {
			l = r = nullptr;
			size = 1;
			val = _val;
			p = rand();
		}
	} *root;
	Treap(){
		root = nullptr;
	}
	int size(node* t) {
		if(t) return t -> size;
		return 0;
	}
	void split(node* t, node* &l, node* &r, int val) {
		if(t == nullptr) l = r = nullptr;
		else if(val <= t -> val) { split(t -> l, l, t -> l, val); r = t; }
		else { split(t -> r, t -> r, r, val); l = t; }
		if(t) t -> size = size(t -> l) + size(t -> r) + 1;
	}
	void merge(node* &t, node* l, node* r) {
		if(l == nullptr || r == nullptr) t = l ? l : r;
		else if(l -> p > r -> p) { merge(l -> r, l -> r, r); t = l; }
		else { merge(r -> l, l, r -> l); t = r; }
		if(t) t -> size = size(t -> l) + size(t -> r) + 1;
	}
	void insert_node(node* &t, int val) {
		node* n = new node(val), *a = nullptr;
		split(t, t, a, val);
		merge(t, t, n);
		merge(t, t, a);
	}
	void insert(int val) {
		insert_node(root, val);
	}
	int order_of_key_node(node* t, int val) {
		if(t == nullptr) return 0;
		else if(t -> val >= val) return order_of_key_node(t -> l, val);
		else return 1 + size(t -> l) + order_of_key_node(t -> r, val);
	}
	int order_of_key(int val) {
		return order_of_key_node(root, val);
	}
};
Treap t[10004];

int32_t main()
{
	IO_OP;
	
	srand(time(0));
	int n, K;
	cin >> n >> K;
	vector<pi> v;
	for(int i=0;i<n;i++) {
		cin >> x[i] >> r[i] >> f[i];
		v.EB(r[i], i);
	}
	sort(ALL(v), greater<pi>());
	int ans = 0;
	for(int i=0;i<v.size();i++) {
		int j = v[i].S;
		for(int k=max(1LL,f[j]-K);k<=min(10000LL, f[j]+K);k++) {
			int L = x[j] - r[j];
			int R = x[j] + r[j];
			ans += t[k].order_of_key(R+1) - t[k].order_of_key(L);	
		}
		t[f[j]].insert(x[j]);
	}
	cout << ans << endl;
	
}