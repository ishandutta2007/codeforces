#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int dp[1003][13][13],n,m;
vector<int>v[1003],g[13],V[1003];
long long f[1003][4096],ans,_ans;
void dfs(int x,int p){
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p){
			dfs(v[x][i],x);
			V[x].push_back(v[x][i]);
		}
	for(int i=0;i<m;i++){
		for(int j=0;j<V[x].size();j++)
			for(int k=0;k<(1<<g[i].size());k++){
				f[j+1][k]=f[j][k];
				for(int l=0;l<g[i].size();l++)
					if(k&(1<<l))
						f[j+1][k]=(f[j+1][k]+f[j][k^(1<<l)]*dp[V[x][j]][g[i][l]][i])%mod;
			}
		ans+=f[V[x].size()][(1<<g[i].size())-1];
		for(int j=0;j<g[i].size();j++)
			dp[x][i][g[i][j]]=f[V[x].size()][(1<<g[i].size())-1^(1<<j)];
	}
}
int mypow(int x,int times){
	int ret=1;
	while(times){
		if(times&1)
			ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;times>>=1;
	}return ret;
}
int main(){
//	freopen("trtr.in","r",stdin);
//	freopen("trtr.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}cin>>m;f[0][0]=1;
	for(int i=1;i<m;i++){
		int x,y;
		cin>>x>>y;x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}dfs(0,-1);
	_ans=ans;ans=0;
	n=m;
	for(int i=0;i<m;i++)
		v[i]=g[i],V[i].clear();
	dfs(0,-1);
	cout<<1ll*_ans*mypow(ans,mod-2)%mod;
}