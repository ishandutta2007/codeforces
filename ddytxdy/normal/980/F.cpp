#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=5e5+50,inf=1e9;
int n,m,be[N],f[N],cnt,sub[N],SUB[N],vfa[N],q[N*2],l,r;bool vis[N],tp[N];
vector<int>e[N],v[N],vv;
void cmax(int &x,int y){y>x?x=y:0;}
void dfs1(int x){
	vis[x]=1;
	if(f[x])e[x].erase(find(e[x].begin(),e[x].end(),f[x]));
	for(int i=0,y;i<e[x].size();i++){
		if(!vis[y=e[x][i]])f[y]=x,dfs1(y);
		else if(!be[y]){
			be[y]=++cnt;tp[y]=1;v[cnt].pb(y);
			for(int z=x;z!=y;z=f[z])
				be[z]=cnt,v[cnt].pb(z);
		}
	}
	if(!be[x])be[x]=++cnt,tp[x]=1,v[cnt].pb(x);
}
void calc1(int x){
	int id=be[x],sz=v[id].size();
	for(int i=0;i<sz;i++){
		int mx0=0,mx1=-inf;int z=v[id][i];
		for(int j=0,y;j<e[z].size();j++)
			if(be[y=e[z][j]]!=id){
				int val=SUB[y]+1;
				if(val>mx0)mx1=mx0,mx0=val;
				else if(val>mx1)mx1=val;
			}
		sub[z]=mx0;cmax(SUB[x],mx0+min(i,sz-i));
		for(int j=0,y;j<e[z].size();j++)
			if(be[y=e[z][j]]!=id)cmax(vfa[y],SUB[y]+1!=mx0?mx0+1:mx1+1);
	}
}
void dfs2(int x){
	vis[x]=1;
	for(int i=0,y;i<e[x].size();i++)
		if(!vis[y=e[x][i]])dfs2(y);
	if(tp[x])calc1(x);
}
void calc2(int x){
	cmax(sub[x],vfa[x]);vv.clear();
	int id=be[x],sz=v[id].size();
	for(int i=0;i<2;i++)for(int j=0;j<v[id].size();j++)vv.pb(v[id][j]);
	l=1;r=0;
	for(int i=0;i<vv.size();i++){
		if(i-q[l]>sz/2)l++;
		if(l<=r)cmax(vfa[vv[i]],i-q[l]+sub[vv[q[l]]]);
		while(l<=r&&sub[vv[q[r]]]-q[r]<sub[vv[i]]-i)r--;
		q[++r]=i;
	}
	l=1;r=0;
	for(int i=vv.size()-1;~i;i--){
		if(q[l]-i>sz/2)l++;
		if(l<=r)cmax(vfa[vv[i]],q[l]-i+sub[vv[q[l]]]);
		while(l<=r&&sub[vv[q[r]]]+q[r]<sub[vv[i]]+i)r--;
		q[++r]=i;
	}
	for(int i=0;i<v[id].size();i++)
		for(int z=v[id][i],j=0,y;j<e[z].size();j++)
			if(be[y=e[z][j]]!=id)cmax(vfa[y],vfa[z]+1);
}
void dfs3(int x){
	vis[x]=1;if(tp[x])calc2(x);
	for(int i=0,y;i<e[x].size();i++)
		if(!vis[y=e[x][i]])dfs3(y);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
		scanf("%d%d",&x,&y),
		e[x].pb(y),e[y].pb(x);
	dfs1(1);
	memset(vis,0,sizeof(vis));dfs2(1);
	memset(vis,0,sizeof(vis));dfs3(1);
	for(int i=1;i<=n;i++)printf("%d ",max(sub[i],vfa[i]));
	return 0;
}