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
#define INF 2000000000000000000
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

int _runtimeTerror_()
{
	int n;
	cin>>n;
	int i,j,k;
	int a[n];
	for(i=0;i<n;++i)
		cin>>a[i];
	int f[n][201];
	mem0(f);
	f[0][a[0]]++;
	for(i=1;i<n;++i)
	{
		for(j=1;j<=200;++j)
			f[i][j]=f[i-1][j];
		f[i][a[i]]++;
	}
	vector<int> v[201];
	for(i=0;i<n;++i)
		v[a[i]].pb(i);
	int ans=1;
	for(i=1;i<=200;++i)
	{
		if(v[i].empty())continue;
		int nn=sz(v[i]);
		if(nn==1)continue;
		for(j=0;j<nn/2;++j)
		{
			int find=0;
			for(k=1;k<=200;++k)
				find=max(f[v[i][nn-j-1]-1][k]-f[v[i][j]][k],find);
			//cout<<find<<endl;
			amax(ans,find+2*j+2);
		}
	}
	cout<<ans<<endl;
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
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<"\n"<<_time_;
	return 0;
}