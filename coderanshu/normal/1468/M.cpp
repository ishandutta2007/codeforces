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

const int N = 200005;

vector<int> v[N];
bool f[N];
int fx[N];

int _runtimeTerror_()
{
    map<int,int> idx;
    int cur = 1;
    auto get = [&](int x)
    {
        if(idx.count(x))
            return idx[x];
        return idx[x] = cur++;
    };
    vector<vector<int>> big,small;
    vector<int> bsz,ssz;
    int n;
    cin>>n;
    const int Lim = 350;
    for(int i=1;i<=n;++i)
    {
        int k;
        cin>>k;
        vector<int> v(k);
        for(auto &j:v)
        {
            cin>>j;
            j = get(j);
        }
        if(k>=Lim)
            big.pb(v),bsz.pb(i);
        else
            small.pb(v),ssz.pb(i);
    }
    for(int i=0;i<sz(big);++i)
    {
        for(auto &j:big[i])
            f[j] = true;
        for(int j=i+1;j<sz(big);++j)
        {
            int cnt = 0;
            for(auto &k:big[j])
            {
                if(cnt>=2)
                    break;
                cnt += f[k];
            }
            if(cnt>=2)
            {
                for(auto &j:big[i])
                    f[j] = false;
                cout<<bsz[i]<<" "<<bsz[j]<<"\n";
                return 0;
            }
        }
        for(int j=0;j<sz(small);++j)
        {
            int cnt = 0;
            for(auto &k:small[j])
            {
                if(cnt>=2)
                    break;
                cnt += f[k];
            }
            if(cnt>=2)
            {
                for(auto &j:big[i])
                    f[j] = false;
                cout<<bsz[i]<<" "<<ssz[j]<<"\n";return 0;
            }
        }
        for(auto &j:big[i])
            f[j] = false;
    }  
    // vector<int> t; 
    int cnt = 0;
    for(int i=1;i<cur;++i)
        v[i].clear();
    for(int i=0;i<sz(small);++i)
    {
        for(auto &j:small[i])
            v[j].pb(i);
    }
    for(int i=1;i<cur;++i)
    {   
        pii ans = {-1,-1};
        for(int j=0;j<sz(v[i]);++j)
        {
            for(auto &k:small[v[i][j]])
            {
                if(k == i)
                    continue;
                if(fx[k])
                {
                    ans = {fx[k],ssz[v[i][j]]};
                    break;
                }
                fx[k] = ssz[v[i][j]];
            }
            if(ans.F != -1)
                break;
        }
        for(auto &j:v[i])
            for(auto &k:small[j])
                fx[k] = 0;
        if(ans.F!=-1)
        {
            cout<<ans.F<<" "<<ans.S<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
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