// Har Har Mahadev
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

//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 300005;

vector<int> v[N];

struct node
{
    ll val = 0,cnt = 0;
}fake;

struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        if(a.val == b.val)
            ret.val = a.val , ret.cnt = a.cnt + b.cnt;
        else if(a.cnt > b.cnt)
            ret.cnt = a.cnt - b.cnt,ret.val = a.val;
        else
            ret.val = b.val , ret.cnt = b.cnt - a.cnt;
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.val = val,ret.cnt = 1;
        return ret;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(a[st]);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    node query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake;
        if(st>=l && en<=r)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg;

int _runtimeTerror_()
{
    int n,Q;
    cin>>n>>Q;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        a[i] = x;
        seg.a[i] = x;
        v[x].push_back(i);
    }
    seg.buildTree(1,1,n);
    auto cnt = [&](int l,int r,int i)
    {
        return upper_bound(all(v[i]),r) - lower_bound(all(v[i]),l);
    };
    for(int i=1;i<=Q;++i)
    {
        int l,r;
        cin>>l>>r;
        int mx = -1;
        int len = r-l+1;
        int el = seg.query(1,1,n,l,r).val;
        if(cnt(l,r,el) > (len+1)/2)
            mx = cnt(l,r,el);
        if(mx == -1)
            cout<<"1\n";
        else
            cout<<2*mx-len<<"\n";
    }
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