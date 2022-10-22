#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

ll fs[MAXN];
ll t[MAXN];

template <typename T>
struct ST{
    vector< T > st,lazy;
    int sz;
    T neutroL;

    ST (int n,T neutrol) : sz(n),st(4*n),lazy(4*n),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        return (v1+v2)%mod;
    }

    void up(int p,int l,int r,T v)
    {
        st[p]=((r-l+1)*v)%mod;
        lazy[p]=v;
    }

    void push(int p,int l,int r)
    {
        if(l==r)
        {
            lazy[p]=neutroL;
            return ;
        }
        if(lazy[p]==neutroL)
            return ;
        ///(basic) up to code
        T v=lazy[p];
        up((p<<1),l,(l+r)>>1,v);
        up((p<<1)+1,((l+r)>>1)+1,r,v);
        lazy[p]=neutroL;
    }

    void build(vector<T> &arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,vector<T> &arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            lazy[p]=neutroL;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        lazy[p]=neutroL;
    }

    void build(T *arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,T *arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            lazy[p]=neutroL;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        lazy[p]=neutroL;
    }

    void update(int L,int R,T v) { update(1,0,sz-1,L,R,v); }

    void update(int p,int l,int r,int L,int R,T v)
    {
        push(p,l,r);
        if(L<=l && r<=R)
        {
            up(p,l,r,v);
            return ;
        }

        int mid=(l+r)>>1;

        if(L<=mid)
            update(p<<1,l,mid,L,R,v);
        if(R>mid)
            update((p<<1)+1,mid+1,r,L,R,v);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    T query(int L,int R) { return query(1,0,sz-1,L,R); }

    T query(int p,int l,int r,int L,int R)
    {
        push(p,l,r);
        if(L<=l && r<=R)
            return st[p];

        int mid=(l+r)>>1;

        if(R<=mid)
            return query(p<<1,l,mid,L,R);
        if(L>mid)
            return query((p<<1)+1,mid+1,r,L,R);
        return merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
    }
};

ll solve(vector<ll> &v)
{
    ll sum=0;
    ll sumdp=0;
    ll mendp=0;
    ll last=1;
    ll clast=0;
    v.push_back(1);
    int sz=v.size();
//    for(int i=0;i<sz;i++)
//        cout << v[i] << ' ';
//    cout << '\n';
    ST<ll> st(MAXN,0);
    for(int i=0;i<sz;i+=2)
    {
        sumdp=(sumdp+last)%mod;
        mendp=(mendp+(sum*last))%mod;

        sum+=v[i];
        last=(sumdp*sum-mendp+mod)%mod;
        clast=last;
        last=(last*v[i+1])%mod;
        if(i+2<sz)
            last=(last-st.query(1,v[i+1])+mod)%mod;
        st.update(1,v[i+1],clast);
//        cout << i/2 << ' ' << sumdp << ' ' << sum << ' ' << mendp << ' ' << clast << ' ' << last << '\n';
    }
    return last;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen(".in","r",stdin);

    string s;
    cin >> s;
    int ty=s[0]-'0';
    int cant=0;
    int sz=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(ty!=s[i]-'0')
        {
            fs[cant]=sz;
            t[cant]=ty;
            sz=0;
            cant++;
            ty=1-ty;
        }
        sz++;
    }
    fs[cant]=sz;
    t[cant]=ty;
    cant++;

    if(fs[0]==n)
    {
        db(n)
        return 0;
    }
    ll mul=1;
    int ini=0;
    if(!t[0])
    {
        ini++;
        mul=fs[0]+1;
    }
    int fin=cant-1;
    if(!t[fin])
    {
        mul=(mul*(fs[fin]+1))%mod;
        fin--;
    }

    vector<ll> ts;
    for(int i=ini;i<=fin;i++)
        ts.push_back(fs[i]);

    db((solve(ts)*mul)%mod)
//    int l=0;
//    int r=100000;
//    ll v=1e5;
//    db((r-l)*v)
    return 0;
}
/**
000
0101
0001111
00101100011100
**/