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
#define pi 3.1415926536

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
ll a[10]={1,10,5,10,5,2,5,10,5,10};
ll sum[10]={0,45,20,45,20,5,20,45,20,45};
ll func(ll num,ll d)
{
	ll rem=num%a[d];
	ll ans=(num/a[d])*sum[d];
	ll temp=0;
	for(ll i=0;i<rem;i++)
	{
		ans+=(d*(i+1))%10;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t,n,m,count;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<func(n/m,m%10)<<endl;
	}


	return 0;
}