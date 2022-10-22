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
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(2e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

template <typename T>
struct ST{
    vector< T > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    void build(vector<T> &arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,vector<T> &arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=min(st[p<<1],st[(p<<1)+1]);
    }

    void update(int pos,T v) { update(1,0,sz-1,pos,v); }

    void update(int p,int l,int r,int pos,T v)
    {
        if(pos<=l && r<=pos)
        {
            st[p]=v;
            return ;
        }
        int mid=(l+r)>>1;

        if(pos<=mid)
            update(p<<1,l,mid,pos,v);
        if(pos>mid)
            update((p<<1)+1,mid+1,r,pos,v);

        st[p]=min(st[p<<1],st[(p<<1)+1]);
    }

    T query(int L,int R) { return query(1,0,sz-1,L,R); }

    T query(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
            return st[p];

        int mid=(l+r)>>1;

        if(R<=mid)
            return query(p<<1,l,mid,L,R);
        if(L>mid)
            return query((p<<1)+1,mid+1,r,L,R);
        return min(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
    }
};

int mask(int x)
{
    vector<int> ds;
    for(int i=0;i<9;i++)
    {
        ds.push_back(x%10);
        x/=10;
    }

    int res=0;
    for(int i=0;i<9;i++)
        if(ds[i])
            res+=(1<<i);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<ST<pii>> vst;
    vector<pii> ini[9];
    for(int j=0;j<9;j++)
        for(int i=0;i<n;i++)
            ini[j].push_back(pii(oo,i));
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        int b=mask(a);
        for(int j=0;j<9;j++)
            if(b&(1<<j))
                ini[j][i].f=a;
    }
    for(int i=0;i<9;i++)
    {
        vst.push_back(ST<pii>(n));
        vst.back().build(ini[i]);
    }

    while(m--)
    {
        int ty;
        cin >> ty;
        if(ty==1)
        {
            int p,x;
            cin >> p >> x;
            p--;
            int b=mask(x);
            for(int i=0;i<9;i++)
            {
                if(b&(1<<i))
                    vst[i].update(p,pii(x,p));
                else
                    vst[i].update(p,pii(oo,p));
            }
        }
        else
        {
            int l,r;
            cin >> l >> r;
            l--,r--;
            int res=2e9+5;
            for(int i=0;i<9;i++)
            {
                pii mi=vst[i].query(l,r);
                if(mi.f==oo)
                    continue;
                int pos=mi.s;
                vst[i].update(pos,pii(oo,pos));

                pii ma=vst[i].query(l,r);
                vst[i].update(pos,pii(mi.f,pos));
                if(ma.f==oo)
                    continue;

                res=min(res,ma.f+mi.f);
            }

            if(res==2e9+5)
                db(-1)
            else
                db(res)
        }
    }

    return 0;
}
/**
4 5
300 10001 20 20
2 1 3
1 1 310
2 1 3
2 3 3
2 3 4
**/