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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif

//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int _runtimeTerror_()
{
    int n = rng() % M,k = 1;
    cin >> n >> k;
    // cout << n << " ";
    string s = to_string(n);
    int x = sz(s);
    set<char> have;
    int last = 0;

    if(k == 1)
    {
    	string t = string(x,s[0]);
    	if(t >= s)
    		cout << t << "\n";
    	else
    		cout << string(x,s[0] + 1) << "\n";
    	return 0;
    }

    for(int i=0;i<x;++i)
    {
    	have.insert(s[i]);
    	if(have.size() > k)
    		break;
    	string t = s;
    	for(int j=i+1;j<x;++j)
    	{
    		if(have.size() == k)
    			t[j] = *have.rbegin();
    		else
    			t[j] = '9';
    	}
    	if(t >= s)
    		last = i;
    }
    if(last == x - 1)
    {
    	cout << s << "\n";
    	return 0;
    }
    have.clear();
    for(int i=0;i<=last;++i)
    	have.insert(s[i]);
    for(auto i = s[last+1] + 1;i <= '9';++i)
    {
    	bool had = have.count(i);
    	have.insert(i);
    	if(have.size() > k)
    	{
    		if(!had)
    			have.erase(i);
    		continue;
    	}
    	string t = s;
    	t[last+1] = i;
    	for(int j=last+2;j<x;++j)
    	{
    		if(have.size() == k)
    			t[j] = *have.begin();
    		else
    			t[j] = '0';
    	}
    	assert(t >= s);
    	cout << t << "\n";
    	return 0;
    }
    assert(false);
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
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}