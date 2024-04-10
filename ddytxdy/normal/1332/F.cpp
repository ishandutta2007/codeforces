#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=3e5+50,mod=998244353;
int n,f[N],g[N][3];
vector<int>v[N];
void dfs(int x){
	if(f[x])v[x].erase(find(v[x].begin(),v[x].end(),f[x]));
	g[x][0]=1;
	for(int i=0,y;i<v[x].size();i++){
		f[y=v[x][i]]=x;dfs(y);
		int w0=g[x][0],w1=g[x][1],w2=g[x][2],v0=g[y][0],v1=g[y][1],v2=g[y][2];
		g[x][0]=w0*(0ll+v0+v1+v2)%mod;
		g[x][1]=(w1*(0ll+v0+v1+v2)%mod+(w0+w1)*(2ll*v0+v1+v2)%mod)%mod;
		g[x][2]=(w2*(0ll+v0+v1+v2)%mod+1ll*(w0+w2)*(v0+v1)%mod)%mod;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
		scanf("%d%d",&x,&y),
		v[x].pb(y),v[y].pb(x);
	dfs(1);
	cout<<(mod-1ll+g[1][0]+g[1][1]+g[1][2])%mod;
	return 0;
}