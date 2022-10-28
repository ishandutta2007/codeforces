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
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll x,count;
	cin>>x;
	if(x==1){cout<<"1 1";return 0;}
	ll l=sqrt(x);
	vector<ll> v;
	map<ll,ll> m;
	for(ll i=2;i<=l;i++)
	{
		if(x%i==0)
		{
			count=0;
			while(x%i==0){count++;x/=i;}
			m[i]=count;
			v.pb(i);
		}
	}
	if(x!=1){v.pb(x);m[x]=1;}
	ll s=v.size();
	//for(auto j:v)cout<<j;
	//	cout<<endl<<s;
	ll z=(1<<s)-1;
	ll ans1,ans2,j,actans=1000000000000,tbs1,tbs2;
	for(ll i=0;i<=z;i++)
	{
		ans1=ans2=1;
		for(j=0;j<s;j++)
		{
			if(i&(1<<j))
			{
				ans1*=power(v[j],m[v[j]]);
			}
			else
				ans2*=power(v[j],m[v[j]]);
		}
		if(max(ans1,ans2)<actans)
		{
			actans=max(ans1,ans2);
			tbs1=ans1;tbs2=ans2;
		}
	}
	cout<<tbs1<<" "<<tbs2;
	return 0;
}