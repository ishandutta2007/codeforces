#include <bits/stdc++.h>
using namespace std;
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

const int INF=1e9 + 5;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;

struct node{
	node *left,*right;
	int val=0;
	void merge(node *l,node *r){
		val=l->val + r->val;
	}
};

node ns[35*N];
int cnt=0;

node* create()
{
	node *tmp;
	if(cnt<35*N)tmp=&ns[cnt++];
	else tmp = new node();
	tmp->val=0;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}
struct dynamicsegtree{
	node *root;
	dynamicsegtree()
	{
		root=create();
	}
	
	node* update(node *x,int tl,int tr,int pos,int val)
	{
		node *ret = create();
		ret->left=x->left;
		ret->right=x->right;
		if(tl==tr){
			ret->val=val;
			return ret;
		}
		int tm=tl + (tr-tl)/2;
		
		if(!ret->left)ret->left=create();
		if(!ret->right)ret->right=create();
		if(tm >= pos){
			ret->left = update(ret->left,tl,tm,pos,val);
		}
		else{
			ret->right = update(ret->right,tm+1,tr,pos,val);
		}
		
		
		ret->merge(ret->left,ret->right);
		return ret;
	}
	node* upd(node *x,int pos,int val){
		return update(x,0,N-1,pos,val);
	}
	
	int descent(node *x,int tl,int tr,int k,int &prev){
		int here=0;
		if(x)here=x->val;
		if(prev+here < k){
			prev+=here;
			return N;
		}
		if(tl == tr)return tl;
		
		int tm=tl + (tr-tl)/2;
		
		int ans=descent(x->left,tl,tm,k,prev);
		if(ans!=N)return ans;
		return descent(x->right,tm+1,tr,k,prev);
	}
	
	int descent(node *x,int k){
		int prev=0;
		return descent(x,0,N-1,k,prev);
	}
	
} t;

node *ptr[N];
int last[N],a[N];

void solve(){
	int n;
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
		last[i+1]=-1;
	}
	ptr[n]=t.root;
	for(int i=n-1;i>=0;i--){
		ptr[i]=ptr[i+1];
		if(last[a[i]]!=-1){
			ptr[i] = t.upd(ptr[i],last[a[i]],0);
		}
		last[a[i]]=i;
		ptr[i] = t.upd(ptr[i],i,1);
	}
	
	rep(k,1,n+1){
		int z=0,ans=0;
		while(z<n){
			ans++;
			z=t.descent(ptr[z],k+1);
		}
		cout<<ans<<" ";
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