#include<bits/stdc++.h>
const int A=1003,N=1003,M=1e6+3;
int f[A],n,m,b[N],c[N],dp[M],s,ans;
signed main(){
	std::fill(f,f+A,A);
	f[1]=0;
	for(int i=1;i<A;i++)
		for(int j=1;j<=i;j++)if(i+i/j<A)f[i+i/j]=std::min(f[i+i/j],f[i]+1);
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",b+i),b[i]=f[b[i]];
	s=0;
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
		s+=b[i];
		for(int j=s;j>=b[i];j--)dp[j]=std::max(dp[j],dp[j-b[i]]+c[i]);
	}
	ans=0;
	for(int j=0;j<=s&&j<=m;j++)ans=std::max(ans,dp[j]);
	printf("%d\n",ans);
	for(int j=0;j<=s;j++)dp[j]=0;
	}return 0;
}