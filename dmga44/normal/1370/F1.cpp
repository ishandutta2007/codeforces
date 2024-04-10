#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

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
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

pii ask(vector<int> &a)
{
    cout << "?" << ' ' << a.size();
    for(auto y : a)
        cout << ' ' << y+1;
    cout << '\n';
    cout.flush();
    int u,d;
    cin >> u >> d;
    return pii(u,d);
}

vector<int> g[MAXN];
bool mk[MAXN];
int level[MAXN];
int d[MAXN];
vector<int> dl[2][MAXN];
vector<int> fin[MAXN];

int dfs(int u)
{
    mk[u]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            level[v]=level[u]+1;
            dfs(v);
        }
}

void dfs2(int u)
{
    mk[u]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            d[v]=d[u]+1;
            dfs2(v);
        }
}

void dfs3(int u)
{
    mk[u]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            level[v]=level[u]+1;
            fin[level[v]].push_back(v);
            dfs3(v);
        }
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,u,v;
        cin >> n;
        for(int i=0;i<n-1;i++)
        {
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> pp;
        for(int i=0;i<n;i++)
            pp.push_back(i);

        pii base=ask(pp);

        dfs(0);
        for(int i=0;i<n;i++)
            mk[i]=0;
        int center=base.first-1;
        dfs2(center);
        dl[0][0].push_back(center);
        int m[2];
        m[0]=m[1]=0;
        for(int i=0;i<n;i++)
        {
            bool f=((level[i]-level[center])==d[i]);
            dl[f][d[i]].push_back(i);
            m[f]=max(m[f],d[i]);
        }

        int act=1;
//        if(m[0]<500)
//            act=0;
        pii ok=base;
        int dis=0;
        for(int u=(1<<9);u;u>>=1)
        {
            if(dis+u>m[act])
                continue;
            pii xxx=ask(dl[act][dis+u]);
            if(xxx.second==base.second)
            {
                dis+=u;
                ok=xxx;
            }
        }

        center=ok.f-1;
        level[center]=0;
        for(int i=0;i<n;i++)
            mk[i]=0;

        dfs3(center);

        pii ans=ask(fin[ok.s]);
        cout << "!" << ' ' << ok.f << ' ' << ans.first << '\n';
        cout.flush();
        string que_es_esto;
        cin >> que_es_esto;

        for(int i=0;i<MAXN;i++)
        {
            mk[i]=0;
            level[i]=0;
            d[i]=0;
            g[i].clear();
            dl[0][i].clear();
            dl[1][i].clear();
            fin[i].clear();
        }
    }

    return 0;
}