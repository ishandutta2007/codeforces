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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 3000
#endif

const int N = 300005;
struct node
{
    ll sum;
}fake={0};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    ll lazy[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.sum=a.sum+b.sum;
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.sum=val;
        return ret;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        tree[v].sum+=(en-st+1)*lazy[v];
        if(st!=en)
        {
            lazy[v<<1]+=lazy[v];
            lazy[v<<1 | 1]+=lazy[v];
        }
        lazy[v]=0;
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
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in,ll val)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(val);
            a[st]=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val);
        else
            update(v<<1 | 1,mid+1,en,in,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void rupdate(ll v,ll st,ll en,ll l,ll r,ll val)
    {
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(en<l || st>r)return ;
        if(st>=l && en<=r)
        {
            lazy[v]=val;
            pushdown(v,st,en);
            return ;
        }
        ll mid=(st+en)>>1;
        rupdate(v<<1,st,mid,l,r,val);
        rupdate(v<<1 | 1,mid+1,en,l,r,val);
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
    int get_1(int v, int st, int en, int l) {
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(en < l || tree[v].sum == 0) {
            return -1;
        }
        if(st == en) {
            return st;
        }
        int mid = (st + en) >> 1;
        int u = get_1(v << 1, st, mid, l);
        if(u != -1) {
            return u;
        }
        return get_1(v << 1 | 1, mid + 1, en, l);
    }
    int get_0(int v, int st, int en, int l) {
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(en < l || tree[v].sum == en - st + 1) {
            return -1;
        }
        if(st == en) {
            return st;
        }
        int mid = (st + en) >> 1;
        int u = get_0(v << 1, st, mid, l);
        if(u != -1) {
            return u;
        }
        return get_0(v << 1 | 1, mid + 1, en, l);
    }
    int last_1(int v, int st, int en) {
        if(lazy[v] != 0) {
            pushdown(v, st, en);
        }
        if(st == en) {
            return st;
        }
        int mid = (st + en) / 2;
        pushdown(v << 1 | 1, mid + 1, en);
        if(tree[v << 1 | 1].sum == 0) {
            return last_1(v << 1, st, mid);
        }
        return last_1(v << 1 | 1, mid + 1, en);
    }
}seg;


int _runtimeTerror_()
{
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n + 1), b(N + 1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        ++b[a[i]];
    }
    for(int i=1;i<=2e5 + 100;++i) {
        b[i + 1] += b[i] / 2;
        b[i] &= 1;
        seg.a[i] = b[i];
    }
    n = 3e5;
    seg.buildTree(1, 1, n);
    while(Q--) {
        int id, x;
        cin >> id >> x;
        int ans = seg.get_1(1, 1, n, a[id]);
        if(ans > a[id]) {
            seg.rupdate(1, 1, n, a[id], ans - 1, 1);
        }
        seg.rupdate(1, 1, n, ans, ans, -1);
        ans = seg.get_0(1, 1, n, x);
        if(ans > x) {
            seg.rupdate(1, 1, n, x, ans - 1, -1);
        }
        seg.rupdate(1, 1, n, ans, ans, 1);

        a[id] = x;

        cout << seg.last_1(1, 1, n) << "\n";
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
        initncr();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}