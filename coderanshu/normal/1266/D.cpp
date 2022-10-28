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
	ll n,m,i,j,x,y,z;
	cin>>n>>m;
	ll a[n+100];
	mem0(a);
	vector<pair<ll,ll> > pp,pn;
	for(i=0;i<m;i++)
	{
		cin>>x>>y>>z;
		a[x]-=z;a[y]+=z;
	}
	if(n==1)
	{
		cout<<0;return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]<0)
			pn.pb(mp(i,abs(a[i])));
		else if(a[i]>0)
			pp.pb(mp(i,abs(a[i])));
	}
	i=j=0;
	vector<pair<ll,pair<ll,ll> > >v;
	while(i<pn.size() && j<pp.size())
	{
		if(pn[i].S<pp[j].S)
		{
			v.pb({pn[i].F,{pp[j].F,pn[i].S}});
			pp[j].S-=pn[i].S;
			i++;
		}
		else if(pn[i].S>pp[j].S)
		{
			v.pb({pn[i].F,{pp[j].F,pp[j].S}});
			pn[i].S-=pp[j].S;
			j++;
		}
		else
		{
			v.pb({pn[i].F,{pp[j].F,pp[j].S}});
			i++;j++;
		}


	}
	cout<<v.size()<<endl;
	for(auto j:v)
	{
		cout<<j.F<<" "<<j.S.F<<" "<<j.S.S<<endl;
	}

	return 0;
}