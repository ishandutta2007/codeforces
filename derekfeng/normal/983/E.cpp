#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first 
#define se second
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void wwrite(int x){
	if (x==-1) putchar('-'),putchar('1');
	else write(x);
}
int n,m,par[18][200004],depth[200004],lg[200004],L[200004],R[200004],cnt,f[18][200004],Q,ans[200004],dat[200004],sum[200004];
vector<int>g[200004],h[200004],t[200004];
vector<pii>q[200004];
struct BIT{
  void upd(int x,int val){
    for(;x<=n;x+=(x&-x)) dat[x]+=val;
  }
  int qry(int x){
    int ret=0;
    for(;x;x-=(x&-x))ret+=dat[x];
    return ret;
  }
}Tree;
void dfs(int x){
	L[x]=++cnt;
	if (x!=1) depth[x]=depth[par[0][x]]+1;
	for (int i=0;i<g[x].size();i++)
		dfs(g[x][i]);
	R[x]=cnt;
}
void init(){
	for (int i=0;i<18;i++) lg[1<<i]=i;
	for (int i=3;i<n;i++) lg[i]=max(lg[i],lg[i-1]); 
	for (int i=1;i<=lg[n-1];i++)
		for (int j=1;j<=n;j++)
			par[i][j]=par[i-1][par[i-1][j]];
}
int lca(int u,int v){
	if (depth[u]>depth[v]) swap(u,v);
	while (depth[u]<depth[v]) v=par[lg[depth[v]-depth[u]]][v];
	if (u==v) return u;
	for (int i=lg[depth[u]];i>=0;i--)
		if (par[i][u]!=par[i][v]) u=par[i][u],v=par[i][v];
	return par[0][u];
}
void dfs1(int x){
	f[0][x]=x;
	for (int i=0;i<h[x].size();i++)
		if (depth[h[x][i]]<depth[f[0][x]])f[0][x]=h[x][i];
	for (int i=0;i<g[x].size();i++){
		dfs1(g[x][i]);
		if (depth[f[0][g[x][i]]]<depth[f[0][x]]) f[0][x]=f[0][g[x][i]];
	}
}
void init1(){
	for (int i=1;i<18;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=f[i-1][f[i-1][j]];
}
pii ANS(int x,int pos){
	if (x==pos) return mkp(x,0);
	int res=0;
	for (int i=lg[depth[x]];i>=0;i--)
		if (depth[f[i][x]]>depth[pos]) x=f[i][x],res|=(1<<i);
	if (f[0][x]==x) return mkp(x,-1);
	return mkp(x,res);
}
int main(){
	read(n),par[0][1]=1;
	for (int i=2;i<=n;i++){
		int x;
		read(x),g[x].push_back(i),par[0][i]=x;
	}
	init(),dfs(1),read(m);
	for (int i=0;i<m;i++){
		int x,y;read(x),read(y);
		int Lca=lca(x,y);
		if (L[x]>L[y]) swap(x,y);
		t[L[x]].push_back(L[y]);
		if (Lca!=x) h[x].push_back(Lca); 
		if (Lca!=y) h[y].push_back(Lca); 
	}
	dfs1(1),init1(),read(Q);
	for (int i=1;i<=Q;i++){
		int x,y;read(x),read(y);int LCA=lca(x,y);
		pii A=ANS(x,LCA),B=ANS(y,LCA);
		if (A.se==-1 || B.se==-1){
			ans[i]=-1;continue;
		}
		if (A.fi==LCA || B.fi==LCA){
			ans[i]=A.se+B.se+1;continue;
		}
		ans[i]=A.se+B.se+2,x=A.fi,y=B.fi;
		if (L[x]>L[y]) swap(x,y);
    	q[L[x]-1].push_back(mkp(y,-i));
    	q[R[x]].push_back(mkp(y,i));
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<t[i].size();j++) Tree.upd(t[i][j],1);
		for(int j=0;j<q[i].size();j++){
    		int inv=(q[i][j].se>0?1:-1);
    		int x=q[i][j].fi,id=q[i][j].se*inv;
    		sum[id]+=inv*(Tree.qry(R[x])-Tree.qry(L[x]-1)); 
    	}
	}
	for (int i=1;i<=Q;i++) wwrite(ans[i]-(sum[i]>0?1:0)),puts("");
}