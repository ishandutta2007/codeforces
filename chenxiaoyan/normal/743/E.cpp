#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1000,A=8,LOGN=10;
int n;
int a[N+1];
int cnt[A+1],rk[N+1],kth[A+1][N+1];
int dp[N+1][1<<A];
int ans(int m){
//	cout<<"m="<<m<<"\n";
	for(int i=0;i<=n;i++)for(int j=1;j<1<<8;j++)dp[i][j]=-inf;
	for(int i=1;i<=n;i++)for(int j=1;j<1<<8;j++){
		dp[i][j]=max(dp[i][j],dp[i-1][j]);
		for(int k=1;k<=8;k++)if(j&1<<k-1){
			if(m==1)dp[i][j]=max(dp[i][j],dp[i][j^1<<k-1]);
			if(a[i]==k){
				if(rk[i]>=m)dp[i][j]=max(dp[i][j],m+dp[kth[k][rk[i]-m+1]-1][j^1<<k-1]);
				if(rk[i]>=m-1&&m-1)dp[i][j]=max(dp[i][j],m-1+dp[kth[k][rk[i]-m+2]-1][j^1<<k-
				1]);
			}
		}
	}
//	for(int i=1;i<=n;i++)for(int j=1;j<1<<8;j++){
//		printf("dp[%d][",i);
//		for(int k=1;k<=8;k++)cout<<!!(j&1<<k-1);
//		printf("]=%d\n",dp[i][j]);
//	}
	return dp[n][(1<<8)-1];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)rk[i]=++cnt[a[i]],kth[a[i]][rk[i]]=i;
	int m=0;
	for(int i=LOGN;~i;i--)if(1+(m|1<<i)<=n&&ans(1+(m|1<<i))>0)m|=1<<i;
	printf("%d",ans(m+1));
	return 0;
}
/*1
3
1 1 1
*/
/*2
8
8 7 6 5 4 3 2 1
*/
/*3
24
1 8 1 2 8 2 3 8 3 4 8 4 5 8 5 6 8 6 7 8 7 8 8 8
*/
/*4
15
5 2 2 7 5 2 6 4 3 8 1 8 4 2 7
*/