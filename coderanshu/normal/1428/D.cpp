#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<ll> a(n+1);
    set<ll> s;
    vector<bool> done(n+1,false);
    vector<int> ff(n+1,-1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        s.insert(i);
    }
    set<ll> v[4];
    for(int i=1;i<=n;++i)
    {
        v[a[i]].insert(i);
    }
    vector<pll> ans;
    for(int i=1;i<=n;++i)
    {   
        v[a[i]].erase(i);
        if(done[i])
            continue;
        if(a[i]==0)
            continue;
        if(a[i]==1)
        {
            if(s.empty() && ff[i]==-1)
            {
                cout<<"-1\n";return 0;
            }
            int u = ff[i];
            if(ff[i]==-1)
            {  
                u = *s.begin();
                s.erase(s.begin());
                ans.pb({u,i});
            }
            continue;
        }
        else if(a[i]==2)
        {
            if((v[1].empty() || s.empty()) && ff[i]==-1)
            {
                cout<<"-1\n";return 0;
            }
            if(v[1].empty())
            {
                cout<<"-1\n";return 0;
            }
            int l=ff[i];
            if(ff[i]==-1)
            {
                l= *s.begin();
                s.erase(l);
                ans.pb({l,i});
            }
            int x = *v[1].begin();
            v[1].erase(x);
            done[x] = true;
            ans.pb({l,x});
        }
        else if(a[i]==3)
        {
            if((sz(s)<2 && ff[i]==-1) || (sz(s)<1 && ff[i]!=-1))
            {
                cout<<"-1\n";return 0;
            }
            int l = ff[i];
            if(l==-1)
            {   
                l = *s.begin();
                s.erase(l);
                ans.pb({l,i});
            }
            int r = *s.begin();
            s.erase(r);
            if(v[1].empty() && v[2].empty() && v[3].empty())
            {
                cout<<"-1\n";return 0;
            }

            if(!v[3].empty())
            {
                int x = *v[3].begin();
                v[3].erase(x);
                ff[x] = r;
                ans.pb({l,x});
                ans.pb({r,x});
                continue;
            }
            if(!v[2].empty())
            {
                int x = *v[2].begin();
                v[2].erase(x);
                ff[x] = r;
                ans.pb({l,x});
                ans.pb({r,x});
                continue;
            }
            if(!v[1].empty())
            {
                int x = *v[1].begin();
                v[1].erase(x);
                ff[x] = r;
                ans.pb({l,x});
                ans.pb({r,x});
                continue;
            }
            // if(!v[1].empty())
            // {
            //     int x = *v[1].begin();
            //     v[1].erase(x);
            //     done[x] = true;
            //     ans.pb({l,i});
            //     ans.pb({l,x});
            //     continue;
            // }
        }
    }
    cout<<sz(ans)<<"\n";
    for(auto &j:ans)
        cout<<j.F<<" "<<j.S<<"\n";
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