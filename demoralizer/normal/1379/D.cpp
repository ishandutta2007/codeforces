#include "bits/stdc++.h"
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
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

int maxn=5e8+10;

struct node{
	pii val = {0,0};
	node *left=NULL,*right=NULL;
	int lazy = 0;
	void merge(node d,node u)
	{
		val = min(d.val, u.val);
	}
};

const int N = 1e5+5;

node ns[230*N];
int cnt = 1;

node *create(){
	assert(cnt < 230*N);
	if(cnt < 230*N) return (ns+cnt++);
	return (new node);
}
struct segtree{
	node *root;
	segtree(){
		root=create();
	}
public:
	//if a node has lazy tag then its info is correct but its children's info
	//is old, so pushdown() before going into children
	void pushdown(node *x,int tl,int tr)
	{
		int tm=(tl+tr)/2;
		if(x->left == NULL) x->left=create() , x->left->val.sc = tl;
		if(x->right == NULL) x->right=create() , x->right->val.sc = tr;
		if(x -> lazy){
			apply(x->left,tl,tm,x -> lazy);
			apply(x->right,tm+1,tr,x -> lazy);
			x -> lazy = 0;
		}
	}
	// //apply() is an auxillary function to apply range update and set lazy tag
	void apply(node *x,int tl,int tr,int val)
	{
		if(tl!=tr){
			x->lazy += val;
			x->val.fr += val;
		}
		else x-> val.fr += val;
	}
	pii query(node *x, int tl, int tr, int l,int r) {
		if (l > tr || r < tl)
			return {M,0};
		if (l <= tl && tr <= r) {
			return (x->val);
		}
		pushdown(x,tl,tr);
		int tm = (tl + tr) / 2;
			return min(query(x->left, tl, tm, l,r),query(x->right, tm+1, tr, l,r));
	}
	pii query(int l,int r){
		return query(root,0,maxn-1,l,r);
	}
	void rupd(node *x, int tl, int tr, int l, int r, int val)
	{
		if(l > tr || r < tl)
			return;
		if(l <= tl && tr <= r)
		{
			apply(x,tl,tr,val);
			return;
		}
		pushdown(x,tl,tr);
		int tm = (tl + tr)/2;
		rupd(x->left,tl,tm,l,r,val);
		rupd(x->right,tm+1,tr,l,r,val);
		x->merge(*x->left,*x->right);
	}
	void rupd(int l,int r,int val){
		rupd(root,0,maxn-1,l,r,val);
	}
}t;

int h[N],m[N],tim[N];

void solve(){
	int n,H,M,k;
	cin>>n>>H>>M>>k;
	
	M /= 2;
	
	rep(i,0,n){
		cin>>h[i]>>m[i];
		tim[i] = (1LL*h[i]*(2*M) + m[i]) % M;
		if(k <= 2) continue;
		int L = (tim[i] + 1)%M , R = (tim[i] + k - 1)%M;
		// cout<<L <<" " <<R<< "\n";
		if(L <= R) t.rupd(L,R,1);
		else t.rupd(0,R,1),t.rupd(L,M-1,1);
	}
	
	// rep(i,0,M){
	// 	cout<<t.query(i,i).fr<< " ";
	// }
	// cout<<"\n";
	
	pii ans = t.query(0,M-1);
	cout<<ans<<"\n";
	int opt = ans.sc;
	rep(i,0,n){
		if(k <= 2) continue;
		int L = (tim[i] + 1)%M , R = (tim[i] + k - 1)%M;
		if(L <= R){
			if(opt >= L && opt <= R){
				cout<<(i+1)<<"\n";
			}
		}
		else{
			if(opt >= L || opt <= R){
				cout<<(i+1)<<"\n";
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}