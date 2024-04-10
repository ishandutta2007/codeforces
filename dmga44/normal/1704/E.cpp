#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
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
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<ll> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        // db(n)
        vector<int> g[n];
        vector<int> ts;
        vector<int> deg(n);
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            deg[v]++;
        }
        // db(n)

        // db("xxx")
        queue<int> q;
        for(int i=0;i<n;i++)
            if(!deg[i])
                q.push(i);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            ts.push_back(u);
            for(auto v : g[u])
            {
                deg[v]--;
                if(!deg[v])
                    q.push(v);
            }
        }
        // db(n)
        // db("xxx")

        int tar=ts.back();
        vector<ll> ap=a;
        int extra=0;
        int outs=0;
        int last=-1;
        for(int i=0;i<=n+1;i++)
        {
            // db(i)
            vector<ll> cpy=ap;
            for(int j=0;j<n;j++)
            {
                if(ap[ts[j]])
                {
                    cpy[ts[j]]--;
                    for(auto v : g[ts[j]])
                    {
                        cpy[v]++;
                    }
                }
            }
            // db(i)
            if(!ap[tar])
            {
                extra++;
            }
            else
            {
                outs++;
                last=i;
            }
            ap=cpy;
            // db(i)
        }
        // db("xxx")

        // cout << extra << ' ' << outs << ' ' << last << '\n';

        for(int i=0;i<n-1;i++)
        {
            for(auto v : g[ts[i]])
                a[v]=(a[v]+a[ts[i]])%mod;
            a[ts[i]]=0;
        }

        // cout << a[tar] << '\n';
        if(ap[tar])
        {
            cout << (extra+a[tar])%mod << '\n';
        }
        else
        {
            cout << last+1 << '\n';
        }
    }

    return 0;   
}