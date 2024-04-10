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
const int MAXN=1e6+10;
int n,m,x[MAXN],y[MAXN];
int p[MAXN],vis[MAXN];
int ord[MAXN];
set<int>s;
vector<int>occ[MAXN];
struct BIT{
	ll tree[MAXN];
	void update(int x,int val){
		for(;x<=n;x+=lowbit(x))tree[x]+=val;
	}
	int q(int x){
		ll ret=0;
		for(;x;x-=lowbit(x))ret+=tree[x];
		return ret;
	}
	int query(int S){
		return q(n)-q(S-1);
	}
}tree1;
struct SegmentTree{
	ll sum[MAXN<<2],tag[MAXN<<2];
	void pushup(int x){sum[x]=sum[lc(x)]+sum[rc(x)];}
	void pushdown(int x,int l,int r){
		int mid=(l+r)>>1;
		sum[lc(x)]+=tag[x]*(mid-l+1);sum[rc(x)]+=tag[x]*(r-mid); 
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];tag[x]=0;
	}
	void update(int x,int l,int r,int ql,int qr,ll val){
		if(ql<=l && qr>=r){sum[x]+=val*(r-l+1);tag[x]+=val;return;}
		pushdown(x,l,r);int mid=(l+r)>>1;
		if(ql<=mid)update(lc(x),l,mid,ql,qr,val);
		if(qr>mid)update(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
	ll query(int x,int l,int r,int ql,int qr){
		if(ql<=l && qr>=r)return sum[x];
		pushdown(x,l,r);int mid=(l+r)>>1;ll ret=0;
		if(ql<=mid)ret+=query(lc(x),l,mid,ql,qr);
		if(qr>mid)ret+=query(rc(x),mid+1,r,ql,qr);
		pushup(x);return ret;
	}
}tree2;
void solve1(){
	rep(i,1,m){if(ord[i]!=0)continue;
		int L=1,R=n,ret=-1;
		while(L<=R){
			int mid=(L+R)>>1;
			//=y[i]
			ll val=mid+tree1.query(mid);
			if(val==y[i]){
				ret=mid;
				L=mid+1;
			}else if(val<y[i])L=mid+1;
			else R=mid-1;
		}
		if(ret==-1){printf("-1\n");exit(0);}
		if(p[ret]){printf("-1\n");exit(0);}
		vis[x[i]]=ret;
		p[ret]=x[i];
		tree1.update(ret,1);
	}
}
void add(int pos){
	int u=x[pos];
	if(ord[pos]==0){
		tree2.update(1,1,m,1,pos,1);
	}else{
		tree2.update(1,1,m,occ[u][ord[pos]-1]+1,pos,1);
	}
}
void solve2(){
	rep(i,2,m){
		add(i-1);if(ord[i]==0)continue;
		ll ret=0,u=x[i];
		if(occ[u][ord[i]-1]+1<i){
			ret=tree2.query(1,1,m,occ[u][ord[i]-1]+1,occ[u][ord[i]-1]+1);
		} 
		if(1+ret!=y[i]){
			printf("-1\n");exit(0);
		}
	}
}
il void Read(int& num){
	char ch;
	while((ch=getchar()) && !isdigit(ch));
	num=ch-'0';
	while((ch=getchar()) && isdigit(ch))num=num*10+ch-'0';
}
int main(){
	Read(n);Read(m);
	rep(i,1,m){
		Read(x[i]);Read(y[i]);
		ord[i]=occ[x[i]].size();
		occ[x[i]].pb(i);
	}
	solve1(); //construct a permutation
	solve2(); //check the permutation
	rep(i,1,n)if(!vis[i])s.is(i); 
	rep(i,1,n)if(!p[i]){
		p[i]=*s.begin();
		s.erase(p[i]);
	}
	rep(i,1,n)printf("%d ",p[i]);
	return 0;
}