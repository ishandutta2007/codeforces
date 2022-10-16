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
const int MAXN=3e5+10;
int n,q,k,a[MAXN],l[MAXN],r[MAXN];
int cnt,L[MAXN],R[MAXN],b[MAXN];
int power[20],logn[MAXN],st[20][MAXN];
map<pi,ll>ans;
vector<pi>qry[MAXN],qwq[MAXN];
pi sta[MAXN];
int top;
int query(int l,int r){
	int len=logn[r-l+1];
	return min(st[len][l],st[len][r-power[len]+1]);
}
int idx(int n){return (n-1)/k+1;}
int idx(int n,int r){return (n<r)?1:idx(n-r+1)+(r!=1);}
struct SegmenTree{
	ll tree[MAXN<<2],tag[MAXN<<2];
	void pushup(int x){tree[x]=tree[lc(x)]+tree[rc(x)];}
	void pushdown(int x,int l,int r){
		if(!tag[x])return;
		int mid=(l+r)>>1;
		tree[lc(x)]+=tag[x]*(mid-l+1);tree[rc(x)]+=tag[x]*(r-mid);
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];tag[x]=0;
	}
	void build(int x,int l,int r){
		tree[x]=tag[x]=0;
		if(l==r)return;
		int mid=(l+r)>>1;build(lc(x),l,mid);build(rc(x),mid+1,r);
	}
	void upd(int x,int l,int r,int ql,int qr,ll val){
		if(ql<=l && qr>=r){
			tree[x]+=val*(r-l+1);
			tag[x]+=val;
			return;
		}
		pushdown(x,l,r);int mid=(l+r)>>1;
		if(ql<=mid)upd(lc(x),l,mid,ql,qr,val);
		if(qr>mid)upd(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
	ll query(int x,int l,int r,int ql,int qr){
		if(ql<=l && qr>=r)return tree[x];
		pushdown(x,l,r);int mid=(l+r)>>1;ll ret=0;
		if(ql<=mid)ret+=query(lc(x),l,mid,ql,qr);
		if(qr>mid)ret+=query(rc(x),mid+1,r,ql,qr);
		pushup(x);return ret;
	}
}tree;
void solve(int r){
	cnt=0;
	if(r!=1)L[++cnt]=1,R[cnt]=r-1;
	while(R[cnt]!=n){
		cnt++;L[cnt]=R[cnt-1]+1;
		R[cnt]=min(L[cnt]+k-1,n);
	}
	rep(i,1,cnt)b[i]=query(L[i],R[i]),qwq[i].clear();
	
	for(auto pr:qry[r]){
		int x=pr.fr,y=pr.se;
		if(ans.find(mp(x,y))!=ans.end())continue;
		if(y-x+1<=k){
			ans[mp(x,y)]=a[x];
			continue;
		}
		int llim=idx(x,r),rlim=idx(y,r);
		if(llim+1==rlim){
			ans[mp(x,y)]=a[x]+query(x,x+k); 
			continue;
		}
		//x
		//(llim,rlim)
		ans[mp(x,y)]+=a[x];
		if(y==R[rlim-1]+k)ans[mp(x,y)]+=query(x,y);
		int ll=llim+1,rr=rlim-1,ret=llim;
		while(ll<=rr){
			int mid=(ll+rr)>>1;
			if(query(L[llim+1],R[mid])>=a[x]){
				ret=mid;
				ll=mid+1;
			}else{
				rr=mid-1;
			}
		}
		ans[mp(x,y)]+=(long long)(ret-llim)*a[x];
		if(ret==rlim-1)continue;
		qwq[ret+1].pb(mp(x,y));
	}
	//seg 
	tree.build(1,1,cnt);
	top=0;
	per(i,cnt,1){
		ll num=1;
		while(top){
			if(b[sta[top].fr]>=b[i]){
				tree.upd(1,1,cnt,sta[top].fr,sta[top].fr+sta[top].se-1,-b[sta[top].fr]);
				num+=sta[top].se;
				top--;
			}else break;
		}
		sta[++top]=mp(i,num);
		tree.upd(1,1,cnt,i,i+num-1,b[i]);
		//
		for(auto pr:qwq[i]){
			int x=pr.fr,y=pr.se;
			int rlim=idx(y,r);
			//[i,rlim)
			ans[mp(x,y)]+=tree.query(1,1,cnt,i,rlim-1);
		}
	}
	
}
int main(){
	scanf("%d%d%d",&n,&q,&k);
	rep(i,1,n)scanf("%d",&a[i]),st[0][i]=a[i];
	power[0]=1;rep(i,1,19)power[i]=power[i-1]*2;
	logn[0]=-1;rep(i,1,3e5)logn[i]=logn[i>>1]+1;
	rep(i,1,19)rep(j,1,n){
		if(j+power[i]-1>n)break;
		st[i][j]=min(st[i-1][j],st[i-1][j+power[i-1]]);
	}
	rep(i,1,q){
		scanf("%d%d",&l[i],&r[i]);
		qry[l[i]%k+1].pb(mp(l[i],r[i])); 
	}
	rep(i,1,k){
		solve(i);
	}
	rep(i,1,q){
		printf("%lld\n",ans[mp(l[i],r[i])]);
	}
	
	return 0;
}