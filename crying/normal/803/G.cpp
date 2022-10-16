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
const int MAXN=1e5+10,MAXK=1e4+10,MAXM=1e7+10,INF=2e9,SIGN=2e9;

struct DynamicSegmentTree{
	int lc[MAXM],rc[MAXM],val[MAXM],tag[MAXM],tot;
	il int node(){return ++tot;}
	il void copy(int from,int to){lc[to]=lc[from],rc[to]=rc[from],val[to]=val[from],tag[to]=tag[from];}
	void pushup(int x){val[x]=min(val[lc[x]],val[rc[x]]);}
	void pushdown(int x){
		// 
		int tmp;
		tmp=lc[x];lc[x]=node();copy(tmp,lc[x]);
		tmp=rc[x];rc[x]=node();copy(tmp,rc[x]);
		//
		if(!tag[x])return;
		val[lc[x]]=val[rc[x]]=tag[x];tag[lc[x]]=tag[rc[x]]=tag[x];tag[x]=0; 
	}
	void update(int x,int l,int r,int ql,int qr,int v){
		if(ql<=l && qr>=r){val[x]=tag[x]=v;return;}
		pushdown(x);
		int mid=(l+r)>>1;
		if(ql<=mid)update(lc[x],l,mid,ql,qr,v);
		if(qr>mid)update(rc[x],mid+1,r,ql,qr,v);
		pushup(x);
	}
	int query(int x,int l,int r,int ql,int qr){
		if(ql<=l && qr>=r){return val[x];}
		pushdown(x);
		int mid=(l+r)>>1,ret=INF;
		if(ql<=mid)ret=min(ret,query(lc[x],l,mid,ql,qr));
		if(qr>mid)ret=min(ret,query(rc[x],mid+1,r,ql,qr));
		return ret;
	}
}small; // 
struct SegmentTree{
	int lc[MAXK<<2],rc[MAXK<<2],tag[MAXK<<2],val[MAXK<<2];
	void pushup(int x){val[x]=min(val[lc[x]],val[rc[x]]);}
	void pushdown(int x){if(!tag[x])return;
		val[lc[x]]=val[rc[x]]=tag[lc[x]]=tag[rc[x]]=tag[x];
		tag[x]=0;
	}
	void build(int x,int l,int r){
		if(l==r)return;
		int mid=(l+r)>>1;
		lc[x]=x<<1;rc[x]=lc[x]|1;
		build(lc[x],l,mid);build(rc[x],mid+1,r);
	}
	void update(int x,int l,int r,int ql,int qr,int v){
		if(ql<=l && qr>=r){val[x]=tag[x]=v;return;}
		pushdown(x);
		int mid=(l+r)>>1;
		if(ql<=mid)update(lc[x],l,mid,ql,qr,v);
		if(qr>mid)update(rc[x],mid+1,r,ql,qr,v);
		pushup(x);
	}
	int query(int x,int l,int r,int ql,int qr){
		if(ql<=l && qr>=r){return val[x];}
		pushdown(x);
		int mid=(l+r)>>1,ret=INF;
		if(ql<=mid)ret=min(ret,query(lc[x],l,mid,ql,qr));
		if(qr>mid)ret=min(ret,query(rc[x],mid+1,r,ql,qr));
		return ret;
	}
}big,tag; // 
int n,k,b[MAXN],q,op,l,r,x;
int root[MAXK],initval=INF;
void update(int x,int l,int r,int val=-1){
//	printf("x:%d l:%d r:%d val:%d\n",x,l,r,val);
	//check
	int v=tag.query(1,1,k,x,x);
	if(v!=SIGN){
	//	printf("RECOVERD %d\n",v);
		tag.update(1,1,k,x,x,SIGN);
		big.update(1,1,k,x,x,v);
		small.update(root[x],1,n,1,n,v);
	}
	if(val==-1)return;
	//cover
	small.update(root[x],1,n,l,r,val);
	v=small.query(root[x],1,n,1,n);
	big.update(1,1,k,x,x,v);
}
int main(){
	small.val[0]=INF;
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%d",&b[i]);initval=min(initval,b[i]);
	}
	big.build(1,1,k);tag.build(1,1,k);
	tag.update(1,1,k,1,k,SIGN); //
	big.update(1,1,k,1,k,initval); // 
	root[0]=small.node();
	rep(i,1,n){small.update(root[0],1,n,i,i,b[i]);}
	rep(i,1,k){
		root[i]=small.node();
		small.copy(root[0],root[i]);
	}
	scanf("%d",&q);
	//(???) 
	rep(i,1,q){
		scanf("%d%d%d",&op,&l,&r);
		int L=(l+n-1)/n,R=(r+n-1)/n,ans=INF; //l,r
		// 
		if(op==1){scanf("%d",&x);
			if(L+1<=R-1){
			//	printf("%d,%d,%d\n",L+1,R-1,x);
				big.update(1,1,k,L+1,R-1,x);
				tag.update(1,1,k,L+1,R-1,x);
			}
			if(L==R){ 
				update(L,(l-1)%n+1,(r-1)%n+1,x);
			}else{
				update(L,(l-1)%n+1,n,x); 
				update(R,1,(r-1)%n+1,x);
			}
		}else{
			if(L+1<=R-1){ans=min(ans,big.query(1,1,k,L+1,R-1));}
		//	printf("ANS:%d\n",ans);
			if(L==R){
				update(L,(l-1)%n+1,(r-1)%n+1);
				ans=min(ans,small.query(root[L],1,n,(l-1)%n+1,(r-1)%n+1));
			}else{
				update(L,(l-1)%n+1,n);
				ans=min(ans,small.query(root[L],1,n,(l-1)%n+1,n));
			//	printf("ANS:%d\n",ans);
				update(R,1,(r-1)%n+1);	
				ans=min(ans,small.query(root[R],1,n,1,(r-1)%n+1));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}