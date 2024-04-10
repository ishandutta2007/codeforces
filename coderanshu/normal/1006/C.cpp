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

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	ll n,i,ansSum,lsum,rsum,j;
	cin>>n;
	vector<ll> a(n);
	for(i=0;i<n;++i)
		cin>>a[i];
	ansSum=0;i=0;j=n-1;
	if(i==j)
	{
		cout<<0;return 0;
	}
	lsum=rsum=0;
	lsum+=a[i];rsum+=a[j];
	while(i<j)
	{
		if(lsum==rsum)
		{
			ansSum=lsum;++i;--j;
			lsum+=a[i];rsum+=a[j];
		}
		else if(lsum>rsum)
		{
			--j;rsum+=a[j];
		}
		else
		{
			++i;lsum+=a[i];		
		}
	}
	cout<<ansSum;
	return 0;
}