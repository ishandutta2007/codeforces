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
#define mod (ll)(1e9+7)
#define eps (1e-6)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

vector<int> g[MAXN];
bool mk[MAXN];
vector<int> sons[MAXN];
int res[MAXN];
int ls[MAXN],lu[MAXN];
vector<int> dss[MAXN];
int ac[MAXN];

void dfs1(int u)
{
    mk[u]=1;
    ls[u]=0;
    for(auto v : g[u])
        if(!mk[v])
        {
            sons[u].push_back(v);
            dfs1(v);
            ls[u]=max(ls[u],ls[v]+1);
        }
}

void dfs2(int u)
{
    vector<pii> ds;
    for(auto v : sons[u])
        ds.push_back(pii(ls[v]+2,v));

    ds.push_back(pii(lu[u]+1,-1));
    sort(allr(ds));

    for(auto v : sons[u])
    {
        lu[v]=ds[0].f;
        if(v==ds[0].s)
            lu[v]=ds[1].f;
        dfs2(v);
    }
}

void dfs_easy(int u)
{
    vector<int> ds;
    if(u)
        ds.push_back(lu[u]);
    for(auto v : sons[u])
    {
        ds.push_back(ls[v]+1);
        dfs_easy(v);
    }
    sort(allr(ds));

    for(int i=0;i<ds.size();i++)
    {
        ll v=ds[i];
        res[2*v]=max(res[2*v],i+1);
        res[2*v-1]=max(res[2*v-1],i+1);
        if(i && ds[i]<ds[i-1])
            res[2*v+1]=max(res[2*v+1],i+1);
    }
}

void dfs_hard(int u)
{
    vector<int> ds;
    vector<pii> ds2;
    if(u)
    {
        ds.push_back(lu[u]);
        ds2.push_back(pii(lu[u],-1));
    }
    for(auto v : sons[u])
    {
        dfs_hard(v);
        ds.push_back(ls[v]+1);
        dss[u].push_back(ls[v]+1);
        ds2.push_back(pii(ls[v]+1,v));
    }

    sort(all(ds));
    sort(allr(dss[u]));
    sort(allr(ds2));

    vector<pii> to_take;
    set<pii> s;
    for(auto v : sons[u])
    {
        s.insert(pii(0,v));
        for(int i=0;i<dss[v].size();i++)
        {
            int cant=i+ds.size()-(lower_bound(all(ds),dss[v][i])-ds.begin());
            res[2*dss[v][i]]=max(res[2*dss[v][i]],cant);
            to_take.push_back(pii(dss[v][i],v));
        }
    }
    sort(allr(to_take));

    int p=0;
    for(int i=0;i<ds2.size();i++)
    {
        while(p<to_take.size() && to_take[p].f>=ds2[i].f)
        {
            int v=to_take[p].s;
            s.erase(pii(-ac[v],v));
            ac[v]++;
            s.insert(pii(-ac[v],v));
            p++;
        }

        int v=ds2[i].s;
        pii t=(*s.begin());
        if(t.s==v)
        {
            auto it=s.begin();
            it++;
            t=*it;
        }
        res[2*ds2[i].f]=max(res[2*ds2[i].f],(int)(i-t.f));
    }


}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen(".in","r",stdin);

    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    res[n]=res[n-1]=1;
    for(int i=0;i<n;i++)
        res[1]=max(res[1],(int)g[i].size()+1);

    dfs1(0);
    for(int i=0;i<n;i++)
        mk[i]=0;

    dfs2(0);

    dfs_easy(0);

    dfs_hard(0);

//    for(int i=0;i<n;i++)
//    {
//        db("")
//        db(i)
//        cout << lu[i] << ' ' << ls[i] << '\n';
//    }

    for(int i=n-2;i>=1;i--)
        res[i]=max(res[i],res[i+2]);
    for(int i=1;i<=n;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}