#include<cstdio>
inline int read(){
	int a=0;char c=getchar();
	for(;c<48||c>57;c=getchar());for(;c>47&&c<58;a=a*10+c-48,c=getchar());
	return a;
}
inline int max(int a,int b){return a>b?a:b;}
const int N=1e5+1;
struct edge{int v,nxt;}g[N+N];
int n,a[N],b[N],s,m,head[N],k;
inline int Push(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
int dfs(int u,int fa,int x){
	int v,f=0;
	b[u]=a[u]?b[fa]+1:0;
	x=max(x,b[u]);
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa)
	  dfs(v,u,x),f=1;
	if(!f){s+=x<=m;return 0;}
}
int main(){
	int u,v;
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)u=read(),v=read(),Push(u,v),Push(v,u);
	dfs(1,0,0);
	printf("%d",s);
	return 0;
}