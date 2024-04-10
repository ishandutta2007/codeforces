#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 3e5+5,INF = 0x7fffffff;
int n,l,r;

struct node {
	int p,v,sz=1,lz=0;
	node *l=0, *r=0;
	node(int v):v(v),p((rand()<<16)^16) {};
	~node(){delete l; delete r; }
};

void push(node* d) {
	if(d->l) d->l->lz += d->lz;
	if(d->r) d->r->lz += d->lz;
	d->v += d->lz;
	d->lz = 0;
}

int rbst_size(node *d) { return (d)?d->sz:0; }

void rbst_update(node *d) {
	d->sz = 1+rbst_size(d->l)+rbst_size(d->r);
}

// l contains elements < v
// r contains elements >= v
void rbst_split(node *d, int v, node *&l, node *&r) {
	l = r = 0;
	if(!d) return;
	push(d);
	if(v <= d->v) {
		rbst_split(d->l,v,l,d->l);
		r=d;
	} else {
		rbst_split(d->r,v,d->r,r);
		l=d;
	}
	rbst_update(d);
}

node* rbst_merge(node *l, node *r) {
	if(!l || !r) return l?l:r;
	push(l); push(r);
	if(l->p < r->p) {
		l->r = rbst_merge(l->r,r);
		rbst_update(l);
		return l;
	}
	r->l = rbst_merge(l,r->l);
	rbst_update(r);
	return r;
}

bool rbst_contains(node* d, int v) {
	if(!d) return false;
	push(d);
	if(v == d->v) return true;
	if(v < d->v) return rbst_contains(d->l,v);
	return rbst_contains(d->r,v);
}

void rbst_insert(node *&d, int v) {
	if(rbst_contains(d,v)) return;
	node *l,*r;
	rbst_split(d,v,l,r);
	d = rbst_merge(rbst_merge(l,new node(v)),r);
}

// erase node with value v
void rbst_erase(node *&d, int v) {
	node *l,*m,*r;
	rbst_split(d,v,l,m);
	rbst_split(m,v+1,m,r);
	if(m) delete m;
	d = rbst_merge(l,r);
}

//value of element at index k
int rbst_at(node* d, int k) {
	if(rbst_size(d->l) == k) return d->v;
	if(k < rbst_size(d->l)) return rbst_at(d->l,k);
	return rbst_at(d->r,k-rbst_size(d->l)-1);
}

//number of elements smaller than v
int rbst_index(node* d, int v) {
	if(!d) return 0;
	if(d->v == v) return rbst_size(d->l);
	if(v < d->v) return rbst_index(d->l,v);
	return 1+rbst_size(d->l)+rbst_index(d->r,v);
}

node* root;

void print(node* d, int h) {
	if(!d) return;
	print(d->l,h+1);
	printf("%d ",d->v);
	print(d->r,h+1);
	if(!h) printf("\n");
}

int main() {
	scanf("%d",&n);
	rbst_insert(root,0);
	while(n--) {
		scanf("%d %d",&l,&r);
		node *a,*b,*c;
		rbst_split(root,l,a,b);
		rbst_split(b,r,b,c);
		if(b) b->lz += 1;
		if(c) rbst_erase(c,rbst_at(c,0));
		root = rbst_merge(rbst_merge(a,new node(l)),rbst_merge(b,c));
	}
	cout << rbst_size(root)-1 << "\n";
	return 0;
}