#include<bits/stdc++.h>
using namespace std;
int n,son[1000010],len[1000010],ans[1000010];
vector<int> v[1000010];
int *f[1000010],dp[1000010],*fl=dp;
void dfs(int x,int fa){
	for(int i=0;i<v[x].size();i++){
		if(v[x][i]==fa) continue;
		dfs(v[x][i],x);
		if(len[v[x][i]]>len[son[x]]) son[x]=v[x][i];
	}
	len[x]=len[son[x]]+1;
}
void solve(int x,int fa){
	f[x][0]=1;
	if(!son[x]) return;
	f[son[x]]=f[x]+1;
	solve(son[x],x);
	if(f[son[x]][ans[son[x]]]>1) ans[x]=ans[son[x]]+1;
	for(int i=0;i<v[x].size();i++){
		if(v[x][i]==fa||v[x][i]==son[x]) continue;
		f[v[x][i]]=fl;fl+=len[v[x][i]];
		solve(v[x][i],x);
		for(int j=1;j<=len[v[x][i]];j++){
			f[x][j]+=f[v[x][i]][j-1];
			if(f[x][ans[x]]==f[x][j]&&j<ans[x]) ans[x]=j;
			if(f[x][ans[x]]<f[x][j]) ans[x]=j;
		}
	} 
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
//	for(int i=1;i<=n;i++) printf("%d\n",len[i]);
	f[1]=fl;fl+=len[1];
	solve(1,0);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}