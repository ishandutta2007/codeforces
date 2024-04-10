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
    string s;
    cin>>s;
    int n = sz(s);
    string t = s;
    reverse(all(t));
    t = s + "#" + t;
    vector<int> z = zFunction(t);
    vector<bool> pal(n+1,false);
    for(int i=n+1;i<2*n+1;++i)
    {
    	int id = n-(i-n-1)-1;
    	if(2*z[i] >= id+1)
    		pal[id] = true;
    }
    ll ans = 1;
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i=1;i<n;++i)
    {
    	dp[i] = pal[i]?1+dp[(i-1)/2]:0;
        ans += dp[i];
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