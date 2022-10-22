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
typedef pair<int,int> pii;
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
#define oo (ll)(2e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<pii> g[MAXN];
set<pii> ig[MAXN];
map<pii,int> fq;
int cant[MAXN];
int ma[100][100];

int trans(pii x)
{
    return ((x.f)*(x.f-1))/2+x.s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        g[u].push_back(pii(w,v));
    }

    for(int i=0;i<n;i++)
    {
        sort(all(g[i]));
        for(int j=0;j<g[i].size();j++)
        {
            int u=g[i][j].s;
            cant[u]++;
            ig[u].insert(pii(g[i].size(),j));
        }
    }

    bool ok=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(!cant[i])
            ok=0;
        sum+=ig[i].size();
        vector<pii> ks;
        for(auto y : ig[i])
        {
            fq[y]++;
//            cout << y.f << ' ' << y.s << '\n';
            ks.push_back(y);
        }

        for(int j=0;j<ks.size();j++)
            for(int u=j+1;u<ks.size();u++)
                ma[trans(ks[j])][trans(ks[u])]=ma[trans(ks[u])][trans(ks[j])]=1;
    }

  //  ok&=(sum==m);
    if(!ok)
    {
        db(0)
        return 0;
    }

    ll f[k+1];
    f[0]=1;
    for(int i=1;i<=k;i++)
        f[i]=f[i-1]*i;
    ll res=0;
    for(int i=0;i<f[k];i++)
    {
        vector<int> p;
        int ff=i;
        for(int j=0;j<k;j++)
        {
            p.push_back(ff/(f[k]/f[j+1]));
            ff%=(f[k]/f[j+1]);
        }
        ll sum=0;
        for(int j=0;j<k;j++)
            sum+=fq[pii(j+1,p[j])];
        bool ok=1;
        for(int j=0;j<k;j++)
            for(int u=j+1;u<k;u++)
                ok&=(!ma[trans(pii(j+1,p[j]))][trans(pii(u+1,p[u]))]);
//        for(int i=0;i<k;i++)
//            cout << p[i] << ' ';
//        cout << '\n';
//        cout << ok << ' ' << sum << '\n';
        if(ok && sum==n)
        {
            res++;
//            for(int i=0;i<k;i++)
//                cout << p[i] << ' ';
//            cout << '\n';
        }
//        db("")
    }
    db(res)

    return 0;
}
/**
4 6 3
4 2 1
1 2 2
2 4 3
4 1 4
4 3 5
3 1 6

5 5 1
1 4 1
5 1 2
2 5 3
4 3 4
3 2 5
**/