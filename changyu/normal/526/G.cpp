#include<bits/stdc++.h>
const int N=1e5+3,K=20;
int n,m,p[2],dis[N],t0[N],ans;
bool Cmp(const int&i,const int&j){return t0[i]>t0[j];}
struct edge{int v,c;};
std::vector<edge>g[N];
void Dfs0(int u,int fa,int f){
	int v;
	for(int i=0;i<g[u].size();i++)
		if((v=g[u][i].v)!=fa)
			dis[v]=dis[u]+g[u][i].c,Dfs0(v,u,f);
	if(dis[u]>dis[p[f]])p[f]=u;
}
#define M (L+R>>1)
struct solve{
	int root,rt[N],dis[N],son[N],top[N],fot[N],hei[N],p[N],q[N],ls[N*K*2],rs[N*K*2],c[N*K*2],s[N*K*2],t;
	inline void Up(int k){c[k]=c[ls[k]]+c[rs[k]],s[k]=s[ls[k]]+s[rs[k]];}
	void Build(int L,int R,int&k){
		k=++t;
		if(L==R){
			c[k]=top[p[L]]==p[L];
			s[k]=c[k]*hei[p[L]];
			return;
		}
		Build(L,M,ls[k]),Build(M+1,R,rs[k]);
		Up(k);
	}
	void Update(int i,int L,int R,int g,int&k){
		k=++t;
		ls[k]=ls[g],rs[k]=rs[g],c[k]=c[g],s[k]=s[g];
		if(L==R){
			c[k]^=1;
			s[k]=c[k]*hei[p[L]];
			return;
		}
		i<=M?Update(i,L,M,ls[g],ls[k]):Update(i,M+1,R,rs[g],rs[k]);
		Up(k);
	}
	int Query(int x,int L,int R,int k){
		if(!x)return 0;
		if(L==R)return s[k];
		if(c[ls[k]]>=x)
			return Query(x,L,M,ls[k]);
		else
			return Query(x-c[ls[k]],M+1,R,rs[k])+s[ls[k]];
	}
	void Dfs1(int u,int fa){
		int v;
		for(int i=0;i<g[u].size();i++)
			if((v=g[u][i].v)!=fa){
				dis[v]=dis[u]+g[u][i].c;
				Dfs1(v,u);
				hei[v]+=g[u][i].c;
				if(hei[v]>hei[u]){
					son[u]=v;
					hei[u]=hei[v];
				}
			}
	}
	void Dfs2(int u,int fa){
		int v;
		top[u]=top[u]?top[u]:u;
		fot[top[u]]=u;
		if(son[u])top[son[u]]=top[u],Dfs2(son[u],u);
		fot[u]=fot[top[u]];
		for(int i=0;i<g[u].size();i++)
			if((v=g[u][i].v)!=fa&&v!=son[u])Dfs2(v,u);
	}
	void Dfs3(int u,int fa){
		int v;
		Update(q[u],1,n,rt[fa],rt[u]);
		if(son[u])Update(q[son[u]],1,n,rt[u],rt[u]);
		for(int i=0;i<g[u].size();i++)
			if((v=g[u][i].v)!=fa)
				Dfs3(v,u);
	}
	void Init(int Root){
		int u;
		root=Root;
		Dfs1(root,0);
		Dfs2(root,0);
		for(u=1;u<=n;u++)p[u]=u,t0[u]=hei[u];
		std::sort(p+1,p+1+n,Cmp);
		for(u=1;u<=n;u++)q[p[u]]=u;
		Build(1,n,rt[0]);
		Dfs3(root,0);
	}
	inline int Ans(int u,int x){
		return dis[fot[u]]+Query((x-1)*2,1,n,rt[fot[u]]);
	}
}slv[2];
int main(){
	int u,v,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&x);
		g[u].push_back((edge){v,x});
		g[v].push_back((edge){u,x});
	}
	dis[1   ]=0,p[0]=1   ,Dfs0(1   ,0,0);
	dis[p[0]]=0,p[1]=p[0],Dfs0(p[0],0,1);
	slv[0].Init(p[0]);
	slv[1].Init(p[1]);
	for(;m--;){
		scanf("%d%d",&u,&x),u=(u+ans-1)%n+1,x=(x+ans-1)%n+1;
		printf("%d\n",ans=std::max(slv[0].Ans(u,x),slv[1].Ans(u,x)));
	}return 0;
}