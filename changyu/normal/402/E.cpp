#include<cstdio>
namespace io{
const int D=1<<20;char buf[D],*s,*t;
inline char get(){return s==t&&(t=(s=buf)+fread(buf,1,D,stdin),s==t)?-1:*s++;}
inline int read(){
	int a=0;char c=get();
	for(;c<48||c>57;c=get());for(;c>47&&c<58;a=a*10+c-48,c=get());
	return a;
}
}using io::read;
const int N=2003;
int g[N][N],n,ord[N],k,c,used[N];
void Dfs(int u){
	if(used[u])return;
	used[u]=1;
	for(int v=1;v<=n;v++)if(g[u][v])Dfs(v);
	ord[++k]=u; 
}
void Dfs1(int u){
	if(used[u])return;
	used[u]=1;
	for(int v=1;v<=n;v++)if(g[v][u])Dfs1(v); 
}
signed main(){
	int u,v;
	n=read();
	for(u=1;u<=n;u++)for(v=1;v<=n;v++)g[u][v]=read();
	k=0;
	for(u=1;u<=n;u++)used[u]=0;
	Dfs(1);
	if(k<n)return 0*puts("NO");
	c=0;
	for(u=1;u<=n;u++)used[u]=0;
	for(int i=k;i;i--)
	  if(!used[ord[i]]){
	  	if(c)return 0*puts("NO");
		Dfs1(ord[i]),c=1;
	  }
	puts("YES");
	return 0;
}