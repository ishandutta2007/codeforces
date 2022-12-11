#include<bits/stdc++.h>
using namespace std;
const int S=5e5+5;
vector<int>d[S],o[S];
bool *f[26][S],dp[26][S],ans[S],*ptr[26];int dep[S],fir[S],l[S<<1],to[S<<1],Dep[S],ec,son[S],n,m;char s[S];
void link(int a,int b){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;}
void dfs(int p){
	for(int i=fir[p],y;y=to[i];i=l[i])Dep[y]=Dep[p]+1,dfs(y),son[p]=dep[y]>dep[son[p]]?y:son[p];
	dep[p]=dep[son[p]]+1;
}
void DFS(int p){
	if(son[p]){
		for(int i=0;i<26;++i)f[i][son[p]]=f[i][p]+1;
		DFS(son[p]);
	}
	f[s[p]-'a'][p][0]^=1;
	for(int i=fir[p],y;y=to[i];i=l[i])if(y!=son[p]){
		for(int j=0;j<26;++j)f[j][y]=ptr[j],ptr[j]+=dep[y];
		DFS(y);
		for(int j=1;j<=dep[y];++j)for(int i=0;i<26;++i)f[i][p][j]^=f[i][y][j-1];
	}
	for(int i=0;i<d[p].size();++i)
		if(d[p][i]<0||d[p][i]>=dep[p])ans[o[p][i]]=1;
		else{
			int cnt=0;
			for(int j=0;j<26;++j)cnt+=f[j][p][d[p][i]];
			ans[o[p][i]]=cnt<=1;
		}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2,a;i<=n;++i)scanf("%d",&a),link(a,i);
	scanf("%s",s+1);
	for(int i=0;i<26;++i)ptr[i]=dp[i];
	dfs(Dep[1]=1);
	for(int i=0;i<26;++i)f[i][1]=ptr[i],ptr[i]+=dep[1];
	for(int i=1,u,D;i<=m;++i)scanf("%d%d",&u,&D),o[u].push_back(i),d[u].push_back(D-Dep[u]);
	DFS(1);
	for(int i=1;i<=m;++i)puts(ans[i]?"Yes":"No");
}