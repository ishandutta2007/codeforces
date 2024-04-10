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
        int n,k;
        cin >> n >> k;
        vector<set<int>> v(n+1);
        auto add=[&](int a,int b)
        {
            v[a].insert(b);
            v[b].insert(a);
        };
        auto rm=[&](int a,int b)
        {
            v[a].erase(b);
            v[b].erase(a);
        };
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            add(a,b);
        }
        set<array<int,2>> s;
        queue<int> leaves[n+1];
        for(int i=1;i<=n;i++)
        {
            for(int to:v[i])
            {
                if(v[to].size()==1) leaves[i].push(to);
            }
            s.insert({(int)leaves[i].size(),i});
        }
        vector<bool> vis(n+1,0);
        int res=0;
        while(!s.empty()&&(*s.rbegin())[0]>=k)
        {
            auto [c,a]=(*s.rbegin());
            s.erase({c,a});
            if(vis[a]==1) continue;
            for(int i=0;i<k;i++)
            {
                int to=leaves[a].front();
                leaves[a].pop();
                vis[to]=1;
                rm(a,to);
            }
            s.insert({(int)leaves[a].size(),a});
            if(v[a].size()==1)
            {
                int to=(*v[a].begin());
                int x=leaves[to].size();
                s.erase({x,to});
                leaves[to].push(a);
                s.insert({x+1,to});
            }
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}