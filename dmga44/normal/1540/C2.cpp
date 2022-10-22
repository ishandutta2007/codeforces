//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e2+5)

template <typename T>
struct ST{
    vector< T > st,lazy;
    int sz;
    T neutroL;

    ST (int n = 0,T neutrol = 0) : sz(n),st(4*n),lazy(4*n),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        return (v1+v2)%mod;
    }

    void up(int p,int l,int r,T v)
    {
        st[p]=(st[p]+v*(r-l+1))%mod;
        lazy[p]=(lazy[p]+v)%mod;
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

ll aux(vector<ll> cs,vector<ll> b,ll n,ll x)
{
    vector<ll> sums(100*100+2);
    for(int i=1;i<=100*100+1;i++)
        sums[i]=1;
    ll sum=0;
    ll v=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            v=x;
            sum=x;
        }
        else
        {
            v+=b[i-1];
            sum+=v;
        }
        vector<ll> s2(100*100+2);
        for(int k=0;k<=100*100;k++)
            s2[k+1]=(sums[k+1]-sums[max(k-cs[i],0ll)]+mod)%mod;
        sums=s2;
        for(int j=0;j<=100*100;j++)
        {
            if(j<=sum)
                sums[j]=0;
            sums[j+1]=(sums[j+1]+sums[j])%mod;
        }
    }

//    for(int i=0;i<20;i++)
//        cout << sums[700-i] << ' ';
//    cout << '\n';


    ll ans=sums[100*100+1];
//    for(int i=0;i<=100*100;i++)
//        ans=(ans+sums[i])%mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> cs(n);
    for(int i=0;i<n;i++)
        cin >> cs[i];
    vector<ll> b(n-1);
    for(int i=0;i<n-1;i++)
        cin >> b[i];
    int q;
    cin >> q;
    vector<ll> ans(q);
    vector<pii> qs;
    for(int i=0;i<q;i++)
    {
        int x;
        cin >> x;
        qs.push_back(pii(x,i));
    }
//    db("xxx")
//    vector<ST<ll>> sums(n+1);
//    for(int i=0;i<n+1;i++)
//        sums[i]=ST<ll>(100*100+1,0);
////    db("xxx")
//    sums[0].update(0,0,1);
//
//    for(int i=0;i<n;i++)
//        for(int j=0;j<=100*100;j++)
//            sums[i+1].update(j,j,sums[i].query(max(j-cs[i],0ll),j));

    sort(all(qs));

    ll ini=aux(cs,b,n,-1e5);
    int last=-1e6;
    vector<ll> lvs(n,-1e6);
    for(int i=0;i<q;i++)
    {
        int id=qs[i].s;
        int x=qs[i].f;
        if(x==last)
        {
            ans[id]=ans[qs[i-1].s];
            continue;
        }
        vector<ll> vs;
        ll v=x;
        vs.push_back(x);
        for(int j=0;j<n-1;j++)
        {
            v+=b[j];
            vs.push_back(vs.back()+v);
        }
        if(vs.back()<0)
        {
            ans[id]=ini;
            continue;
        }
        if(vs.back()>100*100)
        {
            ans[id]=0;
            continue;
        }

//        for(int j=n-1;j>=0;j--)
//        {
//            ll ini=max(0ll,lvs[j]);
//            ll fin=min(100*100ll,vs[j]-1);
////            cout << j << ' ' << ini << ' ' << fin << '\n';
//            for(ll k=ini;k<=fin;k++)
//            {
//                ll act=sums[j].query(max(k-cs[j],0ll),k);
//                if(j<n-1 && max(vs[j+1],(ll)k)<=min(k+cs[j+1],100*100ll))
//                    sums[j+2].update(max(vs[j+1],(ll)k),min(k+cs[j+1],100*100ll),(mod-act));
//            }
//        }
//
//        for(int j=n-1;j>=0;j--)
//        {
//            ll ini=max(0ll,lvs[j]);
//            ll fin=min(100*100ll,vs[j]-1);
//            for(ll k=ini;k<=fin;k++)
//            {
//                ll act=sums[j+1].query(k,k);
//                sums[j+1].update(k,k,(mod-act));
//            }
//        }
        lvs=vs;
        last=x;
//        db("xxx")
//        for(int i=0;i<=n;i++)
//        {
//            for(int j=0;j<=20;j++)
//                cout << sums[i].query(700-j,700-j)  << ' ';
//            cout << '\n';
//        }
//        db("")
        ll v2=aux(cs,b,n,x);
//        ans[id]=sums[n].query(0,100*100)%mod;
        ans[id]=v2;
//        if(ans[id]!=v2)
//        {
//            cout << ans[id] << ' ' << v2 << '\n';
//            cout << "xxx: " << x << '\n';
//            db("")
//        }
    }

    for(int i=0;i<q;i++)
        db(ans[i])

    return 0;
}
/**
3
2 3 4
2 1
5
-1 0 1 -100000 100000

7
100 100 100 100 100 100 100
0 0 0 0 0 0
4
100
99
98
0

7
10 10 10 10 10 10 10
0 0 0 0 0 0
4
10
99
98
0
**/