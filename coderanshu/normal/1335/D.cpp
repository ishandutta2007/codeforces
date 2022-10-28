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
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
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

char func(char n)
{
	if(n=='9')
		return '1';
	else return n+1;
}
int _runtimeTerror_()
{
	char a[9][9];
	ll n,i,j;
	for(i=0;i<9;++i)
		for(j=0;j<9;++j)
			cin>>a[i][j];
	a[0][0]=func(a[0][0]);
	a[1][3]=func(a[1][3]);
	a[2][6]=func(a[2][6]);
	a[3][1]=func(a[3][1]);
	a[4][4]=func(a[4][4]);
	a[5][7]=func(a[5][7]);
	a[6][2]=func(a[6][2]);
	a[7][5]=func(a[7][5]);
	a[8][8]=func(a[8][8]);
	for(i=0;i<9;++i)
	{
		for(j=0;j<9;++j)
			cout<<a[i][j];
		cout<<endl;
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
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<"\n"<<_time_;
	return 0;
}