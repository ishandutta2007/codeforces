#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e==1)
		return b;
	if(e%2==0)
		return power(b*b%m,e/2,m);
	else
		return b*power(b*b%m,(e-1)/2,m)%m;
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

	ll n;
	cin>>n;
	if(n<=2)cout<<"1\n";
	else cout<<"2\n";
	for(ll i=2;i<=n+1;i++)
	{
		if(is_prime(i))
			cout<<"1 ";
		else cout<<"2 ";
	}
	return 0;
}