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

const int N = (1 << 18) + 100;

struct node
{
    ll ans, sum;
    int len;
    ll suf, pref;
    node() {
        sum = 0;
        ans = -INF, len = 0, suf = -INF, pref = -INF;
    }
}fake;
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    ll lazy[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.ans = max(a.ans, b.ans);
        ret.ans = max(ret.ans, a.suf + b.pref);
        ret.sum = a.sum + b.sum;
        ret.len = a.len + b.len;
        ret.pref = max(a.pref, a.sum + b.pref);
        ret.suf = max(b.suf, b.sum + a.suf);
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.sum = val;
        ret.ans = max(0ll, val);
        ret.len = 1;
        ret.suf = ret.pref = ret.ans;
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
    void update(int v, int st, int en, int len) {
        if(en - st + 1 == len) {
            swap(tree[v << 1], tree[v << 1 | 1]);
            tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
            return;
        }
        int mid = (st + en) / 2;
        update(v << 1, st, mid, len);
        update(v << 1 | 1, mid + 1, en, len);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
}seg;

int _runtimeTerror_()
{
    int n;
    cin >> n;
    int sz = (1 << n);
    for(int i=1;i<=sz;++i) {
        cin >> seg.a[i];
    }
    seg.buildTree(1, 1, sz);

    vector<ll> ans(1 << n, -INF);
    function<void(int, int)> dfs = [&](int mask, int len) {
        if(len == n) {
            ans[mask] = seg.tree[1].ans;
            return ;
        }
        dfs(mask, len + 1);
        seg.update(1, 1, sz, (1 << (len + 1)));
        dfs(mask | (1 << len), len + 1);
        seg.update(1, 1, sz, (1 << (len + 1)));
    };
    dfs(0, 0);

    int Q;
    cin >> Q;
    int mask = 0;
    while(Q--) {
        int x;
        cin >> x;
        mask ^= (1 << x);
        cout << ans[mask] << "\n";
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