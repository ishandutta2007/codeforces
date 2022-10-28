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
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const long double PI = acos(-1);

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
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int _runtimeTerror_()
{
	ll n,k;
	cin>>n>>k;
	bool ffk=false;
	ll ans=INF;
	for(int i=0;i<=9;++i)
	{
		int cnt=0;
		ll val=0;
		for(int x=0;x<=k;++x)
		{
			val+=(i+x)%10;
			if(i+x>=10)
				++cnt;
		}
		if(val>n)
			continue;
		ll x=n-val;
		//cout<<x<<"\n";
		//cout<<"cnt "<<cnt<<'\n';
		for(int l=0;l<=17;++l)
		{
			ll y=l*9*(k+1-cnt);
			if(y>x)
				break;
			ll z=x-y-cnt;
			if(z<0 || z%(k+1)!=0)
				continue;
			z/=k+1;
			//cout<<"z "<<z<<endl;
			ll num=0;
			for(int nn=0;nn<l;++nn)
			{
				num*=10;
				num+=9;
			}
			num*=10;
			num+=i;
			ll fof=l+1;
			if(z>8)
			{
				num+=8*power(10,l+1);
				z-=8;
				++fof;
			}
			if(fof>=18)
				continue;
			bool xx=false;
			int ff=z/9,kk=z%9;
			for(int nn=0;nn<ff;++nn)
			{
				num+=9*power(10,fof++);
				if(fof>=18)
				{
					xx=true;
					break;
				}
			}
			if(xx)continue;
			if(fof>=18)
				continue;
			num+=kk*power(10,fof++);
			//cout<<"num "<<num<<'\n';
			amin(ans,num);
			ffk=true;
		}
	}
	//cout<<ffk<<'\n';
	if(ffk)
		cout<<ans<<'\n';
	else cout<<-1<<'\n';
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
	return 0;
}