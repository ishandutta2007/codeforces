#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> cat(n+1);
    for(int i=1;i<=n;i++) cin >> cat[i];
    vector<int> graph[n+1];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> d(n+1,-1);
    queue<int> q;
    d[1]=cat[1];
    q.push(1);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int to:graph[x])
        {
            if(d[to]==-1)
            {
                if(cat[to]!=0)
                {
                    d[to]=d[x]+cat[to];
                    if(!(d[to]>m)) q.push(to);
                }
                else
                {
                    d[to]=0;
                    q.push(to);
                }
            }
        }
    }
    int res=0;
    for(int i=2;i<=n;i++)
    {
        if(graph[i].size()==1&&0<=d[i]&&d[i]<=m) res++;
    }
    cout << res << "\n";
    return 0;
}