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

const int N = 200005;

int r[N],lenr[N];
int rnk[N],p[N];

int parent(int i)
{
    return p[i] = (p[i]==i)?i:parent(p[i]);
}

void merge(int x,int y)
{
    x = parent(x),y = parent(y);
    if(x==y)
        return ;
    if(rnk[x]>rnk[y])
        swap(x,y);
    if(rnk[x]==rnk[y])
        ++rnk[y];
    p[x] = y;
    amax(r[y],r[x]);
    amax(lenr[y],lenr[x]);
}

int px[N],lx[N];
struct Qu
{
    int x,y,i;
};

template<typename T=long long>
struct fenwick {
    T a[N],bit[N];
    int n;
    fenwick() 
    {
        for(int i=1;i<=N-2;++i)
            a[i] = T(0),bit[i] = T(0);
    }
    void build(int n_)
    {
        n = n_;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;j+=j&-j)
                bit[j] += a[i];
    }
    void update(int j,T val)
    {
        int pos = j;
        for(;j<=n;j+=j&-j)
            bit[j] += val - a[pos];
        a[pos] = val;
    }
    T get(int r)
    {
        T u = 0;
        for(;r;r-=r&-r)
            u += bit[r]; 
        return u;
    }
    T query(int l,int r)
    {
        return get(r)-get(l-1);
    }
};

fenwick<int> fenw;
int ans[N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>px[i]>>lx[i];
        p[i] = i;
        r[i] = i;
        lenr[i] = px[i] + lx[i];
    }   
    int Q;
    cin>>Q;
    vector<Qu> q(Q);
    int curr = Q-1;    
    for(int i=0;i<Q;++i)
    {
        cin>>q[i].x>>q[i].y;
        q[i].i = i;
    }
    sort(all(q),[&](Qu a,Qu b)
    {
        return a.x<b.x;
    }); 
    fenw.build(n);
    for(int i=n-1;i>=1;--i)
    {
        int cur = i;
        fenw.update(cur+1,px[cur+1]-lenr[cur]);
        while(cur < n && lenr[parent(cur)]>=px[cur+1])
        {
            fenw.update(cur+1,0);
            merge(cur,cur+1);
            cur = r[parent(cur)];
        }
        fenw.update(cur+1,px[cur+1]-lenr[parent(cur)]);
        while(curr >=0 && q[curr].x==i)
        {
            ans[q[curr].i] = fenw.query(i,q[curr].y);
            --curr;
        }
    }   
    for(int i=0;i<Q;++i)
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