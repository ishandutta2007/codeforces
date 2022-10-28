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
#define llevel 20
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
ll a[100005],phi[100],m,findone[100005];
ll myphi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
void doIt()
{
	phi[0]=m;
	phi[1]=myphi(m);
	for(ll i=2;phi[i-1]!=1;++i)
		phi[i]=myphi(phi[i-1]);
}
ll check(ll l,ll r)
{
	r=min(r,findone[l]);
	ll ans=a[r];
	if(ans>32)return ans;
	for(ll j=r-1;j>=l;--j)
	{
		if(a[j]>32 || ans>32)return 33;
		ll z=1;
		for(ll k=1;k<=ans;++k)
		{
			z*=a[j];
			if(z>32)return 33;
		}
		ans=z;
	}
	return ans;
}
ll query(ll l,ll r,ll i)
{
	ll ans=1;
	if(l==r)
		return a[l]%phi[i];
	if(phi[i]==1)
		return 0;
	if(check(l+1,r)>32)
		ans*=power(a[l],query(l+1,r,i+1)+phi[i+1],phi[i]);
	else
		ans*=power(a[l],check(l+1,r),phi[i]);
	//cout<<ans<<endl;
	return ans;
}
int _runtimeTerror_()
{
	ll n,q,i,j;cin>>n>>m;
	doIt();
	for(i=0;i<n;++i)cin>>a[i];
	findone[n]=n;
	for(i=n-1;i>=0;--i)
	{
		if(a[i]==1)findone[i]=i;
		else findone[i]=findone[i+1];
	}
	cin>>q;
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		--l;--r;
		cout<<query(l,r,0)<<endl;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}