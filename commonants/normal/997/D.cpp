#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MX=4005,MXK=81;
const int md=998244353;

int n1,n2,k;
int f[3][MXK];
vector<int>G[MX];

int fa[MX],g[MX][MXK],gs[MX][MXK],gf[MX][MXK];

#define A(x,y) ((x)=((x)+(ll)(y))%md)

void dfs(int i,int f){
	fa[i]=f;
	for(auto j:G[i])if(j!=f)dfs(j,i);
}
void dfsgs(int i){
	for(auto j:G[i])if(j!=fa[i])dfsgs(j);
	gs[i][0]=1;
	for(int t=2;t<=k;t+=2){
		for(auto j:G[i])if(j!=fa[i])
			for(int l=0;l<=t-2;l+=2)
				A(gs[i][t],(ll)gs[j][l]*gs[i][t-l-2]);
	}
}
void dfsgf(int i){
	for(auto j:G[i])if(j!=fa[i])gf[j][0]=1;
	for(int t=2;t<=k;t+=2){
		static int tmp[MXK];
		memset(tmp,0,sizeof(int)*(k+1));
		for(int q=0;q<=t-2;q+=2)A(tmp[q],gf[i][q]);
		for(auto j:G[i])if(j!=fa[i])
			for(int q=0;q<=t-2;q+=2)
				A(tmp[q],gs[j][q]);
		for(auto j:G[i])if(j!=fa[i]){
			for(int q=0;q<=t-2;q+=2)
				A(tmp[q],md-gs[j][q]);
			for(int q=0;q<=t-2;q+=2)
				A(gf[j][t],(ll)tmp[q]*gf[j][t-q-2]);
			for(int q=0;q<=t-2;q+=2)
				A(tmp[q],gs[j][q]);
		}
	}
	for(auto j:G[i])if(j!=fa[i])dfsgf(j);
}
void solve(int n,int k,int ans[]){
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs(1,0);
	memset(g,0,sizeof(g));
	memset(gs,0,sizeof(gs));
	memset(gf,0,sizeof(gf));
	dfsgs(1);
	dfsgf(1);
	for(int i=1;i<=n;i++){
		g[i][0]=1;
		for(int t=2;t<=k;t+=2){
			for(int q=0;q<=t-2;q+=2)
				A(g[i][t],(ll)gf[i][q]*g[i][t-q-2]);
			for(auto j:G[i])if(j!=fa[i]){
				for(int q=0;q<=t-2;q+=2)
					A(g[i][t],(ll)gs[j][q]*g[i][t-q-2]);
			}
		}
		for(int j=0;j<=k;j+=2)A(ans[j],g[i][j]);
	}
}
int C[MXK][MXK];
void ini(){
	for(int i=0;i<MXK;i++)
		for(int j=(C[i][0]=C[i][i]=1);j<i;j++)
			A(C[i][j],C[i-1][j]+C[i-1][j-1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n1>>n2>>k;
	ini();
	solve(n1,k,f[1]);
	solve(n2,k,f[2]);
	int ans=0;
	for(int i=0;i<=k;i+=2){
		A(ans,(ll)f[1][i]*f[2][k-i]%md*C[k][i]);
	}
	cout<<ans<<endl;
	return 0;
}
// r-l=max-min

// f[i][j]: i  j 
// f[i][j](...)