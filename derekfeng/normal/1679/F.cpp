#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,msk[10];
int f[514],g[514];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		msk[u]|=1<<v,msk[v]|=1<<u;
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		memset(g,0,sizeof(g));
		for(int j=0;j<(1<<9);j++)if(f[j])
			for(int k=0;k<10;k++)if(!((j>>k)&1))
				(g[(j|((1<<k)-1))&msk[k]]+=f[j])%=M;
		memcpy(f,g,sizeof(g));
	}
	int ans=0;
	for(int i=0;i<(1<<9);i++)(ans+=f[i])%=M;
	printf("%d",ans);
}