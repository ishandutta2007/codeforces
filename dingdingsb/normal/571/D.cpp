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
const int N=1e6+100;
int n,m;ll ans[N];
vector<int>qq[N];// fi
struct qry{
	char op;int x,y;
	void in(){
		op=getchar();while(!isalpha(op))op=getchar();
		read(x);if(op=='U'||op=='M')read(y);
	}
}q[N];
struct Tree{
	struct DSU{
		int fa[N];
		DSU(){for(int i=0;i<N;i++)fa[i]=i;}
		int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	}D;
	int dfin[N],dfout[N],cnt,tot;
	vector<int>e[N];
	void merge(int x,int y){
		x=D.find(x),y=D.find(y);
		++cnt;e[cnt].pb(x),e[cnt].pb(y);
		D.fa[x]=D.fa[y]=cnt;
	}
	void dfs(int u){
		if(u<=n)dfin[u]=dfout[u]=++tot;
		for(auto v:e[u]){
			dfs(v);
			if(!dfin[u])dfin[u]=dfin[v];
			dfout[u]=dfout[v];
		}
	}
	int sz(int x){
		x=D.find(x);
		return dfout[x]-dfin[x]+1;
	}
	void work(){
		for(int i=1;i<=cnt;i++)if(D.fa[i]==i)dfs(i);
		for(int i=1;i<=cnt;i++)D.fa[i]=i;cnt=n;
	}
}T1,T2;
struct SGT{
	int cov[N<<1];
	void pushtag(int x,int c){cov[x]=c;}
	void pushdown(int x){if(cov[x])pushtag(lc,cov[x]),pushtag(rc,cov[x]),cov[x]=0;}
	void cover(int x,int l,int r,int ql,int qr,int val){
		if(ql<=l&&r<=qr)return pushtag(x,val);
		if(r<ql||qr<l)return;
		pushdown(x);
		cover(lc,l,mid,ql,qr,val);
		cover(rc,mid+1,r,ql,qr,val);
	}
	int ask(int x,int l,int r,int p){
		if(l==r)return cov[x];
		pushdown(x);
		if(p<=mid)return ask(lc,l,mid,p);
		else return ask(rc,mid+1,r,p);
	}
}T3;
struct BIT{
	ll tree[N];
	void upd(int x,int y){for(;x<=n;x+=lowbit(x))tree[x]+=y;}
	void upd(int l,int r,int x){upd(l,x);upd(r+1,-x);}
	ll ask(int x){ll res=0;for(;x;x-=lowbit(x))res+=tree[x];return res;}
}T4;
signed main(){
	read(n,m);T1.cnt=T2.cnt=n;
	for(int i=1;i<=m;i++)q[i].in();
	for(int i=1;i<=m;i++)if(q[i].op=='U')T1.merge(q[i].x,q[i].y);else if(q[i].op=='M')T2.merge(q[i].x,q[i].y);
	T1.work();T2.work();
	for(int i=1;i<=m;i++)
		if(q[i].op=='M')T2.merge(q[i].x,q[i].y);
		else if(q[i].op=='Z')T3.cover(1,1,n,T2.dfin[T2.D.find(q[i].x)],T2.dfout[T2.D.find(q[i].x)],i);
		else if(q[i].op=='Q')qq[T3.ask(1,1,n,T2.dfin[q[i].x])].pb(i);
	for(int i=1;i<=m;i++){
		if(q[i].op=='U')T1.merge(q[i].x,q[i].y);
		else if(q[i].op=='A')T4.upd(T1.dfin[T1.D.find(q[i].x)],T1.dfout[T1.D.find(q[i].x)],T1.sz(q[i].x));
		else if(q[i].op=='Q')ans[i]+=T4.ask(T1.dfin[q[i].x]);
		for(auto id:qq[i])ans[id]-=T4.ask(T1.dfin[q[id].x]);
	}
	for(int i=1;i<=m;i++)if(q[i].op=='Q')writeln(ans[i]);
}