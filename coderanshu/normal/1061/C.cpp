#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,i;
	cin>>n;
	vector<ll> a(n);
	for(i=0;i<n;++i)
	{
		cin>>a[i];
	}
	ll m[1000005];
	mem0(m);
	ll j,k;
	for(i=0;i<n;++i)
	{
		vector<ll> myAns;
		for(j=1;j*j<=a[i];++j)
		{
			if(a[i]%j==0)
			{
				myAns.pb(-j);
				if(j*j!=a[i])
					myAns.pb(-a[i]/j);
			}
		}
		sort(all(myAns));
		ll sz=myAns.size()-1;
		for(j=0;j<sz;++j)
		{
			m[-myAns[j]]+=m[-myAns[j]-1];
			m[-myAns[j]]%=M;
		}
		m[1]++;m[1]%=M;
		
	}
	ll ans=0;
	for(i=1;i<=1e6;++i)
	{
		ans=(ans+m[i])%M;
	}
	cout<<ans;
	return 0;
}