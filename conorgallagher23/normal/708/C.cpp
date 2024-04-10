#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=4e5+5;
struct Edge{int to,nxt;}e[N<<1];
int n,fst[N],tote,siz[N],fa[N],ma[N],id[N],pre[N],suf[N],son[N],upma[N];bool fld[N],flu[N];
void adde(int u,int v){e[++tote]=(Edge){v,fst[u]};fst[u]=tote;}
void dfs(int u){
	siz[u]=1;
	for(int i=fst[u],v;i;i=e[i].nxt)if((v=e[i].to)!=fa[u])
		fa[v]=u,dfs(v),siz[u]+=siz[v],ma[u]=max(ma[u],siz[v]);
	if(ma[u]>(n>>1))fld[u]=true;else if(n-siz[u]>(n>>1))flu[u]=true;
	ma[u]=max(ma[u],n-siz[u]);
}
void dfs2(int u){
	for(int i=fst[u],v;i;i=e[i].nxt)if((v=e[i].to)!=fa[u]){
		dfs2(v);
		if(siz[v]<=(n>>1)){if(siz[v]>siz[id[u]])id[u]=v;}
		else if(siz[id[v]]>siz[id[u]])id[u]=id[v];
	}
}
void dfs3(int u,int ups){
	if(n-siz[u]<=(n>>1))ups=max(ups,n-siz[u]);
	upma[u]=ups;int lens=0;
	for(int i=fst[u],v;i;i=e[i].nxt)if((v=e[i].to)!=fa[u])son[++lens]=v;
	pre[0]=suf[lens+1]=0;
	for(int i=1,v;i<=lens;i++){
		v=son[i];
		if(siz[v]<=(n>>1))pre[i]=max(pre[i-1],siz[v]);else pre[i]=max(pre[i-1],siz[id[v]]);
	}
	for(int i=lens,v;i;i--){
		v=son[i];
		if(siz[v]<=(n>>1))suf[i]=max(suf[i+1],siz[v]);else suf[i]=max(suf[i+1],siz[id[v]]);
	}
	vector<int>vec;vec.resize(lens+1);
	for(int i=1;i<=lens;i++)vec[i]=max(ups,max(pre[i-1],suf[i+1]));
	for(int i=fst[u],now=0,v;i;i=e[i].nxt)if((v=e[i].to)!=fa[u])dfs3(v,vec[++now]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),adde(u,v),adde(v,u); 
	dfs(1);dfs2(1);dfs3(1,0);
	for(int i=1;i<=n;i++,printf("%c",i>n?'\n':' '))
		if(!fld[i]&&!flu[i])printf("1");
		else if(fld[i]){
			if(ma[i]-siz[id[i]]<=(n>>1))printf("1");else printf("0");
		}else{
			if(n-siz[i]-upma[i]<=(n>>1))printf("1");else printf("0");
		}
	return 0;
}