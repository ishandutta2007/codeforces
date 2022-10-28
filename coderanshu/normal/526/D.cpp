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
    ll n,k;
    cin>>n>>k;
	string s;
	cin>>s;
	if(k==1)
	{
		string ans(n,'1');
		cout<<ans<<'\n';
		return 0;
	}
	string ans(n,'0');
	string t = s + "#" + s;
	vector<int> z = zFunction(t);
	vector<int> cnt(n+1,0);
	for(int i=n+2;i<2*n+1;++i)
	{
		int id = i-n-1;
		int len = id;
		int u = z[i];
		amin(u,len*k);
		if(u<(len*(k-1)))
			continue;
		++cnt[id + len*(k-1) - 1];
		--cnt[u + id];
	}	
	int sum = 0;
	for(int i=0;i<n;++i)
	{
		sum += cnt[i];
		if(sum)
			ans[i] = '1';
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