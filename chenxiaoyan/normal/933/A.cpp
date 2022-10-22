#include<bits/stdc++.h>
using namespace std;
#define N 2000
int a[N+1],dp1[N+1],dp2[N+2];
int main(){
	int n,ans=0,i,j;scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++){
		dp1[i]=1;
		for(j=1;j<i;j++)if(a[j]<=a[i])dp1[i]=max(dp1[i],dp1[j]+1);
	}
	for(i=2;i<=n;i++)dp1[i]=max(dp1[i-1],dp1[i]);
	for(i=n;i>=1;i--){
		dp2[i]=1;
		for(j=n;j>i;j--)if(a[j]>=a[i])dp2[i]=max(dp2[i],dp2[j]+1);
	}
	for(i=n-1;i;i--)dp2[i]=max(dp2[i+1],dp2[i]);
//	for(i=1;i<=n;i++)printf("dp1[%d]=%d,dp2[%d]=%d\n",i,dp1[i],i,dp2[i]);
	for(i=0;i<=n;i++)ans=max(ans,dp1[i]+dp2[i+1]);
	printf("%d",ans);
	return 0;
}
/*1'-
4
1 2 1 2
*/
/*2
10
1 1 2 2 2 1 1 2 2 1
*/