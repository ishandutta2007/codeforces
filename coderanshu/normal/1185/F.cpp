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
#define INF 2e9+10
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)

const long double PI = acos(-1);

//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

const int N=9;
ll a[1<<N],b[1<<N],idx[1<<N],cnt[1<<N],d[1<<N],idx2[1<<N];
int _runtimeTerror_()
{
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<(1<<N);++i)
		b[i]=INF,idx[i]=-1,idx2[i]=-1,d[i]=INF;
	for(int i=0;i<n;++i)
	{
		ll f;
		cin>>f;
		int msk=0;
		for(int j=0;j<f;++j)
		{
			ll k;
			cin>>k;
			msk+=(1<<(k-1));
		}
		a[msk]++;
	}
	for(int i=1;i<=m;++i)
	{
		ll c,r;
		cin>>c>>r;
		int msk=0;
		for(int j=0;j<r;++j)
		{
			ll k;
			cin>>k;
			msk+=(1<<(k-1));
		}
		if(b[msk]>c)
		{
			if(b[msk]!=INF)
				d[msk]=b[msk],idx2[msk]=idx[msk];
			idx[msk]=i,b[msk]=c;
		}
		else if(d[msk]>c)
		{
			idx2[msk]=i,d[msk]=c;
		}
		cnt[msk]++;
	}
	int nn=(1<<N);
	int ansval=0,cost=INF;
	pair<int,int> ans={-1,-1};
	for(int i=1;i<nn;++i)
	{
		if(cnt[i]>=2)
		{
			int msk=i;
			int val=0,cst=b[i]+d[i];
			for(int k=msk;k;k=(k-1)&msk)
				val+=a[k];
			if(val>ansval)
				ansval=val,cost=cst,ans={idx[i],idx2[i]};
			else if(val==ansval)
			{
				if(cst<cost)
					cost=cst,ans={idx[i],idx2[i]};
			}
		}
		for(int j=1;j<nn;++j)
		{
			if(idx[i]==-1 || idx[j]==-1 || (i==j))
				continue;
			int msk=(i|j);
			int val=0,cst=b[i]+b[j];
			for(int k=msk;k;k=(k-1)&msk)
				val+=a[k];
			if(val>ansval)
				ansval=val,cost=cst,ans={idx[i],idx[j]};
			else if(val==ansval)
			{
				if(cst<cost)
					cost=cst,ans={idx[i],idx[j]};
			}
		}
	}
	if(ans.F==-1 && ans.S==-1)
		ans={1,2};
	cout<<ans.F<<" "<<ans.S;
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
	cerr<<"\n"<<_time_;
	return 0;
}