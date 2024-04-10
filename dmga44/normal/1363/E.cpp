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
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN 200005

vector<int> g[MAXN];
ll a[MAXN],b[MAXN],c[MAXN];
ll mac[MAXN],sons[MAXN][4],res;
bool mk[MAXN];

void dfs(int u)
{
    mk[u]=1;
    mac[u]=min(mac[u],a[u]);
    sons[u][c[u]+2*b[u]]=1;
    for(auto v : g[u])
    {
        if(!mk[v])
        {
            mac[v]=mac[u];
            dfs(v);
            for(int i=0;i<4;i++)
                sons[u][i]+=sons[v][i];
        }
    }

    int x=min(sons[u][1],sons[u][2]);
    res+=2*x*mac[u];
    sons[u][1]-=x;
    sons[u][0]+=x;
    sons[u][2]-=x;
    sons[u][3]+=x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,u,v;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i] >> b[i] >> c[i];

    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    mac[0]=1e9+5;
    dfs(0);

    if(sons[0][0]+sons[0][3]==n)
        db(res)
    else
        db(-1)

    return 0;
}
/**
5
1 0 1
20 1 0
100 0 1
4000 0 0
50000 1 0
1 2
2 3
2 4
1 5

**/