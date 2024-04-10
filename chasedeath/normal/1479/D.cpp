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

const int N=3e5+10,INF=1e9+10;

int n,m,len;
int A[N];
vector <int> G[N];
int I[N*2],C,L[N],R[N],fa[N][20],dep[N];
void dfs(int u,int f){
	I[L[u]=++C]=A[u];
	dep[u]=dep[fa[u][0]=f]+1;
	rep(i,1,19) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:G[u]) if(v!=f) dfs(v,u);
	I[R[u]=++C]=A[u];
}
int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=0,del=dep[x]-dep[y];(1<<i)<=del;++i) if(del&(1<<i)) x=fa[x][i];
	if(x==y) return x;
	drep(i,18,0) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

struct Node{
	int l,r,lca,a,b,id;
	bool operator < (const Node __) const {
		int a=l/len,b=__.l/len;
		if(a!=b) return a<b;
		return (a&1)?r<__.r:r>__.r;
	}
} Q[N];
int ans[N];
int s[N],t[N];
void Switch(int x){
	//cout<<"Switch "<<x<<endl;
	s[x]?(s[x]=0,t[x/len]--):(s[x]=1,t[x/len]++);
}
int Find(int l,int r){
	int p1=l/len,p2=r/len;
	if(p1==p2) {
		rep(i,l,r) if(s[i]) return i;
		return -1;
	}
	rep(i,p1+1,p2-1) if(t[i]) rep(j,i*len,(i+1)*len-1) if(s[j]) return j;
	if(t[p1]) rep(i,l,(p1+1)*len-1) if(s[i]) return i;
	if(t[p2]) rep(i,p2*len,r) if(s[i]) return i;
	return -1;
}

int main(){
	n=rd(),m=rd(),len=ceil(sqrt(max(n,m))/1.3);
	rep(i,1,n) A[i]=rd();
	rep(i,2,n) {
		int u=rd(),v=rd();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,0);
	rep(i,1,m) {
		int u=rd(),v=rd(),l=rd(),r=rd();
		if(L[u]>L[v]) swap(u,v);
		Q[i]=(Node){L[u],L[v],A[LCA(u,v)],l,r,i};
	}
	sort(Q+1,Q+m+1);
	int l=0,r=0;
	//rep(i,1,C) cout<<I[i]<<' ';
	//puts("");
	rep(i,1,m) {
		while(l<Q[i].l) Switch(I[++l]);
		while(l>Q[i].l) Switch(I[l--]);
		while(r<Q[i].r) Switch(I[++r]);
		while(r>Q[i].r) Switch(I[r--]);
		Switch(Q[i].lca);
		//cout<<"Query "<<Q[i].id<<' '<<Q[i].l<<' '<<Q[i].r<<endl;
		//rep(j,1,n) cout<<s[j]<<' ';
		//puts("");
		ans[Q[i].id]=Find(Q[i].a,Q[i].b);
		Switch(Q[i].lca);
	}
	rep(i,1,m) printf("%d\n",ans[i]);
	//rep(i,1,m) printf("%d\n",min(ans[i],1));
}