#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a)    memset(a,0,sizeof(a))
#define mem1(a)    memset(a,-1,sizeof(a))
#define memf(a)    memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

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
const int N=17;
vector<ll> v(1 << N);
const int mod=1e9+7;
void xor_fwht(vector<ll> &a,bool invert)
{
	int n=(int)a.size();
	for(int len=2;len<=n;len<<=1)
	{
		for(int i=0;i<n;i+=len)
		{
			for(int j=0;j<len/2;++j)
			{
				ll u=a[i+j],v=a[i+j+len/2];
				a[i+j]=u+v;
				a[i+j+len/2]=u-v;
				a[i+j]%=mod;a[i+j]+=mod;a[i+j]%=mod;
				a[i+j+len/2]%=mod;a[i+j+len/2]+=mod;a[i+j+len/2]%=mod;
 
			}
		}
	}
	if(invert)
	{
		ll inv_n=power(n,mod-2,mod);
		for(int i=0;i<n;++i)
			a[i]*=inv_n,a[i]%=mod;
	}
}
void and_fwht(vector<ll> &a,bool invert)
{
	int n=(int)a.size();
	for(int len=2;len<=n;len<<=1)
	{
		for(int i=0;i<n;i+=len)
		{
			for(int j=0;j<len/2;++j)
			{
				ll u=a[i+j],v=a[i+j+len/2];
				if(invert)
					a[i+j]=-u+v,a[i+j+len/2]=u;
				else
					a[i+j]=v,a[i+j+len/2]=u+v;
				a[i+j]%=mod;a[i+j]+=mod;a[i+j]%=mod;
				a[i+j+len/2]%=mod;a[i+j+len/2]+=mod;a[i+j+len/2]%=mod;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		v[x]++;
	}
	vector<ll> fib(1<<N);
	fib[0]=0,fib[1]=1;
	for(int i=2;i<(1<<N);++i)
	{
		fib[i]=fib[i-1]+fib[i-2];fib[i]%=mod;
	}
	vector<ll> v1(1 << N),v2(1 << N),v3(1 << N);
	v2=v;
	v3=v;
	int x=power(2,17,mod)-1;
	for(int i=0;i< (1<<N);++i)
	{
		int mask=(~i)&x;
		v1[i]+=v[i]*v[0];
		v1[i]%=mod;
		for(int j=mask;j;j=(j-1)&mask)
		{
			v1[i|j]+=v[i]*v[j];
			v1[i|j]%=mod;
		}
	}
	xor_fwht(v3,false);
	for(int i=0;i<(1<<N);++i)v3[i]*=v3[i];
	xor_fwht(v3,true);
	for(int i=0;i<(1<<N);++i)
	{
		v1[i]%=mod;v2[i]%=mod;v3[i]%=mod;
		v1[i]*=fib[i];v2[i]*=fib[i];v3[i]*=fib[i];
		v1[i]%=mod;v2[i]%=mod;v3[i]%=mod;
	}
	and_fwht(v1,false);and_fwht(v2,false);and_fwht(v3,false);
	for(int i=0;i<(1<<N);++i)
	{
		v1[i]*=v2[i];v1[i]%=mod;v1[i]*=v3[i];v1[i]%=mod;
	}
	and_fwht(v1,true);
	ll ans=0;
	for(int i=0;i<N;++i)
	{
		ans+=v1[1<<i];ans%=mod;
	}
	cout<<ans;
	return 0;
}