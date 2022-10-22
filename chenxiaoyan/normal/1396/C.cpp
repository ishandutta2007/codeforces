/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=1000000;
int n;
int r1,r2,r3,d;
int a[N+1];
int dp[N+1];
int x[N+1],y[N+1];
int Sum[N+1];
signed main(){
	cin>>n>>r1>>r2>>r3>>d;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++){
		x[i]=a[i]*min(r1,r3)+r3;
		y[i]=min(r2+min(min(r1,r2),r3),a[i]*min(r1,r3)+min(r1,r2)+min(min(r1,r2),r3));
		Sum[i]=Sum[i-1]+min(x[i],y[i]);
//		cout<<x[i]<<" "<<y[i]<<"\n";
	}
	int mn=inf;
	dp[1]=x[1];
	for(int i=2;i<n;i++){
		mn=min(mn,dp[i-2]-Sum[i-2]-2*(i-1)*d);
		dp[i]=min(dp[i-1]+x[i],mn+Sum[i]+2*i*d);
//		cout<<dp[i]<<"\n";
	}
	dp[n]=dp[n-1]+x[n];
	for(int i=0;i<=n-2;i++)
		dp[n]=min(dp[n],dp[i]+Sum[n]-Sum[i]+2*n*d-2*(i+1)*d),
		dp[n]=min(dp[n],dp[i]+Sum[n-1]-Sum[i]+x[n]+n*d-(i+1)*d);
	cout<<dp[n]+(n-1)*d;
	return 0;
}