#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> g[N];

array<int,2> bfs(int src)
{
    vector<int> d(N,-1);
    d[src]=0;
    queue<int> q;
    q.push(src);
    int x=src;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int to:g[a])
        {
            if(d[to]==-1)
            {
                d[to]=d[a]+1;
                if(d[to]>d[x]) x=to;
                q.push(to);
            }
        }
    }
    return {x,d[x]};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(n+1,0);
    for(int i=1;i<=n;i++) cin >> c[i];
    vector<int> v[n+1];
    vector<array<int,2>> edges(n-1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        edges[i]={a,b};
    }
    vector<int> comp(n+1,0);
    int id=1;
    for(int i=1;i<=n;i++)
    {
        if(comp[i]!=0) continue;
        comp[i]=id++;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            for(int to:v[a])
            {
                if(comp[to]==0&&c[to]==c[a])
                {
                    q.push(to);
                    comp[to]=comp[a];
                }
            }
        }
    }
    for(auto [a,b]:edges)
    {
        if(comp[a]!=comp[b])
        {
            g[comp[a]].push_back(comp[b]);
            g[comp[b]].push_back(comp[a]);
        }
    }
    int src=bfs(1)[0];
    int d=bfs(src)[1];
    cout << (d+1)/2 << "\n";
    return 0;
}