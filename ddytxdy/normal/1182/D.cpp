#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+50;
int n,x,y,ver[N*2],nxt[N*2],head[N],du[N],tot,d[N],p[N],mp[N];bool vis[N];
int s[N];
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;du[y]++;
}
void dfs(int x,int fa){
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)continue;
		d[y]=d[x]+1;
		dfs(y,x);
	}
}
bool check(int x,int fa,int dis){
	if(!fa)memset(p,0,sizeof(p));
	if(!p[dis])p[dis]=du[x];
	else if(du[x]!=p[dis])return 0;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)continue;
		if(!check(y,x,dis+1))return 0;
	}
	return 1;
}
void find(int x){printf("%d\n",x);exit(0);}
bool dfs1(int x,int fa){
	if(x==y){vis[x]=1;return 1;}
	for(int i=head[x];i;i=nxt[i]){
		int yy=ver[i];if(yy==fa)continue;
		if(dfs1(yy,x)){s[x]=yy;vis[x]=1;return 1;}
	}
	return 0;
}
void dfs2(int x,int fa,int dis){
	if(du[x]==1)mp[dis]=x;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(vis[y]||du[y]>2||y==fa)continue;
		dfs2(y,x,dis+1);
	}
}
int main(){
	scanf("%d",&n);
	if(n==1)find(1);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)if(d[i]>d[x])x=i;
	d[x]=0;dfs(x,0);
	for(int i=1;i<=n;i++)if(d[i]>d[y])y=i;
	if(check(x,0,0))find(x);
	if(check(y,0,0))find(y);
	if(d[y]&1)find(-1);
	memset(vis,0,sizeof(vis));
	dfs1(x,0);int xx=x;
	for(;d[xx]!=(d[y]>>1);xx=s[xx]);
	if(check(xx,0,0))find(xx);
	dfs2(xx,0,0);
	for(int i=0;i<=n;i++)if(mp[i]){
		if(check(mp[i],0,0))find(mp[i]);
		else find(-1);
	}
	find(-1);
	return 0;
}