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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(2e18+5);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int a[MAXN];
vector<int> g[MAXN];
int p[MAXN];
int ini[MAXN];
int ord;
int cont;
ll ans;
int node1;

void dfs1(int u)
{
    ord++;
    ini[u]=ord;
    for(auto v : g[u])
        dfs1(v);
}

bool mk[MAXN];

bool dfs2(int u,int lim,int lvl)
{
    if(a[u]==lim+1)
    {
        node1=u;
        ans+=lvl;
    }
    bool ok=1;
    for(auto v : g[u])
        ok&=dfs2(v,lim,lvl+1);
    if(cont<lim)
    {
        ans+=lvl;
        mk[u]=1;
        if(a[u]!=cont+1)
            ok=0;
    }
    cont++;
    return ok;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        p[v]=u;
    }

    for(int i=0;i<n;i++)
    {
        vector<pii> ts;
        for(auto u : g[i])
            ts.push_back(pii(a[u],u));
        sort(all(ts));
        g[i].clear();
        for(auto p : ts)
            g[i].push_back(p.s);
    }

    dfs1(0);

    ord=0;

    if(a[0]==1)
    {
        bool ok=1;
        for(int i=0;i<n;i++)
            ok&=(a[i]==ini[i]);
        if(!ok)
            db("NO")
        else
        {
            db("YES")
            db(0)
            for(int i=0;i<n;i++)
                cout << ini[i] << ' ';
            cout << '\n';
        }
        return 0;
    }
//    db("xxx")

    int lim=a[0]-2;

    bool ok=dfs2(0,lim,0);

    vector<int> ca(n);
    for(int i=0;i<n;i++)
        ca[i]=a[i];

    int cpy1=node1;
    while(node1!=0)
    {
        swap(ca[node1],ca[p[node1]]);
        node1=p[node1];
    }

    vector<pii> ts;
    for(int i=0;i<n;i++)
        if(!mk[i])
            ts.push_back(pii(ini[i],i));
    sort(all(ts));

    for(int i=0;i<ts.size();i++)
        ok&=(ca[ts[i].s]==lim+i+1);
//    db("xxx")
//    cout << node1 << '\n';
    while(node1!=cpy1 && g[node1].size()!=0)
    {
//        cout << node1 << '\n';
        bool kk=0;
        for(auto u : g[node1])
            if(!mk[u])
            {
                swap(ca[u],ca[node1]);
                swap(u,node1);
                kk=1;
                break;
            }
        if(!kk)
            break;
    }
//    db("xxx")
    for(int i=0;i<n;i++)
        ok&=(ca[i]==a[i]);

    if(!ok)
        db("NO")
    else
    {
        db("YES")
        db(ans)
        for(int i=0;i<n;i++)
            cout << ini[i] << ' ';
        cout << '\n';
    }

    return 0;
}
/**
7
7 6 5 3 1 4 2
4 3
2 5
3 7
1 4
7 2
2 6
**/