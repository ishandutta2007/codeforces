
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define MOD 1000000007
#define MODD 998244353
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define F first
#define S second
ll power(ll a, ll b)	//a is base, b is exponent
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	if(b%2 == 1)
		return (power(a,b-1)*a);
	ll q = power(a,b/2);
	return (q*q);
}
using namespace std;
ll n,k;
ll dp(ll mid)
{
	ll ch=0;
	ll x=mid,cnt=0;
	while(x<=n)
		x*=2,++cnt;
	x/=2;
	ch=power(2,cnt)-2;
	x=n%x;
	ch+=min(power(2,cnt),x+1);
	return ch;
}
int main()
{
	scanf("%lld %lld",&n,&k);
	if(k==1)
	{
		printf("%lld",n);
		return 0;
	}
	ll lo=2,hi=n-(n&1);
	ll ans=0;
	while(lo<=hi)
	{
		ll mid=(lo+hi)>>1;
		mid=mid-(mid&1);
		ll ch=dp(mid);
		if(ch>=k)
			lo=mid+2;
		else hi=mid-2;
	}
	ans=max(ans,lo-2);
	lo=1,hi=n-1+(n&1);
	while(lo<=hi)
	{
		ll mid=(lo+hi)>>1;
		mid=mid-1+(mid&1);
		ll ch=0;
		if(mid*2<=n)
			ch+=dp(2*mid);
		++ch;
		if(ch>=k)
			lo=mid+2;
		else hi=mid-2;
	}
	ans=max(ans,lo-2);
	printf("%lld",ans);
	return 0;
}