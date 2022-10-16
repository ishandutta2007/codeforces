#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const int MAXN=1e6+10,INF=1e9;
int T,n,m,a[MAXN],b[MAXN],c[MAXN*2],tot;
int ans[MAXN*2],raw[MAXN*2];
vector<int>occ[MAXN*2];
struct SegmentTree{
	int tree[MAXN<<3],tag[MAXN<<3];
	void pushup(int x){tree[x]=min(tree[lc(x)],tree[rc(x)]);}
	void pushdown(int x){
		tree[lc(x)]+=tag[x];tree[rc(x)]+=tag[x];
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];tag[x]=0;
	}
	void build(int x,int l,int r){
		tag[x]=0;
		if(l==r){tree[x]=l;return;}
		int mid=(l+r)>>1;
		build(lc(x),l,mid);build(rc(x),mid+1,r);
		pushup(x);
	}
	void update(int x,int l,int r,int ql,int qr,int val){
		if(ql<=l && qr>=r){
			tree[x]+=val;tag[x]+=val;
			return;
		}
		pushdown(x);
		int mid=(l+r)>>1;
		if(ql<=mid)update(lc(x),l,mid,ql,qr,val);
		if(qr>mid)update(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
}tree;
struct BIT{
	int tree[MAXN*2];
	void update(int x,int val){
		for(;x<=tot;x+=lowbit(x))tree[x]+=val;
	}
	int query(int x){
		int ret=0;
		for(;x;x-=lowbit(x))ret+=tree[x];
		return ret;
	}
}tree2;
void solve(){
	scanf("%d%d",&n,&m);
	tot=0;
	rep(i,1,n)scanf("%d",&a[i]),c[++tot]=a[i];
	rep(i,1,m)scanf("%d",&b[i]),c[++tot]=b[i];
	sort(c+1,c+1+tot);
	tot=unique(c+1,c+1+tot)-c-1;
	rep(i,1,n)a[i]=lower_bound(c+1,c+1+tot,a[i])-c;
	rep(i,1,m)b[i]=lower_bound(c+1,c+1+tot,b[i])-c;
	rep(i,1,tot)ans[i]=INF,occ[i].clear();
	rep(i,1,n)occ[a[i]].pb(i);
	tree.build(1,1,n);
	rep(i,1,tot)ans[i]=0;
	raw[0]=0;
	rep(i,1,tot)raw[i]=raw[i-1]+occ[i-1].size();
	rep(i,1,tot){
		for(auto u:occ[i-1])tree.update(1,1,n,u,n,-1);
		for(auto u:occ[i])tree.update(1,1,n,u,n,-1);
		ans[i]=min(ans[i],tree.tree[1]);	
	}
	ll ret=0;
	rep(i,1,m)ret+=raw[b[i]]+ans[b[i]];
	per(i,n,1){
		tree2.update(a[i],1);
		ret+=tree2.query(a[i]-1);
	}
	rep(i,1,n)tree2.update(a[i],-1);
	printf("%lld\n",ret);
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}