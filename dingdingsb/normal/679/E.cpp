#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define int ll
const int N=1e5+100;
int n,q,a[N];
int pw[10];
int calc(int x){return *lower_bound(pw,pw+10,x)-x;}
struct SGT{
	int mn[N<<2],tag[N<<2],add[N<<2];
	void pushup(int x){mn[x]=min(mn[lc],mn[rc]);}
	void pushcov(int x,int t){
		tag[x]=t;add[x]=0;
		mn[x]=calc(tag[x]);
	}
	void pushadd(int x,int t){
		if(~tag[x])tag[x]+=t,mn[x]=calc(tag[x]);
		else add[x]+=t,mn[x]-=t;
	}
	void pushdown(int x){
		if(~tag[x]){
			pushcov(lc,tag[x]);
			pushcov(rc,tag[x]);
			tag[x]=-1;
		}else{
			pushadd(lc,add[x]);
			pushadd(rc,add[x]);
			add[x]=0;
		}
	}
	void build(int x,int l,int r){
		tag[x]=-1;add[x]=0;
		if(l==r)return tag[x]=a[l],mn[x]=calc(tag[x]),void();
		build(lc,l,mid);build(rc,mid+1,r);
		pushup(x);
	}
	void Cov(int x,int l,int r,int ql,int qr,int v){
		if(ql<=l&&r<=qr)return pushcov(x,v);
		if(r<ql||qr<l)return;
		pushdown(x);
		Cov(lc,l,mid,ql,qr,v);
		Cov(rc,mid+1,r,ql,qr,v);
		pushup(x);
	}
	void Add(int x,int l,int r,int ql,int qr,int v){
		if(ql<=l&&r<=qr){
			if(mn[x]>=v)return pushadd(x,v);
			if(~tag[x])return pushadd(x,v);
		}
		if(r<ql||qr<l)return;
		pushdown(x);
		Add(lc,l,mid,ql,qr,v);
		Add(rc,mid+1,r,ql,qr,v);
		pushup(x);
	}
	int qry(int x,int l,int r,int p){
		if(l==r)return tag[x];
		pushdown(x);
		if(p<=mid)return qry(lc,l,mid,p);
		else return qry(rc,mid+1,r,p);
	}
}T;
signed main(){
	pw[0]=1;for(int i=1;i<10;i++)pw[i]=pw[i-1]*42;
	read(n,q);
	for(int i=1;i<=n;i++)read(a[i]);
	T.build(1,1,n);
	while(q--){
		int op;
		read(op);
		if(op==1){
			int i;
			read(i);
			writeln(T.qry(1,1,n,i));
		}else if(op==2){
			int l,r,x;
			read(l,r,x);
			T.Cov(1,1,n,l,r,x);
		}else{
			int l,r,x;
			read(l,r,x);
			T.Add(1,1,n,l,r,x);
			while(T.mn[1]==0)T.Add(1,1,n,l,r,x);
		}
	}
}