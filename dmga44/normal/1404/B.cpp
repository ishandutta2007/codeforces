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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<int> g[MAXN];
bool mk[MAXN];
int d[MAXN];
int diam;
int len[MAXN];

void dfs(int u)
{
    mk[u]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            d[v]=d[u]+1;
            dfs(v);
        }
}

void dfs2(int u)
{
    mk[u]=1;
    vector<int> ds;
    for(auto v : g[u])
        if(!mk[v])
        {
            dfs2(v);
            ds.push_back(len[v]);
        }

    sort(allr(ds));

    if(ds.empty())
    {
        len[u]=1;
        return ;
    }
    len[u]=ds[0]+1;
    if(ds.size()==1)
        diam=max(diam,ds[0]);
    else
        diam=max(diam,ds[0]+ds[1]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,a,b,da,db;
        int u,v;
        cin >> n >> a >> b >> da >> db;
        a--,b--;
        diam=0;
        for(int i=0;i<n;i++)
        {
            g[i].clear();
            mk[i]=0;
            d[i]=0;
            len[i]=0;
        }
        for(int i=0;i<n-1;i++)
        {
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(a);

        if(d[b]<=da || db<=2*da)
        {
            db("Alice")
            continue;
        }

        for(int i=0;i<n;i++)
            mk[i]=0;
        dfs2(0);

//        for(int i=0;i<n;i++)
//            cout << len[i] << ' ';
//        cout << '\n';
//        db(diam)
        if(diam<=2*da)
            db("Alice")
        else
            db("Bob")
    }

    return 0;
}
/**
4
4 3 2 1 2
1 2
1 3
1 4
6 6 1 2 5
1 2
6 5
2 3
3 4
4 5
9 3 9 2 5
1 2
1 6
1 9
1 3
9 5
7 9
4 8
4 3
11 8 11 3 3
1 2
11 9
4 9
6 5
2 10
3 2
5 9
8 3
7 4
7 10
**/