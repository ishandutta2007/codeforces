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
typedef double ld;
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
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<pip> qs;
set<int> lims[MAXN];
vector<int> intervals[MAXN];
vector<pii> updates;

template <typename T>
struct ST1{
    vector< T > st;
    vector< pii > intervals;
    int sz;

    ST1 (int n) : sz(n),st(4*n),intervals(4*n) {}
    ST1 () : sz(0),st(0) {}

    T merge(T v1,T v2)
    {
        return v1+v2;
    }

    void build(vector<T> &arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,vector<T> &arr)
    {
        if(l==r)
        {
            st[p]=0;
            intervals[p]=pii(arr[l],arr[r+1]-1);
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=0;
        intervals[p]=pii(arr[l],arr[r+1]-1);
    }

    void update(int L,int R) { update(1,0,sz-1,L,R); }

    void update(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
        {
            if(st[p]==r-l+1)
                return ;
            else
            {
                if(l!=r)
                {
                    int mid=(l+r)>>1;

                    update(p<<1,l,mid,L,R);
                    update((p<<1)+1,mid+1,r,L,R);

                    st[p]=merge(st[p<<1],st[(p<<1)+1]);
                }
                else
                {
                    st[p]=1;
                    updates.push_back(intervals[p]);
                }
            }
            return ;
        }

        int mid=(l+r)>>1;

        if(L<=mid)
            update(p<<1,l,mid,L,R);
        if(R>mid)
            update((p<<1)+1,mid+1,r,L,R);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }
};

ST1<int> bases[MAXN];

template <typename T>
struct ST2{
    vector< T > st;
    vector<pii> lazy;
    int sz;
    pii neutroL;

    ST2 (int n,pii neutrol) : sz(n),st(4*n),lazy(4*n),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        return (v1+v2)%mod;
    }

    void up(int p,int l,int r,pii v)
    {
        ll m=v.f;
        ll s=v.s;
        st[p]=(st[p]*m+s*(r-l+1))%mod;
        ll mm=lazy[p].f;
        ll ss=lazy[p].s;
        mm=(mm*m)%mod;
        ss=(ss*m+s)%mod;
        lazy[p]=pii(mm,ss);
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
        pii v=lazy[p];
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

    void update(int L,int R,pii v) { update(1,0,sz-1,L,R,v); }

    void update(int p,int l,int r,int L,int R,pii v)
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++)
    {
        lims[i].insert(0);
        lims[i].insert(n);
    }
    for(int i=0;i<q;i++)
    {
        int ty;
        cin >> ty;
        if(ty==1)
        {
            int l,r,x;
            cin >> l >> r >> x;
            l--;
            x--;
            qs.push_back(pip(x,pii(l,r)));
            lims[x].insert(l);
            lims[x].insert(r);
        }
        if(ty==2)
        {
            int l,r;
            cin >> l >> r;
            l--,r--;
            qs.push_back(pip(-1,pii(l,r)));
        }
    }

    for(int i=0;i<n;i++)
    {
        for(auto y : lims[i])
            intervals[i].push_back(y);
//        db("")
//        cout << i << '\n';
//        for(auto y : intervals[i])
//            cout << y << ' ';
//        cout << '\n';
        bases[i]=ST1<int> (intervals[i].size()-1);
        bases[i].build(intervals[i]);
    }

    ST2<ll> st(n,pii(1,0));
    vector<ll> ini(n);
    st.build(ini);

    for(int i=0;i<q;i++)
    {
        int ty=qs[i].f;
        int l=qs[i].s.f;
        int r=qs[i].s.s;
        if(ty==-1)
            db(st.query(l,r))
        else
        {
            int x=ty;
            int lp=lower_bound(all(intervals[x]),l)-intervals[x].begin();
            int rp=lower_bound(all(intervals[x]),r)-intervals[x].begin()-1;
            r--;
            bases[x].update(lp,rp);
            int ap=l;
            for(auto p : updates)
            {
                int li=p.f;
                int ls=p.s;
                if(li>ap)
                    st.update(ap,li-1,pii(2,0));
                st.update(li,ls,pii(1,1));
                ap=ls+1;
            }
            if(ap<=r)
                st.update(ap,r,pii(2,0));
//            db("")
//            cout << i << '\n';
//            for(auto y : updates)
//                cout << y.f << ' ' << y.s << '\n';

            updates.clear();
        }
    }

    return 0;
}
/**
4 4
1 1 2 1
1 1 2 2
1 1 4 1
2 1 4

3 7
1 1 1 3
1 1 1 3
1 1 1 2
1 1 1 1
2 1 1
1 1 1 2
2 1 1
**/