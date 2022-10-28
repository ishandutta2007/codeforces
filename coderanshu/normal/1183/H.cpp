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

int _runtimeTerror_()
{
    int n;
    ll k;
    cin>>n>>k;
    string s;
    cin>>s;
    s = '#' + s;
    vector<ll> v(n+1,1),w(n+1,1);
    vector<ll> ans(n+1,0);
    for(int len=1;len<=n;++len)
    {
    	ll cnt = 0;
    	if(len != 1)
    	{
	    	for(int i=1;i<=n;++i)
	    	{
	    		vector<bool> vis(26,0);
	    		for(int j=i-1;j>=1;--j)
	    		{
	    			if(!vis[s[j]-'a'])
	    				w[i] += v[j],vis[s[j]-'a'] = true;
	    		}
	    	}
	    }
	    vector<bool> vis(26,0);
	    for(int i=n;i>=1;--i)
	    {
	    	if(!vis[s[i]-'a'])
	    		cnt += w[i],vis[s[i]-'a'] = true;
	    }
	    swap(v,w);
	    for(int i=1;i<=n;++i)
	    	w[i] = 0;
	    ans[len] +=cnt;
    }
    ll cost = 0;
    ans[0] = 1;
    for(int i=n;i>=0;--i)
    {
    	if(ans[i]>=k)
    	{
    		cost += k*(n-i);
    		k = 0;
    		break;
    	}
    	cost += ans[i]*(n-i);
    	k -= ans[i];
    	// cout<<i<<" : ";
    	// cout<<ans[i]<<"\n";
    }
    if(k)
    	cost = -1;
    cout<<cost<<"\n";
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