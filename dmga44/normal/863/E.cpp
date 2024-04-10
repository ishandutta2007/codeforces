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
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;

template <typename T>
struct st_lazy{
    vector< T > st,lazy;
    ll sz;
    T neutroQ,neutroL;

    st_lazy (ll n,T neutroq,T neutrol) : sz(n),st(4*n),lazy(4*n),neutroQ(neutroq),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        return min(v1,v2);
    }

    void up(int p,int l,int r,T v)
    {
        lazy[p]+=v;
        st[p]+=v;
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
        int v=lazy[p];
        lazy[p<<1]+=v;
        lazy[(p<<1)+1]+=v;
        st[p<<1]+=v;
        st[(p<<1)+1]+=v;
        lazy[p]=neutroL;
    }

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

    T query(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
            return st[p];
        else if(L>r || l>R)
            return neutroQ;
        push(p,l,r);

        int mid=(l+r)>>1;

        return merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,l,r;
    cin >> n;
    vector<pii> vs;
    set<int> s;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin >> l >> r;
        vs.push_back(pii(l,r));
        s.insert(l);
        s.insert(r+1);
    }

    int cont=0;
    for(auto y : s)
    {
        mp[y]=cont;
        cont++;
    }

    st_lazy<int> st(3*n+10,1e9,0);
    for(int i=0;i<n;i++)
    {
        int p1=mp[vs[i].f];
        int p2=mp[vs[i].s+1]-1;
        st.update(1,0,3*n+9,p1,p2,1);
    }

    int res=-1;
    for(int i=0;i<n;i++)
    {
        int p1=mp[vs[i].f];
        int p2=mp[vs[i].s+1]-1;
        if(st.query(1,0,3*n+9,p1,p2)>1)
            res=i+1;
    }
    db(res)

    return 0;
}
/**
3
1 3
4 6
1 7
**/