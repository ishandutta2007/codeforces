#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
typedef long long ll;
const int N=60;
int T,n,k,x;
int f[70][14][14][14][14];
int dp[14][14][14][70];
int iv[14];
int myp(int x,int t){
	int a=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)a=(ll)a*x%M;
	return a;
}
void init(){
	for(int i=1;i<=12;i++)iv[i]=myp(i,M-2);
	for(int i=2;i<=12;i++)f[i][i-1][i][i-1][0]=1;
	for(int i=1;i<=N;i++)for(int j=11;j;j--)
		for(int p=1;p<=j+1;p++)for(int k=0;k<=11;k++)for(int x=0;x<=11;x++){
			if(f[i][j][p][k][x])for(int t=1;t<=12;t++){
				int ni=i+max(0,t-j),nj=max(j-1,t-1);
				int np=t,nk=k+(t-1),nx=x+(p>t);
				if(nk<=11&&nx<=11)
					(f[ni][nj][np][nk][nx]+=f[i][j][p][k][x])%=M;
			}
		}
	dp[0][0][0][0]=1;
	for(int t=0;t<=11;t++)for(int k=0;k<=11;k++)for(int x=0;x<=11;x++)for(int i=0;i<=N;i++)
		for(int kk=0;kk<=k;kk++)for(int xx=0;xx<=x;xx++)for(int j=0;j<=i;j++)
			(dp[t+1][k][x][i]+=(ll)dp[t][kk][xx][j]*f[i-j][0][1][k-kk][x-xx])%=M;
}
int C(int a,int b){
	int ans=1;
	for(int i=a,j=1;j<=b;i--,j++)
		ans=(ll)ans*i%M*iv[j]%M;
	return ans;
}
void sol(){
	int n,k,x;scanf("%d%d%d",&n,&k,&x);
	int ans=0;
	for(int t=0;t<=11;t++)for(int i=0;i<=N;i++)if(dp[t][k][x][i]&&i<=n)
		(ans+=(ll)dp[t][k][x][i]*C(n-i+t,t)%M)%=M;
	printf("%d\n",ans);
}
int main(){
	init();
	scanf("%d",&T);
	while(T--)sol();
}