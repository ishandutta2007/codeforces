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

vector<int> sa, lc;

void lcp_array(string &s)
{
    s+='$';
    int n=s.size();
    vector<pair<int,int>> v(n);
    vector<int> p(n),c(n),lcp(n);
    
    for(int i=0;i<n;++i)
        v[i].first=s[i]-'a',v[i].second=i;
    sort(v.begin(),v.end());

    for(int i=0;i<n;++i)
        p[i]=v[i].second;
    c[p[0]]=0;
    for(int i=1;i<n;++i)
    {
        if(v[i].first==v[i-1].first)
            c[p[i]]=c[p[i-1]];
        else
            c[p[i]]=c[p[i-1]]+1;
    }
    int k=1;

    while((1<<k)<(n<<1))
    {
        vector<int> cnt(n);
        vector<pair<pair<int,int>,int>> v(n);

        for(int i=0;i<n;++i)
            v[i].first={c[i],c[(i+(1<<(k-1)))%n]},v[i].second=i;
        for(int i=0;i<n;++i)
            cnt[v[i].first.second]++;
        vector<int> pos(n);
        pos[0]=0;
        for(int i=1;i<n;++i)
            pos[i]=pos[i-1]+cnt[i-1];
        vector<pair<pair<int,int>,int>> t(n),ans(n);
        for(int i=0;i<n;++i)
            t[pos[v[i].first.second]++]=v[i];
        for(int i=0;i<n;++i)
            cnt[i]=0;
        for(int i=0;i<n;++i)
            cnt[t[i].first.first]++;
        pos[0]=0;
        for(int i=1;i<n;++i)
            pos[i]=pos[i-1]+cnt[i-1];
        for(int i=0;i<n;++i)
            ans[pos[t[i].first.first]++]=t[i];
        for(int i=0;i<n;++i)
            p[i]=ans[i].second;
        c[p[0]]=0;
        for(int i=1;i<n;++i)
        {
            if(ans[i].first==ans[i-1].first)
                c[p[i]]=c[p[i-1]];
            else
                c[p[i]]=c[p[i-1]]+1;
        }
        ++k;
    }
    k=0;
    sa = p;
    // for(auto k:p)
    //     cout<<k<<" ";
    // cout<<"\n";
    for(int i=0;i<n-1;++i)
    {
        int po=c[i];
        int j=p[po-1];
        while(s[i+k]==s[j+k])
            ++k;
        lcp[po]=k;
        k=max(k-1,0);
    }
    // for(int i=1;i<n;++i)
    //     cout<<lcp[i]<<" ";
    lc = lcp;
    lc.erase(lc.begin());
    return ;
}

int _runtimeTerror_()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    lcp_array(s);
    int ans = 0;
    vector<int> dp(n+1,0);
    sa[0] = -1;
    for(int i=1;i<=n;++i)
    {
        int mn = 1e9;
        for(int j=i-1;j>=0;--j)
        {
            amin(mn,lc[j]);
            if(sa[j] < sa[i])
            {
                // if(sa[i] == 4 && sa[j] == 0)
                    // debug(mn);
                amax(dp[i],dp[j] - mn + n - sa[i]);
            }
        }
        amax(ans,dp[i]);
    }
    // debug(sa,lc,dp);
    cout << ans << "\n";
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