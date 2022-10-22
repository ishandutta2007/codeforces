#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define MAXN 200005

vector<int> g[MAXN],gg[MAXN];
bool mk[MAXN];
int f[2],level[MAXN];

void dfs(int u)
{
    mk[u]=1;
    for(auto y : g[u])
        if(!mk[y])
        {
            gg[u].push_back(y);
            gg[y].push_back(u);
            dfs(y);
        }
}

void dfs1(int u)
{
    mk[u]=1;
    f[level[u]&1]++;
    for(auto y : g[u])
        if(!mk[y])
        {
            level[y]=level[u]+1;
            dfs1(y);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,u,v;
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0);
        for(int i=0;i<n;i++)
            mk[i]=0;

        dfs1(0);

        if(f[0]<f[1] || !f[1])
        {
            db(f[0])
            for(int i=0;i<n;i++)
                if((level[i]&1)==0)
                    cout << i+1 << ' ';
            cout << '\n';
        }
        else
        {
            db(f[1])
            for(int i=0;i<n;i++)
                if((level[i]&1)==1)
                    cout << i+1 << ' ';
            cout << '\n';
        }

        f[0]=f[1]=0;
        for(int i=0;i<=n;i++)
        {
            g[i].clear();
            gg[i].clear();
            level[i]=0;
            mk[i]=0;
        }
    }

    return 0;
}