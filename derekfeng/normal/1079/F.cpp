#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int n;
vector<int>g[300004];
int f[300004][3],nf[3];
void dfs(int x,int fa){
	for(auto y:g[x])if(y!=fa)dfs(y,x);
	f[x][0]=1;
	for(auto y:g[x])if(y!=fa){
		memset(nf,0,sizeof(nf));
		for(int i=0;i<3;i++)(nf[i]+=(ll)f[x][i]*(f[y][0]+f[y][2])%M)%=M;
		(nf[1]+=(ll)f[y][2]*(f[x][0]+f[x][1])%M)%=M;
		(nf[2]+=(ll)f[y][0]*(f[x][0]+f[x][1])%M)%=M;
		(nf[2]+=(ll)f[y][1]*(f[x][0]+f[x][1])%M)%=M;
		(nf[2]+=(ll)f[y][2]*f[x][2]%M)%=M;
		memcpy(f[x],nf,12);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,0);
	printf("%d",(f[1][0]+f[1][2])%M);
}