#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=2e18;
int n;
ll D,a[1000004],r1,r2,r3;
ll dp[1000004][2];
inline ll left0(int x){
	return a[x]*r1+r3;
}
inline ll left1(int x){
	return min(a[x]*r1+r1,r2);
}
int main(){
	scanf("%d%I64d%I64d%I64d%I64d",&n,&r1,&r2,&r3,&D);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for(int i=0;i<=n;i++)for(int j=0;j<2;j++)dp[i][j]=INF;
	dp[1][0]=left0(1),dp[1][1]=left1(1);
	for(int i=2;i<=n;i++){
		dp[i][0]=min(min(dp[i-1][0]+left0(i),dp[i-1][1]+left0(i)+2*D+r1),dp[i-1][1]+left1(i)+2*D+r1+r1)+D;
		dp[i][1]=min(dp[i-1][0]+left1(i),dp[i-1][1]+left1(i)+2*D+r1)+D;
		dp[i][0]=min(dp[i][0],INF);
		dp[i][1]=min(dp[i][1],INF);
	}
	printf("%I64d",min(dp[n][0],dp[n-1][1]+2*D+r1+left0(n)));
}