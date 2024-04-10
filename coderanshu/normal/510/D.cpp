#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define aint(v) v.begin(),v.end()
#define sz(a) (int)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 1000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int power(int b,int e,int m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
int power( int b, int e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

const int N=302;
int a[N],c[N],n;
int mask[N][N];
int dp[N][1<<10];

int getans(int idx,int pos,int msk)
{
	if(pos==n)
	{
		if(msk==0)return 0;
		else return INF;
	}
	if(dp[pos][msk]!=-1)
		return dp[pos][msk];
	int ans=INF;
	amin(ans,getans(idx,pos+1,msk&mask[idx][pos])+c[pos]);
	amin(ans,getans(idx,pos+1,msk));
	return dp[pos][msk]=ans;
}
int _runtimeTerror_()
{
	mem1(dp);
	cin>>n;
	int i,j;
	for(i=0;i<n;++i)
		cin>>a[i];
	for(i=0;i<n;++i)
		cin>>c[i];
	for(i=0;i<n;++i)
	{
		int k=a[i];
		vector<int> v;
		for(j=2;j*j<=k;++j)
		{
			if(k%j==0)
			{
				while(k%j==0)
					k/=j;
				v.pb(j);
			}
		}
		if(k!=1)v.pb(k);
		mask[i][i]=(1<<sz(v))-1;
		for(j=i+1;j<n;++j)
		{
			for(int k=0;k<sz(v);++k)
			{
				if(a[j]%v[k]==0)
					mask[i][j]+=(1<<k);
			}
		}
	}
	int ans=INF;
	for(i=0;i<n;++i)
	{
		mem1(dp);
		amin(ans,getans(i,i+1,mask[i][i])+c[i]);
	}
	if(ans==INF)
		cout<<-1;
	else cout<<ans<<endl;
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