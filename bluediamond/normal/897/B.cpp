#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

ll Get(int x)
{
	ll ans=x;
	while(x)
	{
		int cif=x%10;
		ans=10*ans+cif;
		x/=10;
	}	
	return ans;
}

int main()
{
	int n;
	ll MOD;
	cin>>n>>MOD;
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=Get(i);
		sum%=MOD;
	}	
	cout<<sum<<"\n";
	return 0;
}