#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
typedef long long ll;
const ll inf=1e10,INF=1e18;
int n,K,T;
ll f[205][205][2],g[205][205][2];
ll a[205],b[205],c[205],sa[205],sb[205],sc[205];
int main(){
	for(int i=0;i<205;i++)for(int j=0;j<205;j++)
		for(int k=0;k<2;k++)f[i][j][k]=g[i][j][k]=INF;
	scanf("%d%d%d",&n,&T,&K);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	++n,a[n]=inf,b[n]=inf,c[n]=INF;
	for(int i=1;i<=n;i++)sa[i]=sa[i-1]+a[i],sb[i]=sb[i-1]+b[i],sc[i]=sc[i-1]+c[i];
	memset(f[0],0,sizeof(f[0])),memset(g[0],0,sizeof(g[0]));
	for(int i=1;i<=n;i++)for(int j=0;j<=T;j++)
		for(int k=0;k<2;k++){
			if(f[i-1][j][k]<INF&&a[i]*k+b[i]*j<=c[i]){
				f[i][j][k]=min(f[i][j][k],f[i-1][j][k]);
				ll val=(sa[i-1]*k+sb[i-1]*j+K-1)/K;
				if(val*K<=sa[i]*k+sb[i]*j)g[i][j][k]=min(g[i][j][k],val);
			}
			for(int r=0;r<j;r++)if(g[i][r][k]<INF){
				ll m=sa[i]*k+sb[i]*r-g[i][r][k]*K;
				ll x=(max(m+b[i]*(j-r)-c[i],0ll)+K-1)/K;
				if(x*K>m||f[i-1][j-r][0]==INF)continue;
				f[i][j][k]=min(f[i][j][k],g[i][r][k]+x+f[i-1][j-r][0]);
				ll val=(sb[i-1]*(j-r)+K-1)/K;
				if((g[i][r][k]+x+val)*K<=sa[i]*k+sb[i]*j)g[i][j][k]=min(g[i][j][k],g[i][r][k]+x+val);
			}
		}
	printf("%lld",f[n][T][1]);
}