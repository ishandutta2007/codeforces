#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> vis(n+1,0);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1) continue;
        queue<int> q;
        q.push(i);
        vis[i]=1;
        bool ok=1;
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            ok&=(v[a].size()==2);
            for(int to:v[a])
            {
                if(vis[to]==1) continue;
                q.push(to);
                vis[to]=1;
            }
        }
        res+=ok;
    }
    cout << res << "\n";
    return 0;
}