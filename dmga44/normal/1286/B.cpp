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
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 2005

vector<int> g[MAXN],vals[MAXN];
int p[MAXN],c[MAXN],sons[MAXN],res[MAXN];
bool ok;

void dfs(int u)
{
    sons[u]=1;
    for(auto v : g[u])
    {
        dfs(v);
        sons[u]+=sons[v];
    }
}

void dfs1(int u)
{
    if(c[u]>=sons[u])
    {
        ok=0;
        return;
    }
    res[u]=vals[u][c[u]];
    queue<int> ss;
    for(int i=0;i<sons[u];i++)
        if(i!=c[u])
            ss.push(vals[u][i]);
    for(auto v : g[u])
    {
        for(int i=0;i<sons[v];i++)
        {
            vals[v].push_back(ss.front());
            ss.pop();
        }
        dfs1(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int root=-1;
    for(int i=0;i<n;i++)
    {
        cin >> p[i] >> c[i];
        if(!p[i])
            root=i;
        else
        {
            p[i]--;
            g[p[i]].push_back(i);
        }
    }

    dfs(root);

    for(int i=1;i<=n;i++)
        vals[root].push_back(i);
    ok=1;
    dfs1(root);

    if(ok)
    {
        db("YES")
        for(int i=0;i<n;i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
    else
        db("NO")
    return 0;
}