/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000000,LET=20;
int n;
char a[N+5];
int mx[1<<LET];
int dp[1<<LET];
int main(){
	cin>>a+1;
	n=strlen(a+1);
	for(int i=1;i<=n;i++){
		int now=0;
		for(int j=i;j<=n;j++){
			if(now&1<<a[j]-'a')break;
			now|=1<<a[j]-'a';
			mx[now]=max(mx[now],j-i+1);
		}
	}
	for(int i=1;i<1<<20;i++){
		dp[i]=mx[i];
		for(int j=0;j<20;j++)if(i&1<<j)
			dp[i]=max(dp[i],dp[i^1<<j]);
	}
	int ans=0;
	for(int i=0;i<1<<20;i++)ans=max(ans,mx[i]+dp[(1<<20)-1^i]);
	cout<<ans;
	return 0;
}