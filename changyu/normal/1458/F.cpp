#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+3,K=18;
int n,lg[N*2],ord[K][N*2],dfn[N],dfc,dep[N];
std::vector<int>g[N];
bool vis[N];
int siz[N],ddep[N],fat[N][K],dis[N][K],t0[N];
ll t1[N];
ll ans;
void Dfs0(int u,int fa){
	ord[0][dfn[u]=++dfc]=u;
	for(int v:g[u])
		if(v!=fa){
			dep[v]=dep[u]+1;
			Dfs0(v,u);
			ord[0][++dfc]=u;
		}
}
inline bool Cmp(int u,int v){return dfn[u]<dfn[v];}
inline int Lca(int u,int v){
	int l=dfn[u],r=dfn[v],t;
	if(l>r)std::swap(l,r);
	t=lg[r-l+1];
	return std::min(ord[t][l],ord[t][r-(1<<t)+1],Cmp);
}
inline int Dis(int u,int v){return dep[u]+dep[v]-2*dep[Lca(u,v)];}
void Dfs1(int u,int fa,int nn,int&rt){
	int mx=0;
	siz[u]=1;
	for(int v:g[u])
		if(v!=fa&&!vis[v])
			Dfs1(v,u,nn,rt),siz[u]+=siz[v],mx=std::max(mx,siz[v]);
	mx=std::max(mx,nn-siz[u]);
	if(mx*2<=nn)rt=u;
}
void Dfs2(int u,int fa,int dd,int rt){
	siz[u]=1;
	fat[u][dd]=rt;
	for(int v:g[u])
		if(v!=fa&&!vis[v])
			dis[v][dd]=dis[u][dd]+1,Dfs2(v,u,dd,rt),siz[u]+=siz[v];
}
void Build(int u,int nn,int dd){
	Dfs1(u,0,nn,u);
	ddep[u]=dd,vis[u]=1;
	dis[u][dd]=0,Dfs2(u,0,ddep[u],u);
	for(int v:g[u])
		if(!vis[v])
			Build(v,siz[v],dd+1);
}
inline void Add(int u,int x){
	for(int j=ddep[u],v;~j;j--){
		v=fat[u][j];
		t0[v]+=x;
		t1[v]+=x*(dis[u][j]-(j?dis[u][j-1]:0));
	}
}
inline ll Query(int u){
	ll res=0;
	for(int j=ddep[u],v,l=0;~j;j--){
		v=fat[u][j];
		res+=(ll)dis[u][j]*(t0[v]-t0[l])+t1[v];
		l=v;
	}
	return res;
}
struct path{
	int u,v;
	inline path Insert(int w){
		path c=*this;
		int duw=Dis(u,w),dvw=Dis(v,w),duv=Dis(u,v);
		if(duv<std::max(duw,dvw))duw>dvw?c.v=w:c.u=w;
		return c;
	}
	inline bool Contain(path b){
		return std::max({Dis(u,b.u),Dis(u,b.v),Dis(v,b.u),Dis(v,b.v)})<=Dis(u,v);
	}
	inline int Len(){return Dis(u,v);}
}pth[N];
int len[N];
ll slen[N];
void Solve(int l,int r){
	if(l==r)return;
	int ml=l+r>>1,mr=ml+1;
	Solve(l,ml),Solve(mr,r);
	pth[ml]=(path){ml,ml};
	for(int i=ml-1;i>=l;i--)pth[i]=pth[i+1].Insert(i);
	pth[mr]=(path){mr,mr};
	for(int i=mr+1;i<=r;i++)pth[i]=pth[i-1].Insert(i);
	for(int i=l;i<=r;i++)len[i]=pth[i].Len();
	for(int i=l;i<=ml;i++)slen[i]=(i==l?0:slen[i-1])+len[i];
	for(int i=mr,j=ml,k=ml;i<=r;i++){
		for(;j>=l&&!pth[j].Contain(pth[i]);j--){
			if(Dis(i,pth[j].u)<Dis(i,pth[j].v))std::swap(pth[j].u,pth[j].v);
			Add(pth[j].u, 1);
		}
		for(;k> j&& pth[i].Contain(pth[k]);k--)Add(pth[k].u,-1);
		if(j<k&&Dis(k,pth[i].u)<Dis(k,pth[i].v))std::swap(pth[i].u,pth[i].v);
		ans+=slen[j]+Query(pth[i].u)+(ll)(ml-k)*len[i];
		if(i==r)for(;k>j;k--)Add(pth[k].u,-1);
	}
}
int main(){
	int u,v;
	scanf("%d",&n);
	lg[1]=0;for(int i=2;i<=n*2;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	dep[1]=1,Dfs0(1,0);
	for(int j=1;j<K;j++)
		for(int i=1;i+(1<<j)<=n*2;i++)
			ord[j][i]=std::min(ord[j-1][i],ord[j-1][i+(1<<j-1)],Cmp);
	Build(1,n,0);
	Solve(1,n);
	printf("%lld\n",ans);
	return 0;
}