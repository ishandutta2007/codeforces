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
#define debug(...) 2401
#endif

struct Matrix
{
    ll val[3][3];
    ll n_;
    Matrix (ll n = 3) : n_(n)
    {
        for(ll i=0;i<3;++i) {
            for(int j=0;j<3;++j) {
                val[i][j] = 0;
            }
        }
    }
    void print()
    {
        for(ll i=0;i<n_;++i)
        {
            for(ll j=0;j<n_;++j)
                cout<<val[i][j]<<" ";
            cout<<"\n";
        }
    }
    void set(ll x)
    {
        for(ll i=0;i<n_;++i)
            for(ll j=0;j<n_;++j)
                val[i][j]=x;
    }
    Matrix operator*(const Matrix& b) const 
    {
        ll n=n_;
        Matrix ans(n);
        ans.set(INF);
        for(ll i=0;i<n_;++i)
        {
            for(ll j=0;j<n_;++j)
            {
                ans.val[i][j]=INF;
                for(ll k=0;k<n_;++k)
                {
                    amin(ans.val[i][j], val[i][k] + b.val[k][j]);
                }
            }
        }
        return ans;
    }
};
Matrix I(ll n)
{
    Matrix Iden(n);
    Iden.set(0);
    for(ll i=0;i<n;++i)
        Iden.val[i][i]=1;
    return Iden;
}
Matrix power(Matrix m,ll pw)
{
    if(pw==0)
        return I(m.n_);
    if(pw==1)
        return m;
    Matrix t=power(m,pw/2);
    t=t*t;
    if(pw&1)
        t=t*m;
    return t;
}

const int N = 100005;

struct node
{
    Matrix m;
    node() {
        m = Matrix();
    }
}fake;
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    void update(ll v,ll st,ll en,ll in,char c)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            Matrix &tmp = tree[v].m;
            tmp.set(INF);
            if(c == 'a') {
                tmp.val[0][0] = 1;
            }
            else {
                tmp.val[0][0] = 0;
            }
            tmp.val[1][0] = 0;
            if(c == 'b') {
                tmp.val[1][1] = 1;
            }
            else {
                tmp.val[1][1] = 0;
            }
            tmp.val[2][0] = tmp.val[2][1] = 0;
            if(c == 'c') {
                tmp.val[2][2] = 1;
            }
            else {
                tmp.val[2][2] = 0;
            }
            // cout << c << "\n";
            // tmp.print();
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,c);
        else
            update(v<<1 | 1,mid+1,en,in,c);
        tree[v].m=tree[v<<1|1].m*tree[v<<1].m;
    }
    // Matrix query(ll v,ll st,ll en,ll l,ll r)
    // {
    //     if(en<l || st>r)
    //         return fake;
    //     if(st>=l && en<=r)
    //         return tree[v];
    //     ll mid=(st+en)>>1;
    //     return query(v<<1,st,mid,l,r) * query(v<<1 | 1,mid+1,en,l,r);
    // }
}seg;

int _runtimeTerror_()
{
    int n, Q;
    cin >> n >> Q;
    string s;
    cin >> s;
    for(int i=0;i<n;++i) {
        seg.update(1, 0, n-1, i, s[i]);
    }
    for(int i=1;i<=Q;++i) {
        int id;
        char c;
        cin >> id >> c;
        seg.update(1,0,n-1,id-1,c);
        ll ans = INF;
        Matrix &m = seg.tree[1].m;
        // m.print();
        for(int i=0;i<3;++i) {
            for(int j=0;j<3;++j) {
                amin(ans, m.val[i][j]);
            }
        }
        cout << ans << "\n";
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
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}