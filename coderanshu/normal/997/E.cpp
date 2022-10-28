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

struct node
{
    ll minimum = INF,cnt = 0;
    ll upd = 0;
    ll ans = 0;
    ll lazy = 0;
}fake;
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    inline void combine(node &ret,node &a,node &b)
    {
        ret.cnt = 0;
        ret.minimum = min(a.minimum,b.minimum);
        if(ret.minimum == a.minimum)
            ret.cnt += a.cnt;
        if(ret.minimum == b.minimum)
            ret.cnt += b.cnt;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.minimum = val;
        ret.cnt = 1;
        return ret;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        if(tree[v].lazy == 0 && tree[v].upd == 0)
            return ;
        tree[v].ans += tree[v].cnt * tree[v].upd;
        tree[v].minimum += tree[v].lazy;
        if(st!=en)
        {
            tree[v<<1].lazy += tree[v].lazy;
            tree[v<<1|1].lazy += tree[v].lazy;
            if(tree[v<<1].minimum + tree[v<<1].lazy == tree[v].minimum)
                tree[v<<1].upd += tree[v].upd;
            if(tree[v<<1|1].minimum + tree[v<<1|1].lazy == tree[v].minimum)
                tree[v<<1|1].upd += tree[v].upd;
        }
        tree[v].lazy = 0;
        tree[v].upd = 0;
        return ;
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
        combine(tree[v],tree[v<<1],tree[v<<1 | 1]);
    }
    void rupdate(ll v,ll st,ll en,ll l,ll r,ll val)
    {
        pushdown(v,st,en);
        if(en<l || st>r)return ;
        if(st>=l && en<=r)
        {
            tree[v].lazy = val;
            pushdown(v,st,en);
            return ;
        }
        ll mid=(st+en)>>1;
        rupdate(v<<1,st,mid,l,r,val);
        rupdate(v<<1 | 1,mid+1,en,l,r,val);
        combine(tree[v],tree[v<<1],tree[v<<1 | 1]);
    }
    void query(ll v,ll st,ll en,ll l,ll r,ll &ans)
    {
        if(en<l || st>r)
            return;
        pushdown(v,st,en);
        if(st>=l && en<=r)
        {
            ans += tree[v].ans;
            return;
        }
        ll mid=(st+en)>>1;
        query(v<<1,st,mid,l,r,ans);
        query(v<<1 | 1,mid+1,en,l,r,ans);
    }
}seg;

vector<pii> q[N];
ll ans[N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> p(n+1);
    for(int i=1;i<=n;++i)
        seg.a[i] = 0;
    seg.buildTree(1,1,n);
    for(int i=1;i<=n;++i)
        cin>>p[i];
    vector<int> mn{0},mx{0};
    int Q;
    cin>>Q;
    for(int i=1;i<=Q;++i)
    {
        int l,r;
        cin>>l>>r;
        q[r].push_back({l,i});
    }
    for(int i=1;i<=n;++i)
    {
        while(mn.back() && p[i] < p[mn.back()])
        {
            int r = mn.back();
            mn.pop_back();
            int l = mn.back();
            seg.rupdate(1,1,n,l+1,r,-(p[i]-p[r]));
        }
        seg.rupdate(1,1,n,1,i,-1);
        while(mx.back() && p[i] > p[mx.back()])
        {
            int r = mx.back();
            mx.pop_back();
            int l = mx.back();
            seg.rupdate(1,1,n,l+1,r,p[i]-p[r]);
        }
        mx.push_back(i);
        mn.push_back(i);
        ++seg.tree[1].upd;
        for(auto &[l,id]:q[i])
            seg.query(1,1,n,l,i,ans[id]);
    }
    for(int i=1;i<=Q;++i)
        cout<<ans[i]<<"\n";
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