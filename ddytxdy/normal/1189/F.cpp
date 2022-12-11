#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1010,mod=998244353,M=1e5+50;
int n,k,a[N],s[M],dp[N][N];LL ans;
int calc(int x){
	dp[0][0]=1;
	for(int i=1;i<=k;i++){
		LL sum=0;
		for(int j=i,l=i-1;j<=n;j++){
			while(a[j]-a[l]>=x)sum+=dp[i-1][l++];
			dp[i][j]=sum%mod;
		}
	}
	LL ret=0;
	for(int i=k;i<=n;i++)ret+=dp[k][i];
	return ret%mod;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);a[0]=-1e9;
	for(int i=1;i*(k-1)<=(a[n]-a[1]);i++)s[i]=calc(i);
	for(int i=(a[n]-a[1])/(k-1);i;i--){
		int x=(s[i]+mod-s[i+1])%mod;
		(ans+=1ll*x*i)%=mod;
	}
	cout<<ans%mod;
	return 0;
}