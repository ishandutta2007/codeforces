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
const int N=25;

int a[25][2],n,dp[1<<24],xs,ys,val[1<<24];
int call(int j,int i)
{
	return (a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]);
}
int _runtimeTerror_()
{
	int i,j,k;
	cin>>xs>>ys;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i][0]>>a[i][1];
	a[n][0]=xs;a[n][1]=ys;
	int sub=(1<<n);
	dp[0]=0;
	for(i=1;i<sub;++i)
	{
		for(j=n-1;j>=0;--j)
		{
			if(i&(1<<j))
			{
				dp[i]=dp[i&(~(1<<j))]+2*call(j,n);
				val[i]=j;
				int x=(i&(~(1<<j)));
				for(k=j-1;k>=0;--k)
				{
					if(i&(1<<k))
					{
						int tt=dp[x&(~(1<<k))]+call(j,n)+call(k,n)+call(j,k);
						if(tt<=dp[i])
						{
							dp[i]=tt;
							val[i]=k;
						}
					}
				}
			break;
			}
		}
	}
	//for(i=1;i<sub;++i)
	//	cout<<val[i]<<endl;
	cout<<dp[sub-1]<<endl;
	vector<int> v;
	v.pb(0);
	int num=sub-1;
	while(num!=0)
	{
		for(j=n-1;j>=0;--j)
		{
			if(num&(1<<j))
			{
				v.pb(j+1);
				if(val[num]!=j)
					v.pb(val[num]+1);
				num=num&(~(1<<val[num]));
				num=num&(~(1<<j));
				v.pb(0);
				break;
			}
		}
	}
	for(auto j:v)
		cout<<j<<" ";
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