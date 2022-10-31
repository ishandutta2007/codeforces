#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int n;
int sz[N],dp[N];

void dfs(int k,int fa){
	int s1=0,s2=0;
	sz[k]=1;
	fore(k)if(_to!=fa){
		dfs(_to,k);
		if(s1)s2=_to;
		else s1=_to;
		sz[k]+=sz[_to];
	}
	dp[k]=max(dp[s1]+sz[s2]-1,dp[s2]+sz[s1]-1);
	dp[k]=max(dp[k],0ll);
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)hd[i]=0;S=0;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs(1,0);
	cout<<dp[1]<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}