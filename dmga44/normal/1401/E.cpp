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
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

template <typename T>
struct ST{
    vector< T > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    T merge(T v1,T v2)
    {
        return v1+v2;
    }

    void up(int p,T v)
    {
        st[p]+=v;
    }

    void build(T *arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,T *arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

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

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    void update(int pos,T v) { update(1,0,sz-1,pos,v); }

    void update(int p,int l,int r,int pos,T v)
    {
        if(pos<=l && r<=pos)
        {
            up(p,v);
            return ;
        }
        int mid=(l+r)>>1;

        if(pos<=mid)
            update(p<<1,l,mid,pos,v);
        if(pos>mid)
            update((p<<1)+1,mid+1,r,pos,v);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
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
        return merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
    }
};

vector<pii> ls[MAXN];
vector<int> us0[MAXN];
vector<int> us1[MAXN];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n,m,x,y,l,r;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> y >> l >> r;
        ls[y].push_back(pii(l,r));
    }

    vector<int> ini(MAXN);
    ini[0]=ini[1e6]=1;
    for(int i=0;i<m;i++)
    {
        cin >> x >> l >> r;
        if(!l)
        {
            ini[x]=1;
            us1[r].push_back(x);
//            cout << x << ' ' << l << ' ' << r << '\n';
        }
        else
            us0[l].push_back(x);
    }

    ST<int> st(MAXN);
    st.build(ini);
    set<int> s1;
    set<int,greater<int>> s2;
    ll res=0;
    for(int i=1;i<1e6;i++)
    {
//        db(i)
        for(auto y : us0[i])
        {
            s1.insert(y);
            s2.insert(y);
        }

        for(auto y : ls[i])
        {
            l=y.f;
            r=y.s;
//            cout << l << ' ' << r << '\n';
            res+=st.query(l,r)-1;
//            db("xxx")
            while(!s1.empty() && (*s1.begin())>=l && (*s1.begin())<=r)
            {
                int x=(*s1.begin());
                st.update(x,1);
                s1.erase(x);
                s2.erase(x);
//                cout << "+" << x << '\n';
            }
//            db("xxx")
            while(!s2.empty() && (*s2.begin())>=l && (*s2.begin())<=r)
            {
                int x=(*s2.begin());
                st.update(x,1);
                s1.erase(x);
                s2.erase(x);
//                cout << "+" << x << '\n';
            }
//            db("xxx")
        }

        for(auto y : us1[i])
        {
            st.update(y,-1);
//            cout << "-" << y << '\n';
        }
    }
    res+=st.query(0,1e6)-1;
    db(res)

    return 0;
}
/**
3 3
2 3 1000000
4 0 4
3 0 1000000
4 0 1
2 0 5
3 1 1000000
**/