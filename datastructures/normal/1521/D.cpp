#include <iostream>
#include <cstdio>
using namespace std;
int t,n,u[200005],v[200005],first[200005],nxt[200005];
int up[100005],f[100005][2],g[100005][2],h[100005],idg[100005][2],idh[100005];
int book[100005],c[100005][2],tot;
inline void dp(register int now,register int fa){
	up[now]=fa;
	register int nowval=0,mx1=0,id1=0,mx2=0,id2=0;
	for (register int i=first[now];i;i=nxt[i]){
		if (v[i]!=fa)dp(v[i],now);
		nowval+=f[v[i]][0];
		if (f[v[i]][1]<=f[v[i]][0]){
			if (f[v[i]][0]-f[v[i]][1]>mx1)mx2=mx1,id2=id1,mx1=f[v[i]][0]-f[v[i]][1],id1=v[i];
			else if (f[v[i]][0]-f[v[i]][1]>mx2)mx2=f[v[i]][0]-f[v[i]][1],id2=v[i];
		}
	}
	if (id1==0){
		g[now][0]=g[now][1]=h[now]=now;
		f[now][0]=nowval+1,f[now][1]=nowval;
	}
	else if (id2==0){
		g[now][0]=h[id1],g[now][1]=now,h[now]=h[id1];
		f[now][0]=nowval-mx1+1,f[now][1]=nowval-mx1;
	}
	else{
		g[now][0]=h[id1],g[now][1]=h[id2],h[now]=h[id1];
		f[now][0]=nowval-mx1-mx2+1;
		f[now][1]=nowval-mx1;
	}
	return;
}
inline void dfs(register int now,register int fa){
	if (book[now]==0){
		++tot;
		c[tot][0]=g[now][0],c[tot][1]=g[now][1];
		register int x=g[now][0],y=g[now][1];
		book[now]=tot;
		while(x!=now)book[x]=tot,x=up[x];
		while(y!=now)book[y]=tot,y=up[y];
	}
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=fa)dfs(v[i],now);
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (register int i=1;i<n;i++){
			scanf("%d%d",&u[i],&v[i]);
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		tot=0;
		dp(1,0);
		dfs(1,0);
		int now=0;
		printf("%d\n",tot-1);
		for (register int i=1;i<n;i++){
			if (book[u[i]]!=book[v[i]]){
				++now;
				printf("%d %d %d %d\n",u[i],v[i],c[now][1],c[now+1][0]);
			}
		}
		for (register int i=1;i<=2*n;i++)first[i]=nxt[i]=u[i]=v[i]=0;
		for (register int i=1;i<=n;i++)up[i]=book[i]=f[i][0]=f[i][1]=g[i][0]=g[i][1]=h[i]=0;
	}
	return 0;
}