#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long
#define int long long 
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

const int N=1000005;
template<typename T=pair<ll,pll>>
class fenwick {
public:
    T bit[N]{};
    void update(ll st,ll en,ll in,T val)
    {
        for(ll j=in;j<=en;j+=j&-j)
        {
            bit[j].F+=val.F;bit[j].S.S+=val.S.S;bit[j].S.F+=val.S.F;
        }
    }
    T get(ll r)
    {
        T x{};
        x.F=x.S.F=x.S.S=0;
        while(r>0)
        {
            x.F+=bit[r].F;
            x.S.F+=bit[r].S.F;
            x.S.S+=bit[r].S.S;
            r-=r&-r;
        }
        return x;
    }
    T query(ll l,ll r)
    {
        T a= get(r),b=get(l-1);
        T x;
        x.F=a.F-b.F;
        x.S.F=a.S.F-b.S.F;
        x.S.S=a.S.S-b.S.S;
        return x;
    }
    void clear(int l,int r)
    {
        for(int i=l;i<=r;++i)
            bit[i].F=bit[i].S.F=bit[i].S.S=0;
    }
};
int a[N],b[N];
vector<pair<int,int>> l[N],r[N];
pair<ll,ll> maxl[N],maxr[N];
ll ans[N];
fenwick<> fenw;
int li[N];

int _runtimeTerror_()
{
    ll n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        maxl[i].S=maxr[i].S=i;
    }
    for(int i=0;i<q;++i)
        cin>>li[i];
    for(int i=0;i<q;++i)
    {
        int rx;
        int lx=li[i];
        cin>>rx;
        l[lx].pb({rx,i});
        r[rx].pb({lx,i});
    }
    stack<int> st;
    st.push(1);
    for(int i=2;i<=n;++i)
    {
        while(!st.empty() && a[st.top()]<a[i])
        {
            maxr[st.top()].F=i-1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        maxr[st.top()].F=n;
        st.pop();
    }
    st.push(n);
    for(int i=n-1;i>=1;--i)
    {
        while(!st.empty() && a[st.top()]<a[i])
        {
            maxl[st.top()].F=i+1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        maxl[st.top()].F=1;
        st.pop();
    }
    b[0]=0;
    for(int i=1;i<=n;++i)
        b[i]=b[i-1]+maxr[i].F-maxl[i].F+1;
    sort(maxl+1,maxl+n+1);sort(maxr+1,maxr+n+1,greater<pair<int,int>>());
    int cur=1;
    fenw.clear(0,n);
    for(int i=1;i<=n;++i)
    {
        while(cur<=n && maxl[cur].F<=i)
        {
            pair<ll,pll> p; p.F=maxl[cur].S-maxl[cur].F+1;p.S.F=maxl[cur].S;p.S.S=1;
            fenw.update(1,n,maxl[cur].S,p);
            ++cur;
        }
        for(auto k:l[i])
        {
            ans[k.S]+=b[k.F]-b[i-1];
            pair<ll,pll> p=fenw.query(i,k.F);
            ll x=p.S.F-p.S.S*(i-1);
            x=p.F-x;
            ans[k.S]-=x;
        }
    }
    fenw.clear(0,n);
    cur=1;
    for(int i=n;i>=1;--i)
    {
        while(cur<=n && maxr[cur].F>=i)
        {
            pair<ll,pll> p; p.F=maxr[cur].F-maxr[cur].S+1;p.S.F=maxr[cur].S;p.S.S=1LL;
            fenw.update(1,n,maxr[cur].S,p);
            ++cur;
        }
        for(auto k:r[i])
        {
            pair<ll,pll> p= fenw.query(k.F,i);
            ll x = n*p.S.S - p.S.F - (n-i)*p.S.S+p.S.S;
            x=p.F-x;
            ans[k.S]-=x;
        }
    }
    for(int i=0;i<q;++i)
        cout<<ans[i]<<" ";
    return 0;
}

signed main()
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