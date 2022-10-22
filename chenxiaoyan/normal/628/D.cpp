#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int mod=1000000007;
const int N=2000,M=2000;
int n,m,evn;
string as,bs;
int a[N+1],b[N+1];
int pw[N+1];
int dp[N+1][M];
void dp_init(){
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*10%m;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)
		if(i+n&1)dp[i][j]=dp[i-1][(j-evn*pw[i-1]%m+m)%m];
		else for(int k=0;k<=9;k++)if(k!=evn)(dp[i][j]+=dp[i-1][(j-k*pw[i-1]%m+m)%m])%=mod;
}
bool ok(int dig[]){
	for(int i=1;i<=n;i++)if(i+n&1&&dig[i]!=evn||!(i+n&1)&&dig[i]==evn)return false;
	int rem=0;
	for(int i=1;i<=n;i++)(rem+=dig[i]*pw[i-1])%=m;
	return !rem;
}
int ans(int a[]){
	int res=0,now=0;
	for(int i=0;i<n;i++){
		if(i)
			if((!(n-i+1+n&1)||a[n-i+1]==evn)&&(n-i+1+n&1||a[n-i+1]!=evn))(now+=a[n-i+1]*pw[n-i])%=m;
			else return res;
		vector<int> can;
		if(n-i+n&1)can.pb(evn);
		else for(int j=0;j<=9;j++)if(j!=evn)can.pb(j);
//		for(int j=0;j<can.size();j++)if((i||can[j])&&can[j]<a[n-i])cout<<can[j]<<" ";puts("");
		for(int j=0;j<can.size();j++)if((i||can[j])&&can[j]<a[n-i])
			(res+=dp[n-i-1][(-now-can[j]*pw[n-i-1]%m+2*m)%m])%=mod;
	}
	return (res+ok(a))%mod;
}
int main(){
	cin>>m>>evn>>as>>bs;
	n=as.size();
	for(int i=1;i<=n;i++)a[i]=as[i-1]^48,b[i]=bs[i-1]^48;
	reverse(a+1,a+n+1);reverse(b+1,b+n+1);
	dp_init();
	cout<<(ans(b)-ans(a)+ok(a)+mod)%mod;
	return 0;
}
/*1
2 6
10
99
*/
/*2
2 0
1
9
*/
/*3
19 7
1000
9999
*/
/*4
2 9
10000000000
99999999999
*/