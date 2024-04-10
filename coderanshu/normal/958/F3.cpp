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
typedef complex<double> base;

void fft(vector<base> &a,bool invert)
{
	int n=(int)a.size();
	for(int i=1,j=0;i<n ;++i)
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
		double angle=2*PI/len*(invert?-1:1);
		base w_len(cos(angle),sin(angle)),w(1);
		base pow[len/2];
		pow[0]=w;
		for(int i=1;i<len/2;++i)
			pow[i]=pow[i-1]*w_len;
		for(int i=0;i<n;i+=len)
		{
			for(int j=0;j<len/2;++j)
			{
				base u=a[i+j],v=a[i+j+len/2]*pow[j];
				a[i+j]=u+v;
				a[i+j+len/2]=u-v;
			}
		}
	}
	if(invert)
	{
		for(int i=0;i<n;++i)
			a[i]/=n;
	}
}
void multiply(vector<ll> &a,vector<ll> &b,vector<ll> &res)
{
	int x=max((int)a.size(),(int)b.size());
	int n=1;
	vector<base> fa(all(a)),fb(all(b));
	while(n<x)n<<=1;
	n<<=1;
	fa.resize(n);fb.resize(n);
	fft(fa,false);fft(fb,false);
	for(int i=0;i<n;++i)
		fa[i]*=fb[i];
	fft(fa,true);
	res.resize(n);
	for(int i=0;i<n;++i)
	{
		res[i]=(ll)(fa[i].real()+0.5);
		res[i]%=1009;
	}
}
struct cmp{
	bool operator()(vector<ll> a, vector<ll> b) const{
		return sz(a)<sz(b);
	}
};
int _runtimeTerror_()
{
	ll n,m,k;
	cin>>n>>m>>k;
	ll cnt[m+1];
	mem0(cnt);
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		cnt[x]++;
	}
	multiset<vector<ll>,cmp> s;
	for(int i=1;i<=m;++i)
	{
		if(cnt[i]!=0)
		{
			vector<ll> v;
			v.pb(1);
			for(int j=1;j<=cnt[i];++j)
				v.pb(1);
			s.insert(v);
		}
	}
	while(sz(s)>1)
	{
		vector<ll> x=*s.begin();
		s.erase(s.begin());
		vector<ll> y=*s.begin();
		s.erase(s.begin());
		vector<ll> ans;
		multiply(x,y,ans);
		s.insert(ans);
	}
	vector<ll> res=*s.begin();
	cout<<res[k]%1009<<endl;
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