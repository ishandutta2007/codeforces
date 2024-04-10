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
//typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

struct ST{
    vector< pii > st;
    vector< pii > st2;
    vector<ll>lazy;
    int sz;
    int neutroL;

    ST (int n,int neutrol) : sz(n),st(4*n),st2(4*n),lazy(4*n),neutroL(neutrol) {}

    pii merge(pii v1,pii v2)
    {
        return min(v1,v2);
    }

    pii merge2(pii v1,pii v2)
    {
        return max(v1,v2);
    }

    void up(int p,int l,int r,ll v)
    {
        st[p].f=max(st[p].f,v);
        st2[p].f=max(st2[p].f,v);
        lazy[p]=max(lazy[p],v);
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
        int v=lazy[p];
        up((p<<1),l,(l+r)>>1,v);
        up((p<<1)+1,((l+r)>>1)+1,r,v);
        lazy[p]=neutroL;
    }

    void build(vector<pii> &arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,vector<pii> &arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            st2[p]=arr[l];
            lazy[p]=neutroL;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        st2[p]=merge2(st2[p<<1],st2[(p<<1)+1]);
        lazy[p]=neutroL;
    }

    vector<pip> update(int L,int R,int v)
    {
        vector<pip> res;
//        db("bla")
        pii x=query(L,R);
        int m=x.f;
        int p=x.s;
        while(m<v)
        {
//            cout << m << ' ' << p << '\n';
            pii x2=query2(1,0,sz-1,p,R,m);
//            cout << x2.f << ' ' << x2.s << '\n';
            if(x2.first!=m)
                x2.s--;
            res.push_back(pip(v-m,pii(p,x2.s)));
//            cout << p << ' ' << x2.s << '\n';
            update(1,0,sz-1,p,x2.s,v);

            x=query(L,R);
            m=x.f;
            p=x.s;
        }
//        db("")
        return res;
    }

    void update(int p,int l,int r,int L,int R,int v)
    {
        if(L<=l && r<=R)
        {
            up(p,l,r,v);
            return ;
        }
        push(p,l,r);

        int mid=(l+r)>>1;

        if(L<=mid)
            update(p<<1,l,mid,L,R,v);
        if(R>mid)
            update((p<<1)+1,mid+1,r,L,R,v);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        st2[p]=merge2(st2[p<<1],st2[(p<<1)+1]);
    }

    pii query(int L,int R) { return query(1,0,sz-1,L,R); }

    pii query(int p,int l,int r,int L,int R)
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

    pii query2(int p,int l,int r,int L,int R,int v)
    {
        push(p,l,r);
        if(L<=l && r<=R)
        {
            if(st2[p].f==v)
                return pii(v,r);
            if(l==r)
                return pii(st2[p].f,r);

            int mid=(l+r)>>1;
            pii x1=query2(p<<1,l,mid,L,R,v);
            if(x1.first>v)
                return x1;
            return query2((p<<1)+1,mid+1,r,L,R,v);
        }

        int mid=(l+r)>>1;

        if(R<=mid)
            return query2(p<<1,l,mid,L,R,v);
        if(L>mid)
            return query2((p<<1)+1,mid+1,r,L,R,v);
        pii x1=query2(p<<1,l,mid,L,R,v);
        if(x1.first>v)
            return x1;
        return query2((p<<1)+1,mid+1,r,L,R,v);
    }
};

template <typename T>
struct ST2{
    vector< T > st,lazy;
    int sz;
    T neutroL;

    ST2 (int n,T neutrol) : sz(n),st(4*n),lazy(4*n),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        return min(v1,v2);
    }

    void up(int p,int l,int r,T v)
    {
        st[p].f+=v.f;
        lazy[p].f+=v.f;
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
        if(L<=l && r<=R)
        {
            up(p,l,r,v);
            return ;
        }
        push(p,l,r);

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
        if(L<=l && r<=R)
            return st[p];
        push(p,l,r);

        int mid=(l+r)>>1;

        if(R<=mid)
            return query(p<<1,l,mid,L,R);
        if(L>mid)
            return query((p<<1)+1,mid+1,r,L,R);
        return merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
    }
};

