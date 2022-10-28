#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
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
struct Matrix
{
    ll val[2][2];
    int n_;
    inline Matrix (int n) : n_(n)
    {
        // val.resize(n_);
        //for(ll i=0;i<n_;++i);
            // val[i].resize(n_);
    }
    inline Matrix ():n_(2)
    {
        // val.resize(n_);
        for(int i=0;i<n_;++i);
            // val[i].resize(n_);  
        val[0][0]=val[1][1]=1;
        val[1][0]=val[0][1]=0;
    }
    void set(int x)
    {
        for(int i=0;i<n_;++i)
            for(int j=0;j<n_;++j)
                val[i][j]=x;
    }
    Matrix operator*(const Matrix& b) const 
    {
        int n=n_;
        Matrix ans(n);
        ans.set(0);
        for(int i=0;i<n_;++i)
        {
            for(int j=0;j<n_;++j)
            {
                ans.val[i][j]=0;
                for(ll k=0;k<n_;++k)
                {
                    ans.val[i][j]+=val[i][k]*b.val[k][j];
                    ans.val[i][j]%=M;
                }

            }
        }
        return ans;
    }
};
Matrix I(int n)
{
    Matrix Iden(n);
    Iden.set(0);
    for(int i=0;i<n;++i)
        Iden.val[i][i]=1;
    return Iden;
}
const int N=100005;
Matrix tree[3*N],lazy[3*N];
Matrix ident(2);
Matrix power(Matrix &m,int pw)
{
    if(pw==0)
        return ident;
    if(pw==1)
        return m;
    Matrix t=power(m,pw/2);
    t=t*t;
    if(pw&1)
        t=t*m;
    return t;
}
Matrix fib(2),fake(2),global(2);
ll n,m;
struct SEGTREE
{
    ll a[N];
    //Matrix tree[4*N];
    //Matrix lazy[4*N];
    bool lazyhai[4*N];
    //SEGTREE(){mem0(lazy);}
    inline void combine(Matrix &ans,Matrix &a,Matrix &b)
    {
        ans.set(0);
        for(int i=0;i<2;++i)
            for(int j=0;j<2;++j)
                ans.val[i][j]=(a.val[i][j]+b.val[i][j])%M;
    }
    inline void make_node(Matrix &a,ll val)
    {
        a=power(fib,val-1);
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        tree[v]=tree[v]*lazy[v];
        if(st!=en)
        {
            lazy[v<<1]=lazy[v<<1]*lazy[v];
            lazyhai[v<<1]=true;
            lazyhai[v<<1 | 1]=true;
            lazy[v<<1 | 1]=lazy[v<<1| 1]*lazy[v];
        }
        lazy[v]=ident;
        lazyhai[v]=false;
        return ;
    }
    void buildTree(int v,int st,int en)
    {
        if(st==en)
        {
            make_node(tree[v],a[st]);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        combine(tree[v],tree[v<<1],tree[v<<1 | 1]);
    }
    void rupdate(int v,int st,int en,int l,int r)
    {
        if(lazyhai[v])
        {
            pushdown(v,st,en);
        }
        if(en<l || st>r)return ;
        if(st>=l && en<=r)
        {
            lazy[v]=global;
            lazyhai[v]=true;
            pushdown(v,st,en);
            return ;
        }
        int mid=(st+en)>>1;
        rupdate(v<<1,st,mid,l,r);
        rupdate(v<<1 | 1,mid+1,en,l,r);
        combine(tree[v],tree[v<<1],tree[v<<1 | 1]);
    }
    ll query(int v,int st,int en,int l,int r)
    {
        if(en<l || st>r)
            return 0;
        if(lazyhai[v])
        {
            pushdown(v,st,en);
        }
        if(st>=l && en<=r)
            return tree[v].val[0][0];
        int mid=(st+en)>>1;
        return (query(v<<1,st,mid,l,r)+query(v<<1 | 1,mid+1,en,l,r))%M;
    }
}seg;
int _runtimeTerror_()
{
    fib.set(1);
    fib.val[1][1]=0;
    fake.set(0);
    cin>>n>>m;
    // ll a[n];
    ident=I(2);
    for(int i=0;i<n;++i)
        cin>>seg.a[i];
    seg.buildTree(1,0,n-1);
    for(int i=0;i<4*N;++i)
        seg.lazyhai[i]=false;
    for(int i=0;i<m;++i)
    {
        int tt,l,r;
        cin>>tt>>l>>r;
        if(tt==1)
        {
            int x;
            cin>>x;
            --l;--r;
            global=power(fib,x);
            seg.rupdate(1,0,n-1,l,r);
        }
        else
        if(tt==2)
        {
            --l;--r;
           	ll ans=seg.query(1,0,n-1,l,r);
            cout<<ans<<'\n';
        }
    }
    return 0;
}

int main()
{
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    cerr<<endl<<_time_<<endl;
    return 0;
}