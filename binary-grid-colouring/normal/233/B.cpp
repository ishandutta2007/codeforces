#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s(ll n)
{
	ll sum = 0;
	while(n)
	{
		sum+=n%10;
		n/=10;
	}
	return sum; 
}
int main()
{
	ll n;
	cin>>n;
	ll limit = sqrt(n);
	for(ll i = limit;i>=limit - 100;--i)
	{
		if((i*i + s(i)*i )==n)
		{
			cout<<i<<endl;exit(0);
		}
	}
	cout<<"-1"<<endl;
	return 0;
}