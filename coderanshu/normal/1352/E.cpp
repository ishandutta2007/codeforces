#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define sz(a) (int)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountint(x)

const long double PI = acos(-1);

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
	int a[n],psum[n+1];
	psum[0]=0;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		psum[i+1]=psum[i]+a[i];
	}
	bool mark[n+1];
	memf(mark);
	for(int i=0;i<n;++i)
		for(int j=i+2;j<=n;++j)
			if(psum[j]-psum[i]<=n)
				mark[psum[j]-psum[i]]=true;
	int ans=0;
	for(int i=0;i<n;++i)
	{
		ans+=mark[a[i]];
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