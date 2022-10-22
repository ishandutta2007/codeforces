#include<bits/stdc++.h>
const int N=3003,M=1e9+7;
int n,m,f[N][N];
char a[N][N];
inline int Calc(int sx,int sy,int tx,int ty){
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)f[i][j]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]=='.')
		f[i][j]=i==sx&&j==sy?1:(f[i-1][j]+f[i][j-1])%M;
	return f[tx][ty];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	printf("%lld\n",(((long long)Calc(1,2,n-1,m)*Calc(2,1,n,m-1)-(long long)Calc(1,2,n,m-1)*Calc(2,1,n-1,m))%M+M)%M);
	return 0;
}