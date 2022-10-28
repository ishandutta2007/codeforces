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
#define sz(a) (ll)a.size()
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
const int N=100002;
ll n,a[N],level;
vector<pair<ll,ll>> check;
void merge(ll st,ll en,ll lev)
{
	if(lev==level)
	{
		check.pb({st,en-1});
		return ;
	}
	if(en==st+1 && lev<level)
	{
		cout<<-1<<endl;
		exit(0);
	}
	merge(st,(st+en)/2,lev+1);
	merge((st+en)>>1,en,lev+1);
}
int _runtimeTerror_()
{
	ll n,k;
	cin>>n>>k;
	ll x=1,sum=0,i;
	for(i=0;i<n;++i)
		a[i]=n-i;
	if(k%2==0)
	{
		cout<<-1<<endl;return 0;
	}
	while(sum<k)
	{
		++level;
		sum+=x;
		x*=2;
	}
	ll balance=0;
	if(sum>k)
	{
		--level;
		balance=k-(sum-x/2);
	}
	merge(0,n,1);
	if(!balance)
	{
		for(auto j:check)
			sort(a+j.F,a+j.S+1);
		for(i=0;i<n;++i)
			cout<<a[i]<<" ";
	}
	else
	{
		for(auto j:check)
		{
			if(balance)
			{
				if(j.S-j.F>0)
				{
					balance-=2;
					ll le=j.F,ri=j.S+1;
					sort(a+le,a+(le+ri)/2);
					sort(a+(le+ri)/2,a+ri);
				}
			}
			else
			{
				sort(a+j.F,a+j.S+1);
			}
		}
		if(balance)
		{
			cout<<-1;exit(0);
		}
		for(i=0;i<n;++i)
			cout<<a[i]<<" ";
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}