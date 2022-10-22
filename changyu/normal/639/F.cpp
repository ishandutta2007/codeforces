#include<bits/stdc++.h>
const int N=3e5+3,K=20;
int n,m,q,x[N],y[N],low[N],dfn[N],dfc,st[N],tp,p[N],rt[N],dfnl[N],lg[N*2],ord[K][N*2],R,n0,n1,n2,nn,nod0[N],nod1[N*6],nod2[N],a[N];
bool ans;
struct edge{int v,p;};
std::vector<edge>g0[N],gg[N];
std::vector<int>g[N];
void Dfs0(int u,int ps,int r){
	int v;
	rt[u]=r,low[u]=dfn[u]=++dfc,st[++tp]=u;
	for(int i=0;i<g0[u].size();i++){
		v=g0[u][i].v;
		if(!dfn[v]){
			Dfs0(v,g0[u][i].p,r);
			low[u]=std::min(low[u],low[v]);
		}
		else if(g0[u][i].p!=ps)low[u]=std::min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		for(;st[tp]!=u;tp--)p[st[tp]]=u;
		p[u]=u,tp--;
	}
}
void Dfs1(int u,int fa){
	int v;
	ord[0][dfnl[u]=++dfc]=u;
	for(int i=0;i<g[u].size();i++)
		if((v=g[u][i])!=fa)
			Dfs1(v,u),ord[0][++dfc]=u;
}
bool Cmp(const int&u,const int&v){return dfnl[u]<dfnl[v];}
inline int Lca(int u,int v){
	int l=dfnl[u],r=dfnl[v],t;
	if(l>r)std::swap(l,r);
	t=lg[r-l+1];
	return std::min(ord[t][l],ord[t][r-(1<<t)+1],Cmp);
}
inline void Insert(int u,int v,int i){gg[u].push_back((edge){v,i}),gg[v].push_back((edge){u,i});}
void Dfs2(int u,int ps){
	int v;
	low[u]=dfn[u]=++dfc,st[++tp]=u;
	for(int i=0;i<gg[u].size();i++){
		v=gg[u][i].v;
		if(!dfn[v]){
			Dfs2(v,gg[u][i].p);
			low[u]=std::min(low[u],low[v]);
		}
		else if(gg[u][i].p!=ps)low[u]=std::min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		int cnt=0;
		for(;st[tp]!=u;tp--)cnt+=a[st[tp]];
		cnt+=a[u],tp--;
		if(cnt&&cnt<nn)ans=0;
	}
}
inline int Read(){int x;scanf("%d",&x);return(x+R-1)%n+1;}
inline void Print(bool f,int j){puts(f?"YES":"NO"),R=(R+j*f)%n;}
int main(){
	int u,v,tmp,r;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		x[i]=u,y[i]=v;
		g0[u].push_back((edge){v,i}),g0[v].push_back((edge){u,i});
	}
	for(u=1;u<=n;u++)if(!dfn[u])Dfs0(u,0,u);
	for(int i=1;i<=m;i++){
		u=p[x[i]],v=p[y[i]];
		if(u!=v)g[u].push_back(v),g[v].push_back(u);
	}
	dfc=0;
	for(u=1;u<=n;u++)if(rt[u]==u)Dfs1(u,0);
	lg[1]=0;for(int i=2;i<=n+n;i++)lg[i]=lg[i>>1]+1;
	for(int j=1;j<K;j++)
		for(int i=1;i+(1<<j)<=n+n;i++)
			ord[j][i]=std::min(ord[j-1][i],ord[j-1][i+(1<<j-1)],Cmp);
	for(u=1;u<=n;u++)dfn[u]=0;
	for(int j=1;j<=q;j++){
		scanf("%d%d",&n0,&m);
		nn=0;
		n1=0;
		for(int i=1;i<=n0;i++){
			u=p[Read()];
			nod0[i]=u;
			nod1[++n1]=u,nod1[++n1]=rt[u];
			if(!a[u])a[u]=1,++nn;
		}
		for(int i=1;i<=m;i++){
			u=p[Read()],v=p[Read()];
			x[i]=u,y[i]=v;
			nod1[++n1]=u,nod1[++n1]=rt[u];
			nod1[++n1]=v,nod1[++n1]=rt[v];
			Insert(u,v,i);
		}
		std::sort(nod1+1,nod1+1+n1,Cmp);
		tmp=n1,n1=0;
		for(int i=1;i<=tmp;i++)if(nod1[i]!=nod1[i-1])nod1[++n1]=nod1[i];
		n2=0;
		for(int ii=1;ii<=n1;ii++)
			if(rt[nod1[ii]]==nod1[ii]){
				r=nod1[ii];
				st[tp=1]=r,nod2[++n2]=r;
				for(int i=ii+1;i<=n1&&rt[nod1[i]]!=nod1[i];i++){
					u=nod1[i],v=Lca(u,st[tp]);
					for(;tp>1&&dfnl[st[tp-1]]>=dfnl[v];tp--)Insert(st[tp-1],st[tp],++m);
					if(st[tp]!=v){
						Insert(v,st[tp],++m);
						st[tp]=v,nod2[++n2]=v;
					}
					st[++tp]=u,nod2[++n2]=u;
				}
				for(;tp>1;tp--)Insert(st[tp-1],st[tp],++m);
			}
		ans=1;
		dfc=0,tp=0;
		for(int i=1;i<=n2;i++)if(!dfn[nod2[i]])Dfs2(nod2[i],0);
		Print(ans,j);
		for(int i=1;i<=n0;i++)a[nod0[i]]=0;
		for(int i=1;i<=n2;i++)gg[nod2[i]].clear(),dfn[nod2[i]]=0;
	}
	return 0;
}