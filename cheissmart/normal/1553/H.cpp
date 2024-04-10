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

const int INF = 1e9 + 7;

int n, k;

struct node {
	node *l, *r;
	int len, bit;
	vi mx, mn, ans;
	node(int _bit) {
		bit = _bit, len = 1 << bit;
		if(bit)
			l = new node(bit - 1), r = new node(bit - 1);
		else
			l = r = nullptr;
		mx = vi(len, -INF), mn = vi(len, INF), ans = vi(len, INF);
	}
	void insert(int x) {
		if(bit == 0) {
			mx[0] = mn[0] = 0;
			return;
		}
		if(x >> (bit - 1) & 1) {
			r -> insert(x);
		} else {
			l -> insert(x);
		}
	}
	void build() {
		if(bit == 0) return;
		l -> build();
		r -> build();
		for(int i = 0; i < len / 2; i++) {
			mx[i] = max(l -> mx[i], r -> mx[i] + len / 2);
			mn[i] = min(l -> mn[i], r -> mn[i] + len / 2);
			ans[i] = min({l -> ans[i], r -> ans[i], r -> mn[i] + len / 2 - l -> mx[i]});
		}
		swap(l, r);
		for(int i = 0; i < len / 2; i++) {
			mx[i + len / 2] = max(l -> mx[i], r -> mx[i] + len / 2);
			mn[i + len / 2] = min(l -> mn[i], r -> mn[i] + len / 2);
			ans[i + len / 2] = min({l -> ans[i], r -> ans[i], r -> mn[i] + len / 2 - l -> mx[i]});
		}
		swap(l, r);
	}
	void bye() {
		if(bit == 0) return;
		l -> bye(), r -> bye();
		delete l, delete r;
	}
};

signed main()
{
	IO_OP;
	
	cin >> n >> k;
	node* root = new node(k);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		root -> insert(x);
	}
	root -> build();
	for(int i = 0; i < (1 << k); i++)
		cout << root -> ans[i] << ' ';
	root -> bye();
	delete root;

}