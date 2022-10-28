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
map<int,set<int>> finder;
int n,m;
const int N=200005;
int val[N],sum=0,checker[N];
vector<int> vv[2*N];
bool check(int mm)
{
	int amount=0,i,csum=sum;
	for(i=1;i<=n;++i)
		checker[i]=val[i];
	for(i=1;i<=mm;++i)
	{
		++amount;
		if(vv[i].empty())continue;
		for(auto j:vv[i])
		{
			auto itr=finder[j].upper_bound(mm);
			--itr;
			if(*itr!=i)continue;
			int kk=checker[j];
			if(amount>=kk)
			{
				csum-=kk;
				checker[j]=0;amount-=kk;
			}
			else
			{
				csum-=amount;
				checker[j]-=amount;amount=0;
			}
		}
		if(csum==0)
		{
			return true;
		}
	}
	if(csum*2<=amount)return true;
	return false;
}
int _runtimeTerror_()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;++i)
	{
		cin>>val[i];
		sum+=val[i];
	}
	for(i=0;i<m;++i)
	{
		int t,d;
		cin>>d>>t;
		vv[d].pb(t);
		finder[t].insert(d);
	}
	ll lo=sum,hi=2*sum;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		if(check(mid))
			hi=mid-1;
		else lo=mid+1;
	}
	cout<<hi+1<<endl;
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