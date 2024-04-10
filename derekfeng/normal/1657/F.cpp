#include<bits/stdc++.h>
using namespace std;
int n,q;
int dp[400005],fa[400005];
vector<int>tr[400005];
void dfs(int u,int pa){
	fa[u]=pa,dp[u]=dp[pa]+1;
	for(auto v:tr[u])if(v!=pa)dfs(v,u);
}
vector<int>getpath(int u,int v){
	vector<int>ans,rans;
	if(dp[v]<dp[u])swap(u,v);
	while(dp[v]!=dp[u])
		ans.push_back(v),v=fa[v];
	if(u==v){
		ans.push_back(u);
		return ans;
	}
	while(fa[u]!=fa[v]){
		rans.push_back(u),ans.push_back(v);
		u=fa[u],v=fa[v];
	}
	ans.push_back(v),ans.push_back(fa[v]),ans.push_back(u);
	for(int i=rans.size()-1;~i;i--)ans.push_back(rans[i]);
	return ans;
}
string s[400005],t[400005];
vector<int>path[400005];
char bd[400005][2];
bool vs[400005];
int tot,Id[400005][2],iD[400005][2];
vector<int>g[1600005];
stack<int>sta;
int T,cnt;
int cmp[16000005],vis[16000005],low[16000005];
bool ins[16000005];
void tarjan(int x){
	vis[x]=low[x]=++cnt;
	sta.push(x),ins[x]=1; 
	for(auto y:g[x]){
		if(!vis[y])tarjan(y);
		if(ins[y])low[x]=min(low[x],low[y]);
	}
	if(vis[x]==low[x]){
		T++;
		while(sta.top()!=x)cmp[sta.top()]=T,ins[sta.top()]=0,sta.pop();
		sta.pop(),cmp[x]=T,ins[x]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		tr[u].push_back(v),tr[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)bd[i][0]=bd[i][1]='a';
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		path[i]=getpath(u,v);
		cin>>s[i],t[i]=s[i];
		reverse(t[i].begin(),t[i].end());
		int N=path[i].size();
		for(int j=0;j<N;j++){
			int x=path[i][j];
			if(vs[x])continue;
			vs[x]=1,bd[x][0]=s[i][j],bd[x][1]=t[i][j];
		}
		Id[i][0]=++tot,Id[i][1]=++tot;
	}
	for(int i=1;i<=n;i++)iD[i][0]=++tot,iD[i][1]=++tot;
	for(int i=1;i<=q;i++){
		int N=path[i].size();
		for(int j=0;j<N;j++){
			int x=path[i][j];
			for(int k=0;k<2;k++)if(bd[x][k]!=s[i][j]){
				g[Id[i][0]].push_back(iD[x][k^1]);
				g[iD[x][k]].push_back(Id[i][1]);
			}
			for(int k=0;k<2;k++)if(bd[x][k]!=t[i][j]){
				g[Id[i][1]].push_back(iD[x][k^1]);
				g[iD[x][k]].push_back(Id[i][0]);
			}
		}
	}
	for(int i=1;i<=tot;i++)if(!vis[i])tarjan(i);
	for(int i=1;i<=tot;i+=2)if(cmp[i]==cmp[i+1])
		return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=n;i++){
		if(cmp[iD[i][0]]<cmp[iD[i][1]])putchar(bd[i][0]);
		else putchar(bd[i][1]);
	}
}