#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper") // Enable AVX

/// UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<ll, ll> pii;
typedef pair<ld, ll> pdi;
typedef pair<ld, ld> pdd;
typedef pair<ld, pdd> pdp;
typedef pair<string, ll> psi;
typedef pair<ll, string> pls;
typedef pair<string, string> pss;
typedef pair<ll, pii> pip;
typedef pair<pii, pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point, int> ppi;
#define prec(n)        \
    cout.precision(n); \
    cout << fixed
const ll mod = (1e9 + 7);
const ld eps = (1e-9);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(2e5 + 5)

vector<int> divs[MAXN];
vector<int> divs2[MAXN];
vector<int> imp[MAXN];
ll cant[MAXN];

int may(vector<int>& v,int x)
{
    int ans=-1;
    int n=v.size();
    for(int po=(1<<9);po;po>>=1)
        if(ans+po<n && v[ans+po]>x)
            ans+=po;
    ans++;
    return ans;
}

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    vector<pip> qs;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin >> l >> r;
        qs.push_back(pip(l,pii(r,i)));
    }

    sort(all(qs));

    //prec
    for(int i=1;i<MAXN;i++)
    {
        for(int j=2*i;j<MAXN;j+=i)
            divs[j].push_back(i);
        for(int j=3*i;j<2*MAXN;j+=i)
            if(j%2==0)
                divs2[j/2].push_back(i);
    }

    for(int i=1;i<MAXN;i++)
    {
        int p2=i&-i;
        p2<<=1;
        for(auto d : divs2[i])
            if((d&-d)==p2)
                imp[i].push_back(d);
    }

    for(int i=1;i<MAXN;i++)
    {
        reverse(all(divs[i]));
        reverse(all(divs2[i]));
        reverse(all(imp[i]));
    }

    for(int i=1;i<MAXN;i++)
    {
        ll cantd=divs[i].size();
        cant[i]+=(cantd*(cantd-1))/2;
        for(auto d : divs2[i])
        {
            if((d&-d)==(i*2)&(-(i*2)))
                cant[i]+=may(divs2[i],max(i-d,d));
            else
                cant[i]+=may(imp[i],max(i-d,d));
        }
    }

    ST<ll> st(MAXN);
    st.build(cant);

    // for(int i=1;i<=20;i++)
    // {
    //     cout << i << ' ' << divs2[i].size() << ' ' << imp[i].size() << '\n';
    // }
    // cout << '\n';
    // for(int i=0;i<10;i++)
    // {
    //     cout << cant[i] << ' '; 
    // }
    // cout << '\n';

    vector<ll> ans(q);
    int last=1;
    for(int i=0;i<q;i++)
    {
        int l=qs[i].first;
        int r=qs[i].second.first;
        int id=qs[i].second.second;
        
        while(last<l)
        {
            for(int j=last*2;j<MAXN;j+=last)
            {
                divs[j].pop_back();
                int sz=divs[j].size();
                int dif=-sz;
                cant[j]+=dif;
                // if(j<6)
                //     cout << j << ' ' << dif << " t1" << '\n';
                st.update(j,dif);
            }

            for(int j=3*last;j<2*MAXN;j+=last)
            {
                if(j&1)
                    continue;
                int pos=j/2;
                int type=(j&(-j))==(last&(-last));
                if(type)//imp
                {
                    int dif=may(divs2[pos],max(pos-last,last));
                    cant[pos]-=dif;
                    // if(pos<6)
                        // cout << divslast << ' ' << pos << ' ' << dif << " t21"<<'\n';
                    st.update(pos,-dif);
                    imp[pos].pop_back();
                    divs2[pos].pop_back();
                }
                else
                {
                    int dif=may(imp[pos],max(pos-last,last));
                    cant[pos]-=dif;
                    // if(pos<6)
                    //     cout << pos << ' ' << dif << " t22"<<'\n';
                    st.update(pos,-dif);
                    divs2[pos].pop_back();
                }
            }
            last++;
        }

        ll len=r-l+1;
        // cout << l << ' ' << r << '\n';
        // cout << (len*(len-1)*(len-2))/6 << ' ' << st.query(l,r) << '\n';
        // for(int j=0;j<10;j++)
        //     cout << cant[j] << ' ';
        // cout << '\n';
        // cout << '\n';
        ans[id]=(len*(len-1)*(len-2))/6-st.query(l,r);
    }

    for(int i=0;i<q;i++)
        cout << ans[i] << '\n';

    return 0;
}