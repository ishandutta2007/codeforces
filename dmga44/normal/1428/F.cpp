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
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

ll ma[MAXN];

template<typename T>
struct RMQ{
    vector<vector<T>> rmq;
    vector<int> lg;
    int n;
    bool t;
    RMQ(vector<T> &v,bool t) : n(v.size()),t(t)
    {
        lg.push_back(-1);
        for(int i=1;i<=n+5;i++)
            lg.push_back(lg.back()+!(i&(i-1)));

        for(int i=0;i<=n;i++)
            rmq.push_back(vector<T>(lg[n]+1));
        for(int i=0;i<n;i++)
            rmq[i][0]=v[i];
        for(int j=1;j<=lg[n];j++)
            for(int i=0;i+(1<<j)<=n;i++)
            {
                if(!t)
                    rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
                else
                    rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
            }
    }

    T query(int l,int r)
    {
        if(l>r)
            swap(l,r);
        int po=lg[r-l+1];
        if(!t)
            return min(rmq[l][po],rmq[r-(1<<po)+1][po]);
        return max(rmq[l][po],rmq[r-(1<<po)+1][po]);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int sz=0;
    vector<pii> szs;
    vector<int> a(n);
    ll sum_ini=0;
    ll xxx=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
            sz++;
        else
        {
            if(sz)
                szs.push_back(pii(sz,i-sz));
            sz=0;
        }
        xxx=max(xxx,(ll)sz);
        a[i]=sz;
        sum_ini+=xxx;
    }
    if(sz)
        szs.push_back(pii(sz,n-sz));

    for(auto y : szs)
        ma[y.s]=y.f;
    for(int i=1;i<n;i++)
    {
        if(ma[i])
            continue;
        ma[i]=max(0ll,ma[i-1]-1);
    }

//    for(int i=0;i<n;i++)
//    {
//        cout << ma[i] << ' ';
//    }
//    cout << '\n';
//    for(int i=0;i<n;i++)
//    {
//        cout << a[i] << ' ';
//    }
//    cout << '\n';
//    db(sum_ini)

    RMQ<int> rmq(a,1);
    ll res=sum_ini;
    ll act=sum_ini;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='0')
        {
            res+=act;
            continue;
        }
//        db("")
//        db(ma[i])
        act-=ma[i];
        int l=i+ma[i];
        int r=l-1;
        for(int po=(1<<20);po;po>>=1)
            if(r+po<n && rmq.query(l,r+po)<ma[i])
                r+=po;
//        db(r)
        act-=(r-l+1);
//        cout << i << ' ' << act << '\n';
        res+=act;
    }
    db(res)

    return 0;
}
/**
4
0110

3
111
**/