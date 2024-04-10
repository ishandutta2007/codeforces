#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
using namespace std;
const int MX=600111;
int n,m;
int pool[MX],*c[MX],s[MX];
int hed[MX],nxt[MX],t[MX],ec,vis[MX],vism[MX],no[MX];
set<int>cur;
inline void ade(int u,int v){
	ec++;nxt[ec]=hed[u];t[ec]=v;hed[u]=ec;
}
void dfs(int k){
	vis[k]=1;
	for(int *i=c[k];i!=c[k+1];i++)if(vism[*i])cur.erase(no[*i]);
	for(int *i=c[k];i!=c[k+1];i++)if(!vism[*i]){
		no[*i]=*(cur.lower_bound(1));
		cur.erase(no[*i]);
		vism[*i]=1;
	}
	for(int *i=c[k];i!=c[k+1];i++)cur.insert(no[*i]);
	for(int i=hed[k];i;i=nxt[i])if(!vis[t[i]])dfs(t[i]);
}
int main(){
	scanf("%d%d",&n,&m);
	c[1]=pool;int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		for(int j=0;j<s[i];j++)scanf("%d",&c[i][j]);
		c[i+1]=c[i]+s[i];
		ans=max(ans,s[i]);
	}
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		ade(u,v),ade(v,u);
	}
	ans=max(ans,1);
	for(int i=1;i<=ans;i++)cur.insert(i);
	printf("%d\n",ans);
	dfs(1);
	for(int i=1;i<=m;i++)if(!vism[i])no[i]=1;
	for(int i=1;i<=m;i++)printf("%d ",no[i]);puts("");
	return 0;
}