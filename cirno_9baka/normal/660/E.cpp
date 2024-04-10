#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
const int M=1000000007;
#define ri register int 
#define rl register long long
int n,m;
ll ans=1,s=0;
ll qpow(ll a,ll b)
{
	ll s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(ri i=1;i<=n;++i)
	{
		ll tmp=ans;
		ans=(ans*2*m%M-s*m)%M;
		s=(s*(m-1)+tmp)%M;
	}
	cout<<(ans%M+M)%M;
}