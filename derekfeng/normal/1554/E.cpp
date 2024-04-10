#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int Tc,n,ans[100004],dp[100004];
vector<int>g[100004];
bool ok;
void dfs(int x,int par,int C){
	if(!ok)return;
	for(auto y:g[x])if(y!=par)dfs(y,x,C);
	if(dp[x]%C!=0){
		if(par)dp[x]++;
		if(dp[x]%C!=0){
			ok=0;
			return;
		}
	}else dp[par]++;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)ans[i]=0;
	ans[1]=1;
	for(int i=1;i<n;i++)ans[1]=(ans[1]+ans[1])%M;
	for(int i=2;i<=n-1;i++)if((n-1)%i==0){
		for(int j=0;j<=n;j++)dp[j]=0;
		ok=1,dfs(1,0,i),ans[i]=ok;
	}
	for(int i=n;i;i--)
		for(int j=i+i;j<=n;j+=i)
			ans[i]=(ans[i]-ans[j]+M)%M;
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
}
int main(){for(scanf("%d",&Tc);Tc--;)solve();}