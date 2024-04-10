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
int n,val[MAXN],r,c;
int st1[MAXN],st2[MAXN],top1,top2;
ll ans;
void upd(pi& p1,const pi& p2){
	if(p1.fr>p2.fr)p1=p2;
	else if(p1.fr==p2.fr)p1.se+=p2.se;
}
struct Tree{
	int minn[MAXN<<2],cnt[MAXN<<2],tag[MAXN<<2];
	void build(int x,int l,int r){
		cnt[x]=r-l+1;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(lc(x),l,mid);build(rc(x),mid+1,r);
		pushup(x);
	}
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
	void update(int x,int l,int r,int ql,int qr,int val){
		if(ql>qr)return;
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
		if(ql>qr){return mp(1e9,0);}
		if(ql<=l && qr>=r){
			return mp(minn[x],cnt[x]);
		}
		pushdown(x);
		int mid=(l+r)>>1;
		pi ret=mp(1e9,0);
		if(ql<=mid){
			pi tmp=query(lc(x),l,mid,ql,qr);
			upd(ret,tmp);
		}
		if(qr>mid){
			pi tmp=query(rc(x),mid+1,r,ql,qr);
			upd(ret,tmp);
		}
		pushup(x);
		return ret;
	}
}tree;
int main(){
	scanf("%d",&n);
	tree.build(1,1,n);
	rep(i,1,n){
		scanf("%d%d",&r,&c);
		val[c]=r;
	}
	rep(i,1,n){
		tree.update(1,1,n,1,i-1,-1);
	//	printf("[%d,%d]+%d\n",1,i-1,-1);
		while(top1 && val[st1[top1]]>val[i]){
			tree.update(1,1,n,st1[top1-1]+1,st1[top1],val[st1[top1]]-val[i]);
		//	printf("[%d,%d]+%d\n",st1[top1-1]+1,st1[top1],val[st1[top1]]-val[i]);
			top1--;
		}
		while(top2 && val[st2[top2]]<val[i]){
			tree.update(1,1,n,st2[top2-1]+1,st2[top2],val[i]-val[st2[top2]]);
		//	printf("[%d,%d]+%d\n",st2[top2-1]+1,st2[top2],val[i]-val[st2[top2]]);
			top2--;
		}
		pi tmp=tree.query(1,1,n,1,i);
	//	printf("%d: ",i);
		//rep(j,1,i){
		//	printf("%d ",tree.query(1,1,n,j,j).fr);
		//}
	//	printf("\n");
		ans+=tmp.se;
		st1[++top1]=i;
		st2[++top2]=i;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
5
1 1
4 3
3 2
2 4
5 5

5
1 1
2 2
3 3 
4 4
5 5
*/