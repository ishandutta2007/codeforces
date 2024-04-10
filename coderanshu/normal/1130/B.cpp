#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(i=a;i<b;i++)

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
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n,i;
	cin>>n;
	pair<ll,ll> p[2*n];
	rep(i,0,2*n)
	{
		cin>>p[i].first;
		p[i].second=i;
	}
	sort(p,p+2*n);
	ll ans=0;
	ans+=p[0].second+p[1].second;
	for(i=2;i<2*n;i+=2)
	{
		ans+=min(abs(p[i].second-p[i-1].second)+abs(p[i+1].second-p[i-2].second),abs(p[i].second-p[i-2].second)+abs(p[i+1].second-p[i-1].second));
	}
	cout<<ans;
	return 0;
}