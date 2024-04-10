#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void outputno(){
	puts("IMPOSSIBLE");exit(0);
}
int t,T,n,m,l[100004],r[100004],MAXN,MINN=1e9,u,v,vis[100004];
vector<int>g[100004];
void dfs(int x){
	for(int i=0;i<g[x].size();i++){
		if(vis[g[x][i]]<0) vis[g[x][i]]=(vis[x]^1),dfs(g[x][i]);
		else if(vis[g[x][i]]!=(vis[x]^1)) outputno();
	}
}
int main(){
	read(t),read(T),read(n),read(m);
	for(int i=1;i<=n;i++) read(l[i]),read(r[i]),MINN=min(MINN,r[i]),MAXN=max(MAXN,l[i]);
	if(MINN+MAXN<t)MAXN=t-MINN;
	if(MINN+MAXN>T)MINN=T-MAXN;
	if(MINN<0||MAXN<0)outputno();
	for(int i=1;i<=n;i++){
		vis[i]=-1;
		bool f1=(l[i]<=MINN&&MINN<=r[i]),f2=(l[i]<=MAXN&&MAXN<=r[i]);
		if(!f1 && !f2)outputno();
		if(f1 && !f2)vis[i]=1;
		if(!f1 && f2)vis[i]=0;
	}
	for(int i=0;i<m;i++)
		read(u),read(v),g[u].push_back(v),g[v].push_back(u); 
	for(int i=1;i<=n;i++)if(vis[i]>=0)dfs(i);
	for(int i=1;i<=n;i++)if(vis[i]<0)vis[i]=0,dfs(i);
	puts("POSSIBLE"),write(MAXN),putchar(' '),write(MINN),puts("");
	for(int i=1;i<=n;i++)write(vis[i]+1);
}