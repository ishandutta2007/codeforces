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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

vector<int> g[MAXN];
vector<ll> times;
ll sons[MAXN];
bool mk[MAXN];
int n;

void dfs(int u)
{
    mk[u]=1;
    sons[u]=1;
    for(auto v : g[u])
    {
        if(mk[v])
            continue;
        dfs(v);
        sons[u]+=sons[v];
        times.push_back((sons[v]*(n-sons[v])));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int u,v;
        cin >> n;
        for(int i=0;i<n-1;i++)
        {
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int m;
        cin >> m;
        vector<ll> ps(m);
        for(int i=0;i<m;i++)
            cin >> ps[i];

        sort(all(ps));
        while(ps.size()>=n)
        {
            ll x=ps.back();
            ps.pop_back();
            ll y=ps.back();
            ps.pop_back();
            x=(x*y)%mod;
            ps.push_back(x);
        }
        reverse(all(ps));
        while(ps.size()<n-1)
            ps.push_back(1);
        dfs(0);
        sort(allr(times));

        ll res=0;
        for(int i=0;i<n-1;i++)
        {
            times[i]%=mod;
            res=(res+(ps[i]*times[i]))%mod;
        }
        db(res)

        for(int i=0;i<n;i++)
        {
            sons[i]=0;
            mk[i]=0;
            g[i].clear();
        }
        times.clear();
    }

    return 0;
}