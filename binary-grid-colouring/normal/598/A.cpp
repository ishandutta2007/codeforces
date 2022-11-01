#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll p = 1;
		while(p<=n) p<<=1;
		cout<<(n*(n+1)/2-2*(p-1))<<endl; 
	} 
	return 0;
 }