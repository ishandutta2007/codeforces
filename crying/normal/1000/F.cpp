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
const int MAXN=5e5+10,INF=1e9;
int n,q,a[MAXN];
vector<pi>qry[MAXN];
int ans[MAXN];
vector<int>occ[MAXN];
int idx[MAXN];
void upd(pi& p1,pi p2){
	if(p1.fr>p2.fr)p1.fr=p2.fr,p1.se=p2.se;
}
struct SegmenTree{
	int minn[MAXN<<2],idx[MAXN<<2];
	void pushup(int x){
		if(minn[lc(x)]<minn[rc(x)])minn[x]=minn[lc(x)],idx[x]=idx[lc(x)];
		else minn[x]=minn[rc(x)],idx[x]=idx[rc(x)];
	}
	void build(int x,int l,int r){
		minn[x]=INF;idx[x]=l;
		if(l==r)return;int mid=(l+r)>>1;
		build(lc(x),l,mid);build(rc(x),mid+1,r);
	}
	void update(int x,int l,int r,int pos,int val){
		if(l==r){
			minn[x]=val;return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid)update(lc(x),l,mid,pos,val);
		else update(rc(x),mid+1,r,pos,val);
		pushup(x);
	}
	pi query(int x,int l,int r,int ql,int qr){
		if(ql<=l && qr>=r)return mp(minn[x],idx[x]);
		int mid=(l+r)>>1;pi ans=mp(INF,0);
		if(ql<=mid){
			pi tmp=query(lc(x),l,mid,ql,qr);
			upd(ans,tmp);
		}
		if(qr>mid){
			pi tmp=query(rc(x),mid+1,r,ql,qr);
			upd(ans,tmp);
		}
		return ans;
	}
}tree;
void solve(){
	tree.build(1,1,n);
	rep(i,1,n){
		if(idx[i])tree.update(1,1,n,occ[a[i]][idx[i]-1],INF),tree.update(1,1,n,i,occ[a[i]][idx[i]-1]);
		else tree.update(1,1,n,i,0);
		for(auto Q:qry[i]){
			int l=Q.fr,idx=Q.se,ret=0;
			pi tmp=tree.query(1,1,n,l,i);
		//	printf("%d %d\n",tmp.fr,tmp.se);
			if(tmp.fr<l)ret=a[tmp.se];
			ans[idx]=ret;
		}
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		idx[i]=occ[a[i]].size();
		occ[a[i]].pb(i);
	}
	scanf("%d",&q);
	rep(i,1,q){
		int l,r;
		scanf("%d%d",&l,&r);
		qry[r].pb(mp(l,i));
	}
	solve();
	rep(i,1,q)printf("%d\n",ans[i]);

	return 0;
}