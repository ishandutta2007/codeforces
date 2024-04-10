// endpos equivalency
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

const int N = 500005;
struct node
{
    int minimum = 2e9;
    int sum = 0;
}fake;
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.minimum=min(a.minimum,b.minimum);
        ret.sum = a.sum+b.sum;
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.minimum=val;
        ret.sum = val;
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
    void update(ll v,ll st,ll en,ll in,ll val)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(tree[v].sum+val);
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val);
        else
            update(v<<1 | 1,mid+1,en,in,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    int query(ll v,ll st,ll en,ll l,ll val)
    {
        if(en<l)
            return -1;
        if(tree[v].minimum>=val)
            return -1;
        if(st==en)
        {
            assert(tree[v].minimum<val);
            return st;
        }
        ll mid=(st+en)>>1;
        int u = query(v<<1,st,mid,l,val);
        if(u!=-1)
            return u;
        return query(v<<1|1,mid+1,en,l,val);
    }
    int sum(int v,int st,int en,int l,int r)
    {
        if(en<l || st>r)
            return 0;
        if(st>=l && en<=r)
            return tree[v].sum;
        ll mid=(st+en)>>1;
        return sum(v<<1,st,mid,l,r)+sum(v<<1 | 1,mid+1,en,l,r);
    }
}seg;


vector<pii> q[2*N];
vector<int> idx[2*N];
int cntr[N],n;
const int LEN = 1000005;
// should be 2*length
struct SA
{
    struct state
    {
        int len,link;
        map<char,int> next;
    };
    state st[LEN];
    int sz,last;
    bitset<LEN> vis;
    int cnt[LEN];

    void SA_make()
    {
        sz = 0;
        st[0].len = 0,st[0].link = -1;
        ++sz;
        last = 0;
    }

    SA() {
        SA_make();
    }
    void add(char c)
    {
        int new_n = sz++;
        st[new_n].len = st[last].len + 1;
        int pt = last;
        while(pt!=-1 && !st[pt].next.count(c))
        {
            st[pt].next[c] = new_n;
            pt = st[pt].link;
        }
        if(pt == -1)
        {
            st[new_n].link = 0;
        }
        else
        {
            int q_st = st[pt].next[c];
            if(st[q_st].len == st[pt].len + 1)
                st[new_n].link = q_st;
            else
            {
                int clone = sz++;
                st[clone] = st[q_st];
                st[clone].len = st[pt].len + 1;
                st[q_st].link = st[new_n].link = clone;
                while(pt!=-1 && st[pt].next[c] == q_st)
                {
                    st[pt].next[c] = clone;
                    pt = st[pt].link;
                }
            }
        }
        last = new_n;
    }
    int minlen(int u)
    {
        if(u==0)
            return 0;
        return st[st[u].link].len + 1;
    }
    void build(string &s,int n)
    {
        int id = 1;
        for(char c : s)
        {
            add(c);
            cnt[last] = n-id+1;
            ++id;
        }
        buildIdx();
    }
    void buildIdx()
    {
        vector<int> v;
        for(int i=1;i<sz;++i)
            v.pb(i);
        sort(all(v),[&](int x,int y)
        {
            return st[x].len>st[y].len;
        });
        for(int i=0;i<sz-1;++i)
        {
            if(cnt[v[i]])
                cnt[st[v[i]].link] = cnt[v[i]];
        }
    }
    void dfs(int u=0)
    {
        if(vis[u])
            return ;
        vis[u] = 1;
        if(u)
        {
            int r = cnt[u] + st[u].len-1;
            int l = minlen(u) + cnt[u]-1;
            int v = cntr[cnt[u]-1];
            // cout<<"len : "<<st[u].len<<"\n";
            // cout<<"minlen : "<<minlen(u)<<"\n";
            int rr = seg.query(1,1,n,cnt[u]-1,v);
            // cout<<"u l r "<<u<<" "<<l<<" "<<r<<"\n";
            // cout<<"cnt[u] : "<<cnt[u]<<"\n";
            if(rr==-1)
                rr = n+1;
            // cout<<"rr : "<<rr<<"\n";
            // cout<<"v : "<<v<<"\n";
            amin(rr,r);
            if(rr>=l)
                q[v+n].pb({l,rr});
            // cout<<"-----\n";
        }
        for(auto j:st[u].next)
            dfs(j.S);
    }
}sa;


int _runtimeTerror_()
{
    ll ans = 0;
    cin>>n;
    string s;
    cin>>s;
    reverse(all(s));
    sa.build(s,n); 
    reverse(all(s));
    vector<int> v;
    for(int i=1;i<=n;++i)
    {
        v.pb(i);
        cntr[i] = cntr[i-1] + (s[i-1]=='('?1:-1),seg.a[i] = cntr[i];
        idx[cntr[i]+n].pb(i);
    }
    seg.buildTree(1,1,n);
    sa.dfs();
    for(int i=1;i<=n;++i)
        seg.a[i]=0;
    seg.buildTree(1,1,n);
    for(int i=0;i<=2*n;++i)
    {
        for(auto j:idx[i])
            seg.update(1,1,n,j,1);
        for(auto j:q[i])
        {
            ans += seg.sum(1,1,n,j.F,j.S);
        }
        for(auto j:idx[i])
            seg.update(1,1,n,j,-1);
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