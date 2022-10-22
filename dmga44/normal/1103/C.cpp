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
int level[MAXN];
bool mk[MAXN];
vector<int> leaves;
int parent[MAXN];

void dfs(int u)
{
    mk[u]=1;
    bool is_leaf=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            is_leaf=0;
            parent[v]=u;
            level[v]=level[u]+1;
            dfs(v);
        }
    if(is_leaf)
        leaves.push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    vector<int> el_tipo;
    for(int i=0;i<n;i++)
        if(level[i]>=n/k)
            el_tipo.push_back(i);

    if(el_tipo.size())
    {
        db("PATH")
        int u=el_tipo[0];
        db(level[u]+1)
        while(level[u])
        {
            cout << u+1 << ' ';
            u=parent[u];
        }
        cout << u+1 << '\n';
        return 0;
    }

    db("CYCLES")
    for(int i=0;i<k;i++)
    {
        int leaf=leaves[i];
        int p1=g[leaf][0];
        int p2=g[leaf][1];
        int p3=g[leaf][2];
        vector<pii> kks;
        if(p1!=parent[leaf])
            kks.push_back(pii(level[p1],p1));
        if(p2!=parent[leaf])
            kks.push_back(pii(level[p2],p2));
        if(p3!=parent[leaf])
            kks.push_back(pii(level[p3],p3));
        sort(allr(kks));
        int u=kks[0].s;
        int v=kks[1].s;
        if((level[leaf]-level[u])%3!=2)
        {
            db(level[leaf]-level[u]+1)
            while(leaf!=u)
            {
                cout << leaf+1 << ' ';
                leaf=parent[leaf];
            }
            cout << u+1 << '\n';
        }
        else if((level[leaf]-level[v])%3!=2)
        {
            db(level[leaf]-level[v]+1)
            while(leaf!=v)
            {
                cout << leaf+1 << ' ';
                leaf=parent[leaf];
            }
            cout << v+1 << '\n';
        }
        else
        {
            db(level[u]-level[v]+2)
            cout << leaf+1 << ' ';
            leaf=u;
            while(leaf!=v)
            {
                cout << leaf+1 << ' ';
                leaf=parent[leaf];
            }
            cout << v+1 << '\n';
        }
    }

    return 0;
}