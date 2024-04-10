#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long n,k,l;
pair<long long,int>a[1000003];
long long howmany(int y,int x){
	int b=a[y].second;
	if(b<(l-1)%n+1)return((l-1+n)/n-x)%mod;
    else return((l-1)/n-x)%mod;
}
int main(){
	cin>>n>>l>>k;
	long long dp[k][n];
	long long ans=0,num=0;
	for(int i=0;i<n;i++)scanf("%lld",&a[i].first),a[i].second=i;
	sort(a,a+n);
	for(int i=0;i<n;i++)dp[0][i]=1;
	ans=l%mod;
	for(int i=1;i<k;i++){
		long long cnt=0,kk=0;
		for(int j=0;j<n;j++)
			if(i*n+a[j].second<l)
			{
				while(a[kk].first<=a[j].first&&kk<n)cnt=(cnt+dp[i-1][kk++])%mod;
				dp[i][j]=cnt;
				ans=(ans+dp[i][j]*howmany(j,i)%mod)%mod;
//				cout<<i<<' '<<j<<' '<<cnt<<' '<<dp[i][j]<<' '<<howmany(j,i)<<endl;
			}
	}
	cout<<ans;
}