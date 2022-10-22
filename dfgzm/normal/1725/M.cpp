#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e18
const int maxn=2e6+10;
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
int n,m,beg[maxn],nex[maxn],to[maxn],w[maxn],e;
inline void add(int x,int y,int z){
	++e;nex[e]=beg[x];beg[x]=e;to[e]=y;w[e]=z;
}
ll dis[maxn];int vis[maxn];
priority_queue<pair<ll,int> >Q;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)add(i,i+n,0);
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v+n,u+n,w);
	}Q.push(make_pair(0,1));
	for(int i=2;i<=n+n;i++)dis[i]=INF;
	while(!Q.empty()){
		int x=Q.top().second;Q.pop();
		if(vis[x])continue;vis[x]=1;
		for(int i=beg[x];i;i=nex[i]){
			int t=to[i];
			if(dis[t]>dis[x]+w[i]){
				dis[t]=dis[x]+w[i];
				Q.push(make_pair(-dis[t],t));
			}
		}
	}
	for(int i=n+2;i<=n+n;i++)
		printf("%lld ",dis[i]==INF?-1:dis[i]);
	return 0;
}