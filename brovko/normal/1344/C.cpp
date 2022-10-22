#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int INF=(int)1e9;

int n, m, x, y, Min1[200005], Min2[200005], used1[200005], used2[200005], used3[200005], ans[200005];
vector <int> g[200005], gr[200005];

void dfs1(int v)
{
    used1[v]=1;
    for(auto to:g[v])
        if(used1[to]==0)
            dfs1(to);
        else if(used1[to]==1)
        {
            cout << -1;
            exit(0);
        }
    used1[v]=2;
}

void dfs2(int v)
{
    if(used2[v])
        return;
    used2[v]=1;
    Min1[v]=min(Min1[v], v);

    for(auto to:g[v])
    {
        dfs2(to);
        Min1[v]=min(Min1[v], Min1[to]);
    }
}

void dfs3(int v)
{
    if(used3[v])
        return;
    used3[v]=1;
    Min2[v]=min(Min2[v], v);

    for(auto to:gr[v])
    {
        dfs3(to);
        Min2[v]=min(Min2[v], Min2[to]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        gr[y].push_back(x);
    }

    for(int i=0;i<200005;i++)
    {
        Min1[i]=INF;
        Min2[i]=INF;
    }
    for(int i=0;i<n;i++)
        if(used1[i]==0)
            dfs1(i);
    for(int i=0;i<n;i++)
        if(used2[i]==0)
            dfs2(i);
    for(int i=0;i<n;i++)
        if(used3[i]==0)
            dfs3(i);

    int k=0;
    for(int i=0;i<n;i++)
        if(Min1[i]==i && Min2[i]==i)
        {
            k++;
            ans[i]=1;
        }
    cout << k << endl;
    for(int i=0;i<n;i++)
        if(ans[i])
            cout << "A";
    else cout << "E";
}