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
#define pi 3.1415926536
ll n,pt[500005],r[500005];
void initialize()
{
	for(auto i=0;i<n;i++)
	{
		r[i]=0;pt[i]=i;
	}
}
ll parent(ll i)
{
	if(i==pt[i])
		return i;
	return pt[i]=parent(pt[i]);
}
void union_(ll x,ll y)
{
	ll px=parent(x);
	ll py=parent(y);
	if(r[px]>r[py])
		pt[py]=px;
	else
		pt[px]=py;
	if(r[px]==r[py])
		r[py]++;
}
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
	ll i;
	cin>>n;
	vector<pair<ll,ll>> v,edges;
	pair<ll,ll> p[n];
	for(i=0;i<n;i++)
	{
		cin>>p[i].F>>p[i].S;
		v.pb({p[i].F,i});
		v.pb({p[i].S,i});
	}
	sort(all(v));
	set<pair<ll,ll>> s;
	ll count=0;
	initialize();
	for(auto it:v)
	{
		if(s.count({p[it.S].F,it.S}))
		{
			auto iter=s.find({p[it.S].F,it.S});iter++;
			s.erase({p[it.S].F,it.S});
			for(auto j=iter;j!=s.end();j++)
			{
				count++;
				if(count>n-1)break;
				edges.pb({it.S,j->S});
			}
		}
		else
			s.insert(it);
		if(count>n-1)break;
	}
	if(count!=n-1)
	{
		cout<<"NO";return 0;
	}
	else
	{
		for(auto i:edges)
		{
			if(parent(i.F)!=parent(i.S))
				union_(i.F,i.S);
			else
			{
				cout<<"NO";return 0;
			}
		}
		cout<<"YES";
	}

	return 0;
}