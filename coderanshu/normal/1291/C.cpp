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
int a[4000],n;
int call(int m)
{
	int ans=0;
	for(int i=0;i<m;++i)
	{
		ans=max(ans,max(a[i],a[i+n-m]));
	}
	return ans;
}
int calc2(int i,int j,int m)
{
	int ans=1e9+7;
	for(int l=0;l<m;++l)
	{
		ans=min(ans,max(a[i+l],a[j-m+l]));
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t,m,k,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		for(i=0;i<n;++i)cin>>a[i];
		if(k>=m-1)
			{
				cout<<call(m)<<endl;continue;
			}
		int ans=0; 
		for(i=0;i<=k;++i)
		{
			//cout<<calc2(i,i+n-k,m-k)<<endl;
			ans=max(ans,calc2(i,i+n-k,m-k));
		}
		cout<<ans<<endl;
	}
	return 0;
}