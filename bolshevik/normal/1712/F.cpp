#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
const int o=1e6+10;
int n,q,x,p[o],h[o],cnt,d[o],dep[o],f[o],ans;queue<int> Q;vector<int> val[o];
struct Edge{int v,p;}e[o*2];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw,int fa){
	vector<int>().swap(val[nw]);
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa){
		dfs(e[i].v,nw);
		if(val[nw].size()<val[e[i].v].size()) swap(val[nw],val[e[i].v]);
		for(int j=0,sz=val[e[i].v].size(),len=val[nw].size();j<sz;++j)
			for(int t;(t=max(0,ans+1-x-j))<len&&val[nw][t]+val[e[i].v][j]-dep[nw]*2>ans;++ans);
		for(int j=0,sz=val[e[i].v].size();j<sz;++j) val[nw][j]=max(val[nw][j],val[e[i].v][j]);
	}
	for(int t,len=val[nw].size();(t=max(0,ans+1-x-f[nw]))<len&&val[nw][t]-dep[nw]>ans;++ans);
	if(f[nw]>=(int)val[nw].size()) val[nw].push_back(dep[nw]);
	else val[nw][f[nw]]=max(val[nw][f[nw]],dep[nw]);
}
int main(){
	scanf("%d",&n);dep[1]=1;
	for(int i=2;i<=n;++i) scanf("%d",&p[i]),++d[p[i]],++d[i],dep[i]=dep[p[i]]+1,ad(p[i],i),ad(i,p[i]);
	for(int i=1;i<=n;++i) if(d[i]==1) f[i]=1,Q.push(i);
	for(;!Q.empty();Q.pop()) for(int i=h[Q.front()];i;i=e[i].p)
		if(!f[e[i].v]) f[e[i].v]=f[Q.front()]+1,Q.push(e[i].v);
	for(int i=1;i<=n;++i) --f[i];
	for(scanf("%d",&q);q--;printf("%d ",ans),ans=0) scanf("%d",&x),dfs(1,0);
	return 0;
}