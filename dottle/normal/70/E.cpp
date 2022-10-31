#include<bits/stdc++.h>
#define int long long
const int N=405;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int f[N][N],mn[N],lc[N][N];
int d[N],fa[N],dp[N];
int n,m;

void dfs(int k,int f){
	fa[k]=f,dp[k]=dp[f]+1;
	fore(k)if(_to!=f)
		dfs(_to,k);
}
int lca(int x,int y){
	if(x==y)return x;
	if(lc[x][y])return lc[x][y];
	if(dp[x]<dp[y])swap(x,y);
	return lc[x][y]=lca(fa[x],y);
}
int dis(int x,int y){
	return d[dp[x]+dp[y]-2*dp[lc[x][y]]];
}
void df5(int k,int fa){
	for(int i=1;i<=n;i++)
		f[k][i]=dis(k,i);
	fore(k)if(_to!=fa){
		df5(_to,k);
		mn[k]=0;
		for(int j=1;j<=n;j++)
			f[k][j]+=min(f[_to][mn[_to]]+m,f[_to][j]);
	}
	for(int i=1;i<=n;i++)
		mn[k]=f[k][mn[k]]>f[k][i]?i:mn[k];
}

int ans[N];
void geta(int k,int cs){
	ans[k]=cs;
	fore(k)if(_to!=fa[k]){
		if(f[_to][cs]<f[_to][mn[_to]]+m)geta(_to,cs);
		else geta(_to,mn[_to]);
	}
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<n;i++)cin>>d[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			lc[i][j]=lca(i,j);
	for(int i=1;i<=n;i++)
		f[i][0]=1e18;
	df5(1,0);
	cout<<f[1][mn[1]]+m<<endl;
	geta(1,mn[1]);
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}