#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100000
#define LOGA 18
int a[N+1],dp[N+1][LOGA],Sum[N+1];
signed main(){
	int n,qu,i,j;scanf("%lld",&n);
	for(i=1;i<=n;i++)scanf("%lld\n",a+i),Sum[i]=Sum[i-1]+a[i];
	for(i=1;i<=LOGA;i++)for(j=1;j+(1<<i)-1<=n;j++)
		dp[j][i]=dp[j][i-1]+dp[j+(1<<i-1)][i-1]+((Sum[j+(1<<i)-1]-Sum[j+(1<<i-1)-1])%10+(Sum
		[j+(1<<i-1)-1]-Sum[j-1])%10>=10);
//	for(i=1;i<=LOGA;i++)for(j=1;j+i-1<=n;j++)printf("dp[%lld][%lld]=%lld\n",j,i,dp[j][i]);
	scanf("%lld",&qu);
	while(qu--){
		int l,r;scanf("%lld%lld",&l,&r);
		printf("%lld\n",dp[l][(int)log2(r-l+1)]);
	}
	return 0;
}
/*1
8
8 7 3 1 7 0 9 4
3
1 8
2 5
7 7
*/
/*2
6
0 1 2 3 3 5
3
1 2
1 4
3 6
*/