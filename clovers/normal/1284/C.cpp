#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=250001;

ll n,m;
ll f[N],sum=0;

void init()
{
	f[0]=1;
	for(ll i=1;i<=n;i++) f[i]=f[i-1]*i%m;
}

int main()
{
	scanf("%lld%lld",&n,&m);
	init();
	for(ll i=1;i<=n;i++)
	{
		sum=(sum+f[i]*f[n-i]%m*(n-i+1)%m*(n-i+1)%m)%m;
	}
	cout<<sum<<endl;
}