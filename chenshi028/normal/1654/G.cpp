#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int o=4e5+10;
int n,h[o],cnt,H[o],ans[o],c[o];bool vis[o],flp[o],usd[o];queue<int> q;vector<int> vec[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void Dfs(int nw,int fa){
	usd[nw]=1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v-fa&&H[e[i].v]==H[nw])
		Dfs(e[i].v,nw),c[nw]=min(c[nw],c[e[i].v]+1);
}
void dfs(int nw,int fa){
	for(int i=h[nw];i;i=e[i].p) if(e[i].v-fa&&H[e[i].v]==H[nw])
		c[e[i].v]=min(c[e[i].v],c[nw]+1),dfs(e[i].v,nw);
}
int main(){
	scanf("%d",&n);
	for(int i=1,l;i<=n;++i){
		scanf("%d",&l);
		if(l) q.push(i);
		else H[i]=-1;
	}
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),ad(u,v),ad(v,u);
	for(;!q.empty();q.pop()) for(int i=h[q.front()];i;i=e[i].p)
		if(H[e[i].v]<0) H[e[i].v]=H[q.front()]+1,q.push(e[i].v);
	for(int i=1;i<=n;++i) vec[ans[i]=H[i]].push_back(i);
	for(int i=1;i<=n;++i) for(int j=h[i];j;j=e[j].p)
		if(H[i]==H[e[j].v]) vis[H[i]]=1,flp[i]=1;
	for(int i=0;i<n;++i) if(vis[i]){
		for(int j=1;j<=n;usd[j++]=0) if(H[j]==i&&flp[j]) c[j]=0;else c[j]=o;
		for(int j=i;j<n;++j){
			for(int k=vec[j].size();k;) if(!usd[vec[j][--k]]) Dfs(vec[j][k],0),dfs(vec[j][k],0);
			for(int k=vec[j].size();k;) for(int $=h[vec[j][--k]];$;$=e[$].p)
				if(H[vec[j][k]]+1==H[e[$].v]) c[e[$].v]=min(c[e[$].v],max(0,c[vec[j][k]]-1));
		}
		for(int j=1;j<=n;++j) if(!c[j]) ans[j]=max(ans[j],2*H[j]-i);
	}
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}