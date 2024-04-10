#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

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

int res[MAXN];

void solve(RMQ<int>& rmq,int l,int r,int p,int v)
{
    if(p<=1)
        return ;
    if(rmq.query(l,r)!=v)
        return ;
    res[p-1]=1;
    int v1=rmq.query(l,r-1);
    int v2=rmq.query(l+1,r);
    if(v1==v && v2==v+1)
    {
        res[p-2]=1;
        if(rmq.query(l+1,l+1)==v+1)
            solve(rmq,l+2,r,p-2,v+2);
        else
            solve(rmq,l+1,r-1,p-2,v+2);

    }
    else if(v1==v+1 && v2==v)
    {
        res[p-2]=1;
        if(rmq.query(l,l)==v+1)
            solve(rmq,l+1,r-1,p-2,v+2);
        else
            solve(rmq,l,r-2,p-2,v+2);
    }
    return ;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            res[i]=0;
        for(int i=0;i<n;i++)
            cin >> a[i];
        RMQ<int> rmq(a,0);

        solve(rmq,0,n-1,n,1);
        sort(all(a));
        res[0]=1;
        for(int i=1;i<n;i++)
            if(a[i]==a[i-1])
                res[0]=0;
        for(int i=0;i<n;i++)
            cout << res[i];
        cout << '\n';
    }

    return 0;
}