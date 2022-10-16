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
int n,d,m,ret,b[MAXN],tot,ans;
struct Node{
	int s,a;
	bool operator<(const Node& n2)const{
		return (ll)a*s<(ll)n2.a*n2.s;
	}
}t[MAXN];
struct Seg{
	int tree[MAXN<<2],tag[MAXN<<2];
	void pushup(int x){tree[x]=max(tree[lc(x)],tree[rc(x)]);}
	void pushdown(int x){
		if(!tag[x])return;
		tree[lc(x)]+=tag[x];tree[rc(x)]+=tag[x];
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];tag[x]=0;
	}
	void build(int x,int l,int r){
		tree[x]=-INF;
		if(l==r)return;
		int mid=(l+r)>>1;build(lc(x),l,mid);build(rc(x),mid+1,r);
	}
	void update(int x,int l,int r,int pos,int val){
		if(l==r){
			tree[x]=max(tree[x],val);return;
		}
		pushdown(x);
		int mid=(l+r)>>1;
		if(pos<=mid)update(lc(x),l,mid,pos,val);
		else update(rc(x),mid+1,r,pos,val);
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
	int query(int x,int l,int r,int ql,int qr){
		if(ql<=l && qr>=r)return tree[x];
		pushdown(x);
		int mid=(l+r)>>1,ret=-INF;
		if(ql<=mid)ret=max(ret,query(lc(x),l,mid,ql,qr));
		if(qr>mid)ret=max(ret,query(rc(x),mid+1,r,ql,qr));
		pushup(x);return ret;
	}
}tree;
int main(){
	scanf("%d%d",&n,&d);b[++tot]=d;
	rep(i,1,n){
		int s,a;scanf("%d%d",&s,&a);
		if(a<=d){
			if(s>=d)ret++;
		}else{
			t[++m]=(Node){s,a};
		}
	}
	sort(t+1,t+1+m);
	rep(i,1,m)b[++tot]=t[i].a,b[++tot]=t[i].s;
	sort(b+1,b+1+tot);
	tot=unique(b+1,b+1+tot)-b-1;
	d=lower_bound(b+1,b+1+tot,d)-b;
	rep(i,1,m){
		t[i].a=lower_bound(b+1,b+1+tot,t[i].a)-b;
		t[i].s=lower_bound(b+1,b+1+tot,t[i].s)-b;
//		printf("%d:%d %d\n",i,t[i].s,t[i].a);
	}
	tree.build(1,1,tot);
	tree.update(1,1,tot,d,0);
	rep(i,1,m){
		int s=t[i].s,a=t[i].a;
		//1. p<=min(s,a)
		int val=tree.query(1,1,tot,1,min(s,a))+1;
		tree.update(1,1,tot,a,val);
		//2.a<p<=s
		if(a<s){
			tree.update(1,1,tot,a+1,s,1);
		}
	}
	ans=tree.query(1,1,tot,1,tot);
	printf("%d",ans+ret);
	return 0;
}