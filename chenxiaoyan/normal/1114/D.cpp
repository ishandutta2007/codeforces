#include<bits/stdc++.h>
using namespace std;
#define N 5000
int a[N+1],dp[N+1][N+1];
int main(){
	int n,i,j;scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	n=unique(a+1,a+n+1)-a-1;
//	cout<<n<<"\n";
	if(n==1)return puts("0");
	for(i=1;i<=n;i++)dp[1][i]=0;
	for(i=1;i<n;i++)dp[2][i]=a[i]!=a[i+1];
	for(i=3;i<=n;i++)for(j=1;j+i-1<=n;j++)
		if(a[j]==a[j+i-1])dp[i][j]=dp[i-2][j+1]+1;
		else dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+1;
	printf("%d",dp[n][1]);
	return 0;
}
/*1
4
5 2 2 1
*/
/*2
8
4 5 2 2 1 3 5 5
*/
/*3
1
4
*/