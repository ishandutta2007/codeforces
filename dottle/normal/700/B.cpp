#include<bits/stdc++.h>
#define int long long
const int N=500050;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int sz[N],dp[N],a[N],ans;
void dfs(int k,int fa){
	sz[k]=a[k],dp[k]=dp[fa]+1;
	ans+=dp[k]*a[k];
	fore(k)if(_to!=fa)
		dfs(_to,k),sz[k]+=sz[_to];
}

void solve(int k,int fa,int d){
	ans-=(sz[k]-d);
	int sm=0,mx=0;
	fore(k)if(_to!=fa)
		mx=sz[_to]>sz[mx]?_to:mx;
	if(sz[mx]-d>sz[k]-sz[mx])
		solve(mx,k,d+sz[k]-sz[mx]);
}

main(){
	dp[0]=-1;
	int n,k;cin>>n>>k;
	for(int i=1;i<=k*2;i++){
		int x;cin>>x;
		a[x]=1;
	}
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs(1,0);
	solve(1,0,0);
	cout<<ans+2*k<<endl;
}