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

bool is_prime(ll n)
{
    ll k= sqrt(n);
    for(ll i=2;i<=k;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    vector<ll> pp(61);
    for(int i=2;i<=60;++i)
    {
        ll u = pow(10,18.0/i);
        pp[i] = u;
    }
    // for(int i=2;i<=60;++i)
        // cout<<power(pp[i],i)<<"\n";
    if(k == 1)
    {
        cout<<"0\n";return 0;
    }
    auto powi = [&](ll x,ll i)
    {
        ll lo = 1,hi = pp[i],ans = -1;
        while(lo<=hi)
        {
            ll mid = (lo+hi)/2;
            ll y = power(mid,i);
            if(y<=x)
                lo = mid+1,ans = mid;
            else 
                hi = mid-1;
        }
        if(power(ans,i) == x)
            return ans;
        else
            return -1ll;
    };
    map<ll,vector<ll>> mp;
    vector<ll> v;
    map<ll,ll> freq;
    for(int i=0;i<n;++i)
    {
        if(a[i]<=1e9+10 && is_prime(a[i]))
        {
            ++freq[a[i]];
            mp[a[i]].pb(a[i]);
            a[i] = -1;
            continue;
        }
        for(int j=60;j>=2;--j)
        {
            ll u = powi(a[i],j);
            if(u == -1)
                continue;
            if(is_prime(u))
            {
                ++freq[u];
                mp[u].pb(a[i]);
                a[i] = -1;
            }
            break;
        }
    }
    for(auto &j:freq)
    {
        // cout<<j<<"\n";
        if(j.S == 1)
            mp.erase(j.F);
    }
    vector<ll> primes;
    int cnt = 0;
    for(auto &j:mp)
        cnt += sz(j.S),primes.pb(j.F);
    // cout<<cnt<<"\n";
    if(cnt<=k)
    {
        // cout<<"Yo\n";
        // just add extra elements
        vector<ll> ans;
        for(auto &j:mp)
            for(auto &k:j.S)
                ans.pb(k);
        for(int i=0;i<n;++i)
        {
            ll u = a[i];
            if(ans.size() == k)
                break;
            if(a[i] == -1)
                continue;
            for(auto &j:primes)
                while(a[i]%j==0)
                    a[i] /= j;
            if(a[i] == 1)
                ans.pb(u);
        }
        if(ans.size()<k)
        {
            cout<<"0\n";return 0;
        }
        for(auto &j:ans)
            cout<<j<<" ";
        cout<<"\n";
        return 0;
    }
    ll pr = primes.size();
    if(2*pr <=k || k%2==0)
    {
        vector<ll> ans;
        for(auto &j:mp)
        {
            if(sz(ans)<k)
            {
                assert(k - sz(ans)>=2);
                ans.pb(j.S[0]);
                ans.pb(j.S[1]);
            }
        }
        for(auto &j:mp)
        {
            for(int i=2;i<sz(j.S);++i)
            {
                if(sz(ans) == k)
                    break;
                ans.pb(j.S[i]);
            }
        }
        assert(sz(ans) == k);
        for(auto &j:ans)
            cout<<j<<" ";
        cout<<"\n";
        return 0;
    }
    assert(k&1);
    int mx = -1;
    for(auto &j:mp)
        amax(mx,sz(j.S));
    if(mx >= 3)
    {
        vector<ll> ans;
        int fx = -1;
        for(auto &j:mp)
        {
            if(sz(j.S)>=3 && fx == -1)
            {
                fx = j.F;
                ans.pb(j.S[0]);
                ans.pb(j.S[1]);
                ans.pb(j.S[2]);
                break;
            }
        }
        for(auto &j:mp)
        {
            if(j.F == fx)
                continue;
            if(sz(ans)<k)
            {
                assert(k-sz(ans)>=2);
                ans.pb(j.S[0]);
                ans.pb(j.S[1]);
            }
        }
        for(auto &j:ans)
            cout<<j<<" ";
        cout<<"\n";
        return 0;
    }
    assert(mx == 2);
    int found = -1;
    for(int i=0;i<n;++i)
    {
        if(a[i] == -1 || found != -1)
            continue;
        ll x= 0;
        ll u = a[i];
        vector<ll> dif;
        for(auto &j:primes)
        {
            int cnt = 0;
            while(a[i]%j==0)
                a[i]/=j,++cnt;
            x += cnt>0;
            if(cnt)
                dif.pb(j);
        }
        if(a[i] == 1 && x*2<=k)
        {
            vector<ll> ans;
            ans.pb(u);
            for(auto &j:dif)
            {
                ans.pb(mp[j][0]);
                ans.pb(mp[j][1]);
            }
            set<ll> no;
            for(auto &j:dif)
                no.insert(j);
            for(auto &j:mp)
            {
                if(no.count(j.F))
                    continue;
                if(sz(ans)<k)
                {
                    ans.pb(j.S[0]);
                    ans.pb(j.S[1]);
                }
            }
            for(auto &j:ans)
                cout<<j<<" ";
            cout<<"\n";
            return 0;
        }
    }
    cout<<"0\n";return 0;
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