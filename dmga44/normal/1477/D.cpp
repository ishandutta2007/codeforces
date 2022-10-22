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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

vector<int> g[MAXN];
int cant[MAXN];
int d[MAXN];
vector<int> tree[MAXN];
int match[MAXN];
bool is_leaf[MAXN];
bool mk1[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

bool join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return 0;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
    return 1;
}

pii trans(pii x)
{
    return pii(min(x.f,x.s),max(x.f,x.s));
}

void dfs(int u)
{
    mk1[u]=1;
    is_leaf[u]=1;
    vector<int> leaves;
    vector<int> difs;
    vector<int> eqs;
    for(auto v : tree[u])
    {
        if(mk1[v])
            continue;
        dfs(v);
        is_leaf[u]=0;
        if(is_leaf[v])
            leaves.push_back(v);
        else if(match[v]!=v+1)
            difs.push_back(v);
        else
            eqs.push_back(v);
    }

    if(is_leaf[u])
        return;
    if(leaves.size())
    {
        match[u]=u+1;
        for(auto v : leaves)
            match[v]=u+1;
        return;
    }
    if(difs.size())
    {
        match[u]=u+1;
        match[difs[0]]=u+1;
        return;
    }
    match[u]=eqs[0]+1;
}

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
        set<pii> s;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            if(u>v)
                swap(u,v);
            cant[u]++;
            cant[v]++;
            s.insert(pii(u,v));
        }

        vector<pii> ts;
        for(int i=0;i<n;i++)
            ts.push_back(pii(cant[i],i));

        sort(all(ts));

        vector<int> a(n);
        vector<int> b(n);
        vector<bool> done(n);
        vector<bool> mk(n);
        for(int i=n-1;i>=0;i--)
        {
            if(ts[i].f!=n-1)
                break;
            a[ts[i].s]=b[ts[i].s]=i+1;
            done[ts[i].s]=1;
            mk[ts[i].s]=1;
        }

        if(done[ts[0].s])
        {
            for(int i=0;i<n;i++)
                cout << a[i] << ' ';
            cout << '\n';
            for(int i=0;i<n;i++)
                cout << b[i] << ' ';
            cout << '\n';

            for(int i=0;i<n;i++)
            {
                tree[i].clear();
                g[i].clear();
                cant[i]=0;
                d[i]=0;
                match[i]=0;
                is_leaf[i]=0;
                mk1[i]=0;
            }

            continue;
        }

        for(int i=0;i<n;i++)
            d[i]=-1;
        mk[ts[0].s]=1;
        for(int i=0;i<n;i++)
        {
            if(i==ts[0].s)
                continue;
            if(!s.count(trans(pii(i,ts[0].s))))
            {
                if(join(i,ts[0].s))
                {
                    mk[i]=1;
                    tree[i].push_back(ts[0].s);
                    tree[ts[0].s].push_back(i);
                }
            }
        }

        vector<int> extra;
        for(int i=0;i<n;i++)
            if(!mk[i])
                extra.push_back(i);
        for(int i=0;i<extra.size();i++)
            for(int v=0;v<n;v++)
            {
                int u=extra[i];
                if(u==v)
                    continue;
                if(!s.count(trans(pii(u,v))) && join(u,v))
                {
                    tree[u].push_back(v);
                    tree[v].push_back(u);
                }
            }
//        db("")
//        for(int i=0;i<n;i++)
//        {
//            db(i)
//            for(auto v : tree[i])
//                cout << v << ' ';
//            cout << '\n';
//        }
//        db("")

        for(int i=0;i<n;i++)
        {
            if(done[i] || mk1[i])
                continue;
            dfs(i);
        }
//        for(int i=0;i<n;i++)
//            cout << i << ' ' << match[i] << '\n';
//        db("")

        vector<vector<int> > ocs(n);
        for(int i=0;i<n;i++)
            if(!done[i])
                ocs[match[i]-1].push_back(i);

        int cont=1;
        for(int i=0;i<n;i++)
        {
            if(!ocs[i].size())
                continue;
            int ini=cont;
            int fin=cont+ocs[i].size()-1;
            for(auto v : ocs[i])
            {
                if(v==i)
                {
                    a[v]=ini;
                    b[v]=fin;
                }
                else
                {
                    cont++;
                    a[v]=cont;
                    b[v]=cont-1;
                }
            }
            cont=fin+1;
        }

        for(int i=0;i<n;i++)
            cout << a[i] << ' ';
        cout << '\n';
        for(int i=0;i<n;i++)
            cout << b[i] << ' ';
        cout << '\n';

        for(int i=0;i<n;i++)
        {
            tree[i].clear();
            g[i].clear();
            cant[i]=0;
            d[i]=0;
            match[i]=0;
            is_leaf[i]=0;
            mk1[i]=0;
        }
    }

    return 0;
}