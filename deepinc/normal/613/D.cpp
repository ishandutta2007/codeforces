#include<bits/stdc++.h>
using namespace std;
const int S=2e5+5;
int fir[S],l[S],to[S],ec,dep[S],dfn[S],tim,son[S],sz[S],fa[S],top[S],n,q,r[S],imp[S],sta[S],dp[S],f[S],g[S];
void link(int a,int b){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;}
bool cmp(int x,int y){return dfn[x]<dfn[y];}
void dfs(int p,int fa){
	sz[p]=1; dep[p]=dep[f[p]=fa]+1; dfn[p]=++tim;
	for(int i=fir[p];i;i=l[i])if(to[i]!=fa){
		dfs(to[i],p);sz[p]+=sz[to[i]];
		if(sz[to[i]]>sz[son[p]])son[p]=to[i];
	}
}
void DFS(int p,int tp){
	top[p]=tp;
	if(son[p])DFS(son[p],tp);
	for(int i=fir[p];i;i=l[i])if(!top[to[i]])DFS(to[i],to[i]); fir[p]=0;
}
int lca(int x,int y){
	while(top[x]!=top[y])if(dep[top[x]]<dep[top[y]])y=f[top[y]];else x=f[top[x]];
	return dep[x]<dep[y]?x:y;
}
void Dfs(int p){
	g[p]=imp[p]; dp[p]=0; int cnt=0;
	for(int i=fir[p],y;y=to[i];i=l[i]){
		if(dep[y]==dep[p]+1&&imp[p]&&imp[y]){Dfs(y),dp[p]=n;continue;}
		Dfs(y); dp[p]+=dp[y]; cnt+=g[y];
	}if(imp[p])dp[p]+=cnt;else if(cnt>1)dp[p]++,g[p]=0;else if(cnt==1)g[p]=1;
	fir[p]=imp[p]=0;
}
int main(){
	scanf("%d",&n);
	for(int i=1,a,b;i<n;++i)scanf("%d%d",&a,&b),link(a,b),link(b,a);
	dfs(1,0);DFS(1,1);
	scanf("%d",&q);
	for(int _=1,k;_<=q;++_){
		scanf("%d",&k);ec=0;
		for(int i=1;i<=k;++i)scanf("%d",&r[i]),imp[r[i]]=1;
		if(k==1){puts("0");imp[r[1]]=0;continue;}
		sort(r+1,r+1+k,cmp);
		int top=0;
		for(int i=1,L;i<=k;++i){
			if(!top)goto E;
			if((L=lca(sta[top],r[i]))==sta[top])goto E;
			while(top>1&&dfn[sta[top-1]]>=dfn[L])link(sta[top-1],sta[top]),top--;
			if(sta[top]!=L)link(L,sta[top]),sta[top]=L,imp[L]=0;
			E:sta[++top]=r[i];
		}while(top>1)link(sta[top-1],sta[top]),top--;
		Dfs(sta[1]);printf("%d\n",dp[sta[1]]>=n?-1:dp[sta[1]]);
	}
}