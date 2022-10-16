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
typedef double db;
using namespace std;
const ll MAXN=2e5+10,INF=1e15;
ll T,n,m,cnt,a[MAXN],pre[MAXN*2],nxt[MAXN*2],f[MAXN*2];
pi tmp[MAXN],s[MAXN];
struct Node{
	int tp,l,r;
	bool operator<(const Node& n2)const{
		return l<n2.l;
	}
}ret[MAXN*2];
struct SegmenTree{
	ll tree[MAXN<<3];
	void pushup(int x){tree[x]=min(tree[lc(x)],tree[rc(x)]);}
	void build(int x,int l,int r){
		tree[x]=INF;
		if(l==r)return;
		int mid=(l+r)>>1;build(lc(x),l,mid);build(rc(x),mid+1,r);
	}
	void update(int x,int l,int r,int pos,ll val){
		if(l==r){tree[x]=val;return;}
		int mid=(l+r)>>1;
		if(pos<=mid)update(lc(x),l,mid,pos,val);
		else update(rc(x),mid+1,r,pos,val);
		pushup(x);
	}
	ll query(int x,int l,int r,int ql,int qr){
		if(ql>qr)return INF;
		if(ql<=l && qr>=r)return tree[x];
		int mid=(l+r)>>1;ll ret=INF;
		if(ql<=mid)ret=min(ret,query(lc(x),l,mid,ql,qr));
		if(qr>mid)ret=min(ret,query(rc(x),mid+1,r,ql,qr));
		return ret;
	}
}tree1,tree2;
bool cmp1(const pi& p1,const pi& p2){
	if(p1.fr!=p2.fr)return p1.fr<p2.fr;
	return p1.se>p2.se;
}
int valid(const pi& p){
	if(a[n]<p.fr)return true;
	int idx=lower_bound(a+1,a+1+n,p.fr)-a;
	if(a[idx]<=p.se)return false;
	return true;
}
void dp(){
	tree1.build(1,1,cnt);tree2.build(1,1,cnt);
	rep(i,1,cnt)pre[i]=0,f[i]=INF,nxt[i]=cnt+1;
	ll val=0;
	rep(i,1,cnt){
		pre[i]=val;
		if(ret[i].tp==1)val=i;
	}
	val=cnt+1;
	per(i,cnt,1){
		nxt[i]=val;
		if(ret[i].tp==1)val=i;
	}
	int flag=0;
	rep(i,1,cnt){
		if(ret[i].tp==1)flag=1;
		if(ret[i].tp==2 && flag==0){continue;}
		if(ret[i].tp==1){
			//point
			if(pre[i]==0){f[i]=ret[i].l-ret[1].r;} //the first point
			else{
				int prev=pre[i];
				f[i]=f[i-1];
				f[i]=min(f[i],ret[i].l+tree1.query(1,1,cnt,prev+1,i-1));
			}
		}else{
			//interval
			int pre1=pre[i];
			int pre2=pre[pre1];
	
			if(pre2==0){f[i]=ret[i].l-ret[1].r+min(ret[i].l-ret[pre1].l,ret[pre1].l-ret[1].r);} //the first subsequence
			else{
				f[i]=f[pre1-1]+ret[i].l-ret[pre1].l;
				//case 1:twice at left
				f[i]=min(f[i],tree2.query(1,1,cnt,pre2+1,pre1-1)+ret[i].l);
				//case 2:twice at right
				f[i]=min(f[i],tree1.query(1,1,cnt,pre2+1,pre1-1)+ret[i].l+(ret[i].l-ret[pre1].l));
			}
			tree1.update(1,1,cnt,i,f[i-1]-ret[i].r);
			int nxtv=nxt[i];
			if(nxtv!=cnt+1){
				tree2.update(1,1,cnt,i,f[i-1]-ret[i].r+ret[nxtv].l-ret[i].r);
			}
		}
	}
	printf("%lld\n",f[cnt]);
}
void solve(){
	int mm;
	scanf("%lld%lld",&n,&mm);
	m=cnt=0;
	rep(i,1,n){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	rep(i,1,mm){
		scanf("%d%d",&tmp[i].fr,&tmp[i].se);
	}
	sort(tmp+1,tmp+1+mm,cmp1);
	ll minn=INF;
	per(i,mm,1){
		if(tmp[i].se < minn && valid(tmp[i])){
			s[++m]=tmp[i];
		}
		minn=min(minn,(ll)tmp[i].se);
	}
	if(m==0){printf("0\n");return;}
	rep(i,1,n){
		ret[++cnt]=(Node){1,a[i],a[i]};
	}
	rep(i,1,m){
		ret[++cnt]=(Node){2,s[i].fr,s[i].se};
	}
	sort(ret+1,ret+1+cnt);
	dp();
}
int main(){
	scanf("%lld",&T);
	while(T--){
		solve();
	}
	return 0;
}