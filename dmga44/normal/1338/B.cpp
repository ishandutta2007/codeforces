#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 100005

vector<int> g[MAXN];
int c[MAXN],d[MAXN],cant[MAXN];
int level[MAXN],mk[MAXN];

void dfs(int u)
{
    mk[u]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            level[v]=level[u]+1;
            dfs(v);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
        c[u]++;
        c[v]++;
        d[u]=v;
        d[v]=u;
    }
    for(int i=0;i<n;i++)
        if(c[i]!=1)
            dfs(i);

    bool l[2];
    l[0]=l[1]=0;
    for(int i=0;i<n;i++)
        if(c[i]==1)
        {
            cant[d[i]]++;
            l[level[i]&1]=1;
        }

    if(!l[0] || !l[1])
        cout << 1 << ' ';
    else
        cout << 3 << ' ';

    int r2=n-1;
    for(int i=0;i<n;i++)
        if(cant[i]!=0)
            r2-=(cant[i]-1);
    cout << r2 << '\n';

    return 0;
}