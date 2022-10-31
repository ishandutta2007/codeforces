#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int BITS = 20;
int X = 0;

struct node {
	int sz = 0;
	node* l = 0,*r = 0;
};

int size(node* n) {
	if(!n) return 0;
	return n->sz;
}

node *add(node *n, int i, int a) {
	if(!n) n = new node;
	n->sz = 1;
	if(i < 0) return n;
	if(a&(1<<i)) n->r = add(n->r,i-1,a);
	else n->l = add(n->l,i-1,a);
	n->sz = size(n->l) + size(n->r) + 1;
	return n;
}

node* ROOT;

int mex(node *n, int i) {
	if(i<0) return 0;
	if(!n) return 0;
	int b = 1<<i, c = (b<<1)-1;
	if(X&b) {
		if(size(n->r) != c) return mex(n->r,i-1);
		return b + mex(n->l,i-1);
	} else {
		if(size(n->l) != c) return mex(n->l,i-1);
		return b + mex(n->r,i-1);
	}
}

int main() {	
	int n,m,a,x;
	scanf("%d%d",&n,&m);
	while(n--) {
		scanf("%d",&a);
		ROOT = add(ROOT,BITS,a);
		// cout << endl;
	}
	// print(ROOT,0);
	while(m--) {
		scanf("%d",&x);
		X ^= x;
		printf("%d\n",mex(ROOT,BITS));
	}
}