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
#define MAXN (ll)(2e5+5)

int d[MAXN];
int ma[MAXN],p[MAXN],a[MAXN],last[MAXN];
bool is_p[MAXN];
vector<int> g[MAXN];
int cont;
bool mm[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

void join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
    ma[u]=max(ma[u],ma[v]);
}

void dfs(int u)
{
    mm[u]=1;
    cont++;
    for(auto v : g[u])
        if(!mm[v])
            dfs(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        last[i]=-1;
        d[i]=-1;
        ma[i]=i;
        p[i]=i;
    }

    for(int i=0;i<n-1;i++)
    {
        cin >> a[i];
        a[i]--;
        is_p[a[i]]=1;
        if(last[a[i]]==-1)
            last[a[i]]=i;
    }

    priority_queue<pii,vector<pii>,greater<pii> > pq;
    for(int i=0;i<n;i++)
        if(!is_p[i])
            pq.push(pii(ma[i],i));

    vector<pii> res;
    for(int i=n-2;i>=0;i--)
    {
        if(pq.empty())
            break;
        pii x=pq.top();
//        cout << x.first << ' ' << x.s << '\n';
        pq.pop();

        int u=x.s;
        int v=a[i];
        int par=p[find(v)];
        res.push_back(pii(u,v));
        g[u].push_back(v);
        g[v].push_back(u);
        join(u,v);
        p[find(u)]=par;
        if(i==last[a[i]])
            pq.push(pii(ma[find(u)],p[find(u)]));
    }

    dfs(0);
    if(cont==n)
    {
        db(a[0]+1)
        reverse(all(res));
        for(int i=0;i<n-1;i++)
            cout << res[i].f+1 << ' ' << res[i].s+1 << '\n';
    }
    else
        db(-1)

    return 0;
}
/**
6
3 6 3 1 5
**/