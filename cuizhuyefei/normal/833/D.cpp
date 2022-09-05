#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666,mo=1e9+7;
int res=1,n,head[N],edgenum=1,to[N<<1],nxt[N<<1],A[N<<1],B[N<<1];
int sz[N],T,val[N],c0[N],c1[N],f[N];
bool gg[N];
inline int power(int a, ll n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
void DFS(int u, int fa){
	sz[u]=1;
	L(i,u)if(to[i]!=fa)
		DFS(to[i],u),sz[u]+=sz[to[i]],res=1LL*res*power(A[i],1LL*sz[to[i]]*(n-sz[to[i]]))%mo;
}
bool ck(int x){return power(x,(mo-1)/2)==1;}
Pii mul(Pii a, Pii b, int f){
	return Pii((1LL*a.fi*b.fi+1LL*a.se*b.se%mo*f)%mo,(1LL*a.fi*b.se+1LL*a.se*b.fi)%mo);
}
inline int getsqrt(int a){
	if(!ck(a))assert(0);
	int t=R()%mo;while(ck((1LL*t*t-a+mo)%mo))t=R()%mo;
	int f=(1LL*t*t-a+mo)%mo;
	Pii res(1,0),now(t,1);int mi=(mo+1)/2;
	while(mi){
		if(mi&1)res=mul(res,now,f);
		now=mul(now,now,f);mi>>=1;
	}
	assert(!res.se);return min(res.fi,mo-res.fi);
}
inline void addedge(int u, int v, int x, int c) {
	to[++edgenum]=v; A[edgenum]=x;B[edgenum]=c;
	nxt[edgenum]=head[u]; head[u]=edgenum;
}
void getsz(int u, int fa){
	sz[u]=1;
	L(i,u)if(to[i]!=fa&&!gg[to[i]])
		getsz(to[i],u),sz[u]+=sz[to[i]];
}
void getcen(int u, int fa, Pii &res){
	int mx=T-sz[u];
	L(i,u)if(to[i]!=fa&&!gg[to[i]])
		getcen(to[i],u,res),umax(mx,sz[to[i]]);
	res=min(res,Pii(mx,u));
}
void dfs1(int u, int fa, int x, int y, int z){
	val[u]=x;c0[u]=y;c1[u]=z;f[u]=c1[u]-2*c0[u];
	L(i,u)if(to[i]!=fa&&!gg[to[i]])
		dfs1(to[i],u,1LL*x*A[i]%mo,y+(B[i]==0),z+(B[i]==1));
}
Pii s[N];int len;
void dfsadd(int u, int fa){
	s[++len]=Pii(f[u],val[u]);
	L(i,u)if(to[i]!=fa&&!gg[to[i]])
		dfsadd(to[i],u);
}
void calc(int xs){
	sort(s+1,s+len+1);
	int cur=1,cnt=0;
	int ans=1;
	static int hz[N];
	hz[len+1]=1;per(i,len,1)hz[i]=1LL*hz[i+1]*s[i].se%mo;
	for(int i=1,j=len+1;i<=len;i++){
		while(j-1>=1&&s[i].fi+s[j-1].fi>0)j--;
		int p=max(j,i+1);
		ans=1LL*ans*hz[p]%mo*power(s[i].se,len-p+1)%mo;
	}
//	rep(i,1,len)rep(j,i+1,len)if(s[i].fi+s[j].fi>0)ans=1LL*ans*s[i].se%mo*s[j].se%mo;
	if(xs==1)res=1LL*res*ans%mo;else res=1LL*res*power(ans,mo-2)%mo;
}
void solve(int rt){
	getsz(rt,0);Pii res(1e9,0);T=sz[rt];getcen(rt,0,res);
	rt=res.se;gg[rt]=1;dfs1(rt,0,1,0,0);
	//(1)
	len=0;dfsadd(rt,0);calc(1);
	L(i,rt)if(!gg[to[i]]){
		len=0;dfsadd(to[i],rt);calc(-1);
	}
	L(i,rt)if(!gg[to[i]])solve(to[i]);
}
int main() {
	read(n);
	rep(i,1,n-1){
		int u,v,x,c;
		read(u);read(v);read(x);read(c);
		addedge(u,v,x,c);addedge(v,u,x,c);
	}
	solve(1);
	rep(i,1,edgenum)B[i]^=1;
	memset(gg,0,sizeof(gg));solve(1);
//	cerr<<res<<endl;
//	res=getsqrt(res);
//	cerr<<res<<endl;
	res=power(res,mo-2);
//	cerr<<res<<endl;
	DFS(1,0);cout<<res;
	return 0;
}