map<pii,int> mki;
map<pii,int> mkp;
vector<pip> updsi[MAXN];
vector<pip> updsp[MAXN];
vector<pip> updsi2[MAXN];
vector<pip> updsp2[MAXN];
bool res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q;
    cin >> n >> m >> q;
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin >> x >> y;
        if(x&1)
        {
            x=(x-1)/2;
            y=(y-1)/2;
            if(mki[pii(x,y)])
            {
                updsi[x].push_back(pip(y,pii(mki[pii(x,y)]-1,i-1)));
                mki[pii(x,y)]=0;
            }
            else
                mki[pii(x,y)]=i+1;
        }
        else
        {
            x=(x-1)/2;
            y=(y-1)/2;
            if(mkp[pii(x,y)])
            {
                updsp[x].push_back(pip(y,pii(mkp[pii(x,y)]-1,i-1)));
                mkp[pii(x,y)]=0;
            }
            else
                mkp[pii(x,y)]=i+1;
        }
    }

    for(auto y : mki)
        if(y.second)
            updsi[y.f.f].push_back(pip(y.f.s,pii(y.s-1,q-1)));
    for(auto y : mkp)
        if(y.second)
            updsp[y.f.f].push_back(pip(y.f.s,pii(y.s-1,q-1)));

//    db("par")
//    for(int i=0;i<n;i++)
//    {
//        db("")
//        db(i)
//        for(auto y : updsi[i])
//            cout << y.f << ' ' << y.s.f << ' ' << y.s.s << '\n';
//    }
//    db("impar")
//    for(int i=0;i<n;i++)
//    {
//        db("")
//        db(i)
//        for(auto y : updsp[i])
//            cout << y.f << ' ' << y.s.f << ' ' << y.s.s << '\n';
//    }

    vector<pii> ini(q);
    for(int i=0;i<q;i++)
        ini[i]=pii(-1e9,i);
    ST stp(q,-1e9);
    stp.build(ini);
//    db("xxx")
    for(int i=n-1;i>=0;i--)
        for(auto y : updsp[i])
        {
//            cout << y.f << ' ' << y.s.f << ' ' << y.s.s << '\n';
            vector<pip> r=stp.update(y.s.f,y.s.s,y.f);
            for(auto x : r)
                updsp2[i].push_back(x);
//            for(int j=0;j<q;j++)
//                cout << stp.query(j,j).f << ' ';
//            cout << '\n';
        }
//    db("xxx")

    ST sti(q,-1e9);
    sti.build(ini);
    for(int i=0;i<n;i++)
        for(auto y : updsi[i])
        {
            vector<pip> r=sti.update(y.s.f,y.s.s,-y.f);
            for(auto x : r)
                updsi2[i].push_back(x);
        }

//    for(int i=0;i<n;i++)
//    {
//        db("")
//        db(i)
//        for(auto y : updsi2[i])
//            cout << y.f << ' ' << y.s.f << ' ' << y.s.s << '\n';
//    }
//    for(int i=0;i<n;i++)
//    {
//        db("")
//        db(i)
//        for(auto y : updsp2[i])
//            cout << y.f << ' ' << y.s.f << ' ' << y.s.s << '\n';
//    }

    vector<pii> ff(q);
    for(int i=0;i<q;i++)
        ff[i]=pii(2e9,i);
    ST2<pii> st(q,pii(0,0));
    st.build(ff);
    for(int i=0;i<q;i++)
        st.update(i,i,pii(-(stp.query(i,i).f+1e9),0));
    for(int i=0;i<n;i++)
    {
        for(auto y : updsi2[i])
            st.update(y.s.f,y.s.s,pii(-y.f,0));
        while(1)
        {
            pii x=st.query(0,q-1);
            if(x.f<=0)
            {
                res[x.s]=1;
                st.update(x.s,x.s,pii(2e9,0));
            }
            else
                break;
        }

        for(auto y : updsp2[i])
            st.update(y.s.f,y.s.s,pii(y.f,0));
    }

    for(int i=0;i<q;i++)
    {
        if(res[i])
            db("NO")
        else
            db("YES")
    }

    return 0;
}
/**
1 3 3
1 1
1 5
2 4

3 2 7
4 2
6 4
1 3
2 2
2 4
4 4
3 1

3 2 10
4 2
6 4
1 3
4 2
6 4
2 2
2 4
1 3
4 4
3 1

**/