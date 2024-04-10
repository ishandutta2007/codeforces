#pragma GCC optimize("Ofast")

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
}ll inv[1050+5],fac_inv[1050+5],fac[1050+5];
void initialize()
{
	ll i;
	inv[1]=1;
	for(i=2;i<=1050;i++)
		inv[i]=(M-M/i)*inv[M%i]%M; // fermat's little theorem....
	fac[0]=fac[1]=1;
	for(i=2;i<=1050;i++)
		fac[i]=i*fac[i-1]%M;
	fac_inv[0]=fac_inv[1]=1;
	for(i=2;i<=1050;i++)
		fac_inv[i]=inv[i]*fac_inv[i-1]%M;
}
ll ncr(ll n,ll r,ll m)
{
	if(n<r)return 0;
	return (fac[n]*fac_inv[r]%M)*fac_inv[n-r]%M;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n,m;
	initialize();
	ll ans=0;
	cin>>n>>m;
	for(auto i=1;i<=n;i++)
	{
		ans=(ans+ncr(m+n-1-i,m-1,M)*ncr(i+m-1,m,M)%M)%M;
	}
	cout<<ans;
	return 0;
}