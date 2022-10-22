// Problem: CF1458F Range Diameter Sum
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1458F
// Memory Limit: 500 MB
// Time Limit: 7000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=4e5+100,M=19,inf=1e9+7;
int n;
vector<int>e[N];
int fa[N];
int dep[N],dfn[N],cnt,sz[N],sum,rt,minn;
int ol[N*2][M],lg[N*2];bool vis[N];
long long dsum[N][2];int dcnt[N][2];
int pa[N][M];
int getmin(int a,int b){return dep[a]<dep[b]?a:b;}
void dfs0(int u,int f=0){
	ol[dfn[u]=++cnt][0]=u;dep[u]=dep[f]+1;
	sz[u]=0;pa[u][0]=f;
	for(auto v:e[u])if(v!=f)
		dfs0(v,u),ol[++cnt][0]=u;
}
void init(){
	for(int i=2;i<=cnt;i++)lg[i]=lg[i>>1]+1;
	for(int j=1;1<<j<=cnt;j++)
		for(int i=1;i+(1<<j)<=cnt;i++)
			ol[i][j]=getmin(ol[i][j-1],ol[i+(1<<j-1)][j-1]);
	for(int j=1;1<<j<=2*n;j++)
		for(int i=1;i<=2*n;i++)
			pa[i][j]=pa[pa[i][j-1]][j-1];
}
int lca(int u,int v){
	int uu=min(dfn[u],dfn[v]);
	int vv=max(dfn[u],dfn[v]);
	int len=vv-uu+1;
	return getmin(ol[uu][lg[len]],ol[vv-(1<<lg[len])+1][lg[len]]);
}
int dis(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
int go(int u,int v,int k){
	//?
	int l=lca(u,v);
	int a=u,b=k;
	if(dep[u]-dep[l]<k)
		a=v,b=dep[u]+dep[v]-2*dep[l]-k;
	for(int i=lg[b];~i;i--)
		if(b>>i&1)
			a=pa[a][i];
	return a;
}
void findrt(int u,int f){
	sz[u]=1;int res=0;
	for(auto v:e[u])if(v!=f&&!vis[v]){
		findrt(v,u);sz[u]+=sz[v];
		res=max(res,sz[v]);
	}
	res=max(res,sum-sz[u]);
	if(res<minn)minn=res,rt=u;
}
void dfs(int u){
	assert(!vis[u]);
	vis[u]=1;
	sz[u]=sum+1;
	//if(CCC%1000==0)printf("%d\n",u);
	for(auto v:e[u])if(!vis[v]){
		sum=sz[v];
		minn=inf;rt=0;
		findrt(v,0);
		fa[rt]=u;
		dfs(rt);
	}
}
void add(int u,int op){
	for(int i=u;i;i=fa[i])
		dsum[i][0]+=op*dis(i,u),dcnt[i][0]+=op;
	for(int i=u;fa[i];i=fa[i])
		dsum[i][1]+=op*dis(fa[i],u),dcnt[i][1]+=op;
}
long long qry(int u){
	long long Ans=dsum[u][0];
	for(int i=u;fa[i];i=fa[i]){
		int dis=::dis(u,fa[i]);
		Ans+=dsum[fa[i]][0]+1ll*dcnt[fa[i]][0]*dis;
		Ans-=dsum[i][1]+1ll*dcnt[i][1]*dis;
	}
	return Ans;
}
struct cir{
	int v,r;
	cir(int v=0,int r=0):v(v),r(r){}
	friend cir operator+(const cir&C1,const cir&C2){
		int d=dis(C1.v,C2.v);
		if(C1.r>=d+C2.r)return C1;
		if(C2.r>=d+C1.r)return C2;
		return cir(go(C1.v,C2.v,(d+C2.r-C1.r)/2),(d+C1.r+C2.r)/2);
	}
}val[N];
long long suf[N]; 
long long ans=0;
void cdq(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	cdq(l,mid);cdq(mid+1,r);
	val[mid+1]=cir(mid+1,0);
	for(int i=mid+2;i<=r;i++)
		val[i]=val[i-1]+cir(i,0);
	suf[r+1]=0;for(int i=r;i>=mid;i--)suf[i]=suf[i+1]+val[i].r;
	cir now=cir(mid,0);int x=mid,y=mid+1;
	for(int i=mid;i>=l;i--){
		if(i!=mid)now=now+cir(i,0);
		while(x<r&&dis(val[x+1].v,now.v)+val[x+1].r<=now.r)
			add(val[x+1].v,-1),x++;
		while(y<=r&&(
			val[y].r<dis(val[y].v,now.v)+now.r
			||dis(val[y].v,now.v)+val[y].r<=now.r))
			add(val[y].v,1),y++;
		//printf("[%d %d]  %d->[%d %d]\n",l,r,i,mid+1,r);
		//write(qry(now.v));putchar('\n');
		ans+=1ll*(x-mid)*now.r+suf[y]+
		(qry(now.v)+1ll*(y-x-1)*now.r+suf[x+1]-suf[y])/2;
		/*
		int tmp=0;
		for(int j=mid+1;j<=r;j++){
			cir _=now+val[j];
			tmp+=_.r;
		}
		write(tmp);puts("\n");
		ans+=tmp;*/
	}
	
	//printf("%d %d\n",l,r);
	assert(x<y);
	for(int i=x+1;i!=y;i++)add(val[i].v,-1);
}
signed main(){
//	freopen("test.in","r",stdin);
	read(n);
	for(int i=1,x,y;i<n;i++)
		read(x,y),
		e[x].pb(i+n),e[i+n].pb(x),
		e[y].pb(i+n),e[i+n].pb(y);
	dfs0(1,0);init();
	sum=2*n-1;
	minn=inf;findrt(1,0);
	dfs(rt);
	//printf("%d",maxx);
	//return 0;
	cdq(1,n);
	//for(int l=1;l<=1;l++)
	//	for(int r=4;r<=5;r++){
	//		cir _=cir(l,0);
	//		for(int k=l+1;k<=r;k++)
	//			_=_+cir(k,0);
	//		ans+=_.r;
	//		if(_.r)printf("[%d,%d]  %d\n",l,r,_.r);
	//	}
	write(ans);
}