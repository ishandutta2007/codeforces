#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> v[n+1];
        vector<int> g[n+1];
        vector<int> in(n+1,0);
        for(int i=0;i<m;i++)
        {
            int x,a,b;
            cin >> x >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
            if(x==1)
            {
                g[a].push_back(b);
                in[b]++;
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++) if(in[i]==0) q.push(i);
        vector<int> ord;
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            ord.push_back(a);
            for(int to:g[a])
            {
                in[to]--;
                if(in[to]==0) q.push(to);
            }
        }
        if((int)ord.size()==n)
        {
            cout << "YES\n";
            vector<bool> vis(n+1,0);
            for(int a:ord)
            {
                vis[a]=1;
                for(int to:v[a]) if(vis[to]==0) cout << a << " " << to << "\n";
            }
        }
        else cout << "NO\n";
    }
    return 0;
}