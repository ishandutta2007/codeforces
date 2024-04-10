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
ll n,m,k,a[200005];
bool check(ll mid)
{
	ll currsize=k,l=1;
	for(ll i=mid;i<n;++i)
	{
		if(a[i]>currsize)
		{
			l++;currsize=k-a[i];
		}
		else currsize-=a[i];
		if(l>m)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i;
	cin>>n>>m>>k;
	for(i=0;i<n;++i)
		cin>>a[i];
	ll st=0,en=n;
	while(st<=en)
	{
		ll mid=(st+en)>>1;
		if(check(mid))
			en=mid-1;
		else st=mid+1;
	}
	cout<<n-en-1;
	return 0;
}