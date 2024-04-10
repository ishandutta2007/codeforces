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
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e7+5)

int p[MAXN];
vector<int> sq;

void criba()
{
    for(int i=0;i<MAXN;i++)
        p[i]=i;
    for(int i=2;i*i<MAXN;i++)
        sq.push_back(i*i);
    for(auto x : sq)
        for(int i=x;i<MAXN;i+=x)
            while(p[i]%x==0)
                p[i]/=x;
}

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

int dp[(int)(2e5+5)][22];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<22;j++)
                dp[i][j]=1e9+5;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            a[i]=p[a[i]];
        }
//        for(auto x : a)
//            db(x)
        map<int,int> last;
        vector<int> pre(n);
        for(int i=0;i<n;i++)
        {
            if(last[a[i]])
                pre[i]=last[a[i]]-1;
            else
                pre[i]=-1;
            last[a[i]]=i+1;
        }
//        db("xxx")

        RMQ<int> rmq(pre,1);
//        db("xxx")

        dp[0][0]=0;
//        for(int i=0;i<n;i++)
//            cout << pre[i] << ' ';
//        cout << '\n';
        for(int i=0;i<n;i++)
        {
//            db(i)
            vector<int> pos;
            int act=i;
            for(int j=0;j<=k;j++)
            {
//                db("xxx")
//                db(j)
//                db(act)
                for(int po=(1<<17);po;po>>=1)
                    if(act+po<n && rmq.query(act+1,act+po)<i)
                        act+=po;
                pos.push_back(act);
                if(act<n-1)
                    act++;
            }

            for(int j=0;j<=k;j++)
                for(int l=0;l+j<=k;l++)
                    dp[pos[l]+1][l+j]=min(dp[pos[l]+1][l+j],dp[i][j]+1);
        }

        int res=1e9+5;
        for(int i=0;i<=k;i++)
            res=min(res,dp[n][i]);
        db(res)
    }

    return 0;
}
/**
1
5 2
18 6 2 4 1
**/