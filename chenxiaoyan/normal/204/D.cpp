#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000000
#define mod 1000000007
char s[N+5];
int dp1[N+1],dp2[N+1],Sumw[N+1],Sumb[N+1];
signed main(){
	int n,m,power=1,Sum1=0,Sum2=0,ans=0,i;scanf("%lld%lld%s",&n,&m,s+1);
	for(i=1;i<=n;i++)Sumw[i]=Sumw[i-1]+(s[i]=='W'),Sumb[i]=Sumb[i-1]+(s[i]=='B');
	for(i=m;i<=n;i++){
		if(s[i-m]=='X')(power*=2)%=mod;
		if(i>2*m){
			(Sum1-=dp1[i-m-1])%=mod;(Sum2+=dp1[i-m-1])%=mod;
			if(s[i-m]=='X')(Sum2*=2)%=mod;
		}
		if(Sumw[i]-Sumw[i-m]==0)dp1[i]=(power-Sum1-Sum2)%mod;
		(Sum1+=dp1[i])%=mod;
	}
	power=1;Sum1=Sum2=0;
	for(i=n-m+1;i;i--){
		if(s[i+m]=='X')(power*=2)%=mod;
		if(i<n-2*m+1){
			(Sum1-=dp2[i+m+1])%=mod;(Sum2+=dp2[i+m+1])%=mod;
			if(s[i+m]=='X')(Sum2*=2)%=mod;
		}
		if(Sumb[i+m-1]-Sumb[i-1]==0)dp2[i]=(power-Sum1-Sum2)%mod;
		(Sum1+=dp2[i])%=mod;
	}
	Sum1=0;
	for(i=n-m;i>=m;i--){
		if(s[i+1]=='X')(Sum1*=2)%=mod;
		(Sum1+=dp2[i+1])%=mod;
		(ans+=dp1[i]*Sum1%mod)%=mod;
	}
	printf("%lld",(ans+mod)%mod);
	return 0;
}
/*1
3 2
XXX
*/
/*2
4 2
XXXX
*/
/*3
10 2
XXBXXWXXXX
*/