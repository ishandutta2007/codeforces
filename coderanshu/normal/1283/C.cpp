#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e9
#define endl "\n"

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,i;
	cin>>n;
	ll a[n];
	int temp1[200005],temp2[200005];
	mem0(temp1);mem0(temp2);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			temp1[i+1]=1;
		}
		else temp2[a[i]]=1;
	}
	vector<ll> v1,v2;
	for(i=1;i<=n;i++)
	{
		if(temp1[i]==1 && temp2[i]==0)
		{
			temp1[i]=0;temp2[i]=1;
			v1.pb(i);v2.pb(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(temp1[i]==1)
			v1.pb(i);
	}
	for(i=1;i<=n;i++)
	{
		if(temp2[i]==0)
			v2.pb(i);
	}
	ll k=v1.size();
	for(i=0;i<k-1;i++)
	{
		a[v1[i]-1]=v2[i+1];
	}
	a[v1[k-1]-1]=v2[0];
	for(i=0;i<n;i++)cout<<a[i]<<" ";

	return 0;
}