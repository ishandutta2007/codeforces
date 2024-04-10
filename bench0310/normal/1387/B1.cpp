#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    vector<set<int>> v(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    vector<int> res(n+1,0);
    for(int i=1;i<=n;i++) res[i]=i;
    for(int i=1;i<=n;i++) if(v[i].size()==1) q.push(i);
    int dist=0;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        if(v[a].empty()) continue;
        int to=(*v[a].begin());
        v[a].erase(to);
        v[to].erase(a);
        if(v[to].size()==1) q.push(to);
        if(res[a]==a)
        {
            swap(res[a],res[to]);
            dist+=2;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(res[i]==i)
        {
            swap(res[i],res[g[i][0]]);
            dist+=2;
        }
    }
    cout << dist << "\n";
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}