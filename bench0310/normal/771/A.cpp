#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> v[n+1];
    vector<bool> vis(n+1,0);
    vector<bool> used(m+1,0);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    bool ok=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1) continue;
        queue<int> q;
        int cnt=1;
        int edges=0;
        q.push(i);
        vis[i]=1;
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            for(auto [to,id]:v[a])
            {
                if(vis[to]==0)
                {
                    vis[to]=1;
                    cnt++;
                    q.push(to);
                }
                if(used[id]==0)
                {
                    used[id]=1;
                    edges++;
                }
            }
        }
        ok&=((ll)cnt*(cnt-1)/2==edges);
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}