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
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

bool ty[2*MAXN];
int ini[2*MAXN];
int fin[2*MAXN];
int ff[MAXN];
int d[MAXN];
int cont;
int nexx[MAXN];
vector<int> g[MAXN];

//int find(int u)
//{
//    if(d[u]<0)
//        return u;
//    d[u]=find(d[u]);
//    return d[u];
//}
//
void join(int u,int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
//    u=find(u);
//    v=find(v);
//    if(d[u]>d[v])
//        swap(u,v);
//    d[u]+=d[v];
//    d[v]=u;
    cont++;
}

int cant;
bool mk[MAXN];

void dfs(int u)
{
    mk[u]=1;
    cant++;
    for(auto v : g[u])
        if(!mk[v])
            dfs(v);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int x,y;
    for(int i=0;i<n;i++)
        d[i]=-1;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        ty[x]=1;
        ini[x]=i;
        fin[y]=i;
        ff[i]=y;
    }

    for(int i=0;i<MAXN;i++)
        nexx[i]=-1;

    int in=-1;
    int v,u;
    for(int i=1;i<=2*n && cont<n;i++)
    {
        if(ty[i])
        {
            u=ini[i];
            int last=-1;
            int p=in;
            while(p!=-1 && p<ff[u])
            {
                v=fin[p];
                join(u,v);
                last=p;
                p=nexx[p];
            }

            if(last==-1)
            {
                nexx[ff[u]]=in;
                in=ff[u];
            }
            else
            {
                nexx[last]=ff[u];
                nexx[ff[u]]=p;
            }
        }
        else
            in=nexx[in];
    }

    dfs(0);

    if(cont==n-1 && cant==n)
        db("YES")
    else
        db("NO")

    return 0;
}