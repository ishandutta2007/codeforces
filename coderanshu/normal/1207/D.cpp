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
#define INF 

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
}
ll fact[300005],n;
void form()
{
	fact[0]=fact[1]=1;
	for(auto i=2;i<=n+2;i++)
		fact[i]=fact[i-1]*i%MM;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll v1,v2,v3;
	
	v1=v2=v3=1;
	bool d=true;
	map<ll,ll> m1,m2;
	map<pair<ll,ll>,ll> m3;
	cin>>n;
	pair<ll,ll> p[n];
	form();
	for(auto i=0;i<n;i++)
	{
		cin>>p[i].F>>p[i].S;
		m1[p[i].F]++;m2[p[i].S]++;m3[{p[i].F,p[i].S}]++;
	}
	sort(p,p+n);
	for(auto i=1;i<n;i++)
	{
		if(p[i].S<p[i-1].S)
		{
			d=false;v3=0;break;
		}
	}
	for(auto j:m1)
	{
		v1=v1*fact[j.S]%MM;
	}
	for(auto j:m2)
		v2=v2*fact[j.S]%MM;
	if(d)
	{
		for(auto j:m3)
			v3=v3*fact[j.S]%MM;
	}
	ll ans;
	ans=((fact[n]-v1-v2+MM+MM)%MM+v3)%MM;
	cout<<ans;
	
	return 0;
}
// PIE application