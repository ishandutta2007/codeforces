#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

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
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(2e9+99)
#define mod2 (ll)(998244353)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1.5e3+5)
#define b (ll)(331)

int a[MAXN][MAXN];
map<ll,int> mf;
map<ll,vector<ll> > g;
//map<ll,set<ll> > g;
ll base[MAXN];
ll hs[MAXN][MAXN];
bool mk[MAXN][MAXN];
bool ok[MAXN][MAXN];

vector<ll> dfs(ll u)
{
    vector<ll> res(1);
    res[0]=1;
    for(auto v : g[u])
    {
//        cout << u << ' ' << v << '\n';
        vector<ll> rv=dfs(v);
        vector<ll> nr(res.size()+rv.size()-1);

        vector<int> pv;
        for(int i=1;i<rv.size();i++)
            if(rv[i])
                pv.push_back(i);
        vector<int> pr;
        for(int i=0;i<res.size();i++)
            if(res[i])
                pr.push_back(i);

        for(auto y : pv)
            for(auto x : pr)
                nr[y+x]=(nr[y+x]+rv[y]*res[x])%mod2;
        res=nr;
    }

    if(res.size()<2)
        res.push_back(0);
    res[1]=(res[1]+1)%mod2;
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    base[0]=1;
    for(int i=1;i<MAXN;i++)
        base[i]=(base[i-1]*b)%mod;

    int n;
//    cin >> n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        vector<pii> vp;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
//            cin >> a[i][j];
            vp.push_back(pii(a[i][j],j));
        }

        sort(all(vp));

        ll h=0;
        for(int j=0;j<n;j++)
        {
            h=(h+base[vp[j].s])%mod;
            hs[i][j]=h;
        }
    }

    for(int i=0;i<n;i++)
    {
        vector<pii> vp;
        for(int j=0;j<n;j++)
            vp.push_back(pii(a[i][j],j));

        sort(all(vp));

        for(int j=0;j<n;j++)
        {
            if(mk[i][j])
                continue;
            bool kk=1;
            for(int k=0;k<=j;k++)
            {
                if(mk[vp[k].s][j])
                {
                    kk=0;
                    break;
                }
                if(hs[vp[k].s][j]!=hs[i][j])
                {
                    kk=0;
                    break;
                }
                else
                    mk[vp[k].s][j]=1;
            }
            if(kk)
                for(int k=0;k<=j;k++)
                    ok[vp[k].s][j]=1;
        }
    }

    vector<pii> edges;
    for(int i=0;i<n;i++)
    {
        vector<ll> oks;
        for(int j=0;j<n;j++)
            if(ok[i][j])
                oks.push_back(hs[i][j]);
        for(int j=1;j<oks.size();j++)
            edges.push_back(pii(oks[j],oks[j-1]));
    }

    sort(all(edges));

    for(int i=0;i<edges.size();i++)
        if(!i || edges[i]!=edges[i-1])
            g[edges[i].f].push_back(edges[i].s);
//    for(int i=0;i<n;i++)
//    {
//        vector<pii> vp;
//        for(int j=0;j<n;j++)
//        {
//            scanf("%d",&a[i][j]);
////            cin >> a[i][j];
//            vp.push_back(pii(a[i][j],j));
//        }
//
//        sort(all(vp));
//
//        ll h=0;
//        for(int j=0;j<n;j++)
//        {
//            h=(h+base[vp[j].s])%mod;
//            mf[h]++;
//            hs[i][j]=h;
//        }
//    }
//
//    for(int i=0;i<n;i++)
//    {
//        vector<ll> oks;
//        for(int j=0;j<n;j++)
//            if(mf[hs[i][j]]==j+1)
//                oks.push_back(hs[i][j]);
//        for(int j=1;j<oks.size();j++)
//            g[oks[j]].insert(oks[j-1]);
//    }

    vector<ll> res=dfs(hs[0][n-1]);

    for(int i=1;i<=n;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}
/**
4
0 3 4 6
3 0 2 1
4 2 0 5
6 1 5 0
**/