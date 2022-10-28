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

vector<int> zFunction(string &s)
{
	int n=sz(s),l,r,i;
	vector<int> z(n);
	z[0]=n;
	l=r=0;
	for(i=1;i<n;++i)
	{
		if(i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[z[i]+i])
			++z[i];
		if(i+z[i]-1>r)
		{
			l=i;r=i+z[i]-1;
		}
	}
	return z;
}

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    string p;
    cin>>p;
    int y = sz(p);
    vector<int> z = zFunction(p);
    vector<int> cnt(n+2,0);
    ll ans = 1;
    int pr = -1;
    for(int i=0;i<m;++i)
    {
    	int x;
    	cin>>x;
    	++cnt[x-1],--cnt[x+y-1];
    	if(pr != -1 && pr+y>x)
    	{
    		if(z[x-pr] != y-(x-pr))
    			ans = 0;
    	}
    	pr = x;
    }
    int sum = 0;
    for(int i=0;i<n;++i)
    {
    	sum += cnt[i];
    	if(sum == 0)
    		ans = (ans*26)%M;
    }
    cout<<ans<<"\n";
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