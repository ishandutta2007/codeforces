/* Author haleyk10198 */
/* ?@??:  haleyk10198 */
/* CF handle: haleyk100198*/
//Many thanks to the editorial
#include <bits/stdc++.h>

#define MOD 1000000007
#define LINF (1LL<<60)
#define INF 2147483647
#define PI 3.1415926535897932384626433
#define ll long long
#define pii pair<int,int>
#define mp(x,y) make_pair((x),(y))
#define nullptr NULL
using namespace std;

string itos(int x){
	stringstream ss;
	ss << x;
	return ss.str();
}

struct node{
	int pr, sz, val, add;
	node *l, *r;
	node(int x){
		val = x;
		//random ID can make E(treap_height) = O(log SIZE)
		pr = (rand() << 15) | rand();
		l = r = nullptr;
		add = 0;
	}
};

void push(node* T){
	//push upda
	T->val += T->add;
	if(T->l)
		T->l->add += T->add;
	if(T->r)
		T->r->add += T->add;
	T->add = 0;
}

void merge(node* &T, node* L, node* R){
	//merge with E(height) = O(log SIZE)
	if(L == nullptr){
		T = R;
		return;
	}
	if(R == nullptr){
		T = L;
		return;
	}
	if(L->pr > R->pr){
		push(L);
		merge(L->r, L->r, R);
		T = L;
		return;
	}
	else{
		push(R);
		merge(R->l, L, R->l );
		T = R;
		return;
	}
}

void split(node *T, int val, node* &L, node* &R){
	/*
		how to split the treap:
			provide L, R placholder
			eg: R
			R->r is an auto-include
			R->l is passed as R recursively to determine the parts which fulfills val >= v
			if there are no more candidtaes then set R->l as nullptr
		*/
	if(T == nullptr){
		L = R = nullptr;
		return;
	}
	push(T);
	if(T->val >= val){
		R = T;
		split(T->l, val, L, T->l);
	}
	else{
		L = T;
		split(T->r, val, T->r, R);
	}
}

int frt(node *T){
	//returns the smallest value of the treap
	push(T);
	if(T->l == nullptr)
		return T->val;
	return frt(T->l);
}

int cnt(node *T){
	//returns the amount of nodes that have state transit exp.
	if(T == nullptr)
		return 0;
	push(T);
	return cnt(T->l)+cnt(T->r)+(T->val < MOD);
}

int n;
node *root = new node(0);
node *L, *R, *M, *tmp;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		merge(root, root, new node(MOD+i));
	for(int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		//Split to (L) (MR)
		split(root, l, L, R);
		//... then (M) (R)
		split(R, r, M, R);
		//If there are dp states which l <= val < r, ++val
		if(M != nullptr)
			M->add++;
		//throw away the upperbound
		split(R, frt(R)+1, tmp, R);
		//Add the dp state for val = l
		merge(root, L, new node(l));
		merge(root, root, M);
		merge(root, root, R);
	}
	//The zero state has to be thrown away
	cout << cnt(root)-1 << endl;
	return 0;
}