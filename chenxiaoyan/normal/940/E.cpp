/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100000; 
int n,m;
int a[N+1];
int q[N],head,tail;
int mn[N+1];
int dp[N+1];
signed main(){
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	for(int i=1;i<m;i++){
		while(head<tail&&a[q[tail-1]]>=a[i])tail--;
		q[tail++]=i;
	}
	for(int i=m;i<=n;i++){
		while(head<tail&&q[head]<=i-m)head++;
		while(head<tail&&a[q[tail-1]]>=a[i])tail--;
		q[tail++]=i;
		mn[i-m+1]=a[q[head]];
	}
	for(int i=m;i<=n;i++)dp[i]=max(dp[i-1],dp[i-m]+mn[i-m+1])/*,printf("dp[%lld]=%lld\n",i,dp[i])*/;
	cout<<sum-dp[n];
	return 0;
}