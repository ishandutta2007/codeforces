#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std; 
int t,n,m,u[200005],v[200005],first[200005],nxt[200005],size[200005];
int p[100005],h[100005],fg;
inline void dfs1(int now,int fa){
	size[now]=p[now];
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa)dfs1(v[i],now),size[now]+=size[v[i]];
	return;
}
inline void dfs2(int now,int fa){
	if (size[now]<h[now]||(size[now]-h[now])%2!=0)fg=0;
	int nowy=(size[now]-h[now])/2,sumy=0,son=0;
	for (register int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		son++;
		dfs2(v[i],now);
		sumy+=(size[v[i]]-h[v[i]])/2;
	}
	if (sumy<nowy-p[now])fg=0;
	return;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)scanf("%lld",&p[i]);
		for (int i=1;i<=n;i++)scanf("%lld",&h[i]);
		for (int i=1;i<=n*2;i++)first[i]=nxt[i]=0;
		for (int i=1;i<n;i++){
			scanf("%lld %lld",&u[i],&v[i]);
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		dfs1(1,0);
		fg=1;
		dfs2(1,0);
		if (fg==1)puts("YES");
		else puts("NO");
	}
	return 0;
}