#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(short x){
	if(x>9)write(x/10);
	putchar(x%10+'0'); 
}
void outputno(){
	puts("NO");exit(0);
}
int n,m,n1,n2,n3,u,v,cnt;
int rt[5003],C0[5003],C1[5003];
int fr[5003][5003];
short ans[5003];
vector<int>g[5003];
int vis[5003];
void dfs(int x,int &cnt0,int &cnt1,int cur){
	vis[x]=cur;
	if(cur==0)cnt0++;
	else cnt1++;
	for(int i=0;i<g[x].size();i++){
		if(vis[g[x][i]]<0) dfs(g[x][i],cnt0,cnt1,cur^1);
		else if(vis[g[x][i]]!=cur^1) outputno();
	}
}
void Make(int x,int cur){
	vis[x]=cur;
	if(cur==0)ans[x]=2;
	else{
		if(n1>0) ans[x]=1,n1--;
		else ans[x]=3;
	}
	for(int i=0;i<g[x].size();i++)
		if(vis[g[x][i]]<0) Make(g[x][i],cur^1);
}
void Go(int x,int num){
	if(x==0) return;
	int WANT=num-fr[x][num];
	if(WANT==C0[x]) Make(rt[x],0);
	else Make(rt[x],1);
	Go(x-1,fr[x][num]);
}
int main(){
	memset(vis,-1,sizeof(vis));
	read(n),read(m),read(n1),read(n2),read(n3);
	for(int i=0;i<m;i++){
		read(u),read(v);
		g[u].push_back(v),g[v].push_back(u);
	}
	memset(fr,-1,sizeof(fr));
	fr[0][0]=0;
	for(int i=1;i<=n;i++)if(vis[i]<0){
		rt[++cnt]=i,dfs(i,C0[cnt],C1[cnt],0);
		for(int j=0;j<=n2;j++)if(fr[cnt-1][j]>=0){
			if(j+C0[cnt]<=n2)fr[cnt][j+C0[cnt]]=j;
			if(j+C1[cnt]<=n2)fr[cnt][j+C1[cnt]]=j;
		}
	}
	memset(vis,-1,sizeof(vis));
	if(fr[cnt][n2]<0)outputno();
	Go(cnt,n2);
	puts("YES");
	for(int i=1;i<=n;i++)write(ans[i]);
}