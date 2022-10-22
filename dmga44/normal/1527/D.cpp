#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128_t int128;
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<int> g[MAXN];
bool mk[MAXN];
int sz[MAXN];
int p[MAXN];
vector<int> sons[MAXN];
ll ans[MAXN];

void dfs(int u,int parent)
{
    mk[u]=1;
    p[u]=parent;
    sz[u]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            dfs(v,u);
            sz[u]+=sz[v];
        }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        for(int i=0;i<=n;i++)
        {
            g[i].clear();
            mk[i]=0;
            sz[i]=0;
            p[i]=0;
            ans[i]=0;
            sons[i].clear();
        }
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0,-1);

        for(int i=0;i<n;i++)
            mk[i]=0;

        ll rem=(n*(n-1))/2;
        for(auto v : g[0])
            rem-=(sz[v]*(sz[v]-1))/2;
        ans[0]=(n*(n-1))/2-rem;
        mk[0]=1;
        ll extl=0,extr=0;
        for(int i=1;i<n;i++)
        {
            int u=i;
            while(!mk[u])
            {
                mk[u]=1;
                sons[p[u]].push_back(u);
                u=p[u];
            }

            if(u==i)//already ok
                continue;
            if((sons[u].size()==2 && u!=0) || sons[u].size()>2)
            {
                ans[i]=rem;
                rem=0;
                break;
            }
            //ok
            ll rem_act=rem;
            if(extl==u)
                extl=i;
            else if(extr==u)
                extr=i;
            ll sz1=sz[extl];
            ll sz2=sz[extr];
            for(auto v : sons[extl])
                sz1-=sz[v];
            for(auto v : sons[extr])
                sz2-=sz[v];
            rem=sz1*sz2;
            ans[i]=rem_act-rem;
        }
        ans[n]=rem;

        for(int i=0;i<=n;i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}