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
#define findMax max_element
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
bool is_prime(long long n)
{
	long long k= sqrt(n);
	for(long long i=2;i<=k;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}	
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n,i;
	cin>>n;
	if(is_prime(n))
	{
		cout<<n;return 0;
	}
	ll k=sqrt(n);
	for(i=2;i<=k;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)n/=i;
			break;
		}
	}
	if(n!=1)
		cout<<1;
	else cout<<i;
	return 0;
}