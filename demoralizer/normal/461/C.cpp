#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
	node* l;
	node* r;
	int key;
	int prior;
	int size;
	int val;
	int sum;
	bool rev;
};

node ns[30*N];
int cnt=0;
node* create(int pos,int val)
{
	node* x;
	if(cnt<30*N)x=ns+cnt++;
	else x=new node;
	x->key=pos;
	x->l=NULL;
	x->r=NULL;
	x->prior=uniform_int_distribution<int>(0, 20*N)(rng);
	x->size=1;
	x->val=val;
	x->sum=val;
	x->rev=0;
	return x;
}
struct Treap{
	node* tree;
	Treap(){
		tree=NULL;
	}
	int SZ(node* x){
		return x?x->size:0;
	}
	void upd_SZ(node* x){
		if(x) x->size=SZ(x->l)+SZ(x->r)+1;
	}
	void reset(node* x){
		if(x) x->sum=x->val;
	}
	void combine(node* &t,node* l,node* r){
		if(!l)t->sum=r->sum;
		else if(!r)t->sum=l->sum;
		else t->sum=l->sum + r->sum;
	}
	void operation(node* &t){
		if(!t)return;
		reset(t);
		combine(t,t->l,t);
		combine(t,t,t->r);
	}
	void pushdown(node* t){
		if(!t||!t->rev)return;
		if(t->l)
		{
			t->l->rev=!(t->l->rev);
			swap(t->l->l,t->l->r);
		}
		if(t->r)
		{
			t->r->rev=!(t->r->rev);
			swap(t->r->l,t->r->r);
		}
			t->rev=0;
	}
	void split(node* t,node* &left,node* &right,int key,int add=0) {
		pushdown(t);
		if(!t) { left=right=NULL; return;}
		int curpos= add + SZ(t->l);
		if(curpos<=key)split(t->r,t->r,right,key,curpos +1) ,left=t;
		else split(t->l,left,t->l,key,add), right=t;
		upd_SZ(t);
		operation(t);
	}
	void merge(node* &t,node* l,node* r){
		pushdown(l);
		pushdown(r);
		if(!l)t=r;
		else if(!r)t=l;
		else if(l->prior > r->prior) merge(l->r,l->r,r), t=l;
		else merge(r->l,l,r->l), t=r;
		upd_SZ(t);
		operation(t);
	}
	void reverse(node* &t){
		swap(t->l,t->r);
		t->rev=!t->rev;
		return;
	}
	void insert(node* &t,int pos,int val){
		node* tmp=create(pos,val);
		node* lll;
		node* rrr;
		node* kutta;
		split(t,lll,rrr,pos-1);
		merge(kutta,lll,tmp);
		merge(t,kutta,rrr);
	}
	void insert(int pos,int val){
		insert(tree,pos,val);
	}
	int query(node* &t,int l,int r){
		if(!t)return 0;
		node *le,*ri,*mid;
		split(t,le,mid,l-1);
		split(mid,mid,ri,r-l);
		int ans=mid->sum;
		merge(mid,mid,ri);
		merge(t,le,mid);
			return ans;
	}
	int query(int l,int r){
		return query(tree,l,r);
	}
	
	void pupd(node *t,int pos,int val){
		node *left,*mid,*right;
		split(t,left,mid,pos-1);
		split(mid,mid,right,0);
		mid->val += val;
		merge(mid,mid,right);
		merge(t,left,mid);
	}
	
	void pupd(int pos,int val){
		pupd(tree,pos,val);
	}
	
	
	void print(node* t,vector<int> &v)
	{
		if(!t)return;
		pushdown(t);
		print(t->l,v);
		v.pb(t->val);
		print(t->r,v);
	}
	void print(vector<int> &v){
		print(tree,v);
	}
	// int findkey(node* t,int val)
	// {
	// 	if(!t)return 0;
	// 	if(t->key==val)return SZ(t->l);
	// 	if(t->key>val)return findkey(t->l,val);
	// 	else return SZ(t->l)+1+findkey(t->r,val);
	// }
	// int findkey(int val){
	// 	return findkey(tree,val);
	// }
}t;

void solve(){
	int n,q;
	cin>>n>>q;
	rep(i,0,n){
		t.insert(0,1);
	}
	
	rep(i,0,q){
		int z;
		cin>>z;
		if(z==1){
			int p;
			cin>>p;
			node *A,*B;
			t.split(t.tree,A,B,p-1);
			t.reverse(A);
			vector<int> v;
			if(A->size > B->size){
				t.tree=A;
				t.print(B,v);
			}
			else{
				t.tree=B;
				t.print(A,v);
			}
			rep(i,0,sz(v)){
				t.pupd(i,v[i]);
			}
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<t.query(l,r-1)<<"\n";
		}
	}
	
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}