#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

vector<int> g[MAXN];
ll res,sons[MAXN][2],sum[MAXN],tot[MAXN];
bool mk[MAXN];

void dfs(int u)
{
    mk[u]=1;
    sons[u][0]++;
    tot[u]++;
    for(auto v : g[u])
        if(!mk[v])
        {
            dfs(v);

            sum[v]=(sum[v]+tot[v]-sons[v][1]);
            swap(sons[v][0],sons[v][1]);

            res+=(sum[u]*tot[v]);
            res+=(sum[v]*tot[u]);
            res-=(sons[u][1]*sons[v][1]);

            sum[u]+=sum[v];
            sons[u][0]+=sons[v][0];
            sons[u][1]+=sons[v][1];
            tot[u]=sons[u][0]+sons[u][1];
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
    }

    dfs(0);

    db(res)

    return 0;
}