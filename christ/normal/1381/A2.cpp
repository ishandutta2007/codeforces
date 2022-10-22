#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define setio(x) freopen(x ".in","r",stdin); freopen(x ".out","w",stdout)
const int MN = 1e5 + 2, LOG = 17, INF = 1e8, MOD = 998244353, BASE = 131;
const ll MX = 1e18;
mt19937_64 rnd(time(NULL));
struct Node {
	int v,sz,sum;ll p;bool lz;Node *l, *r;
	Node (int _v) {v = _v;p=uniform_int_distribution<ll>(1,MX)(rnd);l=r=NULL;lz=0;}
};
int sz (Node *root) {return root?root->sz:0;}
int sum (Node *root) {return root?root->sum:0;}
void push (Node *root) {
	if (root && root->lz) {
		root->lz = 0;
		swap(root->l,root->r); root->sum = (root->sz) - root->sum; root->v ^= 1;
		if (root->l) root->l->lz ^= 1;
		if (root->r) root->r->lz ^= 1;
	}
}
void upd (Node *root) {
	if (root) {
		push(root->l); push(root->r);
		root->sz = sz(root->r) + sz(root->l) + 1;
		root->sum = sum(root->r) + sum(root->l) + root->v;
	}
}
void split (Node *root, int idx, Node *& l, Node *& r, int ext = 0) {
	if (!root) return (void) (l = r = NULL);
	push(root);
	int cur = ext + sz(root->l) + 1;
	if (cur >= idx) r = root, split(root->l,idx,l,root->l,ext);
	else l = root, split(root->r,idx,root->r,r,cur);
	upd(root);
}
void merge (Node *&ret, Node *root1, Node *root2) {
	push(root1); push(root2);
	if (!root1 || !root2) ret = root1 ? root1 : root2;
	else if (root1->p > root2->p) merge(root1->r,root1->r,root2), ret = root1;
	else merge(root2->l,root1,root2->l), ret = root2;
	upd(ret);
}
void insert (Node *&root, int pos, int v) {
	push(root);
	Node *l,*r;
	split(root,pos,l,r);
	merge(root,l,new Node(v));
	merge(root,root,r);
}
int query (Node *&root, int l, int r) {
	Node *lc,*mid,*rc;
	split(root,l,lc,mid);
	split(mid,r-l+2,mid,rc);
	int ret = sum(mid);
	merge(mid,mid,rc);
	merge(root,lc,mid);
	return ret;
}
void print (Node *root, int ext = 0) {
	if (!root) return;
	int cur = ext + sz(root->l) + 1;
	print(root->l,ext);
	print(root->r,cur);
}
void update (Node *&root, int l, int r) {
	Node *lc,*mid,*rc;
	split(root,l,lc,mid);
	split(mid,r-l+2,mid,rc);
	mid->lz ^= 1;
	merge(mid,mid,rc);
	merge(root,lc,mid);
}
int kth (Node *root, int k) {
	assert(root && k >= 1);
	if (k == sz(root->l)+1) return root->v;
	if (k>sz(root->l)+1) return kth(root->r,k-sz(root->l)-1);
	return kth(root->l,k);
}
char s[MN], t[MN];
void solve () {
	int n;
	scanf ("%d",&n);
	scanf ("%s\n%s",s+1,t+1);
	Node *rt = NULL;
	for (int i = 1; i <= n; i++) insert(rt,i,s[i]-'0');
	vector<int> ops;
	for (int i = n; i >= 1; i--) {
		int cur = query(rt,i,i);
		if (cur != t[i] - '0') {
			if (query(rt,1,1) != cur) {
				ops.push_back(1);
				update(rt,1,1);
			}
			ops.push_back(i);
			update(rt,1,i);
		}
	}
	printf ("%d ",(int)ops.size());
	for (int i : ops) printf ("%d ",i);
	printf ("\n");
}
int main () {
	int tt;
	scanf ("%d",&tt);
	while (tt--) solve();
	return 0;
}