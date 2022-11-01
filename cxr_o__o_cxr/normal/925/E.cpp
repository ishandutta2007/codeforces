#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int n,m,tim=0,ans=0,B;
int siz[N],fa[N],son[N],top[N],dfn[N];
int __[N],t[N],pos[N],col[N],add[N],sum[204][N<<1],L[204],R[204];
vector<int>e[N]; 
void dfs_1(int x){
	siz[x]=1;
	for(auto v:e[x]){
		fa[v]=x;
		dfs_1(v);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
}
void dfs_2(int x,int tp){
	dfn[x]=++tim;
	top[x]=tp;
	if(son[x])dfs_2(son[x],tp);
	for(auto v:e[x])
		if(v!=son[x])dfs_2(v,v);
}
inline void change(int x,int r){
	col[x]^=1;
	if(t[x]>=n+1-add[pos[x]])ans-=r;
	sum[pos[x]][t[x]]-=r;
}
inline void modify(int l,int r,int v){
	for(int i=l,p=pos[i];i<=r;i++){
		if(!col[i]&&t[i]>=n+1-add[p])ans--;
		if(!col[i])sum[p][t[i]]--;
		t[i]+=v;
		if(!col[i])sum[p][t[i]]++;
		if(!col[i]&&t[i]>=n+1-add[p])ans++; 
	} 
}
inline void update(int l,int r,int v){
	int pl=pos[l],pr=pos[r];
	if(pl==pr){modify(l,r,v);return;}
	modify(l,R[pl],v);modify(L[pr],r,v);
	for(int i=pl+1;i<pr;i++){
		if(v==1){//
			add[i]++;
			ans+=sum[i][n+1-add[i]];
		}
		else{
			ans-=sum[i][n+1-add[i]];
			add[i]--;
		}
	}
}
int main(){
	n=read();m=read();B=500;
	for(int i=2;i<=n;i++)
		e[read()].push_back(i);
	for(int i=1;i<=n;i++)__[i]=read();
	dfs_1(1);
	dfs_2(1,1);
	for(int i=1;i<=n;i++){
		pos[i]=(i-1)/B+1;
		if(pos[i]!=pos[i-1]){
			L[pos[i]]=i;R[pos[i-1]]=i-1;
		}
	} 
	R[pos[n]]=n;
	for(int i=1;i<=n;i++)t[dfn[i]]=n-__[i];
	for(int i=1;i<=n;i++)sum[pos[i]][t[i]]++;
	while(m--){
		static int x,r;
		x=read();
		r=x>0?1:-1;x=abs(x);
		change(dfn[x],r);
		for(;x;x=fa[top[x]])
			update(dfn[top[x]],dfn[x],r);
		cout<<ans<<" ";
	}
	return (0-0);
}