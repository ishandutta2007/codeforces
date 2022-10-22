#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f,mod=998244353;
const int M=500;
int n,m;
int a[M+1];
int mnid[M+1][M+1];
int dp[M+2][M+1];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",a+i);
	for(int i=1;i<=m;i++){
		int mn=0x3f3f3f3f,mnid0;
		for(int j=i;j<=m;j++){
			if(a[j]<mn)mn=a[j],mnid0=j;
			mnid[i][j]=mnid0;
		}
	}
	for(int i=1;i<=m+1;i++)dp[i][i-1]=1;
	for(int i=m;i;i--)for(int j=i;j<=n;j++){
		int sum1=0,sum2=0;
		for(int k=i;k<=mnid[i][j];k++)(sum1+=1ll*dp[i][k-1]*dp[k][mnid[i][j]-1]%mod)%=mod;
		for(int k=mnid[i][j];k<=j;k++)(sum2+=1ll*dp[mnid[i][j]+1][k]*dp[k+1][j]%mod)%=mod;
		dp[i][j]=1ll*sum1*sum2%mod;
	}
	printf("%d",dp[1][m]);
	return 0;
}
/*1
3 3
1 2 3
*/
/*2
7 7
4 5 1 6 2 3 7
*/