/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int N=100000;
int n;
char a[N+5];
int dp[N+1];
int main(){
	cin>>a+1;
	n=strlen(a+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=1)(dp[i]+=dp[i-1])%=mod;
		if(i>=2)(dp[i]+=dp[i-2])%=mod;
	}
	for(int i=1;i<=n;i++)if(a[i]=='m'||a[i]=='w')return puts("0"),0;
	int ans=1;
	for(int i=1,ie;i<=n;i=max(i+1,ie+1)){
		ie=i-1;while(ie+1<=n&&(a[i]=='n'||a[i]=='u')&&a[ie+1]==a[i])ie++;
		ans=1ll*ans*dp[ie-i+1]%mod;
	}
	cout<<ans;
	return 0;
}