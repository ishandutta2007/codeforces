#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t,k,a,b,i;
	cin>>t>>k;
	ll dp[100005];
	dp[0]=0;
	for(i=1;i<k;++i)dp[i]=1;
	dp[k]=2;
	for(i=k+1;i<=100001;++i)
	{
		dp[i]=(dp[i-1]+dp[i-k])%M;
	}
	for(i=1;i<=100001;++i)
		dp[i]=(dp[i-1]+dp[i])%M;
	while(t--)
	{
		cin>>a>>b;
		cout<<(dp[b]-dp[a-1]+M)%M<<endl;
	}
	return 0;
}