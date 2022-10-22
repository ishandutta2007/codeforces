#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,INF=1e9+10;

int n,m,a[N];
vector <int> G[N];
struct Node{
	ll k,b;
	Node(){}
	Node(ll k,ll b):k(k),b(b){}
	ll operator [] (ll x) const { return k*x+b; }
} s[N];
int ls[N],rs[N],cnt;
int New(){
	int u=++cnt;
	ls[u]=rs[u]=0,s[u]=Node(-INF,-INF);
	return u;
}
void Upd(int &p,int l,int r,Node x){
	if(x.k<0) return;
	if(!p) p=New();
	int mid=(l+r)>>1;
	if(s[p][mid]<x[mid]) swap(s[p],x);
	if(l==r) return;
	if(x[l]>s[p][l]) Upd(ls[p],l,mid-1,x);
	if(x[r]>s[p][r]) Upd(rs[p],mid+1,r,x);
}
ll Que(int p,int l,int r,int x){
	if(l==r) return s[p][x];
	int mid=(l+r)>>1;
	return max(s[p][x],x<=mid?Que(ls[p],l,mid,x):Que(rs[p],mid+1,r,x));
}

int vis[N],mi=1e9,rt,sz[N];
void FindRt(int n,int u,int f){
	int ma=0; sz[u]=1;
	for(int v:G[u]) if(v!=f && !vis[v]) {
		FindRt(n,v,u);
		cmax(ma,sz[v]),sz[u]+=sz[v];
	}
	cmax(ma,n-sz[u]);
	if(mi>ma) mi=ma,rt=u;
}

ll s1[N],s2[N],s3[N],s4[N],dep[N];
int L[N],I[N],dfn,R[N];
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	s2[u]=s2[f]+a[u],s1[u]=s1[f]+1ll*a[u]*(dep[u]+1);
	s4[u]=s4[f]+a[u],s3[u]=s3[f]+s4[u];
	I[L[u]=++dfn]=u;
	//cout<<"dfs "<<u<<' '<<s1[u]<<' '<<s2[u]<<' '<<s3[u]<<' '<<s4[u]<<endl;
	for(int v:G[u]) if(v!=f && !vis[v]) dfs(v,u);
	R[u]=dfn;
}
ll ans;
void Div(int n,int u){
	mi=1e9,FindRt(n,u,0),vis[u=rt]=1;
	s1[u]=s2[u]=a[u],s3[u]=s4[u]=dep[u]=0;
	
	I[L[u]=dfn=1]=u;
	for(int v:G[u]) if(!vis[v]) dfs(v,u);
	R[u]=dfn;

	cmax(ans,(ll)a[u]),cnt=rt=0;
	Upd(rt,1,dfn,Node(s2[u],s1[u]));
	//cout<<"Div "<<u<<endl;
	for(int v:G[u]) if(!vis[v]) {
		rep(j,L[v],R[v]) {
			int i=I[j];
			//cout<<"$"<<i<<' '<<Que(rt,1,dfn,dep[i])+s3[i]<<endl;
			cmax(ans,Que(rt,1,dfn,dep[i])+s3[i]);
		}
		rep(j,L[v],R[v]) {
			int i=I[j];
			Upd(rt,1,dfn,Node(s2[i],s1[i]));
		}
	}
	cnt=rt=0;
	drep(k,G[u].size()-1,0) {
		int v=G[u][k];
		if(vis[v]) continue;
		rep(j,L[v],R[v]) {
			int i=I[j];
			//cout<<"$"<<i<<' '<<rt<<' '<<Que(rt,1,dfn,dep[i])+s3[i]<<endl;
			cmax(ans,Que(rt,1,dfn,dep[i])+s3[i]);
		}
		rep(j,L[v],R[v]) {
			int i=I[j];
			//cout<<"$"<<i<<endl;
			Upd(rt,1,dfn,Node(s2[i],s1[i]));
		}
	}
	cmax(ans,Que(rt,1,dfn,dep[u])+s3[u]);
	//cout<<"ans="<<ans<<endl;
	for(int v:G[u]) if(!vis[v]) {
		if(sz[v]>sz[u]) sz[v]=n-sz[u];
		Div(sz[v],v);
	}
}

int main(){
	s[0]=Node(-1,-INF);
	n=rd();
	rep(i,2,n) {
		int u=rd(),v=rd();
		G[u].pb(v),G[v].pb(u);
	}
	rep(i,1,n) a[i]=rd();
	Div(n,1);
	printf("%lld\n",ans);
}