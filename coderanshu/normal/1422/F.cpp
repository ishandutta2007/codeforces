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

#define runSieve
const int N=200005;
bool prime[N];
ll pf[N];
void sieve()
{
    int k=sqrt(N-2);
    for(int i=1;i<=N-2;++i)
        prime[i]=true;
    for(int i=2;i<=k;++i)
    {
        if(prime[i])
        {
            for(int k=i*i;k<=N-2;k+=i)
            {
                prime[k]=false;
                pf[k]=i;
            }
        }
    }
}

    
const int MOD=1000000007;
struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};


// const int N= 100005;
map<int,int> idx;

const int NN = 30000001;
struct node{
    Mint val;
    int L,R;
    node (): L(-1),R(-1),val(1){};
    node(Mint x) : L(-1),R(-1),val(x){};
};
struct PERTREE{
    node tree[NN];
    int cursz=0;
    ll buildTree(ll st,ll en)
    {
        ll v = cursz++;
        tree[v]=node();
        if(st==en)
            return v;
        ll mid=(st+en)>>1;
        tree[v].L=buildTree(st,mid);
        tree[v].R=buildTree(mid+1,en); 
        return v;
    }
    ll update(ll v,ll st,ll en,ll pos,ll val)
    {
        ll u=cursz++;
        // current value + value jo merko add karni hai is my answer //
        // and is node ko update karna hai islie hi ispe call hua hai function
        if(st==en)
        {
            tree[u] = node(val);
            return u;
        }
        // agar leaf hai to seedha return kar do wrna left ya right jisko update karna ho kar do
        // just re adjusting the pointers and combining the updates....
        ll mid=(st+en)>>1;
        if(pos<=mid)
            tree[u].L=update(tree[v].L,st,mid,pos,val);
        else 
            tree[u].R=update(tree[v].R,mid+1,en,pos,val);
        tree[u].L=(tree[u].L==-1)?tree[v].L:tree[u].L;
        tree[u].R=(tree[u].R==-1)?tree[v].R:tree[u].R;
        tree[u].val = (tree[tree[u].L].val*tree[tree[u].R].val);
        // cout<<tree[u].val<<"\n";
        return u;
    }
    Mint query(int v,int st,int en,int l,int r)
    {
        if(en<l || st>r)
            return 1;
        if(st>=l && en<=r)
            return tree[v].val;
        ll mid=(st+en)>>1;
        return query(tree[v].L,st,mid,l,r)*query(tree[v].R,mid+1,en,l,r);
    }
}seg;

int root[N];
int lst[N],a[N];

struct T 
{
    vector<int> v[19];
}el[100];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> pr;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=200000;++i)
        lst[i] = -1;
    int cur = 0;
    for(int i=2;i<=450;++i)
    {
        if(prime[i])
        {
            pr.pb(i);
            idx[i] = cur++;
        }
    }
    int last = 0;
    root[0] = seg.buildTree(1,n);
    for(int i=1;i<=n;++i)
    {
        root[i] = root[i-1];
        int k = a[i];
        while(k!=1 && !prime[k])
        {
            int z=pf[k],cnt = 0;
            while(k%z==0)k/=z,++cnt;
            assert(z<=450);
            int u = idx[z];
            el[u].v[cnt].pb(i);
        }
        if(k!=1)
        {
            if(k<=450)
            {
                int u = idx[k];
                el[u].v[1].pb(i);
            }
            else
            {
                if(lst[k]!=-1)
                    root[i] = seg.update(root[i],1,n,lst[k],1);
                lst[k] = i;
                root[i] = seg.update(root[i],1,n,lst[k],k);
            }
        }
    }
    int Q;
    cin>>Q;
    for(int i=0;i<Q;++i)
    {
        int l,r;
        cin>>l>>r;
        l = (last + l)%n + 1;
        r = (last + r)%n + 1;
        if(l>r)
            swap(l,r);
        Mint x = seg.query(root[r],1,n,l,r);
        for(auto &j:pr)
        {
            int u = idx[j];
            int e = 1;
            int mx = 1;
            for(int k=0;e<=200000;++k)
            {
                auto it = lower_bound(all(el[u].v[k]),l)-el[u].v[k].begin();
                if(it<sz(el[u].v[k]))
                {
                    if(el[u].v[k][it]<=r)
                        amax(mx,e);
                }
                e *=j;
            }
            // if(mx!=1)
                // cout<<mx<<"\n";
            x *= mx;
        }
        cout<<x<<"\n";
        last = (int)x;
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