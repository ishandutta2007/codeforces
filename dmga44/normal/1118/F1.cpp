#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 300005

vector<int> g[MAXN];
int a[MAXN],cont[MAXN][2],f[2],res;
bool mk[MAXN];

void dfs(int u)
{
    mk[u]=1;
    if(a[u])
        cont[u][a[u]-1]++;
    for(auto v : g[u])
        if(!mk[v])
        {
            dfs(v);
            cont[u][0]+=cont[v][0];
            cont[u][1]+=cont[v][1];
        }

    if(!cont[u][0] && cont[u][1]==f[1])
        res++;
    if(!cont[u][1] && cont[u][0]==f[0])
        res++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i])
            f[a[i]-1]++;
    }
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    db(res)

    return 0;
}