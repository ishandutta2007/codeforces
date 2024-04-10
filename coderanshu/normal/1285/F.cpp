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

#define runSieve
const int N=100005;
bool prime[N];
ll pf[N];
void sieve()
{
    int k=sqrt(N-2);
    for(int i=1;i<N;++i)
        prime[i]=true,pf[i] = i;
    for(int i=2;i<=k;++i)
    {
        if(prime[i])
        {
            for(int k=i*i;k<=N-2;k+=i)
            {
                if(prime[k])
                {
                    prime[k]=false;
                    pf[k]=i;
                }
            }
        }
    }
}

vector<int> d[N];
int cnt[N];
int mu[N];
vector<int> val[N];

int _runtimeTerror_()
{
    mu[1] = 1;
    for(int i=2;i<N;++i)
    {
        if(pf[i] == pf[i/pf[i]])
            mu[i] = 0;
        else
            mu[i] = -1*mu[i/pf[i]];
    }
    for(int i=1;i<N;++i)
        for(int j=i;j<N;j+=i)
            d[j].pb(i);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int x;cin>>x;
        for(auto j:d[x])
            val[j].pb(x/j);
    }
    auto check = [&](int x)
    {
        int ans = 0;
        for(auto j:d[x])
            ans += cnt[j]*mu[j];
        return ans>0;
    };
    ll ans = 0;
    auto go_ = [&](int x,int y,int i)
    {
        // cout<<"x y :"<<x<<' '<<y<<"\n";
        if(__gcd(x,y) == 1)
            amax(ans,x*1LL*y*i);
    };
    auto add = [&](int x,int k)
    {
        for(int j:d[x])
            cnt[j] += k;
    };
    for(int i=1;i<N;++i)
    {
        // fixing the gcd
        if(val[i].empty())
            continue;
        sort(all(val[i]),greater<ll>());
        vector<int> st;
        for(int k:val[i])
        {
            // cout<<"fuck : "<<check(k)<<"\n";
            while(!st.empty() && check(k))
            {
                // cout<<"YES\n";
                go_(st.back(),k,i);
                add(st.back(),-1);
                st.pop_back();
            }
            st.push_back(k);
            add(k,1);
        }
        // cout<<"\n";
        while(!st.empty())
            add(st.back(),-1),st.pop_back();
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