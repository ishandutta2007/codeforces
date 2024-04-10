#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=3e5+10;
const ll INF=1e18;
int n,a[MAXN],b[MAXN];
int st[MAXN],top; //
ll f[MAXN]; 
struct segment_tree{
	int L[MAXN<<2],R[MAXN<<2];
	ll val[MAXN<<2],tag[MAXN<<2];
	il void push_up(int x){val[x]=Max(val[lc(x)],val[rc(x)]);}
	il void push_down(int x){
		if(!tag[x])return;
		val[lc(x)]+=tag[x];val[rc(x)]+=tag[x];
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];tag[x]=0;
	}
	void Build(int x,int l,int r){
		val[x]=-INF;L[x]=l;R[x]=r;if(l==r)return;
		int mid=(l+r)>>1;Build(lc(x),l,mid);Build(rc(x),mid+1,r);
		push_up(x);
	}
	void alone_update(int x,int pos,ll v){
		if(L[x]==R[x]){val[x]=v;return;}
		push_down(x);
		int mid=(L[x]+R[x])>>1;
		if(pos<=mid)alone_update(lc(x),pos,v);
		else alone_update(rc(x),pos,v);
		push_up(x);
	}
	void update(int x,int l,int r,ll v){
		if(l<=L[x] && r>=R[x]){
			tag[x]+=v;val[x]+=v;
			return;
		}
		push_down(x);
		int mid=(L[x]+R[x])>>1;
		if(l<=mid)update(lc(x),l,r,v);
		if(r>mid)update(rc(x),l,r,v);
		push_up(x);
	}
	ll query(int x,int l,int r){
		if(l<=L[x] && r>=R[x])return val[x];
		push_down(x);ll ans=-INF;
		int mid=(L[x]+R[x])>>1;
		if(l<=mid)ans=max(ans,query(lc(x),l,r));
		if(r>mid)ans=max(ans,query(rc(x),l,r));
		return ans;
	}
}tree; //max 
int main(){
	scanf("%d",&n);
	rep(i,1,n){scanf("%d",&a[i]);}
	rep(i,1,n){scanf("%d",&b[i]);}
	tree.Build(1,1,n);
	f[1]=b[1];st[++top]=1;tree.alone_update(1,1,b[1]);
	rep(i,2,n){
		while(top && a[st[top]]>a[i]){
			// 
			tree.update(1,st[top-1]+1,st[top],-b[st[top]]);
			top--;
		}
		// 
		tree.update(1,st[top]+1,i-1,b[i]);
		tree.alone_update(1,i,f[i-1]+b[i]);
		st[++top]=i;
		f[i]=tree.query(1,1,i);
	}
	printf("%lld",f[n]);
	return 0;
}