#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

ll n,k,t;

bool check(ll x)
{
	while(x)
	{
		if(x%10==0) return 0;
		x/=10;
	}
	return 1;
}

int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		while(check(n)&&k>1)
		{
			k--;
			ll tmp=n,mx=-1,mi=100;
			while(tmp)
			{
				mx=max(mx,tmp%10);
				mi=min(mi,tmp%10);
				tmp/=10;
			}
			n+=mx*mi;
		}
		printf("%lld\n",n);
	}
	return 0;
}