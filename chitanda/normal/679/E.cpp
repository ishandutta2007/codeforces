//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }

const ll oo = 1LL << 62;

ll cal_diff(ll v){
	ll p = 1;
	while(p < v) p *= 42;
	return p - v;
}

struct Node{
	int len, tot_len;
	ll val, add_val, diff, min_diff;
	Node *left, *right;
	Node() = default;
	Node(const Node& other) = default;
	Node(ll, int);
	void add(ll);
	pair<Node*, Node*> split(int);

	void push_down(){
		if(add_val){
			left->add(add_val);
			right->add(add_val);
			add_val = 0;
		}
	}
	
	ll get(int idx){
		if(idx < left->tot_len){
			return left->get(idx) + add_val;
		}
		idx -= left->tot_len;
		if(idx < len) return val;
		idx -= len;
		return right->get(idx) + add_val;
	}

	Node* update(){
		tot_len = left->tot_len + right->tot_len + len;
		min_diff = min(diff, min(left->min_diff, right->min_diff));
		return this;
	}

	bool fix(){
		if(min_diff > 0) return 0;
		push_down();
		bool res = left->fix() || right->fix();
		if(diff <= 0){
			diff = cal_diff(val);
			res |= diff == 0;
		}
		update();
		return res;
	}
};
Node* null;

Node::Node(ll v, int l): len(l), tot_len(l), val(v), add_val(0), diff(cal_diff(v)), min_diff(diff), left(null), right(null) {}

void Node::add(ll v){
	if(this != null){
		val += v;
		add_val += v;
		diff -= v;
		min_diff -= v;
	}
}

bool random(int a, int b){
	return rand() % (a + b) < a;
}

pair<Node*, Node*> Node::split(int idx){
	if(this == null) return {null, null};
	push_down();
	if(idx <= left->tot_len){
		auto p = left->split(idx);
		left = p.se;
		return {p.fi, update()};
	}
	idx -= left->tot_len;
	if(idx < len){
		Node* n = new Node(*this);
		n->left = null;
		right = null;
		n->len = len - idx;
		len = idx;
		return {update(), n->update()};
	}
	idx -= len;
	auto p = right->split(idx);
	right = p.first;
	return {update(), p.se};
}

Node* merge(Node *a, Node *b){
	if(a == null) return b;
	if(b == null) return a;
	if(random(a->tot_len, b->tot_len)){
		a->push_down();
		a->right = merge(a->right, b);
		return a->update();
	}else{
		b->push_down();
		b->left = merge(a, b->left);
		return b->update();
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	null = new Node();
	null->min_diff = oo;
	int n, q;
	scanf("%d%d", &n, &q);
	Node* root = null;
	for(int i = 0; i < n; ++i){
		int t; scanf("%d", &t);
		root = merge(root, new Node(t, 1));
	}
	while(q--){
		int t, a, b, c;
		scanf("%d", &t);
		if(t == 1){
			scanf("%d", &a);
			printf("%I64d\n", root->get(a - 1));
		}else{
			scanf("%d%d%d", &a, &b, &c);
			Node *l, *r, *x;
			tie(x, r) = root->split(b);
			tie(l, x) = x->split(a - 1);
			if(t == 2) root = merge(l, merge(new Node(c, b - a + 1), r));
			else{
				do{
					x->add(c);
				}while (x->fix());
				root = merge(l, merge(x, r));
			}
		}
	}
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/