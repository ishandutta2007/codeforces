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
	ll n,k,i,rem,j,md,count,l;
	vector<pair<ll,ll>> edge;
	cin>>n>>k;
	md=0;
	vector<ll> v[n];
	ll a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		v[a[i]].pb(i+1);
		md=max(md,a[i]);
	}
	if(v[0].size()!=1)
	{
		cout<<-1;return 0;
	}
	if(v[0].size()*k<v[1].size())
	{
		cout<<-1;return 0;
	}
	for(auto j:v[1])
	edge.pb({v[0][0],j});
	for(i=2;i<=md;i++)
	{
		if(v[i].size()>(v[i-1].size())*(k-1))
		{
			cout<<-1;return 0;
		}
		else
		{
			j=0;rem=v[i].size();
			for(l=0;l<v[i-1].size();l++)
			{
				count=0;
				while(count<min(rem,k-1))
				{
					edge.pb({v[i-1][l],v[i][j]});
					j++;count++;
				}
				rem-=min(rem,k-1);

			}
		}
	}
	cout<<edge.size()<<endl;
	for(auto j:edge)
	{
		cout<<j.F<<" "<<j.S<<endl;
	}
	return 0;
}