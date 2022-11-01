#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> res;
    vector<bool> vis(n+1,0);
    set<int> unvis;
    for(int i=1;i<=n;i++) unvis.insert(i);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        int sz=0;
        queue<int> q;
        q.push(i);
        vis[i]=1;
        unvis.erase(i);
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            sz++;
            vector<int> rm;
            for(int to:v[a])
            {
                if(vis[to]==0)
                {
                    unvis.erase(to);
                    rm.push_back(to);
                }
            }
            for(int b:unvis)
            {
                q.push(b);
                vis[b]=1;
            }
            unvis.clear();
            for(int b:rm) unvis.insert(b);
        }
        res.push_back(sz);
    }
    sort(res.begin(),res.end());
    cout << res.size() << "\n";
    for(int a:res) cout << a << " ";
    cout << "\n";
    return 0;
}