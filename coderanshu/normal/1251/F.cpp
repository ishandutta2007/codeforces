
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a)	memset(a,0,sizeof(a))
#define mem1(a)	memset(a,-1,sizeof(a))
#define memf(a)	memset(a,false,sizeof(a))
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

const int N=300005;
ll cnt[N];
const int mod = 998244353;
const int root = 565042129;
const int inv_root = 950391366;
const int root_pw = 1<<20 ;
void fft(ll a[],bool invert,int n)
{
	for(int i=1,j=0 ; i<n ;++i)
	{
		int bit=n>>1;
		for(;j>=bit;bit>>=1)
			j-=bit;
		j+=bit;
		if(i<j)
			swap(a[i],a[j]);
	}
	for(int len=2;len<=n;len<<=1)
	{
		ll w_len=invert?inv_root:root;
		for(int i=len;i<root_pw;i<<=1)
			w_len=(w_len*w_len)%mod;
		// 2**20 root ko use karke koi bhi 2**i (i<20)root nikala jaa sakta hai bas power
		// raise karke aur yahi kia hai yaha
		// aadhe root power karke aa jaenge baaki unki inverse hote hai just .. its that easy bro
		for(int i=0;i<n;i+=len)
		{
			ll w=1;
			for(int j=0;j<len/2;++j)
			{
				ll u=a[i+j],v=a[i+j+len/2]*w%mod;
				a[i+j]=u+v<mod?u+v:u+v-mod;
				a[i+j+len/2]=u-v<0?u-v+mod:u-v;
				w*=w_len;
				w%=mod;
			}
		}
	}
	if(invert){
		ll inv_n=power(n,mod-2,mod);
		for(int i=0;i<n;++i)
		{
			a[i]*=inv_n;a[i]%=mod;
		}
	}
}
const int NN=1<<20;
ll ones[NN],twos[NN],d[NN];
ll polyans[6][NN];
int _runtimeTerror_()
{
	ll n,k;
	cin>>n>>k;
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		cnt[x]++;
	}
	ones[0]=1;ones[1]=2;
	twos[0]=1,twos[1]=2,twos[2]=1;
	fft(ones,false,NN);
	fft(twos,false,NN);
	vector<ll> v(k);
	for(int i=0;i<k;++i)
		cin>>v[i];
	for(auto j=0;j<k;++j)
	{
		ll os=0,ts=0;
		for(int i=1;i<v[j];++i)
		{
			if(cnt[i]==0)continue;
			if(cnt[i]==1)os++;
			else ts++;
		}
		for(int i=0;i<(1<<20);++i)
		{
			d[i]=power(ones[i],os,mod)*power(twos[i],ts,mod)%mod;
		}
		fft(d,true,NN);
		for(int i=0;i<NN;++i)
			polyans[j][i]=d[i];
	}
	int q;cin>>q;
	for(int i=0;i<q;++i)
	{
		int x;cin>>x;
		x/=2;
		--x;
		ll ans=0;
		for(int j=0;j<k;++j)
		{
			ll y=x-v[j];
			if(y<0)continue;
			ans+=polyans[j][y];
			if(ans>=mod)ans-=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
// poori fft lagake saare coefficients nikal le chahiye ho ya nahi
// baad me saari querries ke time pe coefficient le le .. its that simple yaar
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