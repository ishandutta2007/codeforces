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
const int MAXN=5e5+10;
int n,a[MAXN],idx[MAXN],bucket[MAXN];
ll ans;
vector<int>p[MAXN];
void upd(pi& p1,const pi& p2){
	if(p1.fr>p2.fr){
		p1=p2;
	}else if(p1.fr<p2.fr){
		return;
	}else{
		p1.se+=p2.se;
	}
}
struct SegmenTree{
	int minn[MAXN<<2],cnt[MAXN<<2],tag[MAXN<<2];
	void pushup(int x){
		minn[x]=Min(minn[lc(x)],minn[rc(x)]);
		cnt[x]=0;
		if(minn[lc(x)]==minn[x])cnt[x]+=cnt[lc(x)];
		if(minn[rc(x)]==minn[x])cnt[x]+=cnt[rc(x)];
	}
	void pushdown(int x){if(!tag[x])return;
		minn[lc(x)]+=tag[x];minn[rc(x)]+=tag[x];
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];tag[x]=0;
	}
	void build(int x,int l,int r){
		minn[x]=0;cnt[x]=r-l+1;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(lc(x),l,mid);build(rc(x),mid+1,r);
		pushup(x);
	}
	void update(int x,int l,int r,int ql,int qr,int val){
		if(ql<=l && qr>=r){
			minn[x]+=val;
			tag[x]+=val;
			return;
		}
		pushdown(x);
		int mid=(l+r)>>1;
		if(ql<=mid)update(lc(x),l,mid,ql,qr,val);
		if(qr>mid)update(rc(x),mid+1,r,ql,qr,val);
		pushup(x); 
	}
	pi query(int x,int l,int r,int ql,int qr){
		if(ql<=l && qr>=r){
			return mp(minn[x],cnt[x]);
		}
		pushdown(x);
		int mid=(l+r)>>1; pi ret=mp(1e9,0);
		if(ql<=mid){
			pi tmp=query(lc(x),l,mid,ql,qr);
			upd(ret,tmp);
		}
		if(qr>mid){
			pi tmp=query(rc(x),mid+1,r,ql,qr);
			upd(ret,tmp);
		}
		return ret;	
	}
}tree;
void modify(int pos,int val){
//	if(pos<=4)printf("pos:%d val:%d\n",pos,val);
	if(pos<=4){
//		printf("[1,%d] %d\n",pos,val);
	}
	tree.update(1,1,n,1,pos,val);
	if(idx[pos]>=3){
		if(pos<=4){
		//	printf("[1,%d] %d\n",p[a[pos]][idx[pos]],-val);
		}
		tree.update(1,1,n,1,p[a[pos]][idx[pos]-3],-val);
	}
}
int main(){
	scanf("%d",&n);
	tree.build(1,1,n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		p[a[i]].pb(i);
		idx[i]=p[a[i]].size();
	}
	int L=1;
	rep(i,1,n){
		//
		if(idx[i]>=2){
			modify(p[a[i]][idx[i]-2],-1);
		}
		modify(i,1);
		bucket[a[i]]++;
		// 
		while(bucket[a[i]]>3){
			bucket[a[L]]--;
			L++;
		}
		pi tmp=tree.query(1,1,n,L,i);
		if(tmp.fr==0){
			ans+=tmp.se;
		//	printf("i:%d L:%d ans:%d\n",i,L,tmp.se);
		}
	}
	printf("%lld\n",ans);
	return 0;
}