#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^'0'),ch=getchar();
	return x; 
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int n,l[1000004],len[1000004],ans[1000004];
vector<int>g[1000004],f[1000004];
void dfs(int x,int par){
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(to!=par){
			dfs(to,x);
			if(len[to]+1>len[x])l[x]=to,len[x]=len[to]+1;
		}
	}
}
void dfs1(int x,int par){
	if(!l[x])f[x].push_back(1),ans[x]=0;
	else{
		dfs1(l[x],x);
		swap(f[x],f[l[x]]);
		f[x].push_back(1);
		ans[x]=ans[l[x]];
		if(f[x][ans[x]]==1)ans[x]=len[x];
		for(int i=0;i<g[x].size();i++){
			int to=g[x][i];
			if(to!=par&&to!=l[x]){
				dfs1(to,x);
				for(int j=0;j<=len[to];j++){
					f[x][j+len[x]-len[to]-1]+=f[to][j];
					if(f[x][j+len[x]-len[to]-1]>f[x][ans[x]]||(f[x][j+len[x]-len[to]-1]==f[x][ans[x]]&&ans[x]<j+len[x]-len[to]-1))
						ans[x]=j+len[x]-len[to]-1;
				}
			}
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int u,v;u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,-1);
	dfs1(1,-1);
	for(int i=1;i<=n;i++)print(len[i]-ans[i]),puts("");
}