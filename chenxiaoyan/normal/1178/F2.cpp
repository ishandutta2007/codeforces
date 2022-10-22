#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f,mod=998244353;
const int N=500,M=1000000,NWM=2*N+1;
int n,m;
int a[M+1];
int mn[NWM+1][NWM+1];
int lft[N+1],rit[N+1],inway[N+1];
int dp[NWM+2][NWM+1];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",a+i);
	m=unique(a+1,a+m+1)-1-a;
	if(m>2*n+1)return puts("0")&0;
	for(int i=1;i<=m;i++){
		int mn0=inf;
		for(int j=i;j<=m;j++)mn[i][j]=mn0=min(mn0,a[j]);
	}
	for(int i=1;i<=m;i++){
		if(!lft[a[i]])lft[a[i]]=i;
		rit[a[i]]=i;
	}
	for(int i=1;i<=m+1;i++)dp[i][i-1]=1;
	memset(inway,-1,sizeof(inway));
	for(int i=m;i;i--)for(int j=i;j<=m;j++)if(i<=lft[mn[i][j]]&&j>=rit[mn[i][j]]){
		if(!~inway[mn[i][j]]){
			inway[mn[i][j]]=1;
			int now=lft[mn[i][j]]+1;
			for(int k=now;k<=j;k++)if(a[k]==mn[i][j])
				inway[mn[i][j]]=1ll*inway[mn[i][j]]*dp[now][k-1]%mod,now=k+1;
		}
		int sum1=0,sum2=0;
		for(int k=i;k<=lft[mn[i][j]];k++)
			(sum1+=1ll*dp[i][k-1]*dp[k][lft[mn[i][j]]-1]%mod)%=mod;
		for(int k=rit[mn[i][j]];k<=j;k++)
			(sum2+=1ll*dp[rit[mn[i][j]]+1][k]*dp[k+1][j]%mod)%=mod;
		dp[i][j]=1ll*sum1*inway[mn[i][j]]%mod*sum2%mod;
	}
	printf("%d",dp[1][m]);
	return 0;
}
/*1
3 3
1 2 3
*/
/*2
2 3
1 2 1
*/
/*3
2 3
2 1 2
*/
/*4
7 7
4 5 1 6 2 3 7
*/
/*5
8 17
1 3 2 2 7 8 2 5 5 4 4 4 1 1 6 1 1
*/