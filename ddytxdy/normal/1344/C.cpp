#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50;
int n,m,ans,d[N],st[N],tp,num;bool vis[N][2],fl[N];
vector<int>v[N],vv[N];
void dfs(int x,int op){
	vis[x][op]=1;
	if(op){for(int i=0,y;i<vv[x].size();i++)if(!vis[y=vv[x][i]][1])dfs(y,1);}
	else {for(int i=0,y;i<v[x].size();i++)if(!vis[y=v[x][i]][0])dfs(y,0);}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
		scanf("%d%d",&x,&y),
		v[x].pb(y),vv[y].pb(x),d[y]++;
	for(int i=1;i<=n;i++)if(!d[i])st[++tp]=i;
	while(tp){
		int x=st[tp--];num++;
		for(int i=0,y;i<v[x].size();i++)if(!--d[y=v[x][i]])st[++tp]=y;
	}
	if(num!=n)puts("-1"),exit(0);
	for(int i=1;i<=n;i++){
		if(!vis[i][0]&&!vis[i][1])ans++,fl[i]=1;
		if(!vis[i][0])dfs(i,0);
		if(!vis[i][1])dfs(i,1);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)putchar(fl[i]?'A':'E');
}