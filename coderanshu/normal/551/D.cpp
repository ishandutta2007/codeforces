#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

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
int mod;

struct Matrix
{
	vector<vector<ll>> val;
	ll n_;
	Matrix (ll n) : n_(n)
	{
		val.resize(n_);
		for(ll i=0;i<n_;++i)
			val[i].resize(n_);
	}
	void print()
	{
		for(ll i=0;i<n_;++i)
		{
			for(ll j=0;j<n_;++j)
				cout<<val[i][j]<<" ";
			cout<<"\n";
		}
	}
	void set(ll x)
	{
		for(ll i=0;i<n_;++i)
			for(ll j=0;j<n_;++j)
				val[i][j]=x;
	}
	Matrix operator*(const Matrix& b) const 
	{
		ll n=n_;
		Matrix ans(n);
		ans.set(0);
		for(ll i=0;i<n_;++i)
		{
			for(ll j=0;j<n_;++j)
			{
				ans.val[i][j]=0;
				for(ll k=0;k<n_;++k)
				{
					ans.val[i][j]+=val[i][k]*b.val[k][j];
					ans.val[i][j]%=mod;
				}

			}
		}
		return ans;
	}
};
Matrix I(ll n)
{
	Matrix Iden(n);
	Iden.set(0);
	for(ll i=0;i<n;++i)
		Iden.val[i][i]=1;
	return Iden;
}
Matrix power(Matrix m,ll pw)
{
	if(pw==0)
		return I(m.n_);
	if(pw==1)
		return m;
	Matrix t=power(m,pw/2);
	t=t*t;
	if(pw&1)
		t=t*m;
	return t;
}

int _runtimeTerror_()
{
    ll n,k,l;
    cin>>n>>k>>l>>mod;
    Matrix dp(2);
    dp.set(0);
    dp.val[0][0] = dp.val[0][1] = dp.val[1][0] = 1;
    dp = power(dp,n+1);
    ll val = dp.val[0][0];
    if(l<61 && k>=(1LL<<l))
    {
    	cout<<"0\n";
    	return 0;
    }
    ll answer = 1;
    answer = (answer * power(val,l-popcount(k),mod))%mod;
    answer = (answer * power((power(2,n,mod) - val+ mod)%mod,popcount(k),mod))%mod;
    cout<<answer<<"\n";
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
    return 0;
}