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
#define mod (ll)(2e9+99)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(1e4+5)

bitset<MAXN> ans;

template <typename T>
struct ST{
    vector< vector< T > > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    void up(int p,int l,int r,T v)
    {
        st[p].push_back(v);
    }

    void update(int L,int R,T v) { update(1,0,sz-1,L,R,v); }

    void update(int p,int l,int r,int L,int R,T v)
    {
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
    }

    void query(int L,int R,bitset<MAXN> ini) { query(1,0,sz-1,ini); }

    void query(int p,int l,int r,bitset<MAXN> bs)
    {
        for(auto y : st[p])
            bs|=(bs<<y);
        if(l==r)
        {
            ans|=bs;
            return ;
        }

        int mid=(l+r)>>1;
        query(p<<1,l,mid,bs);
        query((p<<1)+1,mid+1,r,bs);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q,l,r,x;
    cin >> n >> q;
    ST<int> st(n);
    for(int i=0;i<q;i++)
    {
        cin >> l >> r >> x;
        l--,r--;
        st.update(l,r,x);
    }

    ans[0]=1;
    st.query(0,n-1,ans);

    vector<int> res;
    for(int i=1;i<=n;i++)
        if(ans[i])
            res.push_back(i);

    db(res.size())
    for(auto y : res)
        cout << y << ' ';
    cout << '\n';

    return 0;
